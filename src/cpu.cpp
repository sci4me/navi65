#include <assert.h>

#include "cpu.h"
#include "opcodes.h"

#define ZP(x) ((u8) (x))

static inline u16 mem_abs(u8 low, u8 high, u8 off) {
    return (u16) off + (u16) low + ((u16) high << 8);
}

static inline u16 mem_indirect_index(CPU *m, u8 addr, u8 off) {
    return mem_abs(m->bus->read(addr), m->bus->read(addr + 1), off);
}

static inline u16 mem_indexed_indirect(CPU *m, u8 addr, u8 off) {
    return mem_abs(m->bus->read(addr + off), m->bus->read(addr + off + 1), 0);
}

static inline u16 mem_indirect_zp(CPU *m, u8 addr) {
    return mem_abs(m->bus->read(addr), m->bus->read(addr + 1), 0);
}

static inline u8 bcd(u8 val) {
    // bcd is "binary coded decimal"; it treats the upper nibble and lower
    // nibble of a byte each as a decimal digit, so 01011000 -> 0101 1000 -> 58.
    // in other words, treat hex output as decimal output, so 0x58 is treated as
    // 58. this is dumb and adds a bunch of branching to opcode interpretation
    // that I Do Not Like.
    return 10 * (val >> 4) + (0x0F & val);
}

CPU::CPU(Bus *_bus) : bus(_bus) {
	this->stopped = false;
    this->interrupt_waiting = false;
	this->break_waiting = false;
	
	this->pc = 0;
	this->sp = 0xFF;
	this->a = 0;
	this->x = 0;
	this->y = 0;
	this->flags = FLAG_INTERRUPT;
}

CPU::~CPU() {
}

void CPU::reset() {
    this->pc = this->bus->read_u16(RESET_VECTOR);
}

#include <stdio.h>
void CPU::cycle() {
	u8 opcode = this->read_u8();

	u8 arg1 = 0;
	u8 arg2 = 0;
	u8 t1 = 0;
	s8 s1 = 0;
	u16 r1 = 0;
	u16 r2 = 0;
	u8 pc_offset = 0;
	u16 pc_start = this->pc;
	s8 branch_offset = 0;

    u16 addr = 0;
    u8 val = 0;
    u8 t2 = 0;

    u8 mode = OPCODE_ADDRESSING_MODES[opcode];
    switch(mode) {
        case AM_N:
            break;
        case AM_ACC:
            break;
        case AM_AB:
            arg1 = this->read_u8();
            arg2 = this->read_u8();
            addr = mem_abs(arg1, arg2, 0);
            break;
        case AM_ABX:
            arg1 = this->read_u8();
            arg2 = this->read_u8();
            addr = mem_abs(arg1, arg2, this->x);
            break;
        case AM_ABY:
            arg1 = this->read_u8();
            arg2 = this->read_u8();
            addr = mem_abs(arg1, arg2, this->y);
            break;
        case AM_IMM:
            val = this->read_u8();
            break;
        case AM_IN:
            arg1 = this->read_u8();
            r1 = mem_abs(arg1, this->read_u8(), 0);
            addr = mem_abs(this->bus->read(r1), this->bus->read(r1+1), 0);
            break;
        case AM_INX:
            t2 = this->read_u8();
            addr = mem_indexed_indirect(this, t2, this->x);
            break;
        case AM_INY:
            t2 = this->read_u8();
            addr = mem_indirect_index(this, t2, this->y);
            break;
        case AM_REL:
            s1 = this->read_u8();
            break;
        case AM_ZP:
            addr = this->read_u8();
            break;
        case AM_IZP:
            t2 = this->read_u8();
            addr = mem_indirect_zp(this, t2);
            break;
        case AM_ZPX:
            t2 = this->read_u8();
            addr = ZP(t2 + this->x);
            break;
        case AM_ZPY:
            t2 = this->read_u8();
            addr = ZP(t2 + this->y);
            break;
        case AM_S:
            break;
        case AM_I:
            break;
        default:
            fprintf(stderr, "Unrecognized addressing mode: %u\n", mode);
            assert(false);
    }

#ifdef __DEBUG_TRACE__
#define DEBUG_TRACE(...)        printf(__VA_ARGS__)
#define DEBUG_TRACE_ACC(name)   DEBUG_TRACE("%s a", name)
#define DEBUG_TRACE_AB(name)    DEBUG_TRACE("%s $%04X", name, addr)
#define DEBUG_TRACE_ABX(name)   DEBUG_TRACE("%s $%04X,x", name, addr)
#define DEBUG_TRACE_ABY(name)   DEBUG_TRACE("%s $%04X,y", name, addr)
#define DEBUG_TRACE_IMM(name)   DEBUG_TRACE("%s $%02X", name, val)
#define DEBUG_TRACE_IN(name)    DEBUG_TRACE("%s ($%04X)", name, addr)
#define DEBUG_TRACE_INX(name)   DEBUG_TRACE("%s ($%02X,x)", name, t2)
#define DEBUG_TRACE_INY(name)   DEBUG_TRACE("%s ($%02X),y", name, t2)
#define DEBUG_TRACE_REL(name)   DEBUG_TRACE("%s [#$%02X]", name, s1)
#define DEBUG_TRACE_ZP(name)    DEBUG_TRACE("%s $%02X", name, addr)
#define DEBUG_TRACE_INZP(name)  DEBUG_TRACE("%s ($%02X)", name, t2)
#define DEBUG_TRACE_ZPX(name)   DEBUG_TRACE("%s $%02X,x", name, t2)
#define DEBUG_TRACE_ZPY(name)   DEBUG_TRACE("%s $%02X,y", name, t2)
#else
#define DEBUG_TRACE(...)
#define DEBUG_TRACE_ACC(name)
#define DEBUG_TRACE_AB(name)
#define DEBUG_TRACE_ABX(name)
#define DEBUG_TRACE_ABY(name)
#define DEBUG_TRACE_IMM(name)
#define DEBUG_TRACE_IN(name)
#define DEBUG_TRACE_INX(name)
#define DEBUG_TRACE_INY(name)
#define DEBUG_TRACE_REL(name)
#define DEBUG_TRACE_ZP(name)
#define DEBUG_TRACE_INZP(name)
#define DEBUG_TRACE_ZPX(name)
#define DEBUG_TRACE_ZPY(name)
#endif

    DEBUG_TRACE("%04X (%02X) ", this->pc - 1, opcode);

	switch(opcode) {
		#include "opcodes/arithmetic.h"
        #include "opcodes/branch.h"
        #include "opcodes/compare.h"
        #include "opcodes/flags.h"
        #include "opcodes/incdec.h"
        #include "opcodes/interrupts.h"
        #include "opcodes/jump.h"
        #include "opcodes/load.h"
        #include "opcodes/logical.h"
        #include "opcodes/shift.h"
        #include "opcodes/stack.h"
        #include "opcodes/store.h"
        #include "opcodes/transfer.h"
        case NOP:
        	break;
        case STP:
        	this->stopped = true;
        	break;
        default:
            printf("Unrecognized opcode: %02X\n", opcode);
            break;
	}

    DEBUG_TRACE("\n");

	if (this->pc == pc_start) {
        this->pc += pc_offset;
    }
    this->pc += branch_offset;

    if (this->break_waiting && !this->get_flag(FLAG_INTERRUPT)) {
        this->push((this->pc & 0xFF00) >> 8);
        this->push(this->pc & 0xFF);
        this->push(this->flags);

        this->break_waiting = 0x00;
        this->pc = mem_abs(this->bus->read(0xFFFE), this->bus->read(0xFFFF), 0);
        this->flags |= FLAG_INTERRUPT;
    }
}

void CPU::set_flag(u8 flag, bool value) {
    if(value)   this->flags |= flag;
    else        this->flags &= ~flag;
}

bool CPU::get_flag(u8 flag) {
    return this->flags & flag;
}

void CPU::set_flags(u8 val) {
    this->set_flag(FLAG_ZERO, !val);
    this->set_flag(FLAG_NEGATIVE, val & 0x80);
}

void CPU::add(u16 r1) {
    // committing a cardinal sin for my sanity's sake. callers should initialize
    // r1 to the argument to the add.
    if (this->get_flag(FLAG_DECIMAL)) {
        r1 = bcd(r1) + bcd(this->a) + this->get_flag(FLAG_CARRY);
        this->set_flag(FLAG_CARRY, r1 > 99);
    } else {
        r1 += this->a + this->get_flag(FLAG_CARRY);
        this->set_flag(FLAG_CARRY, r1 & 0xFF00);
    }
    this->set_flag(FLAG_OVERFLOW, (this->a & 0x80) != (r1 & 0x80));
    this->set_flag(FLAG_ZERO, r1 == 0);
    this->set_flag(FLAG_NEGATIVE, r1 & 0x80);
    this->a = r1;
}

void CPU::sub(u16 r1) {
    if (this->get_flag(FLAG_DECIMAL)) {
        r1 = bcd(this->a) - bcd(r1) - !this->get_flag(FLAG_CARRY);
        this->set_flag(FLAG_OVERFLOW, r1 > 99 || r1 < 0);
    } else {
        r1 = this->a - r1 - !this->get_flag(FLAG_CARRY);
        this->set_flag(FLAG_OVERFLOW, 0xFF00 & r1);
    }
    this->set_flag(FLAG_CARRY, !(r1 & 0x8000));
    this->set_flag(FLAG_NEGATIVE, r1 & 0x80);
    this->set_flag(FLAG_ZERO, r1 == 0);
    this->a = r1;
}

void CPU::cmp(u8 mem, u8 reg) {
    this->set_flag(FLAG_CARRY, reg >= mem);
    this->set_flag(FLAG_ZERO, reg == mem);
    this->set_flag(FLAG_NEGATIVE, 0x80 & (reg - mem));
}

void CPU::push(u8 value) {
    this->bus->write(this->sp--, value);
}

u8 CPU::pop() {
    return this->bus->read(++this->sp);
}

u8 CPU::read_u8() {
	return this->bus->read(this->pc++);
}

u16 CPU::read_u16() {
	auto result = this->bus->read_u16(this->pc);
    this->pc += 2;
    return result;
}
case LDA_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    m->ac = m->mem[mem_abs(arg1, arg2, 0)];
    set_flags(m, m->ac);
    break;

case LDA_ABX:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    m->ac = m->mem[mem_abs(arg1, arg2, m->x)];
    set_flags(m, m->ac);
    break;

case LDA_ABY:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    m->ac = m->mem[mem_abs(arg1, arg2, m->y)];
    set_flags(m, m->ac);
    break;

case LDA_IMM:
    m->ac = this->read_u8();
    set_flags(m, m->ac);
    break;

case LDA_INX:
    m->ac = m->mem[mem_indexed_indirect(m, this->read_u8(), m->x)];
    set_flags(m, m->ac);
    break;

case LDA_INY:
    m->ac = m->mem[mem_indirect_index(m, this->read_u8(), m->y)];
    set_flags(m, m->ac);
    break;

case LDA_ZP:
    m->ac = m->mem[this->read_u8()];
    set_flags(m, m->ac);
    break;

case LDA_ZPX:
    m->ac = m->mem[this->read_u8() + m->x];
    set_flags(m, m->ac);
    break;

case LDA_INZP:
    m->ac = m->mem[mem_indirect_zp(m, this->read_u8())];
    break;

case LDX_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    m->x = m->mem[mem_abs(arg1, arg2, 0)];
    set_flags(m, m->x);
    break;

case LDX_ABY:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    m->x = m->mem[mem_abs(arg1, arg2, m->y)];
    set_flags(m, m->x);
    break;

case LDX_IMM:
    m->x = this->read_u8();
    set_flags(m, m->x);
    break;

case LDX_ZP:
    m->x = m->mem[this->read_u8()];
    set_flags(m, m->x);
    break;

case LDX_ZPY:
    m->x = m->mem[this->read_u8() + m->y];
    set_flags(m, m->x);
    break;

case LDY_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    m->y = m->mem[mem_abs(arg1, arg2, 0)];
    set_flags(m, m->y);
    break;

case LDY_ABX:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    m->y = m->mem[mem_abs(arg1, arg2, m->x)];
    set_flags(m, m->y);
    break;

case LDY_IMM:
    m->y = this->read_u8();
    set_flags(m, m->y);
    break;

case LDY_ZP:
    m->y = m->mem[this->read_u8()];
    set_flags(m, m->y);
    break;

case LDY_ZPX:
    m->y = m->mem[this->read_u8() + m->x];
    set_flags(m, m->y);
    break;

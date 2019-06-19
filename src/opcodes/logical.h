case AND_IMM:
    this->a &= this->read_u8();
    this->set_flags(this->a);
    break;

case AND_ZP:
    this->a &= this->bus->read(this->read_u8());
    this->set_flags(this->a);
    break;

case AND_ZPX:
    this->a &= this->bus->read(ZP(this->read_u8() + this->x));
    this->set_flags(this->a);
    break;

case AND_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    this->a &= this->bus->read(mem_abs(arg1, arg2, 0));
    this->set_flags(this->a);
    break;

case AND_ABX:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    this->a &= this->bus->read(mem_abs(arg1, arg2, this->x));
    this->set_flags(this->a);
    break;

case AND_ABY:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    this->a &= this->bus->read(mem_abs(arg1, arg2, this->y));
    this->set_flags(this->a);
    break;

case AND_INX:
    this->a &= this->bus->read(mem_indexed_indirect(this, this->read_u8(), this->x));
    this->set_flags(this->a);
    break;

case AND_INY:
    this->a &= this->bus->read(mem_indirect_index(this, this->read_u8(), this->y));
    this->set_flags(this->a);
    break;

case AND_INZP:
    this->a &= this->bus->read(mem_indirect_zp(this, this->read_u8()));
    this->set_flags(this->a);
    break;

case EOR_IMM:
    this->a ^= this->read_u8();
    this->set_flags(this->a);
    break;

case EOR_ZP:
    this->a ^= this->bus->read(this->read_u8());
    this->set_flags(this->a);
    break;

case EOR_ZPX:
    this->a ^= this->bus->read(ZP(this->read_u8() + this->x));
    this->set_flags(this->a);
    break;

case EOR_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    this->a ^= this->bus->read(mem_abs(arg1, arg2, 0));
    this->set_flags(this->a);
    break;

case EOR_ABX:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    this->a ^= this->bus->read(mem_abs(arg1, arg2, this->x));
    this->set_flags(this->a);
    break;

case EOR_ABY:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    this->a ^= this->bus->read(mem_abs(arg1, arg2, this->y));
    this->set_flags(this->a);
    break;

case EOR_INX:
    this->a ^= this->bus->read(mem_indexed_indirect(this, this->read_u8(), this->x));
    this->set_flags(this->a);
    break;

case EOR_INY:
    this->a ^= this->bus->read(mem_indirect_index(this, this->read_u8(), this->y));
    this->set_flags(this->a);
    break;

case EOR_INZP:
    this->a ^= this->bus->read(mem_indirect_zp(this, this->read_u8()));
    this->set_flags(this->a);
    break;

case ORA_IMM:
    this->a |= this->read_u8();
    this->set_flags(this->a);
    break;

case ORA_ZP:
    this->a |= this->bus->read(this->read_u8());
    this->set_flags(this->a);
    break;

case ORA_ZPX:
    this->a |= this->bus->read(ZP(this->read_u8() + this->x));
    this->set_flags(this->a);
    break;

case ORA_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    this->a |= this->bus->read(mem_abs(arg1, arg2, 0));
    this->set_flags(this->a);
    break;

case ORA_ABX:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    this->a |= this->bus->read(mem_abs(arg1, arg2, this->x));
    this->set_flags(this->a);
    break;

case ORA_ABY:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    this->a |= this->bus->read(mem_abs(arg1, arg2, this->y));
    this->set_flags(this->a);
    break;

case ORA_INX:
    this->a |= this->bus->read(mem_indexed_indirect(this, this->read_u8(), this->x));
    this->set_flags(this->a);
    break;

case ORA_INY:
    this->a |= this->bus->read(mem_indirect_index(this, this->read_u8(), this->y));
    this->set_flags(this->a);
    break;

case ORA_INZP:
    this->a |= this->bus->read(mem_indirect_zp(this, this->read_u8()));
    this->set_flags(this->a);
    break;

case BIT_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    t1 = this->bus->read(mem_abs(arg1, arg2, 0));
    this->set_flag(FLAG_ZERO, !(t1 & this->a));
    this->set_flag(FLAG_OVERFLOW, t1 & 0x40);
    this->set_flag(FLAG_NEGATIVE, t1 & 0x80);
    break;

case BIT_ABX:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    t1 = this->bus->read(mem_abs(arg1, arg2, this->x));
    this->set_flag(FLAG_ZERO, !(t1 & this->a));
    this->set_flag(FLAG_OVERFLOW, t1 & 0x40);
    this->set_flag(FLAG_NEGATIVE, t1 & 0x80);
    break;

case BIT_IMM:
    t1 = this->read_u8();
    this->set_flag(FLAG_ZERO, !(t1 & this->a));
    this->set_flag(FLAG_OVERFLOW, t1 & 0x40);
    this->set_flag(FLAG_NEGATIVE, t1 & 0x80);
    break;    

case BIT_ZP:
    t1 = this->bus->read(this->read_u8());
    this->set_flag(FLAG_ZERO, !(t1 & this->a));
    this->set_flag(FLAG_OVERFLOW, t1 & 0x40);
    this->set_flag(FLAG_NEGATIVE, t1 & 0x80);
    break;

case BIT_ZPX:
    t1 = this->bus->read(ZP(this->read_u8() + this->x));
    this->set_flag(FLAG_ZERO, !(t1 & this->a));
    this->set_flag(FLAG_OVERFLOW, t1 & 0x40);
    this->set_flag(FLAG_NEGATIVE, t1 & 0x80);
    break;

case RMB0:
    r1 = this->read_u8();
    this->bus->write(r1, this->bus->read(r1) & ~0x01);
    break;

case RMB1:
    r1 = this->read_u8();
    this->bus->write(r1, this->bus->read(r1) & ~0x02);
    break;

case RMB2:
    r1 = this->read_u8();
    this->bus->write(r1, this->bus->read(r1) & ~0x04);
    break;

case RMB3:
    r1 = this->read_u8();
    this->bus->write(r1, this->bus->read(r1) & ~0x08);
    break;

case RMB4:
    r1 = this->read_u8();
    this->bus->write(r1, this->bus->read(r1) & ~0x10);
    break;

case RMB5:
    r1 = this->read_u8();
    this->bus->write(r1, this->bus->read(r1) & ~0x20);
    break;

case RMB6:
    r1 = this->read_u8();
    this->bus->write(r1, this->bus->read(r1) & ~0x40);
    break;

case RMB7:
    r1 = this->read_u8();
    this->bus->write(r1, this->bus->read(r1) & ~0x80);
    break;

case SMB0:
    r1 = this->read_u8();
    this->bus->write(r1, this->bus->read(r1) | 0x01);
    break;

case SMB1:
    r1 = this->read_u8();
    this->bus->write(r1, this->bus->read(r1) | 0x02);
    break;

case SMB2:
    r1 = this->read_u8();
    this->bus->write(r1, this->bus->read(r1) | 0x04);
    break;

case SMB3:
    r1 = this->read_u8();
    this->bus->write(r1, this->bus->read(r1) | 0x08);
    break;

case SMB4:
    r1 = this->read_u8();
    this->bus->write(r1, this->bus->read(r1) | 0x10);
    break;

case SMB5:
    r1 = this->read_u8();
    this->bus->write(r1, this->bus->read(r1) | 0x20);
    break;

case SMB6:
    r1 = this->read_u8();
    this->bus->write(r1, this->bus->read(r1) | 0x40);
    break;

case SMB7:
    r1 = this->read_u8();
    this->bus->write(r1, this->bus->read(r1) | 0x80);
    break;

case TRB_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    r1 = mem_abs(arg1, arg2, 0);
    this->set_flag(FLAG_ZERO, this->bus->read(r1) & this->a);
    this->bus->write(r1, this->bus->read(r1) & ~this->a);
    break;

case TRB_ZP:
    r1 = this->read_u8();
    this->set_flag(FLAG_ZERO, this->bus->read(r1) & this->a);
    this->bus->write(r1, this->bus->read(r1) & ~this->a);
    break;

case TSB_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    r1 = mem_abs(arg1, arg2, 0);
    this->set_flag(FLAG_ZERO, this->bus->read(r1) & this->a);
    this->bus->write(r1, this->bus->read(r1) | a);
    break;

case TSB_ZP:
    r1 = this->read_u8();
    this->set_flag(FLAG_ZERO, this->bus->read(r1) & this->a);
    this->bus->write(r1, this->bus->read(r1) | a);
    break;
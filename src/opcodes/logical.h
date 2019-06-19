case AND_IMM:
    DEBUG_TRACE_IMM("and");
    this->a &= val;
    this->set_flags(this->a);
    break;

case AND_ZP:
    DEBUG_TRACE_ZP("and");
    this->a &= this->bus->read(addr);
    this->set_flags(this->a);
    break;

case AND_ZPX:
    DEBUG_TRACE_ZPX("and");
    this->a &= this->bus->read(addr);
    this->set_flags(this->a);
    break;

case AND_AB:
    DEBUG_TRACE_AB("and");
    this->a &= this->bus->read(addr);
    this->set_flags(this->a);
    break;

case AND_ABX:
    DEBUG_TRACE_ABX("and");
    this->a &= this->bus->read(addr);
    this->set_flags(this->a);
    break;

case AND_ABY:
    DEBUG_TRACE_ABY("and");
    this->a &= this->bus->read(addr);
    this->set_flags(this->a);
    break;

case AND_INX:
    DEBUG_TRACE_INX("inx");
    this->a &= this->bus->read(addr);
    this->set_flags(this->a);
    break;

case AND_INY:
    DEBUG_TRACE_INY("and");
    this->a &= this->bus->read(addr);
    this->set_flags(this->a);
    break;

case AND_INZP:
    DEBUG_TRACE_INZP("and");
    this->a &= this->bus->read(addr);
    this->set_flags(this->a);
    break;

case EOR_IMM:
    DEBUG_TRACE_IMM("eor");
    this->a ^= val;
    this->set_flags(this->a);
    break;

case EOR_ZP:
    DEBUG_TRACE_ZP("eor");
    this->a ^= this->bus->read(addr);
    this->set_flags(this->a);
    break;

case EOR_ZPX:
    DEBUG_TRACE_ZPX("eor");
    this->a ^= this->bus->read(addr);
    this->set_flags(this->a);
    break;

case EOR_AB:
    DEBUG_TRACE_AB("eor");
    this->a ^= this->bus->read(addr);
    this->set_flags(this->a);
    break;

case EOR_ABX:
    DEBUG_TRACE_ABX("eor");
    this->a ^= this->bus->read(addr);
    this->set_flags(this->a);
    break;

case EOR_ABY:
    DEBUG_TRACE_ABY("eor");
    this->a ^= this->bus->read(addr);
    this->set_flags(this->a);
    break;

case EOR_INX:
    DEBUG_TRACE_INX("eor");
    this->a ^= this->bus->read(addr);
    this->set_flags(this->a);
    break;

case EOR_INY:
    DEBUG_TRACE_INY("eor");
    this->a ^= this->bus->read(addr);
    this->set_flags(this->a);
    break;

case EOR_INZP:
    DEBUG_TRACE_INZP("eor");
    this->a ^= this->bus->read(addr);
    this->set_flags(this->a);
    break;

case ORA_IMM:
    DEBUG_TRACE_IMM("ora");
    this->a |= val;
    this->set_flags(this->a);
    break;

case ORA_ZP:
    DEBUG_TRACE_ZP("ora");
    this->a |= this->bus->read(addr);
    this->set_flags(this->a);
    break;

case ORA_ZPX:
    DEBUG_TRACE_ZPX("ora");
    this->a |= this->bus->read(addr);
    this->set_flags(this->a);
    break;

case ORA_AB:
    DEBUG_TRACE_AB("ora");
    this->a |= this->bus->read(addr);
    this->set_flags(this->a);
    break;

case ORA_ABX:
    DEBUG_TRACE_ABX("ora");
    this->a |= this->bus->read(addr);
    this->set_flags(this->a);
    break;

case ORA_ABY:
    DEBUG_TRACE_ABY("ora");
    this->a |= this->bus->read(addr);
    this->set_flags(this->a);
    break;

case ORA_INX:
    DEBUG_TRACE_INX("ora");
    this->a |= this->bus->read(addr);
    this->set_flags(this->a);
    break;

case ORA_INY:
    DEBUG_TRACE_INY("ora");
    this->a |= this->bus->read(addr);
    this->set_flags(this->a);
    break;

case ORA_INZP:
    DEBUG_TRACE_INZP("ora");
    this->a |= this->bus->read(addr);
    this->set_flags(this->a);
    break;

case BIT_AB:
    DEBUG_TRACE_AB("bit");
    t1 = this->bus->read(addr);
    this->set_flag(FLAG_ZERO, !(t1 & this->a));
    this->set_flag(FLAG_OVERFLOW, t1 & 0x40);
    this->set_flag(FLAG_NEGATIVE, t1 & 0x80);
    break;

case BIT_ABX:
    DEBUG_TRACE_ABX("bit");
    t1 = this->bus->read(addr);
    this->set_flag(FLAG_ZERO, !(t1 & this->a));
    this->set_flag(FLAG_OVERFLOW, t1 & 0x40);
    this->set_flag(FLAG_NEGATIVE, t1 & 0x80);
    break;

case BIT_IMM:
    DEBUG_TRACE_IMM("bit");
    this->set_flag(FLAG_ZERO, !(val & this->a));
    this->set_flag(FLAG_OVERFLOW, val & 0x40);
    this->set_flag(FLAG_NEGATIVE, val & 0x80);
    break;    

case BIT_ZP:
    DEBUG_TRACE_ZP("bit");
    t1 = this->bus->read(addr);
    this->set_flag(FLAG_ZERO, !(t1 & this->a));
    this->set_flag(FLAG_OVERFLOW, t1 & 0x40);
    this->set_flag(FLAG_NEGATIVE, t1 & 0x80);
    break;

case BIT_ZPX:
    DEBUG_TRACE_ZPX("bit");
    t1 = this->bus->read(addr);
    this->set_flag(FLAG_ZERO, !(t1 & this->a));
    this->set_flag(FLAG_OVERFLOW, t1 & 0x40);
    this->set_flag(FLAG_NEGATIVE, t1 & 0x80);
    break;

case RMB0:
    DEBUG_TRACE("rmb 0");
    this->bus->write(addr, this->bus->read(addr) & ~0x01);
    break;

case RMB1:
    DEBUG_TRACE("rmb 1");
    this->bus->write(addr, this->bus->read(addr) & ~0x02);
    break;

case RMB2:
    DEBUG_TRACE("rmb 2");
    this->bus->write(addr, this->bus->read(addr) & ~0x04);
    break;

case RMB3:
    DEBUG_TRACE("rmb 3");
    this->bus->write(addr, this->bus->read(addr) & ~0x08);
    break;

case RMB4:
    DEBUG_TRACE("rmb 4");
    this->bus->write(addr, this->bus->read(addr) & ~0x10);
    break;

case RMB5:
    DEBUG_TRACE("rmb 5");
    this->bus->write(addr, this->bus->read(addr) & ~0x20);
    break;

case RMB6:
    DEBUG_TRACE("rmb 6");
    this->bus->write(addr, this->bus->read(addr) & ~0x40);
    break;

case RMB7:
    DEBUG_TRACE("rmb 7");
    this->bus->write(addr, this->bus->read(addr) & ~0x80);
    break;

case SMB0:
    DEBUG_TRACE("smb 0");
    this->bus->write(addr, this->bus->read(addr) | 0x01);
    break;

case SMB1:
    DEBUG_TRACE("smb 1");
    this->bus->write(addr, this->bus->read(addr) | 0x02);
    break;

case SMB2:
    DEBUG_TRACE("smb 2");
    this->bus->write(addr, this->bus->read(addr) | 0x04);
    break;

case SMB3:
    DEBUG_TRACE("smb 3");
    this->bus->write(addr, this->bus->read(addr) | 0x08);
    break;

case SMB4:
    DEBUG_TRACE("smb 4");
    this->bus->write(addr, this->bus->read(addr) | 0x10);
    break;

case SMB5:
    DEBUG_TRACE("smb 5"); 
    this->bus->write(addr, this->bus->read(addr) | 0x20);
    break;

case SMB6:
    DEBUG_TRACE("smb 6");
    this->bus->write(addr, this->bus->read(addr) | 0x40);
    break;

case SMB7:
    DEBUG_TRACE("smb 7");
    this->bus->write(addr, this->bus->read(addr) | 0x80);
    break;

case TRB_AB:
    DEBUG_TRACE_AB("trb");
    this->set_flag(FLAG_ZERO, this->bus->read(addr) & this->a);
    this->bus->write(addr, this->bus->read(addr) & ~this->a);
    break;

case TRB_ZP:
    DEBUG_TRACE_ZP("trb");
    this->set_flag(FLAG_ZERO, this->bus->read(addr) & this->a);
    this->bus->write(addr, this->bus->read(addr) & ~this->a);
    break;

case TSB_AB:
    DEBUG_TRACE_AB("tsb");
    this->set_flag(FLAG_ZERO, this->bus->read(addr) & this->a);
    this->bus->write(addr, this->bus->read(addr) | a);
    break;

case TSB_ZP:
    DEBUG_TRACE_ZP("tsb");
    this->set_flag(FLAG_ZERO, this->bus->read(addr) & this->a);
    this->bus->write(addr, this->bus->read(addr) | a);
    break;
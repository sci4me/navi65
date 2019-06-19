case STA_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    r1 = mem_abs(arg1, arg2, 0);
    this->bus->write(r1, this->a);
    break;

case STA_ABX:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    r1 = mem_abs(arg1, arg2, this->x);
    this->bus->write(r1, this->a);
    break;

case STA_ABY:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    r1 = mem_abs(arg1, arg2, this->y);
    this->bus->write(r1, this->a);
    break;

case STA_INX:
    r1 = mem_indexed_indirect(this, this->read_u8(), this->x);
    this->bus->write(r1, this->a);
    break;

case STA_INY:
    r1 = mem_indirect_index(this, this->read_u8(), this->y);
    this->bus->write(r1, this->a);
    break;

case STA_ZP:
    r1 = ZP(this->read_u8());
    this->bus->write(r1, this->a);
    break;

case STA_ZPX:
    r1 = ZP(this->read_u8() + this->x);
    this->bus->write(r1, this->a);
    break;

case STA_INZP:
    r1 = mem_indirect_zp(this, this->read_u8());
    this->bus->write(r1, this->a);
    break;

case STX_ZP:
    r1 = ZP(this->read_u8());
    this->bus->write(r1, this->x);
    break;

case STX_ZPY:
    r1 = ZP(this->read_u8() + this->y);
    this->bus->write(r1, this->x);
    break;

case STX_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    r1 = mem_abs(arg1, arg2, 0);
    this->bus->write(r1, this->x);
    break;

case STY_ZP:
    r1 = ZP(this->read_u8());
    this->bus->write(r1, this->y);
    break;

case STY_ZPX:
    r1 = ZP(this->read_u8() + this->x);
    this->bus->write(r1, this->y);
    break;

case STY_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    r1 = mem_abs(arg1, arg2, 0);
    this->bus->write(r1, this->y);
    break;

case STZ_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    r1 = mem_abs(arg1, arg2, 0);
    this->bus->write(r1, 0);
    break;

case STZ_ABX:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    r1 = mem_abs(arg1, arg2, this->x);
    this->bus->write(r1, 0);
    break;

case STZ_ZP:
    r1 = ZP(this->read_u8());
    this->bus->write(r1, 0);
    break;

case STZ_ZPX:
    r1 = ZP(this->read_u8() + this->x);
    this->bus->write(r1, 0);
    break;

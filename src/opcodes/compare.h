case CMP_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    this->cmp(this->bus->read(mem_abs(arg1, arg2, 0)), this->a);
    break;

case CMP_ABX:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    this->cmp(this->bus->read(mem_abs(arg1, arg2, this->x)), this->a);
    break;

case CMP_ABY:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    this->cmp(this->bus->read(mem_abs(arg1, arg2, this->y)), this->a);
    break;

case CMP_IMM:
    this->cmp(this->read_u8(), this->a);
    break;

case CMP_INX:
    this->cmp(this->bus->read(mem_indexed_indirect(this, this->read_u8(), this->x)), this->a);
    break;

case CMP_INY:
    this->cmp(this->bus->read(mem_indirect_index(this, this->read_u8(), this->y)), this->a);
    break;

case CMP_ZP:
    this->cmp(this->bus->read(this->read_u8()), this->a);
    break;

case CMP_ZPX:
    this->cmp(this->bus->read(ZP(this->read_u8() + this->x)), this->a);
    break;

case CMP_INZP:
    this->cmp(this->bus->read(mem_indirect_zp(this, this->read_u8())), this->a);
    break;

case CPX_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    this->cmp(this->bus->read(mem_abs(arg1, arg2, 0)), this->x);
    break;

case CPX_IMM:
    this->cmp(this->read_u8(), this->x);
    break;

case CPX_ZP:
    this->cmp(this->bus->read(this->read_u8()), this->x);
    break;

case CPY_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    this->cmp(this->bus->read(mem_abs(arg1, arg2, 0)), this->y);
    break;

case CPY_IMM:
    this->cmp(this->read_u8(), this->y);
    break;

case CPY_ZP:
    this->cmp(this->bus->read(this->read_u8()), this->y);
    break;

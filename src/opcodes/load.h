case LDA_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    this->a = this->bus->read(mem_abs(arg1, arg2, 0));
    this->set_flags(this->a);
    break;

case LDA_ABX:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    this->a = this->bus->read(mem_abs(arg1, arg2, this->x));
    this->set_flags(this->a);
    break;

case LDA_ABY:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    this->a = this->bus->read(mem_abs(arg1, arg2, this->y));
    this->set_flags(this->a);
    break;

case LDA_IMM:
    this->a = this->read_u8();
    this->set_flags(this->a);
    break;

case LDA_INX:
    this->a = this->bus->read(mem_indexed_indirect(this, this->read_u8(), this->x));
    this->set_flags(this->a);
    break;

case LDA_INY:
    this->a = this->bus->read(mem_indirect_index(this, this->read_u8(), this->y));
    this->set_flags(this->a);
    break;

case LDA_ZP:
    this->a = this->bus->read(this->read_u8());
    this->set_flags(this->a);
    break;

case LDA_ZPX:
    this->a = this->bus->read(this->read_u8() + this->x);
    this->set_flags(this->a);
    break;

case LDA_INZP:
    this->a = this->bus->read(mem_indirect_zp(this, this->read_u8()));
    break;

case LDX_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    this->x = this->bus->read(mem_abs(arg1, arg2, 0));
    this->set_flags(this->x);
    break;

case LDX_ABY:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    this->x = this->bus->read(mem_abs(arg1, arg2, this->y));
    this->set_flags(this->x);
    break;

case LDX_IMM:
    this->x = this->read_u8();
    this->set_flags(this->x);
    break;

case LDX_ZP:
    this->x = this->bus->read(this->read_u8());
    this->set_flags(this->x);
    break;

case LDX_ZPY:
    this->x = this->bus->read(this->read_u8() + this->y);
    this->set_flags(this->x);
    break;

case LDY_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    this->y = this->bus->read(mem_abs(arg1, arg2, 0));
    this->set_flags(this->y);
    break;

case LDY_ABX:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    this->y = this->bus->read(mem_abs(arg1, arg2, this->x));
    this->set_flags(this->y);
    break;

case LDY_IMM:
    this->y = this->read_u8();
    this->set_flags(this->y);
    break;

case LDY_ZP:
    this->y = this->bus->read(this->read_u8());
    this->set_flags(this->y);
    break;

case LDY_ZPX:
    this->y = this->bus->read(this->read_u8() + this->x);
    this->set_flags(this->y);
    break;

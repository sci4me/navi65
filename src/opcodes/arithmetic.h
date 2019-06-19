case ADC_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    this->add(this->bus->read(mem_abs(arg1, arg2, 0)));
    break;

case ADC_ABX:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    this->add(this->bus->read(mem_abs(arg1, arg2, this->x)));
    break;

case ADC_ABY:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    this->add(this->bus->read(mem_abs(arg1, arg2, this->y)));
    break;

case ADC_IMM:
    this->add(this->read_u8());
    break;

case ADC_INX:
    this->add(this->bus->read(mem_indexed_indirect(this, this->read_u8(), this->x)));
    break;

case ADC_INY:
    this->add(this->bus->read(mem_indirect_index(this, this->read_u8(), this->y)));
    break;

case ADC_ZP:
    this->add(this->bus->read(this->read_u8()));
    break;

case ADC_ZPX:
    this->add(this->bus->read(ZP(this->read_u8() + this->x)));
    break;

case ADC_INZP:
    this->add(this->bus->read(mem_indirect_zp(this, this->read_u8())));
    break;

case SBC_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    this->sub(this->bus->read(mem_abs(arg1, arg2, 0)));
    break;

case SBC_ABX:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    this->sub(this->bus->read(mem_abs(arg1, arg2, this->x)));
    break;

case SBC_ABY:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    this->sub(this->bus->read(mem_abs(arg1, arg2, this->y)));
    break;

case SBC_IMM:
    this->sub(this->read_u8());
    break;

case SBC_INX:
    this->sub(this->bus->read(mem_indexed_indirect(this, this->read_u8(), this->x)));
    break;

case SBC_INY:
    this->sub(this->bus->read(mem_indirect_index(this, this->read_u8(), this->y)));
    break;

case SBC_ZP:
    this->sub(this->bus->read(this->read_u8()));
    break;

case SBC_ZPX:
    this->sub(this->bus->read(ZP(this->read_u8() + this->x)));
    break;

case SBC_INZP:
    this->sub(this->bus->read(mem_indirect_zp(this, this->read_u8())));
    break;

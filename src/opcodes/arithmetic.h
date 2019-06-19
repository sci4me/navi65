case ADC_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    addr = mem_abs(arg1, arg2, 0);
    DEBUG_TRACE_AB("adc");
    this->add(this->bus->read(addr));
    break;

case ADC_ABX:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    addr = mem_abs(arg1, arg2, this->x);
    DEBUG_TRACE_ABX("adc");
    this->add(this->bus->read(addr));
    break;

case ADC_ABY:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    addr = mem_abs(arg1, arg2, this->y);
    DEBUG_TRACE_ABY("adc");
    this->add(this->bus->read(addr));
    break;

case ADC_IMM:
    val = this->read_u8();
    DEBUG_TRACE_IMM("adc");
    this->add(val);
    break;

case ADC_INX:
    addr = this->read_u8();
    DEBUG_TRACE_INX("adc");
    this->add(this->bus->read(mem_indexed_indirect(this, addr, this->x)));
    break;

case ADC_INY:
    addr = this->read_u8();
    DEBUG_TRACE_INY("adc");
    this->add(this->bus->read(mem_indirect_index(this, addr, this->y)));
    break;

case ADC_ZP:
    addr = this->read_u8();
    DEBUG_TRACE_ZP("adc");
    this->add(this->bus->read(addr));
    break;

case ADC_ZPX:
    addr = this->read_u8();
    DEBUG_TRACE_ZPX("adc");
    this->add(this->bus->read(ZP(addr + this->x)));
    break;

case ADC_INZP:
    addr = this->read_u8();
    DEBUG_TRACE_INZP("adc");
    this->add(this->bus->read(mem_indirect_zp(this, addr)));
    break;

case SBC_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    addr = mem_abs(arg1, arg2, 0);
    DEBUG_TRACE_AB("sbc");
    this->sub(this->bus->read(addr));
    break;

case SBC_ABX:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    addr = mem_abs(arg1, arg2, this->x);
    DEBUG_TRACE_ABX("sbc");
    this->sub(this->bus->read(addr));
    break;

case SBC_ABY:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    addr = mem_abs(arg1, arg2, this->y);
    DEBUG_TRACE_ABY("sbc");
    this->sub(this->bus->read(addr));
    break;

case SBC_IMM:
    val = this->read_u8();
    DEBUG_TRACE_IMM("sbc");
    this->sub(val);
    break;

case SBC_INX:
    addr = this->read_u8();
    DEBUG_TRACE_INX("sbc");
    this->sub(this->bus->read(mem_indexed_indirect(this, addr, this->x)));
    break;

case SBC_INY:
    addr = this->read_u8();
    DEBUG_TRACE_INY("sbc");
    this->sub(this->bus->read(mem_indirect_index(this, addr, this->y)));
    break;

case SBC_ZP:
    addr = this->read_u8();
    DEBUG_TRACE_ZP("sbc");
    this->sub(this->bus->read(addr));
    break;

case SBC_ZPX:
    addr = this->read_u8();
    DEBUG_TRACE_ZPX("sbc");
    this->sub(this->bus->read(ZP(addr + this->x)));
    break;

case SBC_INZP:
    addr = this->read_u8();
    DEBUG_TRACE_INZP("sbc");
    this->sub(this->bus->read(mem_indirect_zp(this, addr)));
    break;

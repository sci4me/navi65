case ADC_AB:
    DEBUG_TRACE_AB("adc");
    this->add(this->bus->read(addr));
    break;

case ADC_ABX:
    DEBUG_TRACE_ABX("adc");
    this->add(this->bus->read(addr));
    break;

case ADC_ABY:
    DEBUG_TRACE_ABY("adc");
    this->add(this->bus->read(addr));
    break;

case ADC_IMM:
    DEBUG_TRACE_IMM("adc");
    this->add(val);
    break;

case ADC_INX:
    DEBUG_TRACE_INX("adc");
    this->add(this->bus->read(addr));
    break;

case ADC_INY:
    DEBUG_TRACE_INY("adc");
    this->add(this->bus->read(addr));
    break;

case ADC_ZP:
    DEBUG_TRACE_ZP("adc");
    this->add(this->bus->read(addr));
    break;

case ADC_ZPX:
    DEBUG_TRACE_ZPX("adc");
    this->add(this->bus->read(addr));
    break;

case ADC_INZP:
    DEBUG_TRACE_INZP("adc");
    this->add(this->bus->read(addr));
    break;

case SBC_AB:
    DEBUG_TRACE_AB("sbc");
    this->sub(this->bus->read(addr));
    break;

case SBC_ABX:
    DEBUG_TRACE_ABX("sbc");
    this->sub(this->bus->read(addr));
    break;

case SBC_ABY:
    DEBUG_TRACE_ABY("sbc");
    this->sub(this->bus->read(addr));
    break;

case SBC_IMM:
    DEBUG_TRACE_IMM("sbc");
    this->sub(val);
    break;

case SBC_INX:
    DEBUG_TRACE_INX("sbc");
    this->sub(this->bus->read(mem_indexed_indirect(this, addr, this->x)));
    break;

case SBC_INY:
    DEBUG_TRACE_INY("sbc");
    this->sub(this->bus->read(mem_indirect_index(this, addr, this->y)));
    break;

case SBC_ZP:
    DEBUG_TRACE_ZP("sbc");
    this->sub(this->bus->read(addr));
    break;

case SBC_ZPX:
    DEBUG_TRACE_ZPX("sbc");
    this->sub(this->bus->read(addr));
    break;

case SBC_INZP:
    DEBUG_TRACE_INZP("sbc");
    this->sub(this->bus->read(addr));
    break;
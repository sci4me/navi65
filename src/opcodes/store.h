case STA_AB:
    DEBUG_TRACE_AB("sta");
    this->bus->write(addr, this->a);
    break;

case STA_ABX:
    DEBUG_TRACE_ABX("sta");
    this->bus->write(addr, this->a);
    break;

case STA_ABY:
    DEBUG_TRACE_ABY("sta");
    this->bus->write(addr, this->a);
    break;

case STA_INX:
    DEBUG_TRACE_INX("sta");
    this->bus->write(addr, this->a);
    break;

case STA_INY:
    DEBUG_TRACE_INY("sta");
    this->bus->write(addr, this->a);
    break;

case STA_ZP:
    DEBUG_TRACE_ZP("sta");
    this->bus->write(addr, this->a);
    break;

case STA_ZPX:
    DEBUG_TRACE_ZPX("sta");
    this->bus->write(addr, this->a);
    break;

case STA_INZP:
    DEBUG_TRACE_INZP("sta");
    this->bus->write(addr, this->a);
    break;

case STX_ZP:
    DEBUG_TRACE_ZP("stx");
    this->bus->write(addr, this->x);
    break;

case STX_ZPY:
    DEBUG_TRACE_ZPX("stx");
    this->bus->write(addr, this->x);
    break;

case STX_AB:
    DEBUG_TRACE_AB("stx");
    this->bus->write(addr, this->x);
    break;

case STY_ZP:
    DEBUG_TRACE_ZP("sty");
    this->bus->write(addr, this->y);
    break;

case STY_ZPX:
    DEBUG_TRACE_ZPX("sty");
    this->bus->write(addr, this->y);
    break;

case STY_AB:
    DEBUG_TRACE_AB("sty");
    this->bus->write(addr, this->y);
    break;

case STZ_AB:
    DEBUG_TRACE_AB("stz");
    this->bus->write(addr, 0);
    break;

case STZ_ABX:
    DEBUG_TRACE_ABX("stz");
    this->bus->write(addr, 0);
    break;

case STZ_ZP:
    DEBUG_TRACE_ZP("stz");
    this->bus->write(addr, 0);
    break;

case STZ_ZPX:
    DEBUG_TRACE_ZPX("stz");
    this->bus->write(addr, 0);
    break;

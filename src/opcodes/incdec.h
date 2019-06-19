case INC_ACC:
    DEBUG_TRACE_ACC("inc");
    this->set_flags(++this->a);
    break;

case INC_AB: {
    DEBUG_TRACE_AB("inc");
    auto value = this->bus->read(addr) + 1;
    this->bus->write(addr, value);
    this->set_flags(value);
    break;
}

case INC_ABX: {
    DEBUG_TRACE_ABX("inc");
    auto value = this->bus->read(addr) + 1;
    this->bus->write(addr, value);
    this->set_flags(value);
    break;
}

case INC_ZP: {
    DEBUG_TRACE_ZP("inc");
    auto value = this->bus->read(addr) + 1;
    this->bus->write(addr, value);
    this->set_flags(value);
    break;
}

case INC_ZPX: {
    DEBUG_TRACE_ZPX("inc");
    auto value = this->bus->read(addr) + 1;
    this->bus->write(addr, value);
    this->set_flags(value);
    break;
}

case INX:
    DEBUG_TRACE("inx");
    this->set_flags(++this->x);
    break;

case INY:
    DEBUG_TRACE("iny");
    this->set_flags(++this->y);
    break;

case DEC_ACC:
    DEBUG_TRACE_ACC("dec");
    this->set_flags(--this->a);
    break;

case DEC_AB: {
    DEBUG_TRACE_AB("dec");
    auto value = this->bus->read(addr) - 1;
    this->bus->write(addr, value);
    this->set_flags(value);
    break;
}

case DEC_ABX: {
    DEBUG_TRACE_ABX("dec");
    auto value = this->bus->read(addr) - 1;
    this->bus->write(addr, value);
    this->set_flags(value);
    break;
}

case DEC_ZP: {
    DEBUG_TRACE_ZP("dec");
    auto value = this->bus->read(addr) - 1;
    this->bus->write(addr, value);
    this->set_flags(value);
    break;
}

case DEC_ZPX: {
    DEBUG_TRACE_ZPX("dec");
    auto value = this->bus->read(addr) - 1;
    this->bus->write(addr, value);
    this->set_flags(value);
    break;
}

case DEX:
    DEBUG_TRACE("dex");
    this->set_flags(--this->x);
    break;

case DEY:
    DEBUG_TRACE("dex");
    this->set_flags(--this->y);
    break;

case CMP_AB:
    DEBUG_TRACE_AB("cmp");
    this->cmp(this->bus->read(addr), this->a);
    break;

case CMP_ABX:
    DEBUG_TRACE_ABX("cmp");
    this->cmp(this->bus->read(addr), this->a);
    break;

case CMP_ABY:
    DEBUG_TRACE_ABY("cmp");
    this->cmp(this->bus->read(addr), this->a);
    break;

case CMP_IMM:
    DEBUG_TRACE_IMM("cmp");
    this->cmp(val, this->a);
    break;

case CMP_INX:
    DEBUG_TRACE_INX("cmp");
    this->cmp(this->bus->read(addr), this->a);
    break;

case CMP_INY:
    DEBUG_TRACE_INY("cmp");
    this->cmp(this->bus->read(addr), this->a);
    break;

case CMP_ZP:
    DEBUG_TRACE_ZP("cmp");
    this->cmp(this->bus->read(addr), this->a);
    break;

case CMP_ZPX:
    DEBUG_TRACE_ZPX("cmp");
    this->cmp(this->bus->read(addr), this->a);
    break;

case CMP_INZP:
    DEBUG_TRACE_INZP("cmp");
    this->cmp(this->bus->read(addr), this->a);
    break;

case CPX_AB:
    DEBUG_TRACE_AB("cpx");
    this->cmp(this->bus->read(addr), this->x);
    break;

case CPX_IMM:
    DEBUG_TRACE_IMM("cpx");
    this->cmp(val, this->x);
    break;

case CPX_ZP:
    DEBUG_TRACE_ZP("cpx");
    this->cmp(this->bus->read(t2), this->x);
    break;

case CPY_AB:
    DEBUG_TRACE_AB("cpy");
    this->cmp(this->bus->read(addr), this->y);
    break;

case CPY_IMM:
    DEBUG_TRACE_IMM("cpy");
    this->cmp(val, this->y);
    break;

case CPY_ZP:
    DEBUG_TRACE_ZP("cpy");
    this->cmp(this->bus->read(addr), this->y);
    break;

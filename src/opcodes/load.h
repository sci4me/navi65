case LDA_AB:
    DEBUG_TRACE_AB("lda");
    this->a = this->bus->read(addr);
    this->set_flags(this->a);
    break;

case LDA_ABX:
    DEBUG_TRACE_ABX("lda");
    this->a = this->bus->read(addr);
    this->set_flags(this->a);
    break;

case LDA_ABY:
    DEBUG_TRACE_ABY("lda");
    this->a = this->bus->read(addr);
    this->set_flags(this->a);
    break;

case LDA_IMM:
    DEBUG_TRACE_IMM("lda");
    this->a = val;
    this->set_flags(this->a);
    break;

case LDA_INX:
    DEBUG_TRACE_INX("lda");
    this->a = this->bus->read(addr);
    this->set_flags(this->a);
    break;

case LDA_INY:
    DEBUG_TRACE_INY("lda");
    this->a = this->bus->read(addr);
    this->set_flags(this->a);
    break;

case LDA_ZP:
    DEBUG_TRACE_ZP("lda");
    this->a = this->bus->read(addr);
    this->set_flags(this->a);
    break;

case LDA_ZPX:
    DEBUG_TRACE_ZPX("lda");
    this->a = this->bus->read(addr);
    this->set_flags(this->a);
    break;

case LDA_INZP:
    DEBUG_TRACE_INZP("lda");
    this->a = this->bus->read(addr);
    break;

case LDX_AB:
    DEBUG_TRACE_AB("ldx");
    this->x = this->bus->read(addr);
    this->set_flags(this->x);
    break;

case LDX_ABY:
    DEBUG_TRACE_ABY("ldx");
    this->x = this->bus->read(addr);
    this->set_flags(this->x);
    break;

case LDX_IMM:
    DEBUG_TRACE_IMM("ldx");
    this->x = val;
    this->set_flags(this->x);
    break;

case LDX_ZP:
    DEBUG_TRACE_ZP("ldx");
    this->x = this->bus->read(addr);
    this->set_flags(this->x);
    break;

case LDX_ZPY:
    DEBUG_TRACE_ZPY("ldx");
    this->x = this->bus->read(addr);
    this->set_flags(this->x);
    break;

case LDY_AB:
    DEBUG_TRACE_AB("ldy");
    this->y = this->bus->read(addr);
    this->set_flags(this->y);
    break;

case LDY_ABX:
    DEBUG_TRACE_ABX("ldy");
    this->y = this->bus->read(addr);
    this->set_flags(this->y);
    break;

case LDY_IMM:
    DEBUG_TRACE_IMM("ldy");
    this->y = val;
    this->set_flags(this->y);
    break;

case LDY_ZP:
    DEBUG_TRACE_ZP("ldy");
    this->y = this->bus->read(addr);
    this->set_flags(this->y);
    break;

case LDY_ZPX:
    DEBUG_TRACE_ZPX("ldy");
    this->y = this->bus->read(addr);
    this->set_flags(this->y);
    break;
case CLC:
    DEBUG_TRACE("clc");
    this->set_flag(FLAG_CARRY, false);
    break;

case CLD:
    DEBUG_TRACE("cld");
    this->set_flag(FLAG_DECIMAL, false);
    break;

case CLI:
    DEBUG_TRACE("cli");
    this->set_flag(FLAG_INTERRUPT, false);
    break;

case CLV:
    DEBUG_TRACE("clv");
    this->set_flag(FLAG_OVERFLOW, false);
    break;

case SEC:
    DEBUG_TRACE("sec");
    this->set_flag(FLAG_CARRY, true);
    break;

case SED:
    DEBUG_TRACE("sed");
    this->set_flag(FLAG_DECIMAL, true);
    break;

case SEI:
    DEBUG_TRACE("sei");
    this->set_flag(FLAG_INTERRUPT, true);
    break;

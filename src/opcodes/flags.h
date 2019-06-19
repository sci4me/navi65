case CLC:
    this->set_flag(FLAG_CARRY, false);
    break;

case CLD:
    this->set_flag(FLAG_DECIMAL, false);
    break;

case CLI:
    this->set_flag(FLAG_INTERRUPT, false);
    break;

case CLV:
    this->set_flag(FLAG_OVERFLOW, false);
    break;

case SEC:
    this->set_flag(FLAG_CARRY, true);
    break;

case SED:
    this->set_flag(FLAG_DECIMAL, true);
    break;

case SEI:
    this->set_flag(FLAG_INTERRUPT, true);
    break;

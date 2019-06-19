case TAX:
    DEBUG_TRACE("tax");
    this->x = this->a;
    this->set_flags(this->x);
    break;

case TAY:
    DEBUG_TRACE("tay");
    this->y = this->a;
    this->set_flags(this->y);
    break;

case TSX:
    DEBUG_TRACE("TSX");
    this->x = this->sp;
    this->set_flags(this->x);
    break;

case TXA:
    DEBUG_TRACE("txa");
    this->a = this->x;
    this->set_flags(this->a);
    break;

case TXS:
    DEBUG_TRACE("txs");
    this->sp = this->x;
    break;

case TYA:
    DEBUG_TRACE("tya");
    this->a = this->y;
    this->set_flags(this->a);
    break;

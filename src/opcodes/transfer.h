case TAX:
    this->x = this->a;
    this->set_flags(this->x);
    break;

case TAY:
    this->y = this->a;
    this->set_flags(this->y);
    break;

case TSX:
    this->x = this->sp;
    this->set_flags(this->x);
    break;

case TXA:
    this->a = this->x;
    this->set_flags(this->a);
    break;

case TXS:
    this->sp = this->x;
    break;

case TYA:
    this->a = this->y;
    this->set_flags(this->a);
    break;

case TAX:
    m->x = m->ac;
    this->set_flags(m->x);
    break;

case TAY:
    m->y = m->ac;
    this->set_flags(m->y);
    break;

case TSX:
    m->x = m->sp;
    this->set_flags(m->x);
    break;

case TXA:
    m->ac = m->x;
    this->set_flags(m->ac);
    break;

case TXS:
    m->sp = m->x;
    break;

case TYA:
    m->ac = m->y;
    this->set_flags(m->ac);
    break;

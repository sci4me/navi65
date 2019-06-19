case PHA:
    DEBUG_TRACE("pha");
    this->push(this->a);
    break;

case PHP:
    DEBUG_TRACE("php");
    this->push(this->flags);
    break;

case PLA:
    DEBUG_TRACE("PLA");
    this->a = this->pop();
    break;

case PLP:
    DEBUG_TRACE("plp");
    this->flags = this->pop();
    break;

case PHX:
    DEBUG_TRACE("phx");
	this->push(this->x);
    break;

case PHY:
    DEBUG_TRACE("phy");
	this->push(this->y);
    break;

case PLX:
    DEBUG_TRACE("PLX");
	this->x = this->pop();
    break;

case PLY:
    DEBUG_TRACE("ply");
	this->y = this->pop();
    break;

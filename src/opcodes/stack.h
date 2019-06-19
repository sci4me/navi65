case PHA:
    this->push(this->a);
    break;

case PHP:
    this->push(this->flags);
    break;

case PLA:
    this->a = this->pop();
    break;

case PLP:
    this->flags = this->pop();
    break;

case PHX:
	this->push(this->x);
    break;

case PHY:
	this->push(this->y);
    break;

case PLX:
	this->x = this->pop();
    break;

case PLY:
	this->y = this->pop();
    break;

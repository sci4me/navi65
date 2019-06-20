case BRK:
    DEBUG_TRACE("brk");
    this->set_flag(FLAG_BREAK, true);
    this->break_waiting = true;
    break;

case RTI:
    DEBUG_TRACE("rti");
    this->flags = this->pop();
    this->pc = this->pop_u16();
    break;

case WAI:
    DEBUG_TRACE("wai");
	this->interrupt_waiting = true;
    break;
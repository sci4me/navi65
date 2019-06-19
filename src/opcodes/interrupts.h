case BRK:
    DEBUG_TRACE("brk");
    this->set_flag(FLAG_BREAK, true);
    this->break_waiting = true;
    break;

case RTI:
    DEBUG_TRACE("rti");
    this->flags = this->pop();
    arg1 = this->pop();
    this->pc = mem_abs(arg1, this->pop(), 0);
    break;

case WAI:
    DEBUG_TRACE("wai");
	this->interrupt_waiting = true;
    break;
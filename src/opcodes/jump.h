case JMP_AB:
    DEBUG_TRACE_AB("jmp");
    this->pc = addr;
    break;

case JMP_ABX:
    DEBUG_TRACE_ABX("jmp");
    this->pc = addr;
    break;

case JMP_IN:
    DEBUG_TRACE_IN("jmp");
    this->pc = addr;
    break;

case JSR_AB:
    DEBUG_TRACE_AB("jsr");
    // we push the address of the byte immediately before where we want to
    // return to because reasons:
    r2 = this->pc + pc_offset - 1;
    this->push((r2 & 0xFF00) >> 8);
    this->push(r2 & 0xFF);
    this->pc = addr;
    break;

case RTS:
    DEBUG_TRACE("rts");
    arg1 = this->pop();
    this->pc = mem_abs(arg1, this->pop(), 0) + 1;
    break;

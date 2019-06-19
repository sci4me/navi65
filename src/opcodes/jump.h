case JMP_AB:
    arg1 = this->read_u8();
    this->pc = mem_abs(arg1, this->read_u8(), 0);
    break;

case JMP_ABX:
    arg1 = this->read_u8();
    this->pc = mem_abs(arg1, this->read_u8(), this->x);
    break;

case JMP_IN:
    arg1 = this->read_u8();
    r1 = mem_abs(arg1, this->read_u8(), 0);
    this->pc = mem_abs(this->bus->read(r1), this->bus->read(r1+1), 0);
    break;

case JSR_AB:
    arg1 = this->read_u8();
    r1 = mem_abs(arg1, this->read_u8(), 0);
    // we push the address of the byte immediately before where we want to
    // return to because reasons:
    r2 = this->pc + pc_offset - 1;
    this->push((r2 & 0xFF00) >> 8);
    this->push(r2 & 0xFF);
    this->pc = r1;
    break;

case RTS:
    arg1 = this->pop();
    this->pc = mem_abs(arg1, this->pop(), 0) + 1;
    break;

case INC_ACC:
    this->set_flags(++this->a);
    break;

case INC_AB: {
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    r1 = mem_abs(arg1, arg2, 0);
    auto value = this->bus->read(r1) + 1;
    this->bus->write(r1, value);
    this->set_flags(value);
    break;
}

case INC_ABX: {
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    r1 = mem_abs(arg1, arg2, this->x);
    auto value = this->bus->read(r1) + 1;
    this->bus->write(r1, value);
    this->set_flags(value);
    break;
}

case INC_ZP: {
    r1 = this->read_u8();
    auto value = this->bus->read(r1) + 1;
    this->bus->write(r1, value);
    this->set_flags(value);
    break;
}

case INC_ZPX: {
    r1 = ZP(this->read_u8() + this->x);
    auto value = this->bus->read(r1) + 1;
    this->bus->write(r1, value);
    this->set_flags(value);
    break;
}

case INX:
    this->set_flags(++this->x);
    break;

case INY:
    this->set_flags(++this->y);
    break;

case DEC_ACC:
    this->set_flags(--this->a);
    break;

case DEC_AB: {
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    r1 = mem_abs(arg1, arg2, 0);
    auto value = this->bus->read(r1) - 1;
    this->bus->write(r1, value);
    this->set_flags(value);
    break;
}

case DEC_ABX: {
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    r1 = mem_abs(arg1, arg2, this->x);

    auto value = this->bus->read(r1) - 1;
    this->bus->write(r1, value);
    this->set_flags(value);
    break;
}

case DEC_ZP: {
    r1 = this->read_u8();
    auto value = this->bus->read(r1) - 1;
    this->bus->write(r1, value);
    this->set_flags(value);
    break;
}

case DEC_ZPX: {
    r1 = ZP(this->read_u8() + this->x);
    auto value = this->bus->read(r1) - 1;
    this->bus->write(r1, value);
    this->set_flags(value);
    break;
}

case DEX:
    this->set_flags(--this->x);
    break;

case DEY:
    this->set_flags(--this->y);
    break;

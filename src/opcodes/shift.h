case ASL_AB:
    arg1 = this->read_u8();
    r1 = mem_abs(arg1, this->read_u8(), 0);
    this->set_flag(FLAG_CARRY, this->bus->read(r1) & 0x80);
    this->bus->write(r1, (this->bus->read(r1) << 1) & 0xFE);
    this->set_flags(this->bus->read(r1));
    break;

case ASL_ABX:
    arg1 = this->read_u8();
    r1 = mem_abs(arg1, this->read_u8(), this->x);
    this->set_flag(FLAG_CARRY, this->bus->read(r1) & 0x80);
    this->bus->write(r1, (this->bus->read(r1) << 1) & 0xFE);
    this->set_flags(this->bus->read(r1));
    break;

case ASL_ACC:
    this->set_flag(FLAG_CARRY, this->a & 0x80);
    this->a = (this->a << 1) & 0xFE;
    this->set_flags(this->a);
    break;

case ASL_ZP:
    arg1 = this->read_u8();
    this->set_flag(FLAG_CARRY, this->bus->read(arg1) & 0x80);
    this->bus->write(arg1, (this->bus->read(arg1) << 1) & 0xFE);
    this->set_flags(this->bus->read(arg1));
    break;

case ASL_ZPX:
    arg1 = ZP(this->read_u8() + this->x);
    this->set_flag(FLAG_CARRY, this->bus->read(arg1) & 0x80);
    this->bus->write(arg1, (this->bus->read(arg1) << 1) & 0xFE);
    this->set_flags(this->bus->read(arg1));
    break;

case LSR_AB:
    arg1 = this->read_u8();
    r1 = mem_abs(arg1, this->read_u8(), 0);
    this->set_flag(FLAG_CARRY, this->bus->read(r1) & 0x01);
    this->bus->write(r1, (this->bus->read(r1) >> 1) & 0x7F);
    this->set_flags(this->bus->read(r1));
    break;

case LSR_ABX:
    arg1 = this->read_u8();
    r1 = mem_abs(arg1, this->read_u8(), this->x);
    this->set_flag(FLAG_CARRY, this->bus->read(r1) & 0x01);
    this->bus->write(r1, (this->bus->read(r1) >> 1) & 0x7F);
    this->set_flags(this->bus->read(r1));
    break;

case LSR_ACC:
    this->set_flag(FLAG_CARRY, this->a & 0x01);
    this->a = (this->a >> 1) & 0x7F;
    this->set_flags(this->a);
    break;

case LSR_ZP:
    arg1 = this->read_u8();
    this->set_flag(FLAG_CARRY, this->bus->read(arg1) & 0x01);
    this->bus->write(arg1, (this->bus->read(arg1) >> 1) & 0x7F);
    this->set_flags(this->bus->read(arg1));
    break;

case LSR_ZPX:
    arg1 = ZP(this->read_u8() + this->x);
    this->set_flag(FLAG_CARRY, this->bus->read(arg1) & 0x01);
    this->bus->write(arg1, (this->bus->read(arg1) >> 1) & 0x7F);
    this->set_flags(this->bus->read(arg1));
    break;

case ROL_AB:
    arg1 = this->read_u8();
    r1 = mem_abs(arg1, this->read_u8(), 0);
    t1 = this->bus->read(r1) & 0x80;
    this->bus->write(r1, ((this->bus->read(r1) << 1) & 0xFE) | this->get_flag(FLAG_CARRY));
    this->set_flag(FLAG_CARRY, t1);
    this->set_flags(this->bus->read(r1));
    break;

case ROL_ABX:
    arg1 = this->read_u8();
    r1 = mem_abs(arg1, this->read_u8(), this->x);
    t1 = this->bus->read(r1) & 0x80;
    this->bus->write(r1, ((this->bus->read(r1) << 1) & 0xFE) | this->get_flag(FLAG_CARRY));
    this->set_flag(FLAG_CARRY, t1);
    this->set_flags(this->bus->read(r1));
    break;

case ROL_ACC:
    t1 = this->a & 0x80;
    this->a = ((this->a << 1) & 0xFE) | this->get_flag(FLAG_CARRY);
    this->set_flag(FLAG_CARRY, t1);
    this->set_flags(this->a);
    break;

case ROL_ZP:
    arg1 = this->read_u8();
    t1 = this->bus->read(arg1) & 0x80;
    this->bus->write(arg1, ((this->bus->read(arg1) << 1) & 0xFE) | this->get_flag(FLAG_CARRY));
    this->set_flag(FLAG_CARRY, t1);
    this->set_flags(this->bus->read(arg1));
    break;

case ROL_ZPX:
    arg1 = ZP(this->read_u8() + this->x);
    t1 = this->bus->read(arg1) & 0x80;
    this->bus->write(arg1, ((this->bus->read(arg1) << 1) & 0xFE) | this->get_flag(FLAG_CARRY));
    this->set_flag(FLAG_CARRY, t1);
    this->set_flags(this->bus->read(arg1));
    break;

case ROR_AB:
    arg1 = this->read_u8();
    r1 = mem_abs(arg1, this->read_u8(), 0);
    t1 = this->bus->read(arg1) & 0x01;
    this->bus->write(r1, ((this->bus->read(r1) >> 1) & 0x7F) | (this->get_flag(FLAG_CARRY) << 7));
    this->set_flag(FLAG_CARRY, t1);
    this->set_flags(this->bus->read(r1));
    break;

case ROR_ABX:
    arg1 = this->read_u8();
    r1 = mem_abs(arg1, this->read_u8(), this->x);
    t1 = this->bus->read(arg1) & 0x01;
    this->bus->write(r1, ((this->bus->read(r1) >> 1) & 0x7F) | (this->get_flag(FLAG_CARRY) << 7));
    this->set_flag(FLAG_CARRY, t1);
    this->set_flags(this->bus->read(r1));
    break;

case ROR_ACC:
    t1 = this->a & 0x01;
    this->a = ((this->a >> 1) & 0x7F) | (this->get_flag(FLAG_CARRY) << 7);
    this->set_flag(FLAG_CARRY, t1);
    this->set_flags(this->a);
    break;

case ROR_ZP:
    arg1 = this->read_u8();
    t1 = this->bus->read(arg1) & 0x01;
    this->bus->write(arg1, ((this->bus->read(arg1) >> 1) & 0x7F) | (this->get_flag(FLAG_CARRY) << 7));
    this->set_flag(FLAG_CARRY, t1);
    this->set_flags(this->bus->read(arg1));
    break;

case ROR_ZPX:
    arg1 = ZP(this->read_u8() + this->x);
    t1 = this->bus->read(arg1) & 0x01;
    this->bus->write(arg1, ((this->bus->read(arg1) >> 1) & 0x7F) | (this->get_flag(FLAG_CARRY) << 7));
    this->set_flag(FLAG_CARRY, t1);
    this->set_flags(this->bus->read(arg1));
    break;

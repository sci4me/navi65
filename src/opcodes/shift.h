case ASL_AB:
    DEBUG_TRACE_AB("asl");
    this->set_flag(FLAG_CARRY, this->bus->read(addr) & 0x80);
    this->bus->write(addr, (this->bus->read(addr) << 1) & 0xFE);
    this->set_flags(this->bus->read(addr));
    break;

case ASL_ABX:
    DEBUG_TRACE_ABX("asl");
    this->set_flag(FLAG_CARRY, this->bus->read(addr) & 0x80);
    this->bus->write(addr, (this->bus->read(addr) << 1) & 0xFE);
    this->set_flags(this->bus->read(addr));
    break;

case ASL_ACC:
    DEBUG_TRACE_ACC("asl");
    this->set_flag(FLAG_CARRY, this->a & 0x80);
    this->a = (this->a << 1) & 0xFE;
    this->set_flags(this->a);
    break;

case ASL_ZP:
    DEBUG_TRACE_ZP("asl");
    this->set_flag(FLAG_CARRY, this->bus->read(addr) & 0x80);
    this->bus->write(addr, (this->bus->read(addr) << 1) & 0xFE);
    this->set_flags(this->bus->read(addr));
    break;

case ASL_ZPX:
    DEBUG_TRACE_ZPX("asl");
    this->set_flag(FLAG_CARRY, this->bus->read(addr) & 0x80);
    this->bus->write(addr, (this->bus->read(addr) << 1) & 0xFE);
    this->set_flags(this->bus->read(addr));
    break;

case LSR_AB:
    DEBUG_TRACE_AB("lsr");
    this->set_flag(FLAG_CARRY, this->bus->read(addr) & 0x01);
    this->bus->write(addr, (this->bus->read(addr) >> 1) & 0x7F);
    this->set_flags(this->bus->read(addr));
    break;

case LSR_ABX:
    DEBUG_TRACE_ABX("lsr");
    this->set_flag(FLAG_CARRY, this->bus->read(addr) & 0x01);
    this->bus->write(addr, (this->bus->read(addr) >> 1) & 0x7F);
    this->set_flags(this->bus->read(addr));
    break;

case LSR_ACC:
    DEBUG_TRACE_ACC("lsr");
    this->set_flag(FLAG_CARRY, this->a & 0x01);
    this->a = (this->a >> 1) & 0x7F;
    this->set_flags(this->a);
    break;

case LSR_ZP:
    DEBUG_TRACE_ZP("lsr");
    this->set_flag(FLAG_CARRY, this->bus->read(addr) & 0x01);
    this->bus->write(addr, (this->bus->read(addr) >> 1) & 0x7F);
    this->set_flags(this->bus->read(addr));
    break;

case LSR_ZPX:
    DEBUG_TRACE_ZPX("lsr");
    this->set_flag(FLAG_CARRY, this->bus->read(addr) & 0x01);
    this->bus->write(addr, (this->bus->read(addr) >> 1) & 0x7F);
    this->set_flags(this->bus->read(addr));
    break;

case ROL_AB:
    DEBUG_TRACE_AB("rol");
    t1 = this->bus->read(addr) & 0x80;
    this->bus->write(addr, ((this->bus->read(addr) << 1) & 0xFE) | this->get_flag(FLAG_CARRY));
    this->set_flag(FLAG_CARRY, t1);
    this->set_flags(this->bus->read(addr));
    break;

case ROL_ABX:
    DEBUG_TRACE_ABX("rol");
    t1 = this->bus->read(addr) & 0x80;
    this->bus->write(addr, ((this->bus->read(addr) << 1) & 0xFE) | this->get_flag(FLAG_CARRY));
    this->set_flag(FLAG_CARRY, t1);
    this->set_flags(this->bus->read(addr));
    break;

case ROL_ACC:
    DEBUG_TRACE_ACC("rol");
    t1 = this->a & 0x80;
    this->a = ((this->a << 1) & 0xFE) | this->get_flag(FLAG_CARRY);
    this->set_flag(FLAG_CARRY, t1);
    this->set_flags(this->a);
    break;

case ROL_ZP:
    DEBUG_TRACE_ZP("rol");
    t1 = this->bus->read(addr) & 0x80;
    this->bus->write(addr, ((this->bus->read(addr) << 1) & 0xFE) | this->get_flag(FLAG_CARRY));
    this->set_flag(FLAG_CARRY, t1);
    this->set_flags(this->bus->read(addr));
    break;

case ROL_ZPX:
    DEBUG_TRACE_ZPX("rol");
    t1 = this->bus->read(addr) & 0x80;
    this->bus->write(addr, ((this->bus->read(addr) << 1) & 0xFE) | this->get_flag(FLAG_CARRY));
    this->set_flag(FLAG_CARRY, t1);
    this->set_flags(this->bus->read(addr));
    break;

case ROR_AB:
    DEBUG_TRACE_AB("ror");
    t1 = this->bus->read(addr) & 0x01;
    this->bus->write(addr, ((this->bus->read(addr) >> 1) & 0x7F) | (this->get_flag(FLAG_CARRY) << 7));
    this->set_flag(FLAG_CARRY, t1);
    this->set_flags(this->bus->read(addr));
    break;

case ROR_ABX:
    DEBUG_TRACE_ABX("ror");
    t1 = this->bus->read(addr) & 0x01;
    this->bus->write(addr, ((this->bus->read(addr) >> 1) & 0x7F) | (this->get_flag(FLAG_CARRY) << 7));
    this->set_flag(FLAG_CARRY, t1);
    this->set_flags(this->bus->read(addr));
    break;

case ROR_ACC:
    t1 = this->a & 0x01;
    this->a = ((this->a >> 1) & 0x7F) | (this->get_flag(FLAG_CARRY) << 7);
    this->set_flag(FLAG_CARRY, t1);
    this->set_flags(this->a);
    break;

case ROR_ZP:
    DEBUG_TRACE_ZP("ror");
    t1 = this->bus->read(addr) & 0x01;
    this->bus->write(addr, ((this->bus->read(addr) >> 1) & 0x7F) | (this->get_flag(FLAG_CARRY) << 7));
    this->set_flag(FLAG_CARRY, t1);
    this->set_flags(this->bus->read(addr));
    break;

case ROR_ZPX:
    DEBUG_TRACE_ZPX("ror");
    t1 = this->bus->read(addr) & 0x01;
    this->bus->write(addr, ((this->bus->read(addr) >> 1) & 0x7F) | (this->get_flag(FLAG_CARRY) << 7));
    this->set_flag(FLAG_CARRY, t1);
    this->set_flags(this->bus->read(addr));
    break;

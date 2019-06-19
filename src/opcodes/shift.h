case ASL_AB:
    arg1 = this->read_u8();
    r1 = mem_abs(arg1, this->read_u8(), 0);
    set_flag(m, FLAG_CARRY, m->mem[r1] & 0x80);
    m->mem[r1] = (m->mem[r1] << 1) & 0xFE;
    this->set_flags(m->mem[r1]);
    mark_dirty(m, r1);
    break;

case ASL_ABX:
    arg1 = this->read_u8();
    r1 = mem_abs(arg1, this->read_u8(), m->x);
    set_flag(m, FLAG_CARRY, m->mem[r1] & 0x80);
    m->mem[r1] = (m->mem[r1] << 1) & 0xFE;
    this->set_flags(m->mem[r1]);
    mark_dirty(m, r1);
    break;

case ASL_ACC:
    set_flag(m, FLAG_CARRY, m->ac & 0x80);
    m->ac = (m->ac << 1) & 0xFE;
    this->set_flags(m->ac);
    break;

case ASL_ZP:
    arg1 = this->read_u8();
    set_flag(m, FLAG_CARRY, m->mem[arg1] & 0x80);
    m->mem[arg1] = (m->mem[arg1] << 1) & 0xFE;
    this->set_flags(m->mem[arg1]);
    mark_dirty(m, arg1);
    break;

case ASL_ZPX:
    arg1 = ZP(this->read_u8() + m->x);
    set_flag(m, FLAG_CARRY, m->mem[arg1] & 0x80);
    m->mem[arg1] = (m->mem[arg1] << 1) & 0xFE;
    this->set_flags(m->mem[arg1]);
    mark_dirty(m, arg1);
    break;

case LSR_AB:
    arg1 = this->read_u8();
    r1 = mem_abs(arg1, this->read_u8(), 0);
    set_flag(m, FLAG_CARRY, m->mem[r1] & 0x01);
    m->mem[r1] = (m->mem[r1] >> 1) & 0x7F;
    this->set_flags(m->mem[r1]);
    mark_dirty(m, r1);
    break;

case LSR_ABX:
    arg1 = this->read_u8();
    r1 = mem_abs(arg1, this->read_u8(), m->x);
    set_flag(m, FLAG_CARRY, m->mem[r1] & 0x01);
    m->mem[r1] = (m->mem[r1] >> 1) & 0x7F;
    this->set_flags(m->mem[r1]);
    mark_dirty(m, r1);
    break;

case LSR_ACC:
    set_flag(m, FLAG_CARRY, m->ac & 0x01);
    m->ac = (m->ac >> 1) & 0x7F;
    this->set_flags(m->ac);
    break;

case LSR_ZP:
    arg1 = this->read_u8();
    set_flag(m, FLAG_CARRY, m->mem[arg1] & 0x01);
    m->mem[arg1] = (m->mem[arg1] >> 1) & 0x7F;
    this->set_flags(m->mem[arg1]);
    mark_dirty(m, arg1);
    break;

case LSR_ZPX:
    arg1 = ZP(this->read_u8() + m->x);
    set_flag(m, FLAG_CARRY, m->mem[arg1] & 0x01);
    m->mem[arg1] = (m->mem[arg1] >> 1) & 0x7F;
    this->set_flags(m->mem[arg1]);
    mark_dirty(m, arg1);
    break;

case ROL_AB:
    arg1 = this->read_u8();
    r1 = mem_abs(arg1, this->read_u8(), 0);
    t1 = m->mem[r1] & 0x80;
    m->mem[r1] = ((m->mem[r1] << 1) & 0xFE) | get_flag(m, FLAG_CARRY);
    set_flag(m, FLAG_CARRY, t1);
    this->set_flags(m->mem[r1]);
    mark_dirty(m, r1);
    break;

case ROL_ABX:
    arg1 = this->read_u8();
    r1 = mem_abs(arg1, this->read_u8(), m->x);
    t1 = m->mem[r1] & 0x80;
    m->mem[r1] = ((m->mem[r1] << 1) & 0xFE) | get_flag(m, FLAG_CARRY);
    set_flag(m, FLAG_CARRY, t1);
    this->set_flags(m->mem[r1]);
    mark_dirty(m, r1);
    break;

case ROL_ACC:
    t1 = m->ac & 0x80;
    m->ac = ((m->ac << 1) & 0xFE) | get_flag(m, FLAG_CARRY);
    set_flag(m, FLAG_CARRY, t1);
    this->set_flags(m->ac);
    break;

case ROL_ZP:
    arg1 = this->read_u8();
    t1 = m->mem[arg1] & 0x80;
    m->mem[arg1] = ((m->mem[arg1] << 1) & 0xFE) | get_flag(m, FLAG_CARRY);
    set_flag(m, FLAG_CARRY, t1);
    this->set_flags(m->mem[arg1]);
    mark_dirty(m, arg1);
    break;

case ROL_ZPX:
    arg1 = ZP(this->read_u8() + m->x);
    t1 = m->mem[arg1] & 0x80;
    m->mem[arg1] = ((m->mem[arg1] << 1) & 0xFE) | get_flag(m, FLAG_CARRY);
    set_flag(m, FLAG_CARRY, t1);
    this->set_flags(m->mem[arg1]);
    mark_dirty(m, arg1);
    break;

case ROR_AB:
    arg1 = this->read_u8();
    r1 = mem_abs(arg1, this->read_u8(), 0);
    t1 = m->mem[r1] & 0x01;
    m->mem[r1] = ((m->mem[r1] >> 1) & 0x7F) | (get_flag(m, FLAG_CARRY) << 7);
    set_flag(m, FLAG_CARRY, t1);
    this->set_flags(m->mem[r1]);
    mark_dirty(m, r1);
    break;

case ROR_ABX:
    arg1 = this->read_u8();
    r1 = mem_abs(arg1, this->read_u8(), m->x);
    t1 = m->mem[r1] & 0x01;
    m->mem[r1] = ((m->mem[r1] >> 1) & 0x7F) | (get_flag(m, FLAG_CARRY) << 7);
    set_flag(m, FLAG_CARRY, t1);
    this->set_flags(m->mem[r1]);
    mark_dirty(m, r1);
    break;

case ROR_ACC:
    t1 = m->ac & 0x01;
    m->ac = ((m->ac >> 1) & 0x7F) | (get_flag(m, FLAG_CARRY) << 7);
    set_flag(m, FLAG_CARRY, t1);
    this->set_flags(m->ac);
    break;

case ROR_ZP:
    arg1 = this->read_u8();
    t1 = m->mem[arg1] & 0x01;
    m->mem[arg1] = ((m->mem[arg1] >> 1) & 0x7F) | (get_flag(m, FLAG_CARRY) << 7);
    set_flag(m, FLAG_CARRY, t1);
    this->set_flags(m->mem[arg1]);
    mark_dirty(m, arg1);
    break;

case ROR_ZPX:
    arg1 = ZP(this->read_u8() + m->x);
    t1 = m->mem[arg1] & 0x01;
    m->mem[arg1] = ((m->mem[arg1] >> 1) & 0x7F) | (get_flag(m, FLAG_CARRY) << 7);
    set_flag(m, FLAG_CARRY, t1);
    this->set_flags(m->mem[arg1]);
    mark_dirty(m, arg1);
    break;

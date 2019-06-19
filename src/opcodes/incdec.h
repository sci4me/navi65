case INC_ACC:
    set_flags(m, ++m->ac);
    break;

case INC_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    r1 = mem_abs(arg1, arg2, 0);
    set_flags(m, ++m->mem[r1]);
    mark_dirty(m, r1);
    break;

case INC_ABX:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    r1 = mem_abs(arg1, arg2, m->x);
    set_flags(m, ++m->mem[r1]);
    mark_dirty(m, r1);
    break;

case INC_ZP:
    r1 = this->read_u8();
    set_flags(m, ++m->mem[r1]);
    mark_dirty(m, r1);
    break;

case INC_ZPX:
    r1 = ZP(this->read_u8() + m->x);
    set_flags(m, ++m->mem[r1]);
    mark_dirty(m, r1);
    break;

case INX:
    set_flags(m, ++m->x);
    break;

case INY:
    set_flags(m, ++m->y);
    break;

case DEC_ACC:
    set_flags(m, --m->ac);
    break;

case DEC_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    r1 = mem_abs(arg1, arg2, 0);
    set_flags(m, --m->mem[r1]);
    mark_dirty(m, r1);
    break;

case DEC_ABX:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    r1 = mem_abs(arg1, arg2, m->x);
    set_flags(m, --m->mem[r1]);
    mark_dirty(m, r1);
    break;

case DEC_ZP:
    r1 = this->read_u8();
    set_flags(m, --m->mem[r1]);
    mark_dirty(m, r1);
    break;

case DEC_ZPX:
    r1 = ZP(this->read_u8() + m->x);
    set_flags(m, --m->mem[r1]);
    mark_dirty(m, r1);
    break;

case DEX:
    set_flags(m, --m->x);
    break;

case DEY:
    set_flags(m, --m->y);
    break;

case STA_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    r1 = mem_abs(arg1, arg2, 0);
    m->mem[r1] = m->ac;
    mark_dirty(m, r1);
    break;

case STA_ABX:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    r1 = mem_abs(arg1, arg2, m->x);
    m->mem[r1] = m->ac;
    mark_dirty(m, r1);
    break;

case STA_ABY:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    r1 = mem_abs(arg1, arg2, m->y);
    m->mem[r1] = m->ac;
    mark_dirty(m, r1);
    break;

case STA_INX:
    r1 = mem_indexed_indirect(m, this->read_u8(), m->x);
    m->mem[r1] = m->ac;
    mark_dirty(m, r1);
    break;

case STA_INY:
    r1 = mem_indirect_index(m, this->read_u8(), m->y);
    m->mem[r1] = m->ac;
    mark_dirty(m, r1);
    break;

case STA_ZP:
    r1 = ZP(this->read_u8());
    m->mem[r1] = m->ac;
    mark_dirty(m, r1);
    break;

case STA_ZPX:
    r1 = ZP(this->read_u8() + m->x);
    m->mem[r1] = m->ac;
    mark_dirty(m, r1);
    break;

case STA_INZP:
    r1 = mem_indirect_zp(m, this->read_u8());
    m->mem[r1] = m->ac;
    mark_dirty(m, r1);
    break;

case STX_ZP:
    r1 = ZP(this->read_u8());
    m->mem[r1] = m->x;
    mark_dirty(m, r1);
    break;

case STX_ZPY:
    r1 = ZP(this->read_u8() + m->y);
    m->mem[r1] = m->x;
    mark_dirty(m, r1);
    break;

case STX_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    r1 = mem_abs(arg1, arg2, 0);
    m->mem[r1] = m->x;
    mark_dirty(m, r1);
    break;

case STY_ZP:
    r1 = ZP(this->read_u8());
    m->mem[r1] = m->y;
    mark_dirty(m, r1);
    break;

case STY_ZPX:
    r1 = ZP(this->read_u8() + m->x);
    m->mem[r1] = m->y;
    mark_dirty(m, r1);
    break;

case STY_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    r1 = mem_abs(arg1, arg2, 0);
    m->mem[r1] = m->y;
    mark_dirty(m, r1);
    break;

case STZ_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    r1 = mem_abs(arg1, arg2, 0);
    m->mem[r1] = 0;
    mark_dirty(m, r1);
    break;

case STZ_ABX:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    r1 = mem_abs(arg1, arg2, m->x);
    m->mem[r1] = 0;
    mark_dirty(m, r1);
    break;

case STZ_ZP:
    r1 = ZP(this->read_u8());
    m->mem[r1] = 0;
    mark_dirty(m, r1);
    break;

case STZ_ZPX:
    r1 = ZP(this->read_u8() + m->x);
    m->mem[r1] = 0;
    mark_dirty(m, r1);
    break;

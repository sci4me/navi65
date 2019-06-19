case CMP_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    cmp(m, m->mem[mem_abs(arg1, arg2, 0)], m->ac);
    break;

case CMP_ABX:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    cmp(m, m->mem[mem_abs(arg1, arg2, m->x)], m->ac);
    break;

case CMP_ABY:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    cmp(m, m->mem[mem_abs(arg1, arg2, m->y)], m->ac);
    break;

case CMP_IMM:
    cmp(m, this->read_u8(), m->ac);
    break;

case CMP_INX:
    cmp(m, m->mem[mem_indexed_indirect(m, this->read_u8(), m->x)], m->ac);
    break;

case CMP_INY:
    cmp(m, m->mem[mem_indirect_index(m, this->read_u8(), m->y)], m->ac);
    break;

case CMP_ZP:
    cmp(m, m->mem[this->read_u8()], m->ac);
    break;

case CMP_ZPX:
    cmp(m, m->mem[ZP(this->read_u8() + m->x)], m->ac);
    break;

case CMP_INZP:
    cmp(m, m->mem[mem_indirect_zp(m, this->read_u8())], m->ac);
    break;

case CPX_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    cmp(m, m->mem[mem_abs(arg1, arg2, 0)], m->x);
    break;

case CPX_IMM:
    cmp(m, this->read_u8(), m->x);
    break;

case CPX_ZP:
    cmp(m, m->mem[this->read_u8()], m->x);
    break;

case CPY_AB:
    arg1 = this->read_u8();
    arg2 = this->read_u8();
    cmp(m, m->mem[mem_abs(arg1, arg2, 0)], m->y);
    break;

case CPY_IMM:
    cmp(m, this->read_u8(), m->y);
    break;

case CPY_ZP:
    cmp(m, m->mem[this->read_u8()], m->y);
    break;

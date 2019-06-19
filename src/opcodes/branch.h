case BCC_REL:
    s1 = this->read_u8();
    DEBUG_TRACE_REL("bcc");
    if (!this->get_flag(FLAG_CARRY)) {
        branch_offset = s1;
    }
    break;

case BCS_REL:
    s1 = this->read_u8();
    DEBUG_TRACE_REL("bcs");
    if (this->get_flag(FLAG_CARRY)) {
        branch_offset = s1;
    }
    break;

case BEQ_REL:
    s1 = this->read_u8();
    DEBUG_TRACE_REL("beq");
    if (this->get_flag(FLAG_ZERO)) {
        branch_offset = s1;
    }
    break;

case BMI_REL:
    s1 = this->read_u8();
    DEBUG_TRACE_REL("bmi");
    if (this->get_flag(FLAG_NEGATIVE)) {
        branch_offset = s1;
    }
    break;

case BNE_REL:
    s1 = this->read_u8();
    DEBUG_TRACE_REL("bne");
    if (!this->get_flag(FLAG_ZERO)) {
        branch_offset = s1;
    }
    break;

case BPL_REL:
    s1 = this->read_u8();
    DEBUG_TRACE_REL("bpl");
    if (!this->get_flag(FLAG_NEGATIVE)) {
        branch_offset = s1;
    }
    break;

case BVC_REL:
    s1 = this->read_u8();
    DEBUG_TRACE_REL("bvc");
    if (!this->get_flag(FLAG_OVERFLOW)) {
        branch_offset = s1;
    }
    break;

case BVS_REL:
    s1 = this->read_u8();
    DEBUG_TRACE_REL("bvs");
    if (this->get_flag(FLAG_OVERFLOW)) {
        branch_offset = s1;
    }
    break;

case BRA:
    branch_offset = this->read_u8();
    DEBUG_TRACE("bra $%02X", branch_offset);
    break;

case BBR0:
    r1 = ZP(this->read_u8());
    DEBUG_TRACE_REL("bbr 0");
    if(!(this->bus->read(r1) & 0x01)) {
        branch_offset = s1;
    }
    break;

case BBR1:
    r1 = ZP(this->read_u8());
    DEBUG_TRACE_REL("bbr 1");
    if(!(this->bus->read(r1) & 0x02)) {
        branch_offset = s1;
    }
    break;

case BBR2:
    r1 = ZP(this->read_u8());
    DEBUG_TRACE_REL("bbr 2");
    if(!(this->bus->read(r1) & 0x04)) {
        branch_offset = s1;
    }
    break;

case BBR3:
    r1 = ZP(this->read_u8());
    DEBUG_TRACE_REL("bbr 3");
    if(!(this->bus->read(r1) & 0x08)) {
        branch_offset = s1;
    }
    break;

case BBR4:
    r1 = ZP(this->read_u8());
    DEBUG_TRACE_REL("bbr 4");
    if(!(this->bus->read(r1) & 0x10)) {
        branch_offset = s1;
    }
    break;

case BBR5:
    r1 = ZP(this->read_u8());
    DEBUG_TRACE_REL("bbr 5");
    if(!(this->bus->read(r1) & 0x20)) {
        branch_offset = s1;
    }
    break;

case BBR6:
    r1 = ZP(this->read_u8());
    DEBUG_TRACE_REL("bbr 6");
    if(!(this->bus->read(r1) & 0x40)) {
        branch_offset = s1;
    }
    break;

case BBR7:
    r1 = ZP(this->read_u8());
    DEBUG_TRACE_REL("bbr 7");
    if(!(this->bus->read(r1) & 0x80)) {
        branch_offset = s1;
    }
    break;

case BBS0:
    r1 = ZP(this->read_u8());
    DEBUG_TRACE_REL("bbs 0");
    if(this->bus->read(r1) & 0x01) {
        branch_offset = s1;
    }
    break;

case BBS1:
    r1 = ZP(this->read_u8());
    DEBUG_TRACE_REL("bbs 1");
    if(this->bus->read(r1) & 0x02) {
        branch_offset = s1;
    }
    break;

case BBS2:
    r1 = ZP(this->read_u8());
    DEBUG_TRACE_REL("bbs 2");
    if(this->bus->read(r1) & 0x04) {
        branch_offset = s1;
    }
    break;

case BBS3:
    r1 = ZP(this->read_u8());
    DEBUG_TRACE_REL("bbs 3");
    if(this->bus->read(r1) & 0x08) {
        branch_offset = s1;
    }
    break;

case BBS4:
    r1 = ZP(this->read_u8());
    DEBUG_TRACE_REL("bbs 4");
    if(this->bus->read(r1) & 0x10) {
        branch_offset = s1;
    }
    break;

case BBS5:
    r1 = ZP(this->read_u8());
    DEBUG_TRACE_REL("bbs 5");
    if(this->bus->read(r1) & 0x20) {
        branch_offset = s1;
    }
    break;

case BBS6:
    r1 = ZP(this->read_u8());
    DEBUG_TRACE_REL("bbs 6");
    if(this->bus->read(r1) & 0x40) {
        branch_offset = s1;
    }
    break;

case BBS7:
    r1 = ZP(this->read_u8());
    DEBUG_TRACE_REL("bbs 7");
    if(this->bus->read(r1) & 0x80) {
        branch_offset = s1;
    }
    break;
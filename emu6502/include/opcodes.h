//
//  opcodes.h
//  emu6502
//
//  Created by Simone Rolando on 29/01/21.
//

#ifndef opcodes_h
#define opcodes_h

/* 6502 INSTRUCTION OPCODES. DO NOT CHANGE! */

#define OP_ADC_IM 0x69              // add with carry immediate
#define OP_ADC_ZP 0x65              // add with carry zero page
#define OP_ADC_ZP_X 0x75            // add with carry zero page reg x
#define OP_ADC_ABS 0x6D             // add with carry absolute
#define OP_ADC_ABS_X 0x7D           // add with carry absolute reg x
#define OP_ADC_ABS_Y 0x79           // add with carry absolute reg y
#define OP_ADC_IND_X 0x61           // add with carry indirect reg x
#define OP_ADC_IND_Y 0x71           // add with carry indirect reg y

#define OP_AND_IM 0x29              // logical and immediate
#define OP_AND_ZP 0x25              // logical and zero page
#define OP_AND_ZP_X 0x35            // logical and zero page reg x
#define OP_AND_ABS 0x2D             // logical and absolute
#define OP_AND_ABS_X 0x3D           // logical and absolute reg x
#define OP_AND_ABS_Y 0x39           // logical and absolute reg y
#define OP_AND_IND_X 0x21           // logical and indirect reg x
#define OP_AND_IND_Y 0x32           // logical and indirect reg y

#define OP_ASL_ACC 0x0A             // arithmetic shift left acc
#define OP_ASL_ZP 0x06              // arithmetic shift left zero page
#define OP_ASL_ZP_X 0x16            // arithmetic shift left zero page reg x
#define OP_ASL_ABS 0x0E             // arithmetic shift left absolute
#define OP_ASL_ABS_X 0x1E           // arithmetic shift left asolute reg x

#define OP_BCC_REL 0x90             // branch if carry clear relative
#define OP_BCS_REL 0xB0             // branch if carry set relative
#define OP_BEQ_REL 0xF0             // branch if equal relative
#define OP_BIT_ZP 0x24              // bit set check zero page
#define OP_BIT_ABS 0x2C             // bit set check absolute
#define OP_BMI_REL 0x30             // branch if minus relative
#define OP_BNE_REL 0xD0             // branch if not equal relative
#define OP_BPL_REL 0x10             // branch if positive relative
#define OP_BVC_REL 0x50             // branch if overflow clear relative
#define OP_BVS_REL 0x70             // branch if overflow set relative

#define OP_BRK_IMP 0x00             // force interrupt break
#define OP_CLC_IMP 0x18              // clear carry flag
#define OP_CLD_IMP 0xD8             // clear decimal mode
#define OP_CLI_IMP 0x58             // clear interrupt disable
#define OP_CLV_IMP 0xB8             // clear overflow flag

#define OP_CMP_IM 0xC9              // compare acc immediate
#define OP_CMP_ZP 0xC5              // compare acc zero page
#define OP_CMP_ZP_X 0xD5            // compare acc zero page reg x
#define OP_CMP_ABS 0xCD             // compare acc absolute
#define OP_CMP_ABS_X 0xDD           // compare acc absolute reg x
#define OP_CMP_ABS_Y 0xD9           // compare acc absolute reg y
#define OP_CMP_IND_X 0xC1           // compare acc indirect reg x
#define OP_CMP_IND_Y 0xD1           // compare acc indirect reg y

#define OP_CPX_IM 0xE0              // compare reg x immediate
#define OP_CPX_ZP 0xE4              // compare reg x zero page
#define OP_CPX_ABS 0xEC             // compare reg x absolute

#define OP_CPY_IM 0xC0              // compare reg y immediate
#define OP_CPY_ZP 0xC4              // compare reg y zero page
#define OP_CPY_ABS 0xCC             // compare reg y absolute

#define OP_DEC_ZP 0xC6              // decrement memory zero page
#define OP_DEC_ZP_X 0xD6            // decrement memory zero page reg x
#define OP_DEC_ABS 0xCE             // decrement memory absolute
#define OP_DEC_ABS_X 0xDE           // decrement memory absolute reg x

#define OP_DEX_IMP 0xCA             // decrement x reg implied

#define OP_EOR_IM 0x49              // exclusive or immediate
#define OP_EOR_ZP 0x45              // exclusive or zero page
#define OP_EOR_ZP_X 0x55            // exclusive or zero page reg x
#define OP_EOR_ABS 0x4D             // exclusive or absolute
#define OP_EOR_ABS_X 0x5D           // exclusive or absolute reg x
#define OP_EOR_ABS_Y 0x59           // exclusive or absolute reg y
#define OP_EOR_IND_X 0x41           // exclusive or indirect reg x
#define OP_EOR_IND_Y 0x51           // exclusive or indirect reg y

#define OP_INC_ZP 0xE6              // increment memory zero page
#define OP_INC_ZP_X 0xF6            // increment memory zero page reg x
#define OP_INC_ABS 0xEE             // increment memory absolute
#define OP_INC_ABS_X 0xFE           // increment memory absolute reg x

#define OP_INX_IMP 0xE8             // increment reg x implied
#define OP_INY_IMP 0xC8             // increment reg y implied

#define OP_JMP_ABS 0x4C             // jump absolute
#define OP_JMP_IND 0x6C             // jump indirect

#define OP_JSR_ABS 0x20             // jump to subroutine abs

#define OP_LDA_IM 0xA9              // load acc immediate
#define OP_LDA_ZP 0xA5              // load acc zero page
#define OP_LDA_ZP_X 0xB5            // load acc zero page x reg
#define OP_LDA_ABS 0xAD             // load acc absolute
#define OP_LDA_ABS_X 0xBD           // load acc absolute reg x
#define OP_LDA_ABS_Y 0xB9           // load acc absolute reg y
#define OP_LDA_IND_X 0xA1           // load acc indirect x reg
#define OP_LDA_IND_Y 0xB1           // load acc indirect y reg

#define OP_LDX_IM 0xA2              // load x reg immediate
#define OP_LDX_ZP 0xA6              // load x reg zero page
#define OP_LDX_ZP_Y 0xB6            // load x reg zero page reg y
#define OP_LDX_ABS 0xAE             // load x reg absolute
#define OP_LDX_ABS_Y 0xBE           // load x reg absolute reg y

#define OP_LDY_IM 0xA0              // load y reg immediate
#define OP_LDY_ZP 0xA4              // load y reg zero page
#define OP_LDY_ZP_X 0xB4            // load y reg zero page reg x
#define OP_LDY_ABS 0xAC             // load y reg absolute
#define OP_LDY_ABS_X 0xBC           // load y reg absolute reg x

#define OP_LSR_ACC 0x4A             // logical shift right acc
#define OP_LSR_ZP 0x46              // logical shift right zero page
#define OP_LSR_ZP_X 0x56            // logical shift right zero page reg x
#define OP_LSR_ABS 0x4E             // logical shift right absolute
#define OP_LSR_ABS_X 0x5E           // logical shift right absolute reg x

#define OP_NOP 0xEA                 // no operation

#define OP_ORA_IM 0x09              // logical inclusive or immediate
#define OP_ORA_ZP 0x05              // logical inclusive or zero page
#define OP_ORA_ZP_X 0x15            // logical inclusive or zero page reg x
#define OP_ORA_ABS 0x0D             // logical inclusive or absolute
#define OP_ORA_ABS_X 0x1D           // logical inclusive or absolute reg x
#define OP_ORA_ABS_Y 0x19           // logical inclusive or absolute reg y
#define OP_ORA_IND_X 0x01           // logical inclusive or indirect reg x
#define OP_ORA_IND_Y 0x11           // logical inclusive or indirect reg y

#define OP_PHA_IMP 0x48             // push accumulator implied mode
#define OP_PHP_IMP 0x08             // push processor status implied mode
#define OP_PLA_IMP 0x68             // pull accumulator implied mode
#define OP_PLP_IMP 0x28             // pull processor status implied mode

#define OP_ROL_ACC 0x2A             // rotate left accumulator
#define OP_ROL_ZP 0x26              // rotate left zero page
#define OP_ROL_ZP_X 0x36            // rotate left zero page reg x
#define OP_ROL_ABS 0x2E             // rotate left absolute
#define OP_ROL_ABS_X 0x3E           // rotate left absolute reg x

#define OP_ROR_ACC 0x6A             // rotate right accumulator
#define OP_ROR_ZP 0x66              // rotate right zero page
#define OP_ROR_ZP_X 0x76            // rotate right zero page reg x
#define OP_ROR_ABS 0x6E             // rotate right absolute
#define OP_ROR_ABS_X 0x7E           // rotate right absolute x

#define OP_RTI_IMP 0x40             // return from interrupt implied
#define OP_RTS_IMP 0x60             // return from subroutine implied

#define OP_SBC_IM 0xE9              // subtract with carry immediate mode
#define OP_SBC_ZP 0xE5              // subtract with carry zero page
#define OP_SBC_ZP_X 0xF5            // subtract with carry zero page reg x
#define OP_SBC_ABS 0xED             // subtract with carry absolute
#define OP_SBC_ABS_X 0xFD           // subtract with carry absolute reg x
#define OP_SBC_ABS_Y 0xF9           // subtract with carry absolute reg y
#define OP_SBC_IND_X 0xE1           // subtract with carry indirect reg x
#define OP_SBC_IND_Y 0xF1           // subtract with carry indirect reg y

#define OP_SEC_IMP 0x38             // set carry flag
#define OP_SED_IMP 0xF8             // set decimal flag
#define OP_SEI_IMP 0x78             // set interrupt disable flag

#define OP_STA_ZP 0x85              // store accumulator zero page
#define OP_STA_ZP_X 0x95            // store accumulator zero page reg x
#define OP_STA_ABS 0x8D             // store accumulator absolute
#define OP_STA_ABS_X 0x9D           // store accumulator absolute reg x
#define OP_STA_ABS_Y 0x99           // store accumulator absolute reg y
#define OP_STA_IND_X 0x81           // store accumulator indirect reg x
#define OP_STA_IND_Y 0x91           // store accumulator indirect reg y

#define OP_STX_ZP 0x86              // store x register zero page
#define OP_STX_ZP_Y 0x96            // store x register zero page reg y
#define OP_STX_ABS 0x8E             // store x register absolute

#define OP_STY_ZP 0x84              // store y register zero page
#define OP_STY_ZP_X 0x94            // store y register zero page reg x
#define OP_STY_ABS 0x8C             // store y register absolute

#define OP_TAX_IMP 0xAA             // transfer acc to reg x
#define OP_TAY_IMP 0xA8             // transfer acc to reg y
#define OP_TSX_IMP 0xBA             // transfer sp to reg x
#define OP_TXA_IMP 0x8A             // transfer reg x to acc
#define OP_TXS_IMP 0x9A             // transfer reg x to sp
#define OP_TYA_IMP 0x98             // transfer reg y to acc

/* STATUS FLAGS MACRO FOR SPECIFIC OPCODE. DO NOT CHANGE! */

#define LDA_SET_STATUS(cpu) { \
    cpu->z = (cpu->a == 0); \
    cpu->n = (cpu->a & 0b10000000) > 0; \
}

#define LDX_SET_STATUS(cpu) { \
    cpu->z = (cpu->x == 0); \
    cpu->n = (cpu->x & 0b10000000) > 0; \
}

#define LDY_SET_STATUS(cpu) { \
    cpu->z = (cpu->y == 0); \
    cpu->n = (cpu->y & 0b10000000) > 0; \
}

#define AND_SET_STATUS(cpu) { \
    cpu->z = (cpu->a == 0); \
    cpu->n = (cpu->a & 0b10000000) > 0; \
}

#define INX_SET_STATUS(cpu) { \
    cpu->z = (cpu->x == 0); \
    cpu->n = (cpu->x & 0b10000000) > 0; \
}

#define INY_SET_STATUS(cpu) { \
    cpu->z = (cpu->y == 0); \
    cpu->n = (cpu->y & 0b10000000) > 0; \
}

#endif /* opcodes_h */

//
//  core.c
//  emu6502
//
//  Created by Simone Rolando on 28/01/21.
//

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "../include/opcodes.h"
#include "../include/core.h"

void cpu_perror(const char* message)
{
    fprintf(stderr, "CPU ERROR: %s\n", message);
    exit(EXIT_FAILURE);
}

void mem_perror(const char* message)
{
    fprintf(stderr, "MEMORY ERROR: %s\n", message);
    exit(EXIT_FAILURE);
}

void mem_init(struct mem_t* mem)
{
    if (NULL == mem) mem_perror("NULL pointer!");
    
    // initializing memory
    memset((void*)mem->data, 0, MAX_MEM * sizeof(byte));
}

void cpu_reset(struct cpu_t* cpu)
{
    if (NULL == cpu) cpu_perror("NULL pointer!");
    
    // resetting program counter and stack pointer
    cpu->pc = 0xFFFC;
    cpu->sp = 0x0100;
    
    // resetting all status flags
    cpu->c = 0;
    cpu->z = 0;
    cpu->i = 0;
    cpu->d = 0;
    cpu->b = 0;
    cpu->v = 0;
    cpu->n = 0;
    
    // resetting registers
    cpu->a = 0;
    cpu->x = 0;
    cpu->y = 0;
}

void cpu_execute(struct cpu_t* cpu, struct mem_t* mem, dword cycles)
{
    while (cycles > 0) {
        byte instr = cpu_fetch_byte(cpu, mem, &cycles);
        switch (instr) {
            case OP_CLC_IMP: {
                cpu->c = 0x00;
                cycles -= 2;
            } break;
            case OP_CLD_IMP: {
                cpu->d = 0x00;
                cycles -= 2;
            } break;
            case OP_CLI_IMP: {
                cpu->i = 0x00;
                cycles -= 2;
            } break;
            case OP_CLV_IMP: {
                cpu->v = 0x00;
                cycles -=2;
            } break;
            case OP_INX_IMP: {
                cpu->x++;
                cycles -= 2;
                INX_SET_STATUS(cpu);
            } break;
            case OP_INY_IMP: {
                cpu->y++;
                cycles -= 2;
                INY_SET_STATUS(cpu);
            } break;
            case OP_JMP_ABS: {
                word addr = cpu_fetch_word(cpu, mem, &cycles);
                cpu->pc = addr;
                cycles--;
            } break;
            case OP_JMP_IND: {
                word addr = cpu_fetch_word(cpu, mem, &cycles);
                cpu->pc = mem_read_word(mem, addr, &cycles);
                cycles--;
            } break;
            case OP_LDA_IM: {
                cpu->a = cpu_fetch_byte(cpu, mem, &cycles);
                LDA_SET_STATUS(cpu);
            } break;
            case OP_LDA_ZP: {
                byte zp_addr = cpu_fetch_byte(cpu, mem, &cycles);
                cpu->a = mem_read_byte(mem, zp_addr, &cycles);
                LDA_SET_STATUS(cpu);
            } break;
            case OP_LDA_ZP_X: {
                byte zp_addr = cpu_fetch_byte(cpu, mem, &cycles);
                zp_addr += cpu->x;
                cycles--;
                cpu->a = mem_read_byte(mem, zp_addr, &cycles);
                LDA_SET_STATUS(cpu);
            } break;
            case OP_LDA_ABS: {
                word addr = cpu_fetch_word(cpu, mem, &cycles);
                cpu->a = mem_read_byte(mem, addr, &cycles);
                LDA_SET_STATUS(cpu);
            } break;
            case OP_LDA_ABS_X: {
                word addr = cpu_fetch_word(cpu, mem, &cycles);
                addr += cpu->x;
                cycles--;
                cpu->a = mem_read_byte(mem, addr, &cycles);
                LDA_SET_STATUS(cpu);
            } break;
            case OP_LDA_ABS_Y: {
                word addr = cpu_fetch_word(cpu, mem, &cycles);
                addr += cpu->y;
                cycles--;
                cpu->a = mem_read_byte(mem, addr, &cycles);
                LDA_SET_STATUS(cpu);
            } break;
            case OP_LDA_IND_X: {
                byte zp_addr = cpu_fetch_byte(cpu, mem, &cycles);
                zp_addr = (cpu->x + zp_addr) & 0xFF;
                cycles -= 2;
                word tgt_addr = mem_read_word(mem, zp_addr, &cycles);
                cpu->a = mem_read_byte(mem, tgt_addr, &cycles);
                cycles--;
                LDA_SET_STATUS(cpu);
            } break;
            case OP_LDA_IND_Y: {
                byte zp_addr = cpu_fetch_byte(cpu, mem, &cycles);
                word tgt_addr = mem_read_word(mem, zp_addr, &cycles);
                // completing address calculation
                tgt_addr += 0xA;
                cpu->a = mem_read_byte(mem, tgt_addr, &cycles);
                cycles--;
                LDA_SET_STATUS(cpu);
            } break;
            case OP_LDX_IM: {
                cpu->x = cpu_fetch_byte(cpu, mem, &cycles);
                LDX_SET_STATUS(cpu);
            } break;
            case OP_LDX_ZP: {
                byte addr = cpu_fetch_byte(cpu, mem, &cycles);
                cpu->x = mem_read_byte(mem, addr, &cycles);
                LDX_SET_STATUS(cpu);
            } break;
            case OP_LDX_ZP_Y: {
                byte addr = cpu_fetch_byte(cpu, mem, &cycles);
                addr += cpu->y;
                cycles--;
                cpu->x = mem_read_byte(mem, addr, &cycles);
                LDX_SET_STATUS(cpu);
            } break;
            case OP_LDX_ABS: {
                word addr = cpu_fetch_word(cpu, mem, &cycles);
                cpu->x = mem_read_byte(mem, addr, &cycles);
                LDX_SET_STATUS(cpu);
            } break;
            case OP_LDX_ABS_Y: {
                word addr = cpu_fetch_word(cpu, mem, &cycles);
                addr += cpu->y;
                cycles--;
                cpu->x = mem_read_byte(mem, addr, &cycles);
                LDX_SET_STATUS(cpu);
            } break;
            case OP_LDY_IM: {
                cpu->y = cpu_fetch_byte(cpu, mem, &cycles);
                LDY_SET_STATUS(cpu);
            } break;
            case OP_LDY_ZP: {
                byte addr = cpu_fetch_byte(cpu, mem, &cycles);
                cpu->y = mem_read_byte(mem, addr, &cycles);
                LDY_SET_STATUS(cpu);
            } break;
            case OP_LDY_ZP_X: {
                byte addr = cpu_fetch_byte(cpu, mem, &cycles);
                addr += cpu->x;
                cpu->y = mem_read_byte(mem, addr, &cycles);
                LDY_SET_STATUS(cpu);
            } break;
            case OP_LDY_ABS: {
                word addr = cpu_fetch_word(cpu, mem, &cycles);
                cpu->y = mem_read_byte(mem, addr, &cycles);
                LDY_SET_STATUS(cpu);
            } break;
            case OP_LDY_ABS_X: {
                word addr = cpu_fetch_word(cpu, mem, &cycles);
                addr += cpu->x;
                cycles--;
                cpu->y = mem_read_byte(mem, addr, &cycles);
                LDY_SET_STATUS(cpu);
            } break;
            case OP_CMP_IM: {
                byte value = cpu_fetch_byte(cpu, mem, &cycles);
                cycles--;
                CMP_SET_STATUS(cpu, value);
            } break;
            case OP_CMP_ZP: {
                byte addr = cpu_fetch_byte(cpu, mem, &cycles);
                cycles--;
                CMP_SET_STATUS(cpu, mem_read_byte(mem, addr, &cycles));
            } break;
            case OP_JSR_ABS: {
                word sub_addr = cpu_fetch_word(cpu, mem, &cycles);
                mem_write_word(cpu->pc - 1, cpu->sp, mem, &cycles);
                cpu->pc = sub_addr;
                cycles--;
            } break;
            default: {
                fprintf(stderr, "Invalid opcode, skipping. Opcode value: 0x%X\n", instr);
            } break;
        }
    }
}

byte cpu_fetch_byte(struct cpu_t* cpu, struct mem_t* mem, dword* cycles)
{
    byte data = mem->data[cpu->pc];
    cpu->pc++;
    (*cycles)--;
    return data;
}

word cpu_fetch_word(struct cpu_t* cpu, struct mem_t* mem, dword* cycles)
{
    // 6502 is little endian, like x86 cpus,
    // so reading first byte
    word data = mem->data[cpu->pc];
    cpu->pc++;
    
    // reading second byte, adding value
    // to existing data by bitwise ORing
    data |= (mem->data[cpu->pc] << 8);
    cpu->pc++;
    (*cycles) -= 2;
    
    return data;
}

byte mem_read_byte(struct mem_t* mem, word address, dword* cycles)
{
    byte data = mem->data[address];
    (*cycles)--;
    return data;
}

word mem_read_word(struct mem_t* mem, word address, dword* cycles)
{
    word data = mem->data[address];
    data |= (mem->data[address + 1] << 8);
    (*cycles) -=2;

    return data;
}

void mem_write_word(word data, word address, struct mem_t* mem, dword* cycles)
{
    mem->data[address] = data & 0xFF;
    mem->data[address + 1] = (data >> 8);
    (*cycles) -= 2;
}

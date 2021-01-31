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
            case OP_LDA_IM: {
                byte val = cpu_fetch_byte(cpu, mem, &cycles);
                cpu->a = val;
                LDA_SET_STATUS(cpu);
            } break;
            case OP_LDA_ZP: {
                word zp_addr = cpu_fetch_byte(cpu, mem, &cycles);
                cpu->a = mem_read_byte(mem, zp_addr, &cycles);
                LDA_SET_STATUS(cpu);
            } break;
            case OP_LDA_ZP_X: {
                word zp_addr = cpu_fetch_byte(cpu, mem, &cycles);
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
            } break;
            case OP_LDA_ABS_Y: {
                word addr = cpu_fetch_word(cpu, mem, &cycles);
                addr += cpu->y;
                cycles--;
                cpu->a = mem_read_byte(mem, addr, &cycles);
            } break;
            case OP_LDA_IND_X: {
                byte zp_addr = cpu_fetch_byte(cpu, mem, &cycles);
                
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

void mem_write_word(word data, word address, struct mem_t* mem, dword* cycles)
{
    mem->data[address] = data & 0xFF;
    mem->data[address + 1] = (data >> 8);
    (*cycles) -= 2;
}
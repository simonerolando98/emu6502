//
//  main.c
//  emu6502
//
//  Created by Simone Rolando on 28/01/21.
//

#include <stdio.h>
#include <stdlib.h>
#include "../include/core.h"
#include "../include/opcodes.h"

int main(int argc, const char * argv[]) {
    mem_t mem;
    cpu_t cpu;
    
    const dword ticks = 10;
    
    cpu_reset(&cpu);
    mem_init(&mem);
    
    // loading test code
    /*mem.data[0xFFFC] = OP_JSR_ABS;
    mem.data[0xFFFD] = 0x42;
    mem.data[0xFFFE] = 0x42;
    mem.data[0x4242] = OP_LDA_IM;
    mem.data[0x4243] = 0x84;

    mem.data[0xFFFC] = OP_LDA_IND_Y;
    mem.data[0xFFFD] = 0x86;
    mem.data[0x0086] = 0xDF;
    mem.data[0x0087] = 0xBF;
    mem.data[0xBFE9] = 0x41;*/

    /* LDX IMMEDIATE TEST
    mem.data[0xFFFC] = OP_LDX_IM;
    mem.data[0xFFFD] = 0x41; */

    /* LDX ZP_Y TEST
    mem.data[0xFFFC] = OP_LDX_ZP_Y;
    mem.data[0xFFFD] = 0x20;
    cpu.y = 0x20;
    mem.data[0x20 + 0x20] = 0x41; */

    mem.data[0xFFFC] = OP_LDY_ZP_X;
    mem.data[0xFFFD] = 0x52;
    mem.data[0x0053] = 0x40;
    cpu.x = 0x01;
    
    // running code
    cpu_execute(&cpu, &mem, ticks);
    return 0;
}

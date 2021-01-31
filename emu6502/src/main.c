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

    /* LDX ZP TEST */
    mem.data[0xFFFC] = OP_LDX_ZP;
    mem.data[0xFFFD] = 0xFC;
    mem.data[0x00FC] = 0x41;
    
    // running code
    cpu_execute(&cpu, &mem, ticks);
    return 0;
}

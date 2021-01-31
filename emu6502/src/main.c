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
    
    const dword ticks = 3;
    
    cpu_reset(&cpu);
    mem_init(&mem);
    
    // loading test code
    /*mem.data[0xFFFC] = OP_JSR_ABS;
    mem.data[0xFFFD] = 0x42;
    mem.data[0xFFFE] = 0x42;
    mem.data[0x4242] = OP_LDA_IM;
    mem.data[0x4243] = 0x84;*/
    mem.data[0xFFFC] = OP_LDA_IND_X;
    mem.data[0xFFFD] = 0x42;
    mem.data[abs(0xFF - (cpu.x + 0x42))] = 0x86;
    
    // running code
    cpu_execute(&cpu, &mem, ticks);
    return 0;
}

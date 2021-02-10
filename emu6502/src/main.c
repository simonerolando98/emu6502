//
//  main.c
//  emu6502
//
//  Created by Simone Rolando on 28/01/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/stat.h>
#include "../include/core.h"
#include "../include/opcodes.h"

void start_loaded_bin(struct mem_t* mem)
{
    mem->data[0xFFFC] = OP_JMP_ABS;
    mem->data[0xFFFD] = 0x00;
    mem->data[0xFFFE] = 0x01;
}

int main(int argc, const char * argv[]) {
    mem_t mem;
    cpu_t cpu;
    struct stat st;
    stat("/Users/simone/Desktop/prog.bin", &st);
    
    const dword ticks = 100;
    
    cpu_reset(&cpu);
    mem_init(&mem);
    
    FILE* bin = fopen("/Users/simone/Desktop/prog.bin", "rb");
    fread((mem.data + 0x100), 1, st.st_size, bin);
    start_loaded_bin(&mem);
    
    // running code
    cpu_execute(&cpu, &mem, ticks);
    return 0;
}

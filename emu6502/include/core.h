//
//  core.h
//  emu6502
//
//  Created by Simone Rolando on 28/01/21.
//

#ifndef core_h
#define core_h

#include <stdint.h>

#define MAX_MEM 1024 * 64

typedef uint8_t byte;
typedef uint16_t word;
typedef uint32_t dword;

typedef struct mem_t {
    byte data[MAX_MEM];
} mem_t;

typedef struct cpu_t {
    word pc;                    // program counter
    word sp;                    // stack pointer
    
    byte a, x, y;               // gp registers
    
    byte c : 1;                 // cpu carry flag
    byte z : 1;                 // cpu zero flag
    byte i : 1;                 // cpu interrupt disable flag
    byte d : 1;                 // decimal mode flag
    byte b : 1;                 // break command flag
    byte v : 1;                 // overflow flag
    byte n : 1;                 // negative flag
} cpu_t;

void mem_init(struct mem_t* mem);
void cpu_reset(struct cpu_t* cpu);
void cpu_execute(struct cpu_t* cpu, struct mem_t* mem, dword cycles);

byte cpu_fetch_byte(struct cpu_t* cpu, struct mem_t* mem, dword* cycles);
word cpu_fetch_word(struct cpu_t* cpu, struct mem_t* mem, dword* cycles);


void mem_write_word(word data, word address, struct mem_t* mem, dword* cycles);
byte mem_read_byte(struct mem_t* mem, word address, dword* cycles);

#endif /* core_h */

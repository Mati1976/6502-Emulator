#include <stdio.h>
#include <stdlib.h>

using Byte = unsigned char;
using Word = unsigned short;
using u32 = unsigned int;

struct Mem
{
    static constexpr u32 MAX_MEM = 1024 * 64;
    Byte Data[MAX_MEM];

    void Initialise()
    {
        for (u32 i = 0; i < MAX_MEM; i++)
        {
            Data[i] = 0;
        }
    }
};

struct CPU
{
    using Byte = unsigned char;
    using Word = unsigned short;

    Word PC; // program counter
    Word SP; // stack pointer

    Byte A, X, Y; // registers

    Byte C : 1; // Carry flag
    Byte Z : 1; // Zero flag
    Byte I : 1; // Interrupt Disable flag
    Byte D : 1; // Decimal mode flag
    Byte B : 1; // Break mode flag
    Byte O : 1; // Overflow flag
    Byte N : 1; // Negative disable flag

    void Reset(Mem &memory)

    {
        // https://www.c64-wiki.com/wiki/Reset_(Process)

        SP = 0x0100;
        C = Z = I = D = B = O = N = 0; // resetting the flags to zero
        A = X = Y = 0;                 // resetting the registers to zero
        memory.Initialise();
    }
};

int main()
{
    Mem mem;
    CPU cpu;
    cpu.Reset(mem);
    return 0;
}
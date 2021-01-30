#include <stdio.h>
#include <stdlib.h>

using Byte = unsigned char;
using Word = unsigned short;

struct cpu
{
    using Byte = unsigned char;
    using Word = unsigned short;

    Word PC; // program counter
    Word SC; // stack pointer

    Byte A, X, Y; // registers
};

int main()
{
    return 0;
}
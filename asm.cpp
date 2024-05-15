#include <cassert>

#define LASM // on Linux
#define WASM // on Windows

extern "C" int func(int x);
// https://en.cppreference.com/w/cpp/language/asm
asm(R"(
    .globl func
        .type func, @function
        func:
        .cfi_startproc
        movl %edi, %eax /* x is in RDI, see x86-64 calling convention */
        addl $1, %eax
        ret
        .cfi_endproc
    )");

int main(int argc, char **argv)
{
// INFO: asm asm-qualifiers( AssemblerTemplate: OutputOperands[ : InputOperands[ : Clobbers] ])
// ~ asm("инструкции" : выходы : входы : изменяемые);
#ifdef LASM
    {
        asm("nop"); // nice )
    }
    {
        int a = 5;
        int b = 10;
        int result{};
        asm("addl %%ebx, %%eax;" : "=a"(result) : "a"(a), "b"(b));
        assert(result == 15);
    }
    {
        int value = 10;
        int *ptr = &value;
        asm("movl $5, (%0);" : : "r"(ptr));
        assert(value == 5);
    }
    {
        int a = 5;
        int b = 10;
        int result{};
        asm(
            "movl %1, %%eax; "
            "movl %2, %%ebx; "
            "addl %%ebx, %%eax;" : "=a"(result) : "g"(a), "g"(b));
        assert(result == 15);
    }
    {
        int val1 = 100;
        int val2 = 20;
        int add;
        int sub;
        int mul;
        asm("addl %%ebx, %%eax;"
            : "=a"(add)
            : "a"(val1), "b"(val2));
        asm("subl %%ebx, %%eax;"
            : "=a"(sub)
            : "a"(val1), "b"(val2));
        asm("imull %%ebx, %%eax;"
            : "=a"(mul)
            : "a"(val1), "b"(val2));
        assert(add == 120);
        assert(sub == 80);
        assert(mul == 2000);
    }
    {
        int n = func(0110);
        assert(n == 0111);
    }
    {
        asm("movq $60, %rax\n" // the exit syscall number on Linux
            "movq $2,  %rdi\n" // this program returns 2 $?
            "syscall");
    }
#endif
#ifdef WASM // TODO ...
    {
    }
#endif

    return 0;
}

# CPU is first and foremost a stack machine

---

C/C++ programming course at ISP RAS.

---

Necessary tools:

gcc

---

# How to build and run:

When you are in the src folder:

Command in terminal: `gcc main.cpp stack.cpp cpu.cpp -o main && ./main [.bin file]`

For example, you want to launch test1.bin:

`gcc main.cpp stack.cpp cpu.cpp -o main && ./main ./test1.bin`

# Scripts:

> main.cpp - create cpu and launch code
> stach.h, stack.cpp - implementation of stack
> cpu.h, cpu.cpp - implementation of cpu
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

# Example test1.bin:

The program describes the following sequence of commands: `set 1 3 out 1 end`.

The value 3 is written to register 1, then the value (VALUE: 3) is taken from register 1 and output, and the program exits.

# Scripts:

+ main - create cpu, write and execute code
+ stack - implementation of stack
+ cpu - implementation of cpu
+ commands.txt - list of cpu commands with their encoding
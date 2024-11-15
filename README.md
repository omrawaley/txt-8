
# TXT-8 Text-Based Virtual Machine

The TXT-8 is a simple 8-bit virtual machine based on the command line. 

TXT-8 has a minimal instruction set which demonstrates the fundamental aspects of virtualization.

I originally created TXT-8 to provide digestible substance for my lecture on virtualization for the programming club at my school.

## Specs
Components and specifications of TXT-8.

### CPU
- 8x 8-bit general-purpose registers.
- 8-level 12-bit address stack (12 bytes).
- 12-bit stack pointer.
- 12-bit program counter.
- 12-bit index register.

### Memory
- 4096 bytes of memory (4KB).
- 12-bit addressing.

### Special
- 8-bit output buffer.
- 8-bit buffer pointer that points to the end of the buffer.

## Instruction Set
A: 8-bit register (4 bytes).

B: 8-bit register (4 bytes).

ADDR: 12-bit address (12 bytes).

| Opcode | Mnemonic | Operands | Description                                                                    |
| ------ | -------- | -------- | ------------------------------------------------------------------------------ |
| 0      | CALL     | ADDR     | Call subroutine                                                                |
| 1      | RET      | NULL     | Return from subroutine                                                         |
| 2      | JMP      | ADDR     | Jump to address                                                                |
| 3      | ADD      | X, Y     | Add X and Y (store in X)                                                       |
| 4      | SUB      | X, Y     | Subtract Y from X (store in X)                                                 |
| 5      | AND      | X, Y     | AND X and Y (store in X)                                                       |
| 6      | OR       | X, Y     | OR X and Y (store in X)                                                        |
| 7      | XOR      | X, Y     | XOR X and Y (store in X)                                                       |
| 8      | SHR      | X, Y     | Shift X right by Y (store in X)                                                |
| 9      | SHL      | X, Y     | Shift X left by Y (store in X)                                                 |
| A      | LDB      | X        | Load output buffer with value of register X. Y bit low enables ASCII encoding. |
| B      | LDI      | X, BYTE  | Load immediate value into X                                                    |
| C      | LDR      | X, Y     | Load value of Y into X                                                         |
| D      | LDX      | ADRR     | Load index register with address                                               |
| E      | STR      | X        | Load value of X into memory[index]                                             |
| F      | PRNT     | NULL     | Print the text buffer and clear its contents                                   |



## Authors

- [@omrawaley](https://www.github.com/omrawaley)


## Installation

A Makefile is provided in the root directory that can be used to build/clean the project.

Simply run `make build` to compile the project.
## Usage

```
./bin/txt8 <path-to-program>
```

Examples can be found in the `examples` folder.



You can make your own programs by manually typing the instructions into a [hex editor](https://hexed.it/). I plan on making an assembler (so you can use ASM rather than manual hexadecimal) for TXT-8 once I finish fleshing out the instruction set.

The `.t8` extension for programs is not necessary, but I recommend it for clarity.
## License

TXT-8 - [Apache 2.9](https://apache.org/licenses/LICENSE-2.0)


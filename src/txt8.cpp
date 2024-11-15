// Copyright 2024 Om Rawaley (@omrawaley)

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "txt8.h"

#include <cstdint>
#include <fstream>
#include <iostream>

#include "opcode.h"
#include "instructions.h"

TXT8::TXT8()
{
    this->reset();
}

void TXT8::reset()
{
    this->i = 0;
    this->cpu.pc = 0;
    this->cpu.sp = 0;

    this->cpu.reg.fill(0);
    this->cpu.stack.fill(0);
    this->mem.fill(0);
}

void TXT8::loadProgram(const char* path)
{
    std::ifstream rom(path, std::ios::binary | std::ios::ate);

    if(!rom.is_open())
    {
        std::cerr << "Loader error: could not open program" << std::endl;

        exit(EXIT_FAILURE);
    }

    std::streampos size = rom.tellg();

    char* buffer = new char[size];

    rom.seekg(0, std::ios::beg);
    rom.read(buffer, size);
    rom.close();

    for(long i = 0; i < size; ++i)
    {
        this->mem.at(i) = buffer[i];
    }

    delete[] buffer;
}

void TXT8::emulateCycle()
{
    const uint8_t msb = this->mem[this->cpu.pc];
    const uint8_t lsb = this->mem[this->cpu.pc + 1];
    const uint16_t instruction = (msb << 8) | lsb;

    const Opcode opcode = static_cast<Opcode>(instruction >> 12);

    const uint8_t x = (instruction & 0x0F00) >> 8;
    const uint8_t y = (instruction & 0x00F0) >> 4;
    const uint8_t byte = (instruction & 0x00FF);
    const uint16_t addr = (instruction & 0x0FFF);

    bool incrementPC = true;

    switch(opcode)
    {
        case Opcode::CALL:
            Instructions::callSubroutine(this->cpu, addr);
            break;
        case Opcode::RET:
            Instructions::returnSubroutine(this->cpu);
            break;
        case Opcode::JMP:
            Instructions::jump(this->cpu, addr);
            incrementPC = false;
            break;
        case Opcode::ADD:
            Instructions::add(this->cpu, x, y);
            break;
        case Opcode::SUB:
            Instructions::subtract(this->cpu, x, y);
            break;
        case Opcode::AND:
            Instructions::bitwiseAnd(this->cpu, x, y);
            break;
        case Opcode::OR:
            Instructions::bitwiseOr(this->cpu, x, y);
            break;
        case Opcode::XOR:
            Instructions::bitwiseXor(this->cpu, x, y);
            break;
        case Opcode::SHR:
            Instructions::shiftRight(this->cpu, x, y);
            break;
        case Opcode::SHL:
            Instructions::shiftLeft(this->cpu, x, y);
            break;
        case Opcode::LDB:
            Instructions::loadOutputBuffer<255>(this->cpu, x, this->buf, this->bp);
            break;
        case Opcode::LDI:
            Instructions::loadImmediate(this->cpu, x, byte);
            break;
        case Opcode::LDR:
            Instructions::loadRegister(this->cpu, x, y);
            break;
        case Opcode::LDX:
            Instructions::loadIndex(i, addr);
            break;
        case Opcode::STR:
            Instructions::store<4096>(this->cpu, this->mem, x, this->i);
            break;
        case Opcode::PRNT:
            Instructions::print<255>(x, this->buf, this->bp);
            break;

        default:
            std::cerr << "Interpreter error: invalid opcode: " << (size_t)opcode << std::endl;
    }

    if(incrementPC)
        this->cpu.pc += 2;
}

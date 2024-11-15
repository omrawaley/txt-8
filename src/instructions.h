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

#pragma once

#include <iostream>

#include "cpu.h"

namespace Instructions
{
    void callSubroutine(CPU& cpu, const uint16_t& addr)
    {
        cpu.stack.at(cpu.sp) = cpu.pc;
        ++cpu.sp;
        cpu.pc = addr;
    }

    void returnSubroutine(CPU& cpu)
    {
        --cpu.sp;
        cpu.pc = cpu.stack.at(cpu.pc);
    }

    void jump(CPU& cpu, const uint16_t& addr)
    {
        cpu.pc = addr;
    }

    void add(CPU& cpu, const uint8_t& x, const uint8_t& y)
    {
        cpu.reg.at(x) += cpu.reg.at(y);
    }

    void subtract(CPU& cpu, const uint8_t& x, const uint8_t& y)
    {
        cpu.reg.at(x) -= cpu.reg.at(y);
    }

    void bitwiseAnd(CPU& cpu, const uint8_t& x, const uint8_t& y)
    {
        cpu.reg.at(x) &= cpu.reg.at(y);
    }

    void bitwiseOr(CPU& cpu, const uint8_t& x, const uint8_t& y)
    {
        cpu.reg.at(x) |= cpu.reg.at(y);
    }

    void bitwiseXor(CPU& cpu, const uint8_t& x, const uint8_t& y)
    {
        cpu.reg.at(x) ^= cpu.reg.at(y);
    }

    void shiftRight(CPU& cpu, const uint8_t& x, const uint8_t& y)
    {
        cpu.reg.at(x) >>= y;
    }

    void shiftLeft(CPU& cpu, const uint8_t& x, const uint8_t& y)
    {
        cpu.reg.at(x) <<= y;
    }

    template<size_t N>
    void loadOutputBuffer(CPU& cpu, const uint8_t& x, std::array<uint8_t, N>& buf, uint8_t& bp)
    {
        buf.at(bp) = cpu.reg.at(x);
        ++bp;
    }

    void loadImmediate(CPU& cpu, const uint8_t& x, const uint8_t& byte)
    {
        cpu.reg.at(x) = byte;
    }

    void loadRegister(CPU& cpu, const uint8_t& x, const uint8_t& y)
    {
        cpu.reg.at(x) = cpu.reg.at(y);
    }

    void loadIndex(uint16_t& i, const uint16_t& addr)
    {
        i = addr;
    }

    template<size_t N>
    void store(CPU& cpu, std::array<uint8_t, N>& mem, const uint8_t& x, const uint16_t& i)
    {
        mem.at(i) = cpu.reg.at(x);
    }

    template<size_t N>
    void print(const uint8_t& x, std::array<uint8_t, N>& buf, uint8_t& bp)
    {
        for(size_t i = 0; i < bp; ++i)
        {
            if(x == 0)
            {
                std::cout << buf.at(i) << std::flush;
            }
            else
            {
                std::cout << static_cast<size_t>(buf.at(i)) << std::flush;
            }
        
            buf.at(i) = 0;
        }
    
        bp = 0;
    }
};
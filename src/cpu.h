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

#include <cstdint>
#include <array>

struct CPU
{
    private:
        static constexpr size_t numRegisters = 8;
        static constexpr size_t numStackLevels = 8;

    public:
        static constexpr float clockSpeed = 512;

    public:
        std::array<uint8_t, CPU::numRegisters> reg;

        uint16_t pc;

        std::array<uint16_t, CPU::numStackLevels> stack;
        uint16_t sp;
};

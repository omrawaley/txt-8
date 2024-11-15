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

#include "cpu.h"

class TXT8
{
    private:
        static constexpr size_t bufferSize = 255;;
        static constexpr size_t memorySize = 4096;

    private:
        uint8_t bp;
        std::array<uint8_t, TXT8::bufferSize> buf;

        uint16_t i;
        std::array<uint8_t, TXT8::memorySize> mem;

        CPU cpu;

    public:
        TXT8();

        void reset();

        void loadProgram(const char* path);

        void emulateCycle();
};

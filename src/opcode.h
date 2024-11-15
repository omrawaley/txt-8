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

enum class Opcode
{
    CALL = 0x0,
    RET = 0x1,
    JMP = 0x2,
    ADD = 0x3,
    SUB = 0x4,
    AND = 0x5,
    OR = 0x6,
    XOR = 0x7,
    SHR = 0x8,
    SHL = 0x9,
    LDB = 0xA,
    LDI = 0xB,
    LDR = 0xC,
    LDX = 0xD,
    STR = 0xE,
    PRNT = 0xF,
};

/**
* This file is part of BareSDK and licensed under the:
* BSD 3-Clause License
* Copyright (c) 2021, Matheus Xavier
* All rights reserved.
*/

#ifndef LLRT_MATH_H_
#define LLRT_MATH_H_

#include "common.h"

#define llrt_min(A, B) ((A) < (B) ? (A) : (B))
#define llrt_max(A, B) ((A) > (B) ? (A) : (B))

extern uint64_t llrt_exp(uint32_t base, uint16_t exp);

#endif

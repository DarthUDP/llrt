/**
 * This file is part of BareSDK and licensed under the:
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
*/

#ifndef LLRT_HASHES_H
#define LLRT_HASHES_H

#include "common.h"

extern uint64_t llrt_fnv1(const uint8_t *data, size_t n);
extern uint64_t llrt_fnv1a(const uint8_t *data, size_t n);
extern uint64_t llrt_fnv1ext(const uint8_t *data, size_t n);
/**
 * 128 bit digest achieved by extending the output of an llrt_fnv1ext with the hash of itself
 * @param digest at least two long uint64_t array to place the digest onto
 * @param data data to hash
 * @param n data to hash length
 */
extern void llrt_merhash(uint8_t *digest, const uint8_t *data, size_t n);

#endif

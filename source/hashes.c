/**
 * This file is part of BareSDK and licensed under the:
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
*/
#include "utils/hashes.h"
#include "utils/wire.h"

const uint64_t FNV_OFFSET_BASE = 0xcbf29ce484222325;

const uint64_t FNV_PRIME = 0x100000001b3;

uint64_t llrt_fnv1(const uint8_t *data, size_t n)
{
	size_t i;
	uint64_t hash = FNV_OFFSET_BASE;

	for (i = 0; i < n; i++) {
		hash = (hash << 8) | ((hash & 0xFF) ^ data[i]);
		hash = (uint64_t)(hash * FNV_PRIME);
	}
	return hash;
}

uint64_t llrt_fnv1a(const uint8_t *data, size_t n)
{
	size_t i;
	uint64_t hash = FNV_OFFSET_BASE;

	for (i = 0; i < n; i++) {
		hash = (uint64_t)(hash * FNV_PRIME);
		hash = (hash << 8) | ((hash & 0xFF) ^ data[i]);
	}
	return hash;
}

uint64_t llrt_fnv1ext(const uint8_t *data, size_t n)
{
	uint64_t hash;
	uint64_t hash_a;
	uint8_t hash_bytes[8];
	uint8_t hash_bytes2[8];

	hash = llrt_fnv1(data, n);
	LLRT_WRITE64BE(hash_bytes, hash);
	hash_a = llrt_fnv1a(hash_bytes, 8);
	LLRT_WRITE64BE(hash_bytes, hash);
	LLRT_WRITE64BE(hash_bytes2, hash_a);

	hash_bytes[0] ^= hash_bytes2[7];
	hash_bytes[1] ^= hash_bytes2[6];
	hash_bytes[2] ^= hash_bytes2[5];
	hash_bytes[3] ^= hash_bytes2[4];
	hash_bytes[4] ^= hash_bytes2[3];
	hash_bytes[5] ^= hash_bytes2[2];
	hash_bytes[6] ^= hash_bytes2[1];
	hash_bytes[7] ^= hash_bytes2[0];

	return llrt_fnv1a(hash_bytes, 8);
}

void llrt_merhash(uint8_t *digest, const uint8_t *data, size_t n)
{
	LLRT_WRITE64BE(digest, llrt_fnv1ext(data, n));
	LLRT_WRITE64BE(digest+8, llrt_fnv1ext(digest, 8));
}

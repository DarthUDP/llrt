/**
* This file is part of BareSDK and licensed under the:
* BSD 3-Clause License
* Copyright (c) 2021, Matheus Xavier
* All rights reserved.
*/

#ifndef LLRT_HASHMAP_H_
#define LLRT_HASHMAP_H_

#include "common.h"

/**
 * Set the size of keys, impacts how much memory each entry uses
 */
#define HASHMAP_KEY_LEN 64

extern const size_t HASHMAP_ENTRY_SZ;
#define HASHMAP_SIZE_FOR(N) ((N)*HASHMAP_ENTRY_SZ)

struct llrt_hashmap_entry;

struct llrt_hashmap {
	uint64_t len;
	struct llrt_hashmap_entry *entries;
};

extern int llrt_hashmap_init(struct llrt_hashmap *self, struct llrt_hashmap_entry *inner_buffer, uint64_t len);
extern int llrt_hashmap_insert(struct llrt_hashmap *self, uint8_t *key, void *value);
extern void *llrt_hashmap_get(struct llrt_hashmap *self, uint8_t *key);
extern void llrt_hashmap_set(struct llrt_hashmap *self, void *key, void *value);

#endif

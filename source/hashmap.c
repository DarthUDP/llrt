/**
 * This file is part of BareSDK and licensed under the:
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
*/

#include "data_structures/hashmap.h"
#include "utils/hashes.h"
#include "sys/memory.h"

struct llrt_hashmap_entry {
	uint8_t key[HASHMAP_KEY_LEN];
	void *val;
};

const size_t HASHMAP_ENTRY_SZ = sizeof(struct llrt_hashmap_entry);

int llrt_hashmap_init(struct llrt_hashmap *self, struct llrt_hashmap_entry *inner_buffer, uint64_t len)
{
	if (inner_buffer == NULL)
		return -1;

	self->len = len;
	self->entries = inner_buffer;
	return 0;
}

int llrt_hashmap_insert(struct llrt_hashmap *self, uint8_t *key, void *value)
{
	struct llrt_hashmap_entry entry;
	uint64_t hash;
	uint64_t index;

	hash = llrt_fnv1ext(key, HASHMAP_KEY_LEN);

	index = hash % self->len;

	llrt_memcopy(entry.key, key, HASHMAP_KEY_LEN);
	entry.val = value;

	llrt_memcopy(self->entries + index, &entry, HASHMAP_ENTRY_SZ);
	return 0;
}

extern void *llrt_hashmap_get(struct llrt_hashmap *self, uint8_t *key)
{
	uint64_t hash;
	uint64_t index;

	hash = llrt_fnv1ext(key, HASHMAP_KEY_LEN);

	index = hash % self->len;

	return self->entries[index].val;
}

void llrt_hashmap_set(struct llrt_hashmap *self, void *key, void *value)
{
	struct llrt_hashmap_entry *entry;
	uint64_t hash;
	uint64_t index;

	hash = llrt_fnv1ext(key, HASHMAP_KEY_LEN);

	index = hash % self->len;

	entry = self->entries + index;
	entry->val = value;
}

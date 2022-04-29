/**
* @file llrt_runtime.h
* @brief Provides some manner of runtime facilities, like malloc and free
* @authors Matheus Xavier
* This file is part of BareSDK and licensed under the:
* BSD 3-Clause License
* Copyright (c) 2021, Matheus Xavier
* All rights reserved.
*/

#ifndef LLRT_RT
#define LLRT_RT

#include "data_structures.h"

struct malloc_entry {
	void *base_ptr;
	size_t len;
};

struct malloc_state {
	uint8_t *buff_start;
	size_t buff_len;
	struct llrt_hashmap *registry;
};

#endif

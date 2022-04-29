/**
 * This file is part of BareSDK and licensed under the:
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
*/

#include "data_structures/stack.h"
#include "sys/memory.h"

void stack_init(struct llrt_stack *self, uint8_t *buff, size_t buff_len)
{
	self->data = buff;
	self->stack_size = buff_len;
	self->rw_off = 0ul;
}

int stack_push(struct llrt_stack *self, uint8_t *buff, size_t buff_len)
{
	/* First we check to see if we are not going over the rw_off of the
	 * llrt_stack with this push
	 */
	if (self->rw_off + buff_len > self->stack_size) {
		return -1;
	}

	llrt_memcopy((self->data + self->rw_off), buff, buff_len);
	self->rw_off += buff_len;
	return 0;
}

int stack_pop(struct llrt_stack *self, uint8_t *buff, size_t buff_len)
{
	/* First we check to see if we are not going under the start of the
	 * llrt_stack with this pop */
	if (self->rw_off - buff_len > self->stack_size) {
		return -1;
	}

	self->rw_off -= buff_len;
	llrt_memcopy(buff, (self->data + self->rw_off), buff_len);
	return 0;
}

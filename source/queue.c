/**
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
 */

#include "data_structures/queue.h"
#include "sys/memory.h"

void llrt_queue_init(struct llrt_queue *self, uint8_t *buff, size_t buff_len)
{
	self->data = buff;
	self->queue_size = buff_len;
	self->rw_off = 0;
}

int llrt_queue_add(struct llrt_queue *self, uint8_t *buff, size_t buff_len)
{
	/* First we check to see if we are not going over the rw_off of the
	 * llrt_stack with this push
	 */
	if (self->rw_off + buff_len > self->queue_size)
		return -1;

	llrt_memcopy((self->data + self->rw_off), buff, buff_len);
	return 0;
}

int llrt_queue_head(struct llrt_queue *self, uint8_t *buff, size_t buff_len)
{
	/* first we check if we are not going over the last element in the
	 * llrt_queue with the head operation
	 */
	if (self->rw_off + buff_len > self->queue_size)
		return -1;

	llrt_memcopy(buff, (self->data + self->rw_off), buff_len);
	self->rw_off += buff_len;
	return 0;
}

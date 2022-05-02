/**
* This file is part of BareSDK and licensed under the:
* BSD 3-Clause License
* Copyright (c) 2021, Matheus Xavier
* All rights reserved.
*/

#ifndef KKC_QEUE_H_
#define KKC_QEUE_H_

#include "common.h"

struct llrt_queue {
	uint8_t *data;
	/**
     * The rw_off of the llrt_queue as an offset that satisfies offset < stack_size
     */
	size_t rw_off;
	/**
     * The llrt_stack end in bytes
     */
	size_t queue_size;
};

/**
 * Initializes a llrt_stack using `buff` as a backing buffer
 * @warning Care must be taken to not use after freeing of the `buff`
 * buffer (not applicable to llrt_stack memory)
 * @param self Pointer to a uninitialized llrt_stack struct that is to be initialized
 * @param buff Backing buffer to use with this llrt_stack
 * @param buff_len How long is the backing buffer
 */
extern void llrt_queue_init(struct llrt_queue *self, uint8_t *buff, size_t buff_len);

/**
 * Pushes a value on to the rw_off of the `self` llrt_stack.
 * @param self The llrt_stack to push the value into
 * @param buff A buffer holding the value to push onto the llrt_stack
 * @param buff_len How many bytes to push from buff into the llrt_stack
 * @return -1 if the push would go over the llrt_stack's rw_off 0 otherwise
 */
extern int llrt_queue_add(struct llrt_queue *self, uint8_t *buff, size_t buff_len);

/**
 * Removes a value off the rw_off of the llrt_stack (it will remain in memory however).
 * @param self The llrt_stack to pop the value from
 * @param buff A buffer to put the popped value into
 * @param buff_len How many bytes to pop from the llrt_stack into buff
 * @return -1 if the pop would go under the llrt_stack start 0 otherwise
 */
extern int llrt_queue_head(struct llrt_queue *self, uint8_t *buff, size_t buff_len);
#endif

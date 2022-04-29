/**
* This file is part of BareSDK and licensed under the:
* BSD 3-Clause License
* Copyright (c) 2021, Matheus Xavier
* All rights reserved.
*/

#include "utils/math.h"

uint64_t llrt_exp(uint32_t base, uint16_t exp)
{
	uint64_t i;
	uint64_t r = (uint64_t)base;

	if (exp % 2 == 0 && exp >= 1)
		/** Powers of two make the job easy
		 */
		return r << (exp - 1);

	/** If we can't take the shifting shortcut we do multiplications
	 */
	for (i = 1; i < exp; ++i) {
		r *= base;
	}

	return r;
}

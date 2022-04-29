/**
 * This file is part of BareSDK and licensed under the:
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
*/
#include "sys/memory.h"

void llrt_memcopy(void *dst, void *src, size_t n)
{
	size_t i = 0;

	for (i = 0; i < n; ++i) {
		((uint8_t *)dst)[i] = ((uint8_t *)src)[i];
	}
}

size_t llrt_strcp_s(char *dst, char *src, size_t n)
{
	size_t i = 0;

	while ((dst[i] = src[i]) && i < n)
		i++;
	return i;
}

void llrt_strcp(char *dst, char *src)
{
	while ((*dst = *src)) {
		dst++;
		src++;
	}
}

void llrt_memcopy_dst_mod(void *dst, void *src, size_t n, size_t mod)
{
	size_t i;
	size_t i_mod;

	for (i = 0; i < n; ++i) {
		i_mod = i % mod;
		((uint8_t *)dst)[i] = ((uint8_t *)src)[i_mod];
	}
}

void llrt_memcopy_src_mod(void *dst, void *src, size_t n, size_t mod)
{
	size_t i;
	size_t i_mod;

	for (i = 0; i < n; ++i) {
		i_mod = i % mod;
		((uint8_t *)dst)[i_mod] = ((uint8_t *)src)[i];
	}
}

bool llrt_ct_strcmp_ct(char *a, char *b, size_t n)
{
	size_t i;
	volatile uint8_t res = 0;

	for (i = 0; i < n; i++) {
		res = a[i] ^ b[i];
	}
	return !res;
}

bool llrt_strcmp_s(char *a, char *b, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++) {
		if ((a[i] ^ b[i]) != 0)
			return 0;
	}
	return 1;
}

bool llrt_bytecmp(const uint8_t *a, const uint8_t *b, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++) {
		if ((a[i] ^ b[i]) != 0)
			return 0;
	}
	return 1;
}

size_t llrt_strlen(const char *str, size_t max)
{
	size_t i;

	for (i = 0; i < max; i++) {
		if (str[i] == 0)
			break;
		else
			continue;
	}
	return i;
}

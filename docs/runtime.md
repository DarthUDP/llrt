# Runtime services

This documents the runtime services module, it contains currently memory allocation services

## Memory allocation

All functions related to this functionality are defined in [malloc.h](../headers/sys/malloc.h).

Allocation hash is kept using the global `malloc_gs`, it's value is the `struct malloc_state`.
Defined in the same header.

Selecting a memory end to make available to the allocator:


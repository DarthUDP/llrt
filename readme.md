# LLRt

Low Level Runtime, this library contains code that aids in getting tasks done in very constrained
environments, such as those without an OS or embedded systems where the footprint of
something such as RTOS might be too much.

It also contains some utilities such as datastructures, crc32 and hashing algorithms,
these are bound to be useful in more common use cases.

## Code and project structure:

* The [headers](./headers) directory contains all the required headers to make use of the library.
    * [data_structures](./headers/data_structures) Collection of useful and tested datastructures.
    * [sys](./headers/sys) System and runtime code such as memory allocation and memory management.
    * [utils](./headers/utils) Utilities like hashing, crc32 and data ser/des utilities.
* [data_structures.h](./headers/data_structures.h) Convenience header to easily include all the useful data structures.
* [common.h](./headers/common.h) Convenience header defines `bool` `true` and `false`, also includes headers used by all
  the other code.
* The [source](./source) directory contains the implementations of everything defined in the headers.

# Minimum C version

This should work with any standards compliant C90 compiler that can provide the following headers:

```c
#include <stddef.h>
#include <stdint.h>
```

It is built and tested under clang and gcc, but as stated above should work under any compiler that can provide the
mentioned headers.

It should build under C89, however I did not test this personally.

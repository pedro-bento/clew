# Single file OpenCL Extension Wrangler library

`clew.h` is released as public domain, allowing unrestricted use, modification, and distribution without any restrictions. When applicable to the content created by The Khronos Group Inc., this file complies with the Apache License, Version 2.0.

## Example

```c
#define CL_TARGET_OPENCL_VERSION 300
#define CLEW_IMPLEMENTATION
#include "clew.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    cl_uint cl_err;
    const char *clew_err;

    cl_platform_id platform_id;
    char platform_name[64];

    clew_err = clew_init();
    if (clew_err != NULL) {
        printf("[ERROR] failed to init clew: %s\n", clew_err);
        return EXIT_FAILURE;
    }

    cl_err = clGetPlatformIDs(1, &platform_id, NULL);
    if (cl_err != CL_SUCCESS) {
        printf("[ERROR] failed to get platform IDs: %u\n", cl_err);
        return EXIT_FAILURE;
    }

    cl_err = clGetPlatformInfo(platform_id, CL_PLATFORM_NAME, sizeof(platform_name), platform_name, NULL);
    if (cl_err != CL_SUCCESS) {
        printf("[ERROR] failed to get platform name\n");
        return EXIT_FAILURE;
    }

    printf("platform_name: %s\n", platform_name);

    clew_quit();

    return EXIT_SUCCESS;
}
```

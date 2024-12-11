#include <CL/cl.h>
#include <stdio.h>
#include <stdlib.h>

// OpenCL kernel: Computes the square of each element
const char* kernelSource = R"(
    __kernel void square(__global float* input, __global float* output) {
        int idx = get_global_id(0);
        output[idx] = input[idx] * input[idx];
    }
)";

void checkError(cl_int err, const char* operation) {
    if (err != CL_SUCCESS) {
        fprintf(stderr, "Error during operation '%s': %d\n", operation, err);
        exit(EXIT_FAILURE);
    }
}

int main() {
    // Data setup
    const int DATA_SIZE = 10;
    float input[DATA_SIZE];
    float output[DATA_SIZE];
    for (int i = 0; i < DATA_SIZE; i++) {
        input[i] = (float)i;
    }

    // Platform and device setup
    cl_int err;
    cl_platform_id platform;
    cl_device_id device;

    err = clGetPlatformIDs(1, &platform, NULL);
    checkError

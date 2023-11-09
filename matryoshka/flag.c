#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "base64.h"

#define OFFSET 8

#ifndef ROTATED_FLAG
#error ROTATED_FLAG not defined
#endif

int main() {
    unsigned int inputSize = strlen(ROTATED_FLAG);
    unsigned int outputBufLen = b64d_size(inputSize);
    unsigned char* rotatedFlag = (unsigned char*) malloc(outputBufLen);
    unsigned int flagSize = b64_decode(ROTATED_FLAG, inputSize, rotatedFlag);

    for (int i = 0; i < flagSize; i++) {
        rotatedFlag[i] += OFFSET;
    }

    printf("%s\n", rotatedFlag);

    free(rotatedFlag);

    return 0;
}

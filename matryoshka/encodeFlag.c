#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "base64.h"

#define OFFSET 8

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s flag\n", argv[0]);
        return 1;
    }

    char* flag = argv[1];
    unsigned flagSize = strlen(flag);
    for (int i = 0; i < flagSize; i++) {
        flag[i] -= OFFSET;
    }

    unsigned int outputBufLen = b64e_size(flagSize);
    unsigned char* encodedFlag = (unsigned char*) malloc(outputBufLen);
    b64_encode(flag, flagSize, encodedFlag);

    printf("%s\n", encodedFlag);

    return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "aes.h"
#include "base64.h"

#define OFFSET 5

#ifndef ROTATED_AND_ENCRYPTED_FLAG
#error ROTATED_AND_ENCRYPTED_FLAG not defined
#endif

uint8_t* decrypt(uint8_t* buf, size_t ciphertextLen) {
    uint8_t key[] = { 0x60, 0x3d, 0xeb, 0x10, 0x15, 0xca, 0x71, 0xbe, 0x2b, 0x73, 0xae, 0xf0, 0x85, 0x7d, 0x77, 0x81,
                      0x1f, 0x35, 0x2c, 0x07, 0x3b, 0x61, 0x08, 0xd7, 0x2d, 0x98, 0x10, 0xa3, 0x09, 0x14, 0xdf, 0xf4 };
    uint8_t iv[]  = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };

    struct AES_ctx ctx;

    AES_init_ctx_iv(&ctx, key, iv);
    AES_CBC_decrypt_buffer(&ctx, buf, ciphertextLen);

    return buf;
}

void removeOffset(uint8_t* rotateFlag, unsigned int rotateFlagSize) {
    for (unsigned int i = 0; i < rotateFlagSize; i++) {
        rotateFlag[i] -= OFFSET;
    }
}

int main() {
    sleep(86400);

    unsigned int inputSize = strlen(ROTATED_AND_ENCRYPTED_FLAG);
    unsigned int outputBufLen = b64d_size(inputSize);
    uint8_t* encryptedFlag = (uint8_t*) malloc(outputBufLen);
    unsigned int bufferLen = b64_decode(ROTATED_AND_ENCRYPTED_FLAG, inputSize, encryptedFlag);

    removeOffset(encryptedFlag, bufferLen);
    uint8_t* plaintext = decrypt(encryptedFlag, bufferLen);

    printf("%s\n", plaintext);

    free(encryptedFlag);

    return 0;
}


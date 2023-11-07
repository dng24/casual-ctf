#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "aes.h"
#include "base64.h"

#define OFFSET 5

unsigned int getBufferLen(unsigned int flagLen) {
    unsigned int bufferLen = flagLen;
    if (flagLen % 16 != 0) {
        bufferLen += (16 - (flagLen % 16));
    }
    return bufferLen;
}

uint8_t* copyPlaintextToBuffer(char* plaintext, unsigned int flagLen, unsigned int bufferLen) {
    uint8_t* buf = (uint8_t*) malloc(bufferLen);
    memset(buf, 0, bufferLen);
    strncpy(buf, plaintext, flagLen);
    return buf;
}
    
uint8_t* encrypt(uint8_t* buf, size_t plaintextLen) {
    uint8_t key[] = { 0x60, 0x3d, 0xeb, 0x10, 0x15, 0xca, 0x71, 0xbe, 0x2b, 0x73, 0xae, 0xf0, 0x85, 0x7d, 0x77, 0x81,
                      0x1f, 0x35, 0x2c, 0x07, 0x3b, 0x61, 0x08, 0xd7, 0x2d, 0x98, 0x10, 0xa3, 0x09, 0x14, 0xdf, 0xf4 };
    uint8_t iv[]  = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };

    struct AES_ctx ctx;

    AES_init_ctx_iv(&ctx, key, iv);
    AES_CBC_encrypt_buffer(&ctx, buf, plaintextLen);

    return buf;
}

void addOffset(uint8_t* rotateFlag, unsigned int rotateFlagSize) {
    for (unsigned int i = 0; i < rotateFlagSize; i++) {
        rotateFlag[i] += OFFSET;
    }
}

unsigned char* base64Encode(char* input, unsigned int inputLen) {
    unsigned int outputBufLen = b64e_size(inputLen);
    unsigned char* output = (unsigned char*) malloc(outputBufLen);
    b64_encode(input, inputLen, output);
    return output;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s plaintext\n", argv[0]);
        return 1;
    }

    unsigned int flagLen = strlen(argv[1]);
    unsigned int bufferLen = getBufferLen(flagLen);
    uint8_t* plaintext = copyPlaintextToBuffer(argv[1], flagLen, bufferLen);
    uint8_t* encryptedFlag = encrypt(plaintext, bufferLen);

    addOffset(encryptedFlag, bufferLen);
    unsigned char* base64Ciphertext = base64Encode(encryptedFlag, bufferLen);

    printf("%s\n", base64Ciphertext);

    free(base64Ciphertext);

    return 0;
}

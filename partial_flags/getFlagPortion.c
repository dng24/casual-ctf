#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_FLAG_PARTS 4

int min(int a, int b) {
    return a < b ? a : b;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s flag flag_part_to_print\n", argv[0]);
        return 1;
    }

    char* flag = argv[1];
    int flagLen = strlen(flag);
    if (flagLen < NUM_FLAG_PARTS) {
        printf("ERROR: Flag must be of at least length %d.\n", NUM_FLAG_PARTS);
        return 1;
    }

    int partLen = flagLen / NUM_FLAG_PARTS;
    int flagPartsWithExtraChar = flagLen % NUM_FLAG_PARTS;

    int flagPartToPrint = atoi(argv[2]);
    if (flagPartToPrint >= 0 && flagPartToPrint >= NUM_FLAG_PARTS) {
        printf("ERROR: There are %d flag parts, cannot print %dth flag part (0-based index).\n",
                NUM_FLAG_PARTS, flagPartToPrint);
        return 1;
    }

    int startIdx = flagPartToPrint * partLen + min(flagPartToPrint, flagPartsWithExtraChar);
    int actualPartLen = partLen;
    if (flagPartToPrint < flagPartsWithExtraChar) {
        actualPartLen++;
    }

    char* partToPrint = (char*) malloc(actualPartLen + 1);
    strncpy(partToPrint, flag + startIdx, actualPartLen);
    partToPrint[actualPartLen] = 0;
    printf("%s\n", partToPrint);
    free(partToPrint);
    return 0;
}
    

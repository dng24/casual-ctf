#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 256

// flag is stored in 4 parts so participant must put the flag back together
#ifndef FLAG_PART0
#error FLAG_PART0 not defined
#endif

#ifndef FLAG_PART1
#error FLAG_PART1 not defined
#endif

#ifndef FLAG_PART2
#error FLAG_PART2 not defined
#endif

#ifndef FLAG_PART3
#error FLAG_PART3 not defined
#endif


char* prompt() {
    char* input = (char*) malloc(SIZE);
    printf("what is the password?\n");
    printf(">>> ");
    fflush(stdout);
    scanf("%255s", input);
    return input;
}

char* getFlag() {
    int flag0Len = strlen(FLAG_PART0);
    int flag1Len = strlen(FLAG_PART1);
    int flag2Len = strlen(FLAG_PART2);
    int flag3Len = strlen(FLAG_PART3);

    int flagLen = flag0Len + flag1Len + flag2Len + flag3Len;

    char* flag = (char*) malloc(flagLen + 1);
    
    // the order of the memcpys seem to determine the order that the strings are placed in the
    // binary and therefore affects the order they are printed out when strings is run
    // switch up the order to make challenge a little harder
    memcpy(flag + flag0Len + flag1Len + flag2Len, FLAG_PART3, flag3Len);
    memcpy(flag + flag0Len, FLAG_PART1, flag1Len);
    memcpy(flag, FLAG_PART0, flag0Len);
    memcpy(flag + flag0Len + flag1Len, FLAG_PART2, flag2Len);
    
    flag[flagLen] = 0;

    return flag;
}

int isCorrect(char* input) {
    char* flag = getFlag();
    int ret = !strcmp(flag, input);
    free(flag);
    return ret;
}

int main() {
    printf("only those with the correct password can pass!!\n");

    char* input = prompt();
    if (isCorrect(input)) {
        printf("congrats! you are correct!\n");
    } else {
        printf("try again...\n");
    }

    free(input);

    return 0;
}

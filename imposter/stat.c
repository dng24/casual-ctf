#include <stdio.h>
#include <string.h>

#ifndef SHIFTED_FLAG
#error SHIFTED_FLAG not defined
#endif

int main() {
    for (int i = 0; i < strlen(SHIFTED_FLAG); i++ ) { 
        printf("%c", SHIFTED_FLAG[i] + 2);
    }
    printf("\n");
    return 0;
}


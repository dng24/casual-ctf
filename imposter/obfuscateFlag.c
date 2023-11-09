#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage %s flag_to_scramble", argv[0]);
        return 1;
    }

    char* flag = argv[1];
    for (int i = 0; i < strlen(flag); i++) {
        printf("%c", flag[i] - 2);
    }
    return 0;
}

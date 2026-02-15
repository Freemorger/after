#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

size_t to_secs(char* st) {
    size_t len = strlen(st);
    char lit = st[len-1];
    st[len-1] = '\0'; // for easier atoi
    size_t num = atol(st);

    switch (tolower(lit)) {
        case 's': {
            return num;
        }
        case 'm': {
            return num * 60;
        }
        case 'h': {
            return num * 60 * 60;
        } 
        case 'd': { // hopefully no one gotta use this
            return num * 60 * 60 * 60;
        }
    }

    printf("Format: [number][s/m/h/d]\n");
    exit(1);

    return 0;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: after [time] [command]\n");
        return 1;
    }

    size_t conv = to_secs(argv[1]);

    sleep(conv);

    return execvp(argv[2], &argv[2]);
}

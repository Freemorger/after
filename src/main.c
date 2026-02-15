#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

size_t to_secs(char* st) {
    size_t len = strlen(st);
    char lit = st[len-1];
   
    switch (tolower(lit)) {
        case 's': {
            st[len-1] = '\0'; // for easier atoi
            size_t num = atol(st);
            return num;
        }
        case 'm': {
            st[len-1] = '\0'; // for easier atoi
            size_t num = atol(st);
            return num * 60;
        }
        case 'h': {
            st[len-1] = '\0'; // for easier atoi
            size_t num = atol(st);
            return num * 60 * 60;
        } 
        case 'd': { // does one really need it tho
            st[len-1] = '\0'; // for easier atoi
            size_t num = atol(st);
            return num * 60 * 60 * 60;
        }
        default: {
            size_t num = atol(st);
            return num; // expect seconds otherwise
        }
    }

    return 0; 
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: after [time] [command]\n");
        return 1;
    }

    size_t conv = to_secs(argv[1]);
    time_t until = time(NULL) + conv;

    while (time(NULL) < until) { // so it works even after machine suspend
        sleep(1);
    }

    return execvp(argv[2], &argv[2]);
}

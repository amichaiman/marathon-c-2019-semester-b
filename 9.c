#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N (3)

char* biggest_digit(char* s) {
    char* res = NULL;

    while (*s) {
        if (isdigit(*s) && (!res || *s > *res)) {
            res = s;
        }
        s++;
    }
    return res;
}

char** get_all_biggest_digits(char** strings, int size) {
    char** res = (char**) malloc(size*sizeof(char*));
    int i;

    for (i=0; i<size; i++) {
        res[i] = biggest_digit(strings[i]);
    }
    return res;
}

int main() {
    char* strings[N];
    init(strings);
    char** all_biggest_digits = get_all_biggest_digits(strings, N);
    int i;

    for (i=0; i<N; i++) {
        putchar(all_biggest_digits[i] ? *(all_biggest_digits[i]) : ' ');
    }

    return 0;
}

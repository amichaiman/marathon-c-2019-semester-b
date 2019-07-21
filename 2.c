#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* a */
char* is_sorted(char *s) {
    /* if empty string or one before last element */
    if (!s || !*s || !*(s+1)) {
        return NULL;
    }
    /* if current elem isn't smaller than next,
     * return pointer to next elem */
    return s[0]-'0' >= s[1]-'0' ? s+1 : is_sorted(s+1);
}

/* b */
char* get_numbers_from_input() {
    char c;
    int len = 0;
    char *s;

    puts("Enter string");
    while ((c = getchar()) != EOF) {
        if (isdigit(c)) {
            /* make room for new digit */
            s = (char*) realloc(s, len+2);
            if (!s) {
                printf("ERROR: Couldn't allocate memory in function get_numbers_from_input\n");
                exit(1);
            }
            /* add digit to the end */
            s[len++] = c;
            s[len] = '\0';
        }
    }
    /* run "is_sorted" and replace digit if necessary */
    char *p;
    if ((p = is_sorted(s)) != NULL) {
        *p = *(p-1)+1;
    }
    return s;
}

int main() {
    char *s = get_numbers_from_input();
    printf("%s is%s sorted\n", s, is_sorted(s) == NULL ? "" : "n't");

    return 0;
}


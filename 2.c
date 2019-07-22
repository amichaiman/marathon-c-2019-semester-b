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
    char* s = NULL;
    char* temp;
    char c;
    int len = 0;

    while (scanf("%c", &c) == 1) {// while ((c = getchar()) != EOF)
        if (isdigit(c)) {
            temp = (char*) realloc (s, (len + 2)*sizeof(char));
            if (temp) {
                s = temp;
            } else {
                fprintf(stderr, "ERROR: couldn't allocate memory in get_numbers_from_input\n");
                free(s);
                exit(1);
            }
            s[len++] = c; //add new digit at end
                          //increment len
            s[len] = '\0';
            if (temp = is_sorted(s)) {
                *temp = *(temp-1) + 1;
            }
            puts(s);
        }
    }
    return s;
}

int main() {
    char *s = get_numbers_from_input();
    printf("%s is%s sorted\n", s, is_sorted(s) == NULL ? "" : "n't");

    return 0;
}


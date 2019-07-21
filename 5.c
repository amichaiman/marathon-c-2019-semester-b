#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* input: 2 strings
 * output: 1 if s1 starts with s2, 0 otherwise
 * */
int starts_with(char* s1, char* s2) {
    return strstr(s1, s2) == s1;
}

/* input: sorted array of strings, array size, and a string
 * output: pointer to a string in array that begins with str (not necessarely the first)
 * */
char** find_rec(char** dict, int n, char* str) {
    if (n <= 0) {
        return NULL;
    }
    if (starts_with(dict[n/2], str)) {
        return dict+n/2;
    }
    if (strcmp(dict[n/2], str) > 0) {
        return find_rec(dict, n/2, str);
    } else {
        return find_rec(dict+n/2, n/2, str);
    }
}

/* input: sorted array of strings, array size, and a string
 * output: first string in dict that begins with str
 * algorithm: use find_rec to get a string in the dict that starts
 *            with str, then walk back until first
 * */
char** find(char** dict, int n, char* str) {
    char** res = find_rec(dict, n, str);

    /* walk backwords until first word that starts with str */
    if (res) {
        while (res >= dict && starts_with(*res, str)) {
            res--;
        }
        res++;
    }
    return res;
}

/* input: sorted array of strings, array size, a string,
 *        and a list of numbers representing priorities of each string in dict
 * output: pointer to a string in dict, that starts with str and has the highest prio
 * */
char* best_fit(char** dict, int n, char* str, int *priority) {
    char** res = find(dict, n, str);

    if (!res) {
        return NULL;
    }

    char* best_fit_str = *res;
    int   best_fit_prio = priority[res-dict];

    res++;
    /* check all strings starting with str to find one with highest prio */
    while ((res < dict+n) && starts_with(*res, str)) {
        /* if prio is higher, switch return string */
        if (priority[res-dict] > best_fit_prio) {
            best_fit_prio = priority[res-dict];
            best_fit_str = *res;
        }
        res++;
    }
    return best_fit_str;
}

int main() {
    char **dict = (char**) malloc (5*sizeof(char*));
    int priority[] = {3, 4, 1, 2, 5};

    dict[0] = (char*) malloc ((strlen("five") +1)*sizeof(char));
    dict[1] = (char*) malloc ((strlen("four") +1)*sizeof(char));
    dict[2] = (char*) malloc ((strlen("one")  +1)*sizeof(char));
    dict[3] = (char*) malloc ((strlen("three")+1)*sizeof(char));
    dict[4] = (char*) malloc ((strlen("two")  +1)*sizeof(char));

    strcpy(dict[0], "five");
    strcpy(dict[1], "four");
    strcpy(dict[2], "one");
    strcpy(dict[3], "three");
    strcpy(dict[4], "two");

    /* this is dangerous cause find might return NULL */
    puts(*find(dict, 5, "t"));
    puts(best_fit(dict, 5, "t", priority));

    return 0;
}

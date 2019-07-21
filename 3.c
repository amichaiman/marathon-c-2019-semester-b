#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "in.txt"

/* a */
int longest_series(int* max_val, FILE* stream) {
    int prev_val;
    int cur_val;
    int cur_len = 0;
    int max_len = 0;

    if (fscanf(stream, "%d", &prev_val) == 1) { // in case first number is EOF
        cur_len++;
        while (fscanf(stream, "%d", &cur_val) == 1) {
            if (cur_val == prev_val) {
                cur_len++;
            } else { //end of series
                if (cur_len > max_len) { //check if the series was the longest yet
                    max_len = cur_len;
                    *max_val = prev_val;
                }
                cur_len = 1; //this is the beginning of new series
            }
            prev_val = cur_val;
        }
        if (cur_len > max_len) {
            max_len = cur_len;
            *max_val = prev_val;
        }
    }
    return max_len;
}

/* b */
int main() {
    FILE* file = fopen(FILE_NAME, "r");

    if (!file) {
        fprintf(stderr, "ERROR: couldn't open %s\n", FILE_NAME);
        exit(1);
    }

    int val = -1;
    int len = longest_series(&val, file);

    printf("Longest series: %d. value: %d\n", len, val);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void replace_with_distance_from_zero(int* a, int size) {
    int i;

    for (i=1; i<size; i++) {
        if (a[i] != 0) {
            a[i] = a[i-1] + 1;
        }
    }
    for (i=size-2; i>0; i--) {
        if (a[i] != 0) {
            if (a[i+1] + 1 < a[i]) {
                a[i] = a[i+1] + 1;
            }
        }
    }
}

void print_array(int *a, int size) {
    int i;

    for (i=0; i<size; i++) {
        printf("%d\t", a[i]);
    }
    putchar('\n');
}

int* get_vals(int* p_size) {
    int input;
    int* res = NULL;
    int* tmp;

    *p_size = 0;

    while (scanf("%d", &input) == 1) {
        tmp = (int*) realloc (res, (*p_size + 1)*sizeof(int));
        if (tmp) {
            res = tmp;
            (*p_size)++;
        } else {
            fprintf(stderr, "ERROR: Couldn't allocate memory in function get_vals\n");
            exit(1);
        }
        res[(*p_size)-1] = input > 0;
    }
    return res;
}

int main() {
//    int a[] = {0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1};
    int size;
    int *a = get_vals(&size);
    print_array(a, size);
    replace_with_distance_from_zero(a, size);
    print_array(a, size);
    return 0;
}

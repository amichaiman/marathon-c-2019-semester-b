#include <stdio.h>

/* a */
int is_biggest(int *a, int *p) {
    while (a < p) {
        if (*a >= *p) {
            return 0;
        }
        a++;
    }
    return 1;
}

/* b */
int count_bigger(int *a, int size) {
    if (size <= 0) {
        return 0;
    }

    if (size == 1) {
        return 1;
    }

    return is_biggest(a, a+(size-1)) + count_bigger(a, size-1);
}

/* c */
int is_sorted(int *a, int size) {
    return count_bigger(a, size) == size;
}

void print_array(int *a, int size) {
    int i;

    for (i=0; i<size; i++) {
        printf("%d\t", a[i]);
    }
    putchar('\n');
}

int main() {
    int a[] = {1, 3, 4, 2, 3, 8, 5};
    print_array(a, sizeof(a)/sizeof(*a));
    printf("Number elements bigger than all elements to their left: %d\n",
            count_bigger(a, sizeof(a)/sizeof(*a)));
    printf("The array is%s sorted\n",
            is_sorted(a, sizeof(a)/sizeof(*a)) ? "" : "n't");
    return 0;
}


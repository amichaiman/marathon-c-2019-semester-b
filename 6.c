#include <stdio.h>
#include <stdlib.h>

void print_array(int *a, int size) {
    int i;

    for (i=0; i<size; i++) {
        printf("%d\t", a[i]);
    }
    putchar('\n');
}

int are_equal_rec(int *a, int *b, int size_a, int size_b) {
    if (size_a == 0 && size_b == 0) {
        return 1;
    }
    if (!size_a || !size_b || *a != *b) {
        return 0;
    }
    return are_equal_rec(a+1, b+1, size_a-1, size_b-1);
}

int are_equal_iter(int *a, int *b, int size_a, int size_b) {
    if (size_a != size_b) {
        return 0;
    }
    int i;
    for (i=0; i<size_a; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

int count_equal(int **a, int a_size, int *test, int test_size) {
    int i, count = 0;
    for (i=0; i<a_size; i++) {
        if (are_equal_rec(a[i], test, test_size, test_size)) {
            count++;
        }
    }
    return count;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {1, 2, 3, 4, 5};
    int c[] = {3, 2, 3, 4, 5};
    int **nums = (int**) malloc(3*sizeof(int*));
    nums[0] = a;
    nums[1] = b;
    nums[2] = c;

    puts("=====================================");
    puts("========== recursive check ==========");
    puts("=====================================");
    puts("The Arrays:");
    print_array(a, sizeof(a)/sizeof(*a));
    print_array(b, sizeof(b)/sizeof(*b));
    puts(are_equal_rec(a, b, sizeof(a)/sizeof(*a), sizeof(b)/sizeof(*b)) ? "Are equal!" : "Aren't equal!");

    puts("-------------------------------------");

    puts("The Arrays:");
    print_array(a, sizeof(a)/sizeof(*a));
    print_array(c, sizeof(c)/sizeof(*c));
    puts(are_equal_rec(a, c, sizeof(a)/sizeof(*a), sizeof(c)/sizeof(*c)) ? "Are equal!" : "Aren't equal!");

    puts("=====================================");
    puts("========== iterative check ==========");
    puts("=====================================");
    puts("The Arrays:");
    print_array(a, sizeof(a)/sizeof(*a));
    print_array(b, sizeof(b)/sizeof(*b));
    puts(are_equal_iter(a, b, sizeof(a)/sizeof(*a), sizeof(b)/sizeof(*b)) ? "Are equal!" : "Aren't equal!");

    puts("-------------------------------------");

    puts("The Arrays:");
    print_array(a, sizeof(a)/sizeof(*a));
    print_array(c, sizeof(c)/sizeof(*c));
    puts(are_equal_iter(a, c, sizeof(a)/sizeof(*a), sizeof(c)/sizeof(*c)) ? "Are equal!" : "Aren't equal!");

    puts("=====================================");
    puts("Number of arrays equal to the array:");
    puts("=====================================");
    print_array(a, sizeof(a)/sizeof(*a));
    printf("Is %d\n", count_equal(nums, 3, a, sizeof(a)/sizeof(*a)));
    return 0;
}

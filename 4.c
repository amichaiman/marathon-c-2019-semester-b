#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N (3)
#define M (5)

int get_max_in_row(int* a) {
    int i, index_max = 0;
    for (i=1; i<M; i++) {
        if (a[i] > a[index_max]) {
            index_max = i;
        }
    }
    return index_max;
}

int get_max_in_col(int a[][M], int col) {
    int i, index_max = 0;

    for (i=1; i<N; i++) {
        if (a[i][col] > a[index_max][col]) {
            index_max = i;
        }
    }
    return index_max;
}

/* a */
// max_rows {2, 0, 1}        //returns from function
// max_cols {1, 2, 0, 1, 2}  //returns from output param
int* max_rows_cols(int a[][M], int** p_max_cols) {
    int i;
    int* max_rows = (int*) malloc (N*sizeof(int));
    *p_max_cols   = (int*) malloc (M*sizeof(int));

    /* fill max_row array */
    for (i=0; i<N; i++) {
        max_rows[i] = get_max_in_row(a[i]);
    }

    /* fill max_col array */
    for (i=0; i<M; i++) {
        (*p_max_cols)[i] = get_max_in_col(a, i);
    }
    return max_rows;
}

/* b */
void print_array(int *a, int size) {
    int i;

    for (i=0; i<size; i++) {
        printf("%d\t", a[i]);
    }
    putchar('\n');
}

int main() {
    int a[N][M] = {{2, 5, 6, 4, 3},
                   {8, 2, 3, 6, 4},
                   {5, 7, 4, 1, 5}};

    int *max_cols, *max_rows;
    max_rows = max_rows_cols(a, &max_cols);
    print_array(max_rows, N);
    print_array(max_cols, M);
    free(max_cols);
    free(max_rows);
    return 0;
}


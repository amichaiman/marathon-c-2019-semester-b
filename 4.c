#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N (3)
#define M (5)

/* a */
int* max_rows_cols(int a[][M], int **max_cols) {
    int i, j;
    int *max_rows = (int*) calloc(N, sizeof(int));
    *max_cols = (int*) calloc(M, sizeof(int));

    /* fill max_rows */
    for (i=0; i<N; i++) {
        for (j=0; j<M; j++) {
            if (a[i][j] > a[i][max_rows[i]]) {
                max_rows[i] = j;
            }
        }
    }

    /* fill max_cols */
    for (i=0; i<M; i++) {
        for (j=0; j<N; j++) {
            if (a[j][i] > a[(*max_cols)[i]][i]) {
                (*max_cols)[i] = j;
            }
        }
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


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define CORE 4
#define MAX 4

pthread_t thread[CORE * 2];

int mat_A[MAX][MAX], mat_B[MAX][MAX], sum[MAX][MAX], sub[MAX][MAX];

void* addition(void* arg) {
    int i, j;
    int core = (int)arg;
    for (i = core * MAX / 4; i < (core + 1) * MAX / 4; i++) {
        for (j = 0; j < MAX; j++) {
            sum[i][j] = mat_A[i][j] + mat_B[i][j];
        }
    }
}

int main() {
    int i, j, step = 0;
    for (i = 0; i < MAX; i++)  {
        for (j = 0; j < MAX; j++)  {
            mat_A[i][j] = rand() % 10;
            mat_B[i][j] = rand() % 10;
        }
    }
    printf("\nMatrice A:\n");
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            printf("%d ", mat_A[i][j]);
        }
        printf("\n");
    }
    printf("\nMatrice B:\n");
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            printf("%d ", mat_B[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < CORE; i++) {
        pthread_create(&thread[i], NULL, &addition, (void*)step);
        step++;
    }
    for (i = 0; i < CORE * 2; i++) {
        pthread_join(thread[i], NULL);
    }
    printf("somme de la matrice a et b:\n");
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            printf("%d   ", sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}

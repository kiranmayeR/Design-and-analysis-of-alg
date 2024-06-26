#include <stdio.h>
#include <stdlib.h>

#define N 2

void add(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtract(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassen(int A[N][N], int B[N][N], int C[N][N]) {
    int M1[N][N], M2[N][N], M3[N][N], M4[N][N], M5[N][N], M6[N][N], M7[N][N];
    int tempA[N][N], tempB[N][N];

    // M1 = (A11 + A22) * (B11 + B22)
    add(A, A, tempA);
    add(B, B, tempB);
    strassen(tempA, tempB, M1);

    // M2 = (A21 + A22) * B11
    add(A, A, tempA);
    strassen(tempA, B, M2);

    // M3 = A11 * (B12 - B22)
    subtract(B, B, tempB);
    strassen(A, tempB, M3);

    // M4 = A22 * (B21 - B11)
    subtract(B, B, tempB);
    strassen(A, tempB, M4);

    // M5 = (A11 + A12) * B22
    add(A, A, tempA);
    strassen(tempA, B, M5);

    // M6 = (A21 - A11) * (B11 + B12)
    subtract(A, A, tempA);
    add(B, B, tempB);
    strassen(tempA, tempB, M6);

    // M7 = (A12 - A22) * (B21 + B22)
    subtract(A, A, tempA);
    add(B, B, tempB);
    strassen(tempA, tempB, M7);

    // C11 = M1 + M4 - M5 + M7
    add(M1, M4, tempA);
    subtract(tempA, M5, tempB);
    add(tempB, M7, C);

    // C12 = M3 + M5
    add(M3, M5, C);

    // C21 = M2 + M4
    add(M2, M4, C);

    // C22 = M1 - M2 + M3 + M6
    subtract(M1, M2, tempA);
    add(tempA, M3, tempB);
    add(tempB, M6, C);
}

int main() {
    int A[N][N] = {{1, 2}, {3, 4}};
    int B[N][N] = {{5, 6}, {7, 8}};
    int C[N][N];

    strassen(A, B, C);

    printf("Result matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}

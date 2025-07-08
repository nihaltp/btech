/*
  Write a C program to perform matrix multiplication.
  
  Made by: NIHAL T P
  GitHub: https://github.com/nihaltp
  LinkedIn: https://www.linkedin.com/in/nihal-tp/
*/

#include <stdio.h>
int main() {
    int M, N, P, Q;
    
    printf("Enter dimensions of first matrix (M N): ");
    scanf("%d %d", &M, &N);
    printf("Enter dimensions of second matrix (P Q): ");
    scanf("%d %d", &P, &Q);
    
    if (N != P) {
        printf("Matrix multiplication not possible. Number of columns in first matrix must equal number of rows in second matrix.\n");
        return 1;
    }
    
    if (M < 3 || N < 3 || P < 3 || Q < 3) {
        printf("All dimensions must be at least 3.\n");
        return 1;
    }
    
    int A[M][N];
    printf("Enter the elements of Matrix A (%d X %d): \n", M, N);
    for (int i = 0; i < M; i++) {
        printf("\t");
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    
    int B[P][Q];
    printf("Enter the elements of Matrix B (%d X %d): \n", P, Q);
    for (int i = 0; i < P; i++) {
        printf("\t");
        for (int j = 0; j < Q; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    
    // The resultant matrix C will have dimensions M X Q
    int C[M][Q];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < Q; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    printf("Result of Matrix Multiplication is: \n");
    for (int i = 0; i < M; i++) {
        printf("\t");
        for (int j = 0; j < Q; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

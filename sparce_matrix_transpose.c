/*
  Write a C program to find transpose of a sparse matrix.
  
  Made by: NIHAL T P
  GitHub: https://github.com/nihaltp
  LinkedIn: https://www.linkedin.com/in/nihal-tp/
*/

#include <stdio.h>

struct sparse_matrix {
    int row; // Row
    int col; // Column
    int val; // Value
};

void arrayPrint(struct sparse_matrix a[], char text[]) {
    printf("\033[92m\n%s\n", text);
    printf("Row\tColumn\tValue\n");
    printf("%d\t%d\t%d\n", a[0].row, a[0].col, a[0].val);
    printf("-\t-\t-\n");
    for (int i = 1; i <= a[0].val; i++) {
        printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].val);
    }
    printf("\033[0m");
}

void matrixPrint(struct sparse_matrix a[], char text[]) {
    printf("\033[92m%s\n", text);
    int i = 1, j = 0;
    if (a[0].row == 0 || a[0].col == 0) {
        printf("Empty Matrix\n");
        return;
    }
    while (i <= a[0].val) {
        if (j++ < (a[i].row * a[0].col) + a[i].col) {
            printf("0 ");
        } else {
            printf("%d ", a[i++].val);
        }
        if (j % a[0].col == 0) {
            printf("\n");
        }
    }
    printf("\033[0m");
}

int main () {
    int m, n;
    
    printf("\033[92mEnter dimensions of matrices (M N): \033[94m");
    scanf("%d %d", &m, &n);
    
    int A[m][n];
    printf("\033[92mEnter the elements of Matrix A (%d X %d): \n\033[94m", m, n);
    for (int i = 0; i < m; i++) {
        printf("\t");
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    
    struct sparse_matrix s[(m * n) + 1]; // Array to store sparse matrix elements
    int k = 1; // Index for the sparse matrix array
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] != 0) {
                s[k].row = i;
                s[k].col = j;
                s[k].val = A[i][j];
                k++;
            }
        }
    }
    
    s[0].row = m;
    s[0].col = n;
    s[0].val = k - 1;
    
    arrayPrint(s, "Sparse Matrix Representation:");
    
    struct sparse_matrix t[(m * n) + 1]; // Array to store transpose of matrix
    k = 1; // Index for the transpose array
    
    for (int i = 0; i < s[0].col + 1; i++) {
        for (int j = 1; j <= s[0].val; j++) {
            if (s[j].col == i) {
                t[k].row = s[j].col;
                t[k].col = s[j].row;
                t[k].val = s[j].val;
                k++;
            }
        }
    }
    
    t[0].row = s[0].col;
    t[0].col = s[0].row;
    t[0].val = s[0].val;
    
    arrayPrint(t, "Transpose Representation:");
    matrixPrint(t, "Transpose Matrix:");
    
    return 0;
}

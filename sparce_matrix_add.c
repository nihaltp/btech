/*
    Write a C program to find sum of two sparse matrices.
    
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

void findSparse(int a, int b, int A[a][b], struct sparse_matrix s[]) {
    int k = 1; // Index for the sparse matrix array
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (A[i][j] != 0) {
                s[k].row = i;
                s[k].col = j;
                s[k].val = A[i][j];
                k++;
            }
        }
    }
    
    s[0].row = a;
    s[0].col = b;
    s[0].val = k - 1;
}

void arrayPrint(struct sparse_matrix a[], char text[]) {
    printf("\033[92m%s\n", text);
    printf("Row\tColumn\tValue\n");
    printf("%d\t%d\t%d\n", a[0].row, a[0].col, a[0].val);
    printf("-\t-\t-\n");
    for (int i = 1; i <= a[0].val; i++) {
        printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].val);
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
    
    int B[m][n];
    printf("\033[92mEnter the elements of Matrix B (%d X %d): \n\033[94m", m, n);
    for (int i = 0; i < m; i++) {
        printf("\t");
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    
    struct sparse_matrix p[(m * n) + 1]; // Array to store sparse matrix A
    struct sparse_matrix q[(m * n) + 1]; // Array to store sparse matrix B
    struct sparse_matrix r[(m * n) + 1]; // Array to store resultant sparse matrix
    
    findSparse(m, n, A, p);
    arrayPrint(p, "Sparse Matrix Representation of A:");
    findSparse(m, n, B, q);
    arrayPrint(q, "\nSparse Matrix Representation of B:");
    
    int i = 1, j = 1; // To track the index of sparse matrices A and B
    int k = 1; // To track the index of resultant sparse matrix
    
    while (i <= p[0].val && j <= q[0].val) {
        if (p[i].row == q[j].row) {
            if (p[i].col == q[j].col) {
                r[k].row = p[i].row;
                r[k].col = p[i].col;
                r[k++].val = p[i++].val + q[j++].val;
            }
            else if (p[i].col < q[j].col) {
                r[k].row = p[i].row;
                r[k].col = p[i].col;
                r[k++].val = p[i++].val;
            }
            else if (p[i].col > q[j].col) {
                r[k].row = q[j].row;
                r[k].col = q[j].col;
                r[k++].val = q[j++].val;
            }
        }
        else if (p[i].row < q[j].row) {
            r[k].row = p[i].row;
            r[k].col = p[i].col;
            r[k++].val = p[i++].val;
        }
        else if (p[i].row > q[j].row) {
            r[k].row = q[j].row;
            r[k].col = q[j].col;
            r[k++].val = q[j++].val;
        }
    }
    
    while (i <= p[0].val) {
        r[k].row = p[i].row;
        r[k].col = p[i].col;
        r[k++].val = p[i++].val;
    }
    
    while (j <= q[0].val) {
        r[k].row = q[j].row;
        r[k].col = q[j].col;
        r[k++].val = q[j++].val;
    }
    
    r[0].row = m;
    r[0].col = n;
    r[0].val = k - 1;
    
    arrayPrint(r, "\nResultant C:");
    
    return 0;
}

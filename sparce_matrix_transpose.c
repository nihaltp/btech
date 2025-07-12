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

int m = 3; // Number of rows in the sparse matrix
int n = 4; // Number of columns in the sparse matrix

int A[3][4] = {
    {0, 10, 0, 20},
    {0, 0, 30, 0},
    {0, 40, 0, 50}
};

void arrayPrint(struct sparse_matrix a[], char text[]) {
    printf("\033[92m%s\n", text);
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < a[0].val; i++) {
        printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].val);
    }
    printf("\033[0m");
}

int main () {
    struct sparse_matrix s[6]; // Array to store sparse matrix elements
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
    
    struct sparse_matrix t[6]; // Array to store transpose of matrix
    k = 1; // Index for the transpose array
    
    for (int i = 0; i < s[0].col + 1; i++) {
        for (int j = 0; j < s[0].val; j++) {
            if (s[j + 1].col == i) {
                t[k].row = s[j + 1].col;
                t[k].col = s[j + 1].row;
                t[k].val = s[j + 1].val;
                k++;
            }
        }
    }
    
    t[0].row = s[0].col;
    t[0].col = s[0].row;
    t[0].val = s[0].val;
    
    arrayPrint(t, "Transpose Representation:");
    
    return 0;
}

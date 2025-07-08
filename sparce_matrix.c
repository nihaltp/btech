/*
  Write a C program to convert a sparse matrix into a list to save storage.
  
  Made by: NIHAL T P
  GitHub: https://github.com/nihaltp
  LinkedIn: https://www.linkedin.com/in/nihal-tp/
*/

#include <stdio.h>

struct sparse_matrix {
    int row;
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
    
    printf("Sparse Matrix Representation:\n");
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < k; i++) {
        printf("%d\t%d\t%d\n", s[i].row, s[i].col, s[i].val);
    }
    return 0;
}

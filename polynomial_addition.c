/*
  Write a C program to perform polynomial addition.
  
  Made by: NIHAL T P
  GitHub: https://github.com/nihaltp
  LinkedIn: https://www.linkedin.com/in/nihal-tp/
*/

#include <stdio.h>

struct polynomial {
    int cof; // Coefficient
    int exp; // Exponent
};

int main() {
    int m, n;
    
    printf("\033[92mEnter the number of terms of first polynomial: ");
    scanf("%d", &m);
    printf("\nEnter the number of terms of second polynomial: ");
    scanf("%d", &n);
    
    if (m <= 0 || n <= 0) {
        printf("\nThe number of exponents must be more than or equal to 1\033[0m");
        return 0;
    }
    
    struct polynomial p[m];
    struct polynomial q[n];
    struct polynomial r[m + n];
    
    for (int i = 0; i < m; i++) {
        printf("\nEnter the coefficient of polynomial1[%d]: ", i + 1);
        scanf("%d", &p[i].cof);
        printf("Enter the exponent of polynomial1[%d]: ", i + 1);
        scanf("%d", &p[i].exp);
    }
    
    for (int i = 0; i < n; i++) {
        printf("\nEnter the coefficient of polynomial2[%d]: ", i + 1);
        scanf("%d", &q[i].cof);
        printf("Enter the exponent of polynomial2[%d]: ", i + 1);
        scanf("%d", &q[i].exp);
    }
    
    int i = 0, j = 0, k = 0;
    
    while (i < m && j < n) {
        if (p[i].exp == q[j].exp) {
            r[k].exp = p[i].exp;
            r[k].cof = p[i].cof + q[j].cof;
            i++; j++; k++;
        }
        
        else if (p[i].exp > q[j].exp) {
            r[k].exp = p[i].exp;
            r[k].cof = p[i].cof;
            i++; k++;
        }
        
        else if (p[i].exp < q[j].exp) {
            r[k].exp = q[j].exp;
            r[k].cof = q[j].cof;
            j++; k++;
        }
    }
    
    while (i < m) {
        r[k].exp = p[i].exp;
        r[k].cof = p[i].cof;
        i++; k++;
    }
    
    while (j < n) {
        r[k].exp = q[j].exp;
        r[k].cof = q[j].cof;
        j++; k++;
    }
    
    printf("\n-----RESULTANT POLYNOMIAL-----\n");
    for(int i = 0; i < k; i++) {
        if (r[i].cof != 0) {
            printf("%dx^%d", r[i].cof, r[i].exp);
            if (i < k - 1) {
                printf(" + ");
            }
        }
    }
    
    printf("\n\n\033[0m");
    
    return 0;
}

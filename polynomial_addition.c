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

void sort(const int n, struct polynomial s[n]) {
    struct polynomial t;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j + 1].exp > s[j].exp) {
                t = s[j + 1];
                s[j + 1] = s[j];
                s[j] = t;
            }
        }
    }
}

int main() {
    int m, n;
    
    printf("\033[92mEnter the number of terms of first polynomial: \033[94m");
    scanf("%d", &m);
    printf("\n\033[92mEnter the number of terms of second polynomial: \033[94m");
    scanf("%d", &n);
    
    if (m <= 0 || n <= 0) {
        printf("\nThe number of exponents must be more than or equal to 1\033[0m");
        return 0;
    }
    
    struct polynomial p[m];
    struct polynomial q[n];
    struct polynomial r[m + n];
    
    printf("\n\033[91mEnter the parts of polynomial 1 and polynomial 2 in the format: coefficient exponent");
    printf("\ne.g., for 2x^3, enter '2 3'\033[92m\n");
    
    printf("\n\033[93m-----INPUT POLYNOMIALS-----\033[92m\n");
    printf("\n");
    for (int i = 0; i < m; i++) {
        printf("\033[92mEnter the part %d of polynomial 1: \033[94m", i + 1);
        scanf("%d %d", &p[i].cof, &p[i].exp);
    }
    
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("\033[92mEnter the part %d of polynomial 2: \033[94m", i + 1);
        scanf("%d %d", &q[i].cof, &q[i].exp);
    }
    
    sort(m, p);
    sort(n, q);
    
    int i = 0, j = 0, k = 0;
    
    while (i < m && j < n) {
        if (p[i].exp == q[j].exp) {
            r[k].exp = p[i].exp;
            r[k].cof = p[i].cof + q[j].cof;
            i++; j++; k++;
        }
        
        else if (p[i].exp > q[j].exp) {
            r[k++] = p[i++];
        }
        
        else if (p[i].exp < q[j].exp) {
            r[k++] = q[j++];
        }
    }
    
    while (i < m) {
        r[k++] = p[i++];
    }
    
    while (j < n) {
        r[k++] = q[j++];
    }
    
    printf("\n\033[93m-----RESULTANT POLYNOMIAL-----\033[92m\n");
    for(int i = 0; i < k; i++) {
        if (r[i].cof != 0) {
            printf("%dx^%d", r[i].cof, r[i].exp);
            if (r[i + 1].cof  > 0 && i < k - 1) {
                printf(" +");
            } else if (i < k - 1) {
                printf(" ");
            }
        }
    }
    
    printf("\n\n\033[0m");
    
    return 0;
}

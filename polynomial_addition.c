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

struct polynomial p[] = {{4, 5}, {3, 4}, {1, 2}};
struct polynomial q[] = {{3, 4}, {4, 3}, {2, 2}, {5, 1}, {3, 0}};

const int m = 3; // Number of terms in polynomial p
const int n = 5; // Number of terms in polynomial q

int main() {
    struct polynomial r[m + n];
    int i = 0, j = 0, k = 0;
    
    while (i < m && j < n) {
        if (p[i].exp == q[j].exp) {
            r[k].exp = p[i].exp;
            r[k].cof = p[i].cof + q[j].cof;
            i++; j++; k++;
        }
        
        if (p[i].exp > q[j].exp) {
            r[k].exp = p[i].exp;
            r[k].cof = p[i].cof;
            i++; k++;
        }
        
        if (p[i].exp < q[j].exp) {
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
    
    printf("\nResultant Polynomial: ");
    for (int i = 0; i < k; i++) {
        if (i == k - 1) {
            printf("%dx^%d", r[i].cof, r[i].exp);
        } else {
            printf("%dx^%d + ", r[i].cof, r[i].exp);
        }
    }
}

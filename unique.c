/*
    Write a program in C to print all unique elements in an array.
    
    Made by: NIHAL T P
    GitHub: https://github.com/nihaltp
    LinkedIn: https://www.linkedin.com/in/nihal-tp/
*/


#include <stdio.h>

int main() {
    int num;
    printf("Enter the number of elements in Array: ");
    scanf("%d", &num);
    
    int numArray[num];
    printf("Enter the values of array: \n\t");
    
    for (int i = 0; i < num; i++) {
        scanf("%d ", &numArray[i]);
    }
    
    int uniqueArray[num];
    int k = 0;
    int j = 0;
    int isUnique = 1;
    
    for (int i = 0; i < num; i++) {
        int isUnique = 1;
        for (j = 0; j < k; j++) {
            printf("i: %d, j: %d\n", i, j);
            if (uniqueArray[j] == numArray[i]) {
                isUnique = 0;
                break;
            }
        }
        if (isUnique) {
            uniqueArray[k++] = numArray[i];
        }
    }
    
    printf("Unique elements: ");
    for (int i = 0; i < k; i++) {
        printf("%d, ", uniqueArray[i]);
    }
}

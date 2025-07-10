#include <stdio.h>

int main() {
    int num;
    int limit;
    
    printf("\033[92mEnter the number for multiplication table: ");
    scanf("%d", &num);
    
    printf("Enter the limit for multiplication table: ");
    scanf("%d", &limit);
    
    printf("\nMultiplication Table of %d\n", num);
    for(int i = 1; i <= limit; i++){
        printf("%d x %d = %d\n",num, i, num * i);
    }
    printf("\033[0m");
    return 0;
}

/*
    Write a program in C to count the frequency of each element of an array.
    
    Made by: NIHAL T P
    GitHub: https://github.com/nihaltp
    LinkedIn: https://www.linkedin.com/in/nihal-tp/
*/


#include <stdio.h>

struct map{
    int num;
    int count;
};

void sort (int num, int array[num]) {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    int num; // number of elements in numArray
    printf("Enter the number of elements in Array: ");
    scanf("%d", &num);
    
    int numArray[num];
    printf("Enter the values of array: \n\t");
    for (int i = 0; i < num; i++) {
        scanf("%d", &numArray[i]);
    }
    
    sort(num, numArray);
    printf("\nSorted array: ");
    for (int i = 0; i < num; i++) {
        printf("%d, ", numArray[i]);
    }
    
    int lastNum = numArray[num - 1]; // the largest number
    struct map numMap[lastNum];
    int n = 0; // tracker for numMap
    int k = numArray[0]; // assign the smallest number
    
    numMap[0].num = numArray[0];
    numMap[0].count = 0;
    
    for (int j = 0; j  < num;) {
        if (numArray[j] == k) {
            // if the number is same, increment the counter
            numMap[n].count++;
            j++;
        }
        else if (k < numArray[j]) {
            // if the number in array has passed the tracker
            // increment the tracker, move to the next element
            do {
                k++;
            } while (k < numArray[j]);
            
            numMap[++n].num = k;
            numMap[n].count = 0;
        }
    }
    
    for (int i = 0; i <= n; i++) {
        printf("\n%d: num: %d\tcount: %d ", i, numMap[i].num, numMap[i].count);
    }
}

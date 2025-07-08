/*
  Write a C program to rank students based on their total mark from diffrent subjects.
  
  Made by: NIHAL T P
  GitHub: https://github.com/nihaltp
  LinkedIn: https://www.linkedin.com/in/nihal-tp/
*/

#include <stdio.h>
#include <stdbool.h>

struct student {
    char name[20];
    int totalMark;
};

int main() {
    int num; // Number of students
    printf("Enter the number of students: ");
    scanf("%d", &num);
    
    if (num < 1) {
        printf("Number of students should be atleast 1.\n");
        return 1;
    }
    
    struct student s[num];
    
    int numSub; // Number of subjects
    printf("\nEnter the number of subjects: ");
    scanf("%d", &numSub);
    
    if (numSub < 1) {
        printf("Number of subjects should be atleast 1.\n");
        return 1;
    }
    
    // Sort the students in descending order of totalMark
    for (int i = 0; i < num; i++) {
        printf("\nEnter the name of student[%d]: ", i + 1);
        scanf("%s", s[i].name);
        
        s[i].totalMark = 0;
        
        for (int j = 0; j < numSub; j++) {
            printf("Enter the mark of subject[%d]: ", j + 1);
            int mark;
            scanf("%d", &mark);
            s[i].totalMark += mark;
        }
    }
    
    for (int i = 0; i < num - 1; i++) {
        bool swap = false;
        for (int j = 0; j < num - i -1; j++) {
            if (s[j].totalMark < s[j + 1].totalMark) {
                struct student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
                swap = true;
            }
        }
        if (!swap) {
            break;
        }
    }
    
    for (int i = 0; i < num; i++) {
        printf("\nRank %d: %s \ttotal mark %d", i + 1, s[i].name, s[i].totalMark);
    }
    
    return 0;
}

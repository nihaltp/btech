/*
    Write a C program to convert infix equations to postfix.
    
    Made by: NIHAL T P
    GitHub: https://github.com/nihaltp
    LinkedIn: https://www.linkedin.com/in/nihal-tp/
*/

#include <stdio.h>

struct map {
    char symbol;
    int ICP; // Incoming
    int ISP; // In-stack
};

struct map symbols[6] = {
    {'+', 1, 2},
    {'-', 1, 2},
    {'*', 3, 4},
    {'/', 3, 4},
    {'^', 6, 5},
    {'(', 7, 0}
};

int value(char s, char v) {
    for (int i = 0; i < 6; i++) {
        if (symbols[i].symbol == s) {
            if (v == 'c') { // incoming
                return symbols[i].ICP;
            }
            else if (v == 's') { // in stack
                return symbols[i].ISP;
            }
        }
    }
    return -1;
}

int main() {
    char infix[100];
    
    printf("\033[92mEnter the equation, Press enter to submit\n\t\033[94m");
    fgets(infix, sizeof(infix), stdin);
    
    char postfix[100];
    char stack[100];
    int i = 0; // infix pointer
    int j = 0; // postfix pointer
    int k = 1; // stack pointer
    
    stack[0] = '('; // Initialize stack with '('
    
    while (infix[i] != '\n') {
        // skip spaces
        if (infix[i] == ' ') {
            postfix[j++] = ' ';
            i++;
            continue;
        }
        // if it is a valid
        else if (infix[i] >= '0' && infix[i] <= '9' || infix[i] >= 'A' && infix[i] <= 'Z' || infix[i] >= 'a' && infix[i] <= 'z') {
            postfix[j++] = infix[i++];
        }
        // if it is a closing paranthesis, pop everything in stack
        else if (infix[i] == ')') {
            do {
                postfix[j++] = ' ';
                postfix[j++] = stack[--k];
            }
            while (stack[k] != '(');
            i++; j--;
        }
        // if it is a operator, check if it should go to the stack
        else if (value(stack[k - 1], 's') < value(infix[i], 'c')) {
            stack[k++] = infix[i++];
        }
        else {
            // pop everything in stack until the current operator can be appended into the stack
            while (value(stack[k - 1], 's') > value(infix[i], 's')) {
                postfix[j++] = ' ';
                postfix[j++] = stack[--k];
            }
            stack[k++] = infix[i++];
        }
    }
    
    // pop remaining operators from stack
    while (k > 0) {
        postfix[j++] = ' ';
        postfix[j++] = stack[--k];
    }
    
    // mark the end of string
    postfix[--j] = '\0';
    
    // Remove extra spaces
    for (int l = 0; l < j; l++) {
        if (postfix[l] == ' ' && postfix[l + 1] == ' ') {
            for (int m = l; m < j - 1; m++) {
                postfix[m] = postfix[m + 1];
            }
            j--;
            l--;
        }
    }
    
    printf("\n\033[92mInfix: \033[93m%s", infix);
    printf("\n\033[92mPostfix: \033[93m%s\033[0m\n", postfix);
    
    return 0;
}

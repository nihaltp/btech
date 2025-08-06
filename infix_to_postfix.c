/*
    Write a C program to convert infix equations to postfix, then evaluate the postfix equation.
    
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

int power(int base, int exp) {
    if (exp == 0) return 1;
    
    for (int i = 0; i < exp - 1; i++) {
        base *= base;
    }
    return base;
}

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
            postfix[j++] = ' '; // Add a space for sepration
            stack[k++] = infix[i++];
        }
        else {
            // Add a space for sepration
            postfix[j++] = ' ';
            
            // pop everything in stack until the current operator can be appended into the stack
            while (value(stack[k - 1], 's') >= value(infix[i], 's')) {
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
    
    int len = 0;
    // Remove extra spaces
    for (;len < j; len++) {
        if (postfix[len] == ' ' && postfix[len + 1] == ' ') {
            for (int m = len; m < j - 1; m++) {
                postfix[m] = postfix[m + 1];
            }
            j--;
            len--;
        }
    }
    
    printf("\n\033[92mInfix: \033[93m%s", infix);
    printf("\n\033[92mPostfix: \033[93m%s\033[0m\n", postfix);
    
    // MARK: Evaluation
    
    for(int i = 0; i < len; i++) {
        if ((postfix[i] >= '0' && postfix[i] <= '9') || postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^' || postfix[i] == ' ') {
            continue;
        } else {
            printf("Stopping postfix evaluation due to invalid character: %c\n", postfix[i]);
            return 0;
        }
    }
    
    int num[50];
    int numTop = 0;
    int p = 0;
    num[numTop] = 0;
    
    int lastWasDigit = 0;
    for(int i = 0; i < len; i++) {
        if (postfix[i] == ' ') {
            if (lastWasDigit) {
                numTop++;
                num[numTop] = 0;
                lastWasDigit = 0;
            }
            continue;
        }
        
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            num[numTop] = num[numTop] * 10 + (postfix[i] - '0');
            lastWasDigit = 1;
            continue;
        }
        
        if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^') {
            switch (postfix[i])
            {
            case '+':
                num[numTop - 2] = num[numTop - 2] + num[numTop - 1];
                numTop--;
                break;
            
            case '-':
                num[numTop - 2] = num[numTop - 2] - num[numTop - 1];
                numTop--;
                break;
            
            case '*':
                num[numTop - 2] = num[numTop - 2] * num[numTop - 1];
                numTop--;
                break;
            
            case '/':
                num[numTop - 2] = num[numTop - 2] / num[numTop - 1];
                numTop--;
                break;
            
            case '^':
                num[numTop - 2] = power(num[numTop - 2], num[numTop - 1]);
                numTop--;
                break;
            
            default:
                printf("Error, character: %c", postfix[i]);
            }
            lastWasDigit = 0;
        }
    }
    
    printf("\n\033[92mResult: \033[93m%d\033[0m\n", num[0]);
    
    return 0;
}

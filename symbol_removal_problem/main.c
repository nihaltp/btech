#include<stdio.h>
#include <string.h>

void remover (char* input, int num, int k) {
    // if the current character is a space, skip it
    if (input[num] == ' ') {
        num++;
        remover(input, num, k);
        return;
    }
    
    // move the characters to fill the gap
    for (int i = num; i < strlen(input); i++) {
        input[i] = input[i + 1];
    }
    
    // remove the character next to the removed character
    if (k > 0) {
        // if the next character is also a symbol, repeat the process
        if (input[num] == '*' || input[num] == '$' || input[num] == '#') {
            k+=2;
        }
        remover(input, num, --k);
    }
    
    return;
}

int main() {
    char string[106];
    
    // get the string from the user
    printf("\033[92mEnter the string to process: ");
    fgets(string, sizeof(string), stdin);
    
    int length = strlen(string);
    
    // find and remove the symbols
    for(int i = 0;i < length;i++) {
        if (string[i] == '*' || string[i] == '$' || string[i] == '#') {
            remover(string, i, 1);
        }
        
        length = strlen(string);
    }
    
    // print the modified string
    printf("Formatted string: %s\033[0m", string);
    return 0;
}

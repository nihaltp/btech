// Implement backward and forward navigation of visited web pages in a web browser (i.e.
// back and forward buttons) using doubly linked list operations.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void goBack();
void goForward();
void visit();

struct page {
    char url[50];
    struct page *prev;
    struct page *next;
};

struct page* current = NULL;

int main() {
    int running = 1;
    while (running > 0) {
        printf("\033[93m\nChoose your option:\n");
        printf("\t1. Go Back in History\n");
        printf("\t2. View current website\n");
        printf("\t3. Go Forward in History\n");
        printf("\t4. Visit a new page\n");
        printf("\t5. Quit\n");
        printf("Value: \033[94m");
        scanf("%d", &running);
        
        switch (running) {
            case 1:
                goBack();
                break;
            
            case 2:
                printf("\nVisiting: %s", current->url);
                break;
            
            case 3:
                goForward();
                break;
            
            case 4:
                visit();
                break;
            
            case 5:
                running = 0;
                printf("\033[91mStopping the program");
                break;
            
            default:
                printf("\033[91mInvalid Choise: %d", running);
                break;
        }
    }
    
    printf("\033[0m");
    return 0;
}

void goBack() {
    if (current == NULL || current->prev == NULL) {
        printf("\033[95m\nYou are at the beginnig of the history\n\033[0m");
        return;
    }
    
    struct page *prevPage = current->prev;
    printf("\nCurrent page: %s", prevPage->url);
    current = prevPage;
}

void goForward() {
    if (current == NULL || current->next == NULL) {
        printf("\033[95m\nYou are at the front end of the history\n\033[0m");
        return;
    }
    
    struct page *nextPage = current->next;
    
    printf("\nCurrent page: %s", nextPage->url);
    current = nextPage;
}

void visit() {
    char url[50];
    printf("\033[93m\nEnter the website url: \033[94m");
    scanf("%s", url);
    
    struct page *new = (struct page *)malloc(sizeof(struct page));
    strcpy(new->url, url);
    new->prev = current;
    new->next = NULL;
    
    if (current != NULL && current->next != NULL) {
        struct page *temp = current->next;
        while (temp != NULL) {
            struct page *nextPage = temp->next;
            free(temp);
            temp = nextPage;
        }
        current->next = NULL;
    }
    
    if (current != NULL) {
        current->next = new;
    }
    
    current = new;
}

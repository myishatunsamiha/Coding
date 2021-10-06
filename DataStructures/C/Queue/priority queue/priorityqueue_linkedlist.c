#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int value;
    int priority;
    struct NODE* next;
};

typedef struct NODE node;


void enqueue (node **head, int value, int priority) {
    node *newnode = (node*)malloc(1 * sizeof(node));
    newnode->value = value;
    newnode->priority = priority;
    newnode->next = NULL;

    printf("node has been created...");
    
    if (*head == NULL) {
        
        *head = newnode;    

    } else if (priority < (*head)->priority) {

        newnode->next = *head;
        *head = newnode;

    } else {

        node *temp = (*head);
        while (temp->next != NULL && temp->next->priority < priority) {
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }

}

void dequeue (node** head) {
    node* temp = (*head);
    (*head) = (*head)->next;
    printf("dequeued element is %d\n", temp->value);
    free(temp);
}

int peek (node** head) {
    return (*head)->value;
}


int isEmpty (node** head) {
    return (*head == NULL);
}


int main () {
    int option;
    
    node *head = NULL;

    while (1) {
        scanf("%d", &option);
        
        int value, priority;
        if (option == 1) {
            printf("enter the value along with priority of the item: ");
            scanf("%d %d", &value, &priority);
            enqueue(&head, value, priority);
            
        } else if (option == 2) {
            dequeue(&head);
            
        } else if (option == 3) {
            printf("highestPriority element is %d\n", peek(&head));
        }
    }

    return 0;
}
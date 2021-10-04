#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
typedef struct Node node;

node *listhead = NULL;

struct Stack {
    node *top;
    struct Stack *next;
};

typedef struct Stack stack;
stack *stackhead = NULL;

void insertList (int val) {
    node* newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    
    if (listhead == NULL) {
        listhead = newnode;  
    } else {
        newnode->next = listhead;
        listhead = newnode;
    }
}

void push (node *temp) {
    stack *stnode = (stack*)malloc(sizeof(stack));
    stnode->top = temp;
    stnode->next = NULL;
    
    if (stackhead == NULL) {
        stackhead = stnode;
    } else {
        stnode->next = stackhead;
        stackhead = stnode;
    }
}

int isEmpty () {
    if (stackhead == NULL) 
        return 1;
    else
        return 0;
}


void pop () {
    if (stackhead != NULL) {
        stack* temp = stackhead;
        stackhead = stackhead->next;
        free(temp);
    }
}

void reverseList () {
    if (listhead == NULL)
        return;
    
    node *temp = listhead, *h;
    while (temp != NULL) {
        push(temp);
        temp = temp->next;
    }
    
    listhead = stackhead->top;
    temp = stackhead->top;
    pop();
    while (!isEmpty()) {
        temp->next = stackhead->top;
        temp = stackhead->top;
        pop();
    }
    temp->next = NULL;
}

void printList () {
    node* temp = listhead;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    //node *head = NULL;
    int option, val;
    
    while(1) {
        scanf("%d", &option);
        if (option == 1) {
            scanf("%d", &val);
            insertList(val);
            //printf("%p %d %p\n", head, *head, &head);
            
        
        } else if (option == 2) {
            printList();
        } else if (option == 3) {
           reverseList();
        }
    } 

    return 0;
}

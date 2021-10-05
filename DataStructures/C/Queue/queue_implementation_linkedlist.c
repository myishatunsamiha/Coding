#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct QUEUE {
    int data;
    struct QUEUE *next;
};
typedef struct QUEUE queue;

queue* front = NULL;
queue* rear = NULL;

void enqueue (int x) {
    queue* newnode = (queue*)malloc(sizeof(queue));
    newnode->data = x;
    newnode->next = NULL;
    
    if (front == NULL && rear == NULL) {
        front = newnode;
        rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue () {
    queue* temp = front;
    
    if (front == NULL && rear == NULL) {
        printf("Queue is empty!\n");
        return;
        
    } else {
        printf("dequeued %d\n", front->data);
        front = front->next;
    }
    
    free(temp);
}

int get_front () {
    if (front != NULL)
        return front->data;
    else 
        return INT_MIN;
}

int get_rear () {
    if (rear != NULL)
        return rear->data;
    else 
        return INT_MIN;
}

int main () {
    
    int x, option; 
    while (1) {
        scanf("%d", &option);
        
        if (option == 1) {
            scanf("%d", &x);
            enqueue(x);
            
        } else if (option == 2) {
            dequeue();
            
        } else if (option == 3) {
            printf("front %d\n", get_front());
            
        } else if (option == 4) {
            printf("rear %d\n", get_rear());
            
        }
    }
    
    
    return 0;
}
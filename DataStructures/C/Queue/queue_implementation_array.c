/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct QUEUE {
    int front, rear;
    int capacity;
    int *arr;
};

typedef struct QUEUE queue;

queue* createQueue (int capacity) {
    
    queue* q = (queue*)malloc(1 * sizeof(queue));   // allocate space for one queue
    
    q->front = -1;
    q->rear = -1;
    q->capacity = capacity;
    q->arr = (int*)malloc(capacity * sizeof(int));
    
    return q;
}

int isEmpty (queue* q) {
    if (q->front == -1 && q->rear == -1) 
        return 1;
    else 
        return 0;
}

void enqueue (queue* q, int x){
    
    if (q->front == (q->rear + 1) % q->capacity) {
        printf("queue is full!\n");
        return;
        
    } else if (q->front == -1 && q->rear == -1) {
        q->front = 0; 
        q->rear = 0;
        
    } else {
        q->rear = (q->rear + 1) % q->capacity;
    }
    
    q->arr[q->rear] = x;
}

int dequeue (queue* q) {
    int temp;
    if (isEmpty(q)) {
        printf("queue is empty!");
        return INT_MIN;
        
    } 
    
    temp = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
        
    } else {
        q->front = (q->front + 1) % q->capacity;
    }
    
    return temp;
}

int front (queue* q) {
    
    if (isEmpty(q)) {
        printf("queue is empty!\n");
        return INT_MIN;
    } 
    
    return q->arr[q->front];
}

int rear (queue *q) {
    
    if (isEmpty(q)) {
        printf("queue is empty!\n");
        return INT_MIN;
    }
    
    return q->arr[q->rear];
}

int main()
{
    int capacity;
    scanf("%d", &capacity);
    
    queue* q = createQueue(capacity);
    
    int x, option; 
    while (1) {
        scanf("%d", &option);
        
        if (option == 1) {
            scanf("%d", &x);
            enqueue(q, x);
            
        } else if (option == 2) {
            printf("dequeued %d\n", dequeue(q));
            
        } else if (option == 3) {
            printf("front %d\n", front(q));
            
        } else if (option == 4) {
            printf("rear %d\n", rear(q));
            
        }
    }
    
    
    return 0;
}

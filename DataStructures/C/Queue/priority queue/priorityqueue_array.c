/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <limits.h>

struct ITEM {
    int value;
    int priority;
};
typedef struct ITEM item;

item pr[100];
int size = -1;

void enqueue (int value, int priority) {
    size++;
    
    pr[size].value = value;
    pr[size].priority = priority;
}


int peek() {
    
    int highestPriority = INT_MIN;
    int ind = -1;
    
    for (int i=0; i<=size; i++) {
        
        if (pr[i].priority > highestPriority) {
            highestPriority = pr[i].priority;
            ind = i;
            
        } else if ((pr[i].priority==highestPriority) && (ind>-1) && (pr[ind].value < pr[i].value)) {
            highestPriority = pr[i].priority;
            ind = i;
        }
    }
    
    return ind;
}



int dequeue () {
    int ind = peek();   // index of highest priority element
    
    if (ind == -1) {
        printf("queue is empty!");
        return INT_MIN;
    }
    
    int delete_item = pr[ind].value;
    
    for (int i=ind; i<size; i++) {
        pr[i] = pr[i+1];
    }
    
    size--;
    
    return delete_item;
}



int main()
{
    int option;
    
    while (1) {
        scanf("%d", &option);
        
        int value, priority;
        if (option == 1) {
            printf("enter the value along with priority of the item: ");
            scanf("%d %d", &value, &priority);
            enqueue(value, priority);
            
        } else if (option == 2) {
            printf("dequeued element is %d\n", dequeue());
            
        } else if (option == 3) {
            printf("highestPriority element is %d\n", pr[peek()].value);
        }
    }

    return 0;
}

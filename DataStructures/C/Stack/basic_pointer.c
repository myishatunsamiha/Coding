#include <stdio.h>

int main()
{
    int i = 5;
    int *p = &i;
    
    printf("i = %d\n", i);
    printf("*p (value of i variable)= %d\n\n", *p);
    
    
    printf("&i = %p\n", &i);
    printf("p (address of i variable)= %p\n\n", p);

    printf("&p (address of p variable) = %p", &p);
    return 0;
}

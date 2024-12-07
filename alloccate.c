#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    int arr[size];
    int integer;
    int i = 0;
    printf("enter size:\n");
    scanf("%d", &size);
    while(i < size)
    {
        printf("enter integer:\n");
        scanf("%d", &integer);
        arr[i] = integer;
        i++;
    }
    i = 0;
    while(i < size)
    {
        printf("[%d]", arr[i]);
        i++;
        if(i == size)
            printf("\n");
    }

}
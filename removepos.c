#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int* arr;
    int size, i, pos;
    printf("Enter size of array ");
    scanf("%d", &size);
    arr = malloc(size* sizeof(int));
    for (i = 0 ; i < size ; i++)
    {
        printf("Enter element %d of the array ", (i+1));
        scanf ("%d", (arr+i));
    }
    printf("Enter your position of the deleted ");
    scanf("%d", &pos);
    for (i = pos ; i < size-1 ; i++)
         arr[i] = arr[i+1];
    size--;
    arr = realloc (arr,size*sizeof(int));
    for (i = 0 ; i < size ; i++)
        printf("%d ", *(arr+i));
    free (arr);
    return 0;
}
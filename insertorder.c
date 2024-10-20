#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int* arr ;
    int size, i, ele, j ;
    printf("Enter size of array : ");
    scanf("%d", &size);
    arr = malloc(size* sizeof(int));
    for (i = 0 ; i < size ; i++ )
    {
        printf("Enter element %d of the array ", (i+1));
        scanf("%d", (arr+i));
    }
    arr = realloc(arr,(++size)*sizeof(int));
    printf("Enter your element to be inserted : ");
    scanf("%d", &ele);
    for (i = 0 ; i < size-1 ; i++)
        if (arr[i] > ele)
        {
            for (j = size-1 ; j >= i ; j--)
                  arr[j+1] = arr[j];
            arr[i] = ele;
            break;
        }
    if (arr[i-1] < ele)
         arr[size-1]=ele;
    for (i = 0 ; i < size ; i++)
        printf("%d ", *(arr+i));
    free (arr);
    return (0);
}
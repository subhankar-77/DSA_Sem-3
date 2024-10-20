#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int* arr ;
    int size, i, ele, pos ;
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
    printf("Enter your position of the inserted ");
    scanf("%d", &pos);
    for (i = size-1 ; i >= pos ; i--)
         arr[i+1] = arr[i];
    arr[pos] = ele;
    for (i = 0 ; i < size ; i++)
        printf("%d ", *(arr+i));
    free (arr);
    return 0;
}
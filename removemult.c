#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* arr;
    int i, j, ele, size;
    printf("Enter size of the array : ");
    scanf("%d", &size);
    arr = malloc(size*sizeof(int));
    for( i = 0 ; i < size ; i++ )
    {
        printf("Enter element %d of the array ",(i+1));
        scanf("%d", (arr+i));
    }
    printf("Enter your element to be deleted : ");
    scanf("%d", &ele);
    for ( i = 0 ; i < size ; i++ )
    {
        if (arr[i] == ele)
        {
            for ( j = i ; j < size-1 ; j++ )
                arr[j] = arr[j+1];
            i--;
            size--;
        }
    }
    arr = realloc (arr,size*sizeof(int));
    for (i = 0 ; i < size ; i++)
        printf("%d ", arr[i]);
    free (arr);
    return 0;
}
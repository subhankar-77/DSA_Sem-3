#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* arr;
    int i, j, k, ele, size;
    printf("Enter size of the array : ");
    scanf("%d", &size);
    arr = malloc(size*sizeof(int));
    for( i = 0 ; i < size ; i++ )
    {
        printf("Enter element %d of the array ",(i+1));
        scanf("%d", (arr+i));
    }
    for ( k = 0 ; k < size ; k++)
        for ( i = k+1 ; i < size ; i++ )
        {
            if (arr[i] == arr[k])
            {
                for ( j = i ; j < size-1 ; j++ )
                    arr[j] = arr[j+1];
                i--;
                size--;
                k--;
            }
        }
    arr = realloc (arr,size*sizeof(int));
    for (i = 0 ; i < size ; i++)
        printf("%d ", arr[i]);
    free (arr);
    return 0;
}
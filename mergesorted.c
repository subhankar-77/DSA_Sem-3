#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int* arr;
    int* arr1;
    int* arr2;
    int i, j, k, size1, size2;
    printf("Enter size of first array : ");
    scanf("%d", &size1);
    arr1 = malloc (size1*sizeof(int));
    for(i = 0; i < size1; i++)
    {
        printf("Enter element %d of the first array ",(i+1));
        scanf("%d", (arr1+i));
    }
        printf("Enter size of second array : ");
    scanf("%d", &size2);
    arr2 = malloc (size2*sizeof(int));
    for(j = 0; j < size2; j++)
    {
        printf("Enter element %d of the second array ", (j+1));
        scanf("%d" ,(arr2+j));
    }
    arr = malloc ((size1+size2) * sizeof(int));
    i=j=k=0;
    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
            arr[k++] = arr1[i++];
        else
            arr[k++] = arr2[j++];
    }
    while (i < size1)
        arr[k++] = arr1[i++];
    while (j < size2)
        arr[k++] = arr2[j++];
    for (k = 0 ; k < size1+size2 ; k++)
        printf("%d ", *(arr+k));
    free (arr);
    free (arr1);
    free(arr2);
    return 0;
}
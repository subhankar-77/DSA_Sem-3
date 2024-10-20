#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(int *arr, int low, int high) {
    if (low < high) {
        int partition_index = partition(arr, low, high);
        quicksort(arr, low, partition_index - 1);
        quicksort(arr, partition_index + 1, high);
    }
}
int main ()
{
    int n ;
    printf ("Enter size of the array ");
    scanf ("%d" , &n);
    int * arr = (int*)malloc (n*sizeof (int));
    printf ("Enter your elements of the array ");
    for (int i = 0 ; i < n ; i++)
        scanf ("%d", (arr+i));
    quicksort (arr , 0 , n-1);
    for (int i = 0 ; i < n ; i++)
        printf ("%d ", *(arr+i));
}
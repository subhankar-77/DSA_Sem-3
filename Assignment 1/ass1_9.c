#include<stdio.h>
void binarysearch(int key,int n,int ar[]);
void main()
{
int n,i,key;
printf("ENTER THE NUMBER OF ELEMENTS \n");
scanf("%d",&n);
int ar[n];
printf("ENTER THE ELEMENTS: \n");
for(i=0;i<n;i++)
scanf("%d",&ar[i]);
printf("Enter the number to be searched \n");
scanf("%d",&key);
binarysearch(key,n,ar);
}
void binarysearch(int key ,int n,int ar[])
{
 int mid,low=0,high=n;
 while (low<high)
 {
    mid=(low+high)/2;
    if(key==ar[mid])
    {
        printf("FOUND at %d ", mid);
        return ;
    }
    if(ar[mid]<key)
            low=mid+1;
    else
            high=mid-1;
 }
  printf("NOT FOUND");

}





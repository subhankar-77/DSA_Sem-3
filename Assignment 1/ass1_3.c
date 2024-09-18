#include<stdio.h>
void main()
{
int n,i,pos;
printf("ENTER THE NUMBER OF ELEMENTS \n");
scanf("%d",&n);
int ar[n];
printf("The elements are: \n");
for(i=0;i<n;i++)
scanf("%d",&ar[i]);
printf("Enter the position to be deleted \n");
scanf("%d",&pos);
for(i=pos-1;i<n;i++)
ar[i]=ar[i+1];
n--;
for(i=0;i<n;i++)
printf("%d",ar[i]);
}


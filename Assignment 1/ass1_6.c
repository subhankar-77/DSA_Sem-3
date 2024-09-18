#include<stdio.h>
void main()
{
int n,i,j,k;
printf("ENTER THE NUMBER OF ELEMENTS \n");
scanf("%d",&n);
int ar[n];
printf("The elements are: \n");
for(i=0;i<n;i++)
scanf("%d",&ar[i]);
for(i=0;i<n-1;i++)
{
 for(j=i+1;j<n; )
 {
 if(ar[i]== ar[j])
 {
   for(k=j;k<n;k++)
     ar[k]=ar[k+1];
     n--;
 }
 else
  j++;
 }
}
for(i=0;i<n;i++)
printf("%d",ar[i]);
}

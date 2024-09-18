#include<stdio.h>
void main()
{
int n,i,x;
printf("Enter the number of elements");
scanf("%d",&n);
int ar[n+1];
  printf("The elements are ");
for(i=0;i<n;i++)
   scanf("%d",&ar[i]);
printf("Enter the number to be inserted");
scanf("%d",&x);
for(i=n-1;i>0;i--)
{
if(ar[i]>x)
  ar[i+1]=ar[i];
else
{
  ar[i+1]=x;
  break;
}
}
for(i=0;i<=n;i++)
{
printf("%d",ar[i]);
}
return 0;
}

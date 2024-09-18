#include<stdio.h>
void main()
{
int n,i,j,x;
printf("Enter the number of elements");
scanf("%d",&n);
int ar[n];
  printf("The elements are ");
for(i=0;i<n;i++)
   scanf("%d",&ar[i]);
printf("Enter the number to be deleted");
scanf("%d",&x);
for(i=0;i<n;i++){
if(ar[i]==x)
{
 for(j=i;j<n;j++)
 {
   ar[j]=ar[j+1];
 }
}
}
n--;
for(i=0;i<n;i++)
printf("%d",ar[i]);
return 0;

}



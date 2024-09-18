#include<stdio.h>
void linearsearch(int s,int n,int ar[]);
void main()
{
int n,i,s;
printf("ENTER THE NUMBER OF ELEMENTS \n");
scanf("%d",&n);
int ar[n];
printf("ENTER THE ELEMENTS: \n");
for(i=0;i<n;i++)
scanf("%d",&ar[i]);
printf("Enter the number to be searched \n");
scanf("%d",&s);
linearsearch(s,n,ar);
}
void linearsearch(int s,int n,int ar[])
{
 int flag=0,i;
for(i=0;i<n;i++)
{
 if(ar[i]==s)
 {
   flag=1;
   break;
 }
 }
if(flag==1)
    printf("ELEMENT FOUND AT POSITION %d",i+1);
else
    printf("NOT FOUND");
}

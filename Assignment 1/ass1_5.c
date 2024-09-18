#include<stdio.h>
void main()
{
int n1,n2,i,j,k=0;
printf("ENTER THE NO OF ELEMENTS IN FIRST AND SECOND ARRAY :\n");
scanf("%d",&n1);
scanf("%d",&n2);
int ar1[n1],ar2[n2];
printf("Enter the elements in the first array :\n");
for(i=0;i<n1;i++)
scanf("%d",&ar1[i]);
printf("Enter the elements in the second array :\n");
for(j=0;j<n2;j++)
scanf("%d",&ar2[j]);
int ar3[n1+n2];
i=0,j=0;
while(i<n1 && j<n2){
    if(ar1[i]<ar2[j]){
        ar3[k++]=ar1[i++];
    }
    else
    {
     ar3[k++]=ar2[j++];
    }
}
while(i<n1){
    ar3[k++]=ar1[i++];
}
while(j<n2){
     ar3[k++]=ar2[j++];
}
for(k=0;k<n1+n2;k++)
    printf("%d",ar3[k]);
}

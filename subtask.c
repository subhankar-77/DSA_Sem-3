#define Swap(x,y,t) ((t)=(x), (x)=(y), (y)=(t))
#include <stdio.h>
int main ()
{
    int a = 1,t,b = 2 ;
    printf ("X = %d\n",a);
    printf ("Y = %d\n",b);
    Swap(a,b,t);
    printf ("X = %d\n",a);
    printf ("Y = %d\n",b);
}
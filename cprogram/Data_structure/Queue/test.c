#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int a,b;
    float c,d;
    scanf("%d %d",&a,&b);
    printf("%d %d\n", (a+b), (a-b));
    scanf("%f %f",&c,&d);
    printf("%.2f %.2f\n", (c+d), (c-d));
    
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100
int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    char ch;
    scanf("%c", &ch);

    char s[MAX];
    scanf(" %[^\n]%*c",s);

    char sen[MAX];  
    scanf(" %[^\n]%*c",sen);
    
    printf("%c\n%s\n%s\n",ch,s,sen); 
    return 0;
}

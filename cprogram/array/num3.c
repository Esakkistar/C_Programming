#include <stdio.h>
#include <limits.h>

int main() {
    // Signed and unsigned char ranges
    printf("Signed char range: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Unsigned char range: 0 to %u\n", UCHAR_MAX);

    // Signed and unsigned short int ranges
    printf("Signed short int range: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned short int range: 0 to %u\n", USHRT_MAX);

    // Signed and unsigned int ranges
    printf("Signed int range: %d to %d\n", INT_MIN, INT_MAX);
    printf("Unsigned int range: 0 to %u\n", UINT_MAX);

    // Signed and unsigned long int ranges
    printf("Signed long int range: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Unsigned long int range: 0 to %lu\n", ULONG_MAX);


    signed int a = 2147483648;
    unsigned int b = 4294967297;

    printf("a : %d, b : %u\n",a,b);

    unsigned char c = 255;
    c = c + 1;
    printf("%u\n", c);
    
    c = c + 3;
    printf("%u\n", c);

    char ch = 255;
    printf("%d\n", ch);



    return 0;
}


#include <stdio.h>
#include <string.h>

int main() {
    int num = 43245698;
    int t = num;
    int sum = 0;
    while (t != 0) {
        int r = t % 10 + 1;
        if (r == 10) { r = 0; }
        sum = sum * 10 + r;
        t = t / 10;
    }
    
    t = sum;
    sum = 0;
    while (t != 0) {
        sum = sum * 10 + ( t % 10);
        t = t / 10;
    }
    
    printf("%d - %d\n", num, sum);
    
    char s[20];
    sprintf(s, "%d", num);
    printf("s - %s\n", s);
    for (int i =0 ; s[i] != '\0'; i++) {
        if (s[i] == '9') {
            s[i] = '0';
        }
        else {
            s[i] = s[i] + 1;
        }
    }
    sscanf(s, "%d", &t);
    printf("s - %s,t - %d\n", s,t);

    t = num;
    int ss = 0,mul = 1;

    while (t > 0) {
	    int r = t % 10 + 1;
	    r = r % 10;
	    ss = ss + r*mul;
	    mul *= 10;
	    t = t/ 10;
    }
    
    printf("%d - %d\n", num, ss);
    
    return 0;
}

/*
 * Karprekar number, whose square in that base can split into two parts that add upto the original number again. */

#include <stdio.h>

int power(int n, int b) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return n;
    }
    return n * power(n, b-1);
}

int count(int sq) {
    int cnt = 0;

    if (sq <= 9) {
        return 0;
    }
    while (sq != 0) {
        sq = sq / 10;
        cnt++;
    }
    return cnt;
}
int main () {
    for (int i = 1; i <= 1000; i++) {
        int sqr = i*i;
        int cnt = count(sqr);

        for (int j = 1; j < cnt; j++) {
            int equal = power(10, j);

            if (equal == i) {
                continue;
            }
            int t = sqr;
            int p1 = t / equal;
            int p2 = t % equal;

            if (i == p1+p2) {
                printf("%d - %d -> %d + %d\n", i, sqr, p1, p2);
                break;
            }
        }
    }

    return 0;
}


#include <stdio.h>
#include <math.h>

int square (int N) {
	double n = (double) N;
	double num = n / 2.0;
	double epi = 0.000001;
	double diff;

	do {
	    double new_num = (num + n / num) / 2.0;
	    diff = num - new_num;
	    num = new_num;
	}while (diff > epi || diff < -epi);
	
	return (int) num;
}	

int sum_factor(int n) {
    int sum = 0;
    printf("%d : ", n);
    for (int i = 1; i <= square(n); i++) {
        if (n % i == 0) {
            printf("%d ", i);
            sum += i;
            if (n/i != i) {
                 printf("%d ", n/i);
                sum += n/i;
            }
        }
    }
    printf("-> %d\n", sum);
    return sum;
}
int main() {
    int n;
    printf("Enter the number : ");
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= square(n); i++) {
        if (n % i == 0) {
            sum += sum_factor(i);
            if (i != n/ i) {
                 sum += sum_factor(n/i);
            }
        }
    }
    printf("sum of factor : %d\n", sum);

    return 0;
}


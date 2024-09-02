#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

double find_area(triangle* tr) {
	double p = (tr->a + tr->b + tr->c) / 2.0;
	return sqrt( p * (p - tr->a) * (p - tr->b) * (p - tr->c));
	
}

double calculate_area(int a, int b, int c) {
	double p = (a+b+c) / 2.0;
	return sqrt(p * (p-a) * (p-b) * (p-c));
}
void sort_by_area(triangle* tr, int n) {
	double area[n];

	for (int i = 0; i < n; i++) {
		area[i] = find_area(&tr[i]);
		//area[i] = calculate_area(tr[i].a, tr[i].b, tr[i].c);
		printf("Area %d : %f\n",i+1, area[i]);
	}

	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (area[i] > area[j]) {
				triangle temp = tr[i];
				tr[i] = tr[j];
				tr[j] = temp;

				double a = area[i];
				area[i] = area[j];
				area[j] = a;
			}
		}
	}
}

int main()
{
	int n;
	printf("Enter the triangle : ");
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		printf("Enter the %d triangle 3 sides : ",i+1);
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	printf("Sorted triangle by Area : \n");
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}

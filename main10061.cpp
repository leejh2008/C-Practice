#include <stdio.h>
#include <math.h>
//ÖÊÊıÉ¸

int isPrime(int x) {
	int i;
	int s;
	if (x < 2)
		return 0;
	s = (int)sqrt(x);
	for (int i = 2; i <= s; i++) {
		if (x % i == 0)
			return 0;
	}
	return 1;
}

int main() {
	int n;
	scanf("%d", &n);
	int a[200];
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int first = 1;
	for (int i = 0; i < n; i++) {
		if (isPrime(a[i]) == 1) {
			if (first == 0)
				printf(" ");
			printf("%d", a[i]);
			first = 0;
		}
	}
	return 0;
}


#include <stdio.h>
#include <math.h>

//ÖÊÊı¿Ú´ü
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

void println(int num) {
	printf("%d\n", num);
}

int main() {
	int L;
	scanf("%d", &L);
	int i;
	int sum = 0;
	int count = 0;
	for (i = 2; i <= L; i++) {
		if (isPrime(i) == 1) {
			if (sum + i > L)
				break;
			sum = sum + i;
			count += 1;
			println(i);
		}
	}
	println(count);
	return 0;
}
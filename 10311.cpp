#include <stdio.h>

int jiecheng(int n) {
	if (n == 1)
		return 1;
	return n * jiecheng(n - 1);
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", jiecheng(n));
	return 0;
}
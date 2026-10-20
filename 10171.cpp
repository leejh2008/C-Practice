#include <stdio.h>
#include <stdlib.h>

//社团合影
int cmp(const void *x, const void *y) {
	long long a = *(const long long *)x;
	long long b = *(const long long *)y;
	if (a < b)
		return -1;
	if (a > b)
		return 1;
	return 0;
}

int main(int argc, char *argv[]) {
	long long n, k;
	scanf("%lld %lld", &n, &k);
	long long *h = (long long *)malloc(n *sizeof(long long));
	for (long long i = 0; i < n; i++) {
		scanf("%lld", &h[i]);
	}
	qsort(h, n, sizeof(long long), cmp);
	long long left = 0;
	long long ans = 0;
	for (long long right = 0; right < n; right++) {
		while (h[right] - h[left] > k) {
			left++;
		}
		long long len = right - left + 1;
		if (len > ans)
			ans = len;
	}
	printf("%lld\n", ans);
	free(h);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
//ю╤ге
#define MAXN 100010
long long a[MAXN];
int pre[MAXN];
int suf[MAXN];

int main(int argc, char *argv[]) {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	pre[0] = 1;
	for (int j = 1; j <= n; j++) {
		if (j == 1)
			pre[1] = 1;
		else
			pre[j] = pre[j - 1] && (a[j - 1] <= a[j]);
	}
	suf[n + 1] = 1;
	for (int j = n; j >= 1; j--) {
		if (j == n)
			suf[j] = 1;
		else
			suf[j] = suf[j + 1] && (a[j] <= a[j + 1]);
	}
	int ans = 0;
	for (int i = 1; i + k - 1 <= n; i++) {
		int last = i - 1;
		int begin = i + k;
		if (!pre[last] || !suf[begin])
			continue;
		if (last >= 1 && begin <= n && a[last] > a[begin])
			continue;
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}
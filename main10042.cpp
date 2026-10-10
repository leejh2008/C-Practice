#include <stdio.h>

//ÖéĞÄËã²âÑé
int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	int numArr[100000] = {0};
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		numArr[arr[i]] = 1;
	}
	int flag[100000] = {0};
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int sum = arr[i] + arr[j];
			if (numArr[sum])
				flag[sum] = 1;
		}
	}
	int count = 0;
	for (int a = 0; a < 100000; a++) {
		if (flag[a]) {
			count++;
		}
	}
	printf("%d", count);
	return 0;
}
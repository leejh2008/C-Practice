#include <stdio.h>
//µ¹ÐòÊä³ö
int arr[1000000];

int main() {

	int count = 0;
	int num;
	scanf("%d", &num);
	while (num != 0) {
		arr[count] = num;
		count++;
		scanf("%d", &num);
	}
	for (int i = count - 1; i >= 0; i--) {
		printf("%d", arr[i]);
		if (i > 0)
			printf(" ");
	}

	return 0;
}
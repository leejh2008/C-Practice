#include <stdio.h>

//计算两数之和
int main() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%d*%d=%-3d", i, j, j *i);
		}
		printf("\n");
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

//蓝桥：迎新配送
int main(int argc, char *argv[]) {
	//输入扫描材料数量
	long long n;
	scanf("%lld", &n);
	//sum代表距离的总和
	long long sum = 0;
	//代表单趟距离的最大值，初始值为0
	long long maxd = 0;
	//循环找到最大值，遍历到比maxd还要大的数就替换掉
	for (long long i = 0; i < n; i++) {
		long long d;
		scanf("%lld", &d);
		sum += d;
		if (d > maxd)
			maxd = d;
	}
	//计算最短距离方法：距离总和-单趟路程的最大值
	printf("%lld\n", 2 * sum - maxd);
	return 0;
}
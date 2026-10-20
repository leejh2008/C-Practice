#include <stdio.h>
#include <stdlib.h>

//蓝桥：社团出游
//使用qsort比较函数，将数从小到大排列
int cmp(const void *x, const void *y) {
	long long a = *(const long long *)x;
	long long b = *(const long long *)y;
	//a更小，就排前面
	if (a < b)
		return -1;
	//a更大，就排后面
	if (a > b)
		return 1;
	//相等
	return 0;
}

int main(int argc, char *argv[]) {
	//读取输入数据
	//n：报名人数 k：每辆车的座位数 c：每辆车的租金 b：总经费
	long long n, k, c, b;
	scanf("%lld %lld %lld %lld", &n, &k, &c, &b);
	//动态申请n个long long 的空间，用来存每个同学的门票和午餐费
	long long *a = (long long *)malloc(n *sizeof(long long));
	for (long long  i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	//将同学所需的费用从小到大排序
	qsort(a, n, sizeof(long long), cmp);
	//sum为门票和午餐花费，初始值为0
	long long sum = 0;
	//count为可参加人数，初始为0
	long long count = 0;
	//依次尝试安排1人、2人、3人······、n人
	for (long long m = 1; m <= n; m++) {
		//加上第m便宜的同学，费用总和
		sum = sum + a[m - 1];
		//车辆数：m/k（需要向上取整）
		long long car = (m + k - 1) / k;
		//如果费用总和没有超出预算
		if (sum + car * c <= b) {
			//更新答案
			count = m;
		} else {
			//超出预算，直接跳出停止
			break;
		}
	}
	//输出可去的同学数目
	printf("%lld\n", count);
	free(a);
	return 0;
}


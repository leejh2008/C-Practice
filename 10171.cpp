#include <stdio.h>
#include <stdlib.h>


//蓝桥：社团合影
//注意，这里用冒泡、选择、插入排序都会超时（时间复杂度O（n））
//比较函数：供qsort使用，按升序排序
int cmp(const void *x, const void *y) {
	//将x转换为long long 指针并取值，记作a
	long long a = *(const long long *)x;
	long long b = *(const long long *)y;
	//如果a小于b，返回-1，a应该排在b前面
	if (a < b)
		return -1;
	//如果a大于b，返回1，a应该排在b后面
	if (a > b)
		return 1;
	//a等于b时返回0
	return 0;
}

int main(int argc, char *argv[]) {
	//n表示人数，k表示合法的最大升高差
	long long n, k;
	scanf("%lld %lld", &n, &k);
	//动态分配n个long long 大小的内存空间，用来存放每个人的身高
	long long *h = (long long *)malloc(n *sizeof(long long));
	//循环读入每个人的身高，并存入到数组
	for (long long i = 0; i < n; i++) {
		scanf("%lld", &h[i]);
	}
	//调用qsort函数将身高升序排序
	qsort(h, n, sizeof(long long), cmp);
	//left是滑动窗口的左端点，初始值为0
	long long left = 0;
	//ans用来记录满足条件的最大人数
	long long ans = 0;
	//right是窗口的右端点，从左到右依次扩展
	for (long long right = 0; right < n; right++) {
		//当窗口内最高与最矮身高差超过k时
		while (h[right] - h[left] > k) {
			//左端点右移，缩小窗口，直到满足条件
			left++;
		}
		//计算当前窗口内的人数
		long long len = right - left + 1;
		//如果当前窗口内的人数比已记录的最大值大
		if (len > ans)
			//更新替换最大值
			ans = len;
	}
	//输出最多能合影的人数
	printf("%lld\n", ans);
	//释放动态分配的内存
	free(h);
	return 0;
}
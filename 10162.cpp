#include <stdio.h>
#include <stdlib.h>

//蓝桥：讲义补订
int main(int argc, char *argv[]) {
	//按题目输入读取N,L,R
	long long n, l, r;
	scanf("%lld %lld %lld", &n, &l, &r);
	//算需要更换的纸张数目，用向上取整方法：(r + 1) / 2：第L页所在的纸张编号
	//(l + 1) / 2：第R页所在的纸张编号；+1：加上另一端
	long long sheets = (r + 1) / 2 - (l + 1) / 2 + 1;
	//normal:打印的正常页数，初始值为0
	long long normal = 0;
	//如果l取余2为0，打印的正常页数+1
	if (l % 2 == 0)
		normal++;
	//R 在正面且背面有页，R+1 要一起印
	if (r % 2 == 1 && r < n)
		normal++;
	printf("%lld %lld", sheets, normal);
	return 0;
}
#include <stdio.h>

//闰年展示
int main() {
	//输入起始年份与终止年份
	int x, y;
	scanf("%d %d", &x, &y);
	//res数组保存区间内的闰年年份
	int res[3001];
	//计数器，用来存储闰年的个数
	int count = 0;
	//是闰年的条件：年份能被4整除且不能被100整除，或者年份能被400整除
	for (int year = x; year <= y; year++) {
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
			//先把年份存入res[count]里，然后count+1；
			res[count++] = year;
		}
	}
	//先打印区间内闰年的个数
	printf("%d\n", count);
	//遍历打印闰年的年份
	for (int i = 0; i < count; i++) {
		//第一个外，每一个年份先输出一个空格
		if (i > 0)
			printf(" ");
		printf("%d", res[i]);
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
//蓝桥 彩带拆除
//定义数组的上限，略大于1e5
#define MAXN 100010
//存放每面棋子的长度，下标从1开始
long long a[MAXN];
//pre[j]=1表示a[1..j]不递减，否则为0
int pre[MAXN];
int suf[MAXN];

int main(int argc, char *argv[]) {
	//n：彩旗数量；k：需要拆下的彩旗数量
	int n, k;
	//读入n与k
	scanf("%d %d", &n, &k);
	//循环读入n个彩旗长度
	for (int i = 1; i <= n; i++) {
		//读入第i面彩旗的长度，存入a[i]
		scanf("%lld", &a[i]);
	}
	//空前缀视为不递减
	pre[0] = 1;
	//从左到右递推前缀数组
	for (int j = 1; j <= n; j++) {
		//只有一面一定不递减
		if (j == 1)
			pre[1] = 1;
		else
			//让前缀的"不递减"状态沿着数组传递下去，且当前元素不大于后一个，才不递减
			pre[j] = pre[j - 1] && (a[j - 1] <= a[j]);
	}
	//空后缀视为不递减
	suf[n + 1] = 1;
	//从右往左递推后缀数组
	for (int j = n; j >= 1; j--) {
		//单个元素一定不递减
		if (j == n)
			suf[j] = 1;
		else
			suf[j] = suf[j + 1] && (a[j] <= a[j + 1]);
	}
	//记录合法的拆除方案数
	int ans = 0;
	//枚举拆除区间起点i，终点i+k-1不超过n
	for (int i = 1; i + k - 1 <= n; i++) {
		//last:左半段最后一个位置
		int last = i - 1;
		//begin：右半段第一个位置
		int begin = i + k;
		//左半段或右半段只要有一个不是递减的
		if (!pre[last] || !suf[begin])
			//方案不合法，直接跳过
			continue;
		//两边都非空，且拼接处出现下降
		if (last >= 1 && begin <= n && a[last] > a[begin])
			//跳过
			continue;
		//三个条件都满足，方案数+1
		ans++;
	}
	//打印方案数
	printf("%d\n", ans);
	return 0;
}
#include <stdio.h>
//引入数学库，用于sqrt开平方
#include <math.h>
//洛谷 笨小猴

//建立一个函数isPrime，用来判断一个整数n是不是质数，是返回1，不是返回0
int isPrime(int n) {
	//小于2的数都不是质数
	if (n < 2)
		return 0;
	//这里用到了试除法，只需检查到根号n
	int limit = (int)sqrt(n);
	//从2开始，逐个尝试是否整除n
	for (int i = 2; i <= limit; i++) {
		//如果i能整除n，说明n有除1以外的因数
		if (n % i == 0)
			//不是质数，返回0
			return 0;
	}
	//所有的数都试过了不能整除，说明是质数，返回1
	return 1;
}

//主函数
int main() {
	//word数组存放输入的单词
	char word[110];
	//读入一个字符串，遇到空白停止
	scanf("%s", word);
	//count数组分别记录字母a~z出现的次数，全部初始化为0
	int count[26] = {0};
	//从头遍历单词，直到遍历到结束符\0
	for (int i = 0; word[i] != '\0'; i++) {
		//word[i] - 'a'把字母映射为0~25的下标，对应字母出现的次数
		count[word[i] - 'a']++;
	}
	//maxn记录出现次数最多的字母的次数，初始值为0
	//minn记录出现次数最少的字母的次数，初始化为1000
	int maxn = 0;
	int minn = 1000;
	//遍历26个字母的计数
	for (int i = 0; i < 26; i++) {
		//只考虑在单词中出现过的字母
		if (count[i] > 0) {
			//如果当前的字母出现的次数比已知的最大值还大
			if (count[i] > maxn)
				//更新最大值
				maxn = count[i];
			if (count[i] < minn)
				minn = count[i];
		}
	}
	//d是最大次数和最小次数的差值
	int d = maxn - minn;
	//如果d是质数
	if (isPrime(d)) {
		//打印Lucky Word
		printf("Lucky Word\n%d\n", d);
	} else {
		//否则打印No Answer
		printf("No Answer\n0\n");
	}
	return 0;
}
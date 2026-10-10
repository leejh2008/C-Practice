#include <stdio.h>
//统计单词数

int main() {
	//存放待查找的单词
	char word[20];
	//存放整篇文章
	char str[1000020];
	//定义c，用于逐个读取输入的字符
	char c;
	//wlen是待查单词的长度，alen是文章的长度，初始值都为0
	int wlen = 0, alen = 0;
	//输入第一行的第一个字符
	scanf("%c", &c);
	//一直读到换行符为止，即读完整个待查的单词
	while (c != '\n') {
		if (c >= 'A' && c <= 'Z') {//如果是大写字母
			c += 32;//利用ASCII码表全部转成小写字母，不区分大小写
		}
		//把字符存入word数组
		word[wlen] = c;
		//单词长度+1
		wlen++;
		//继续读取下一个字符
		scanf("%c", &c);
	}
	//读第二行文章，每次读取一个字符，读到换行符或文件结束就停止
	//这里的1代表scanf的返回值，意为返回成功匹配并赋值输入项的个数
	while (scanf("%c", &c) == 1 && c != '\n') {
		if (c >= 'A' && c <= 'Z') {
			c += 32;
		}
		//把字符存入文章数组str
		str[alen] = c;
		//文章长度+1
		alen++;
	}
	//count用来记录单词出现的次数
	int count = 0;
	//first用来标记第一次出现的位置，-1表示还没找到
	int first = -1;
	//i是扫描文章当前的下标
	int i = 0;
	//从头到尾扫描文章
	while (i < alen) {
		//如果当前是空格
		if (str[i] == ' ') {
			i++;//跳过空格看下一个字符
		} else {
			//遇到文章的开头，j从i开始向后找这个单词的结尾
			int j = i;
			//while循环控制：只要没到文章的末尾且不是空格，就继续往后走
			while (j < alen && str[j] != ' ') {
				j++;
			}
			//先比较长度是否与待查单词的长度相同
			if (j - i == wlen) {
				//same标记两个单词是否完全相同，先假设相同，标记为1
				int same = 1;
				//逐个字符比较
				for (int k = 0; k < wlen; k++) {
					//只要在遍历过程中发现一个字母不同
					if (str[i + k] != word[k]) {
						//same标记为0（不相同）
						same = 0;
					}
				}
				//如果两个单词完全相同
				if (same == 1) {
					//出现次数+1
					count++;
					//如果这是第一次找到
					if (first == -1) {
						//就记录它在文章中的位置
						first = i;
					}
				}
			}
			//跳到当前文章的末尾，继续扫描后面的内容
			i = j;
		}
	}
	//如果一次都没找到
	if (count == 0) {
		//按题目要求打印-1
		printf("-1\n");
	} else {
		//否则输出出现次数和第一次出现的位置
		printf("%d %d\n", count, first);
	}
	return 0;
}
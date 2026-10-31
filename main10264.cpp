#include <stdio.h>
#include <stdlib.h>

//洛谷结构体P5741：旗鼓相当的对手加强版
typedef struct Student {
	char name[10];
	int ch;
	int ma;
	int en;
	int to;
} Student;
//定义学生数组，按题意，最大1000
Student stu[1000];

int main() {
	//读取输入的人数n
	int n;
	scanf("%d", &n);
	//循环遍历每个学生的信息
	for (int i = 0; i < n; i++) {
		scanf("%s %d %d %d", stu[i].name, &stu[i].ch, &stu[i].ma, &stu[i].en);
		//计算三科总成绩
		stu[i].to = stu[i].ch + stu[i].ma + stu[i].en;
	}
	//外层循环：枚举第一个学生i
	//内层循环：枚举第二个学生j，j+1开始控制i的字典序小于j
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			//按题目要求使用abs绝对值函数判断各科成绩相差小于等于5，&&同时满足
			if (abs(stu[i].ch - stu[j].ch) <= 5 &&
			        abs(stu[i].ma - stu[j].ma) <= 5 &&
			        abs(stu[i].en - stu[j].en) <= 5 &&
			        //同时总成绩相差小于等于10
			        abs(stu[i].to - stu[j].to) <= 10
			   ) {
				//打印两人的名字，记得换行
				printf("%s %s\n", stu[i].name, stu[j].name);
			}
		}
	}

	return 0;
}
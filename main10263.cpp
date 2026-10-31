#include <stdio.h>
#include <stdlib.h>

//洛谷P5740：最厉害的学生
//定义学生的结构体：包含名字、各科成绩、总成绩
typedef struct Student {
	char name[15];
	int ch;
	int ma;
	int en;
	int to;
} Student;

int main() {
	//输入读取人数n
	int n;
	scanf("%d", &n);
	//定义初始结构体，用于替换（细节：总成绩要设计成-1，不要设计成0.原因：
	//若学生成绩全为0，则无法替换）
	Student maxStu = {"", 0, 0, 0, -1};
	//循环遍历每个人的名字及相应成绩
	for (int i = 0; i < n; i++) {
		Student st;
		scanf("%s %d %d %d", st.name, &st.ch, &st.ma, &st.en);
		//计算总成绩
		st.to = st.ch + st.ma + st.en;
		//当前总成绩比最大值还要大
		if (st.to > maxStu.to) {
			//替换
			maxStu = st;
		}
	}
	//打印每位同学的名字与各科成绩
	printf("%s %d %d %d \n", maxStu.name, maxStu.ch,
	       maxStu.ma, maxStu.en);
	return 0;
}
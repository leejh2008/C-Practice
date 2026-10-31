#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//结构体实现
//typedef:关键字
typedef struct Student {
	char name[20];
	int id;
	float score;
} Student;//别名，必加

int main() {
	//定义结构体变量
	Student s1 = {"小明", 10001, 99};
	Student s2 = {"小红", 10002, 100};
	printf("名字：%s 学号：%d 成绩：%.1f \n", s1.name, s1.id, s1.score);
	printf("名字：%s 学号：%d 成绩：%.1f \n", s2.name, s2.id, s2.score);
//在堆上申请一个结构体空间
	Student * stuP = (Student *)malloc(sizeof(Student));
	//习惯性地检查是否申请成功
	if (stuP == NULL) {
		printf("申请内存失败！");
		return 1;
	}
	//字符数组要用strcpy赋值，不能用=
	strcpy(stuP->name, "锦鸿");
	stuP->id = 10003;//指针和普通变量的调用格式不同
	stuP->score = 98;
	printf("名字：%s 学号：%d 成绩：%.1f \n", stuP->name, stuP->id, stuP->score);
	free(stuP);//释放内存
	stuP = NULL;//指针置空
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

//定义结构体变量，包括数据域和指针域
typedef struct Node {
	int data;
	struct Node *next;
} Node;

//定义创建结点函数，返回新申请的内存
Node *creatNode(int data) {
	Node*node = (Node *)malloc(sizeof(Node));
	if (node == NULL) {
		printf("申请内存失败！")
		return NULL;
	}
	//初始化成员变量
	node->data = data;
	//下一个结点必须置为空
	node->next = NULL;
	return node;
}

//尾插
void add(Node *head, int data) {
	Node*node = creatNode(data);
	Node*curr = head;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = node;
}
//头插

//插入数据
Node *insert(Node *head, int index, int data, int *len) {
	//判断下表是否越界
	if (index < 0 || index > (*len)) {
		printf("index超出链表长度，插入失败\n");
		return NULL;
	}
	//利用函数创建结点
	Node *node = creatNode(data);
	//长度+1
	(*len)++;
	//判断插入的位置是否是头结点
	if (index == 0) {
		//将表头给到新结点
		node->next = head;
		//返回新结点
		return node;
	}
	//头结点赋值给curr
	Node*curr = head;
	//遍历结点
	for (int i = 0; i < index - 1; i++) {
		curr = curr->next;
	}
	node->next = curr->next;
	curr->next = node;
	return head;
}

//遍历链表
void printNode(Node *head) {
	Node*curr = head;
	while (curr != NULL) {
		printf("%d ", curr->data);
		curr = curr->next;
	}
	printf("\n");
}

int main() {
	int index = 2;
	int data = 25;
	int len = 4;
	//定义一个头结点，赋值为10
	Node*head = creatNode(10);
	//调用add函数
	add(head, 20);
	add(head, 30);
	add(head, 40);
	//insert函数把新的head用返回值交了回来，再用head=...接收，head不用取值符
	head = insert(head, index, data, &len);
	//遍历结点
	printNode(head);
	return 0;
}
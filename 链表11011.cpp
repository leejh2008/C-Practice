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
		printf("申请内存失败！");
		return NULL;
	}
	//初始化成员变量
	node->data = data;
	//下一个结点必须置为空
	node->next = NULL;
	return node;
}

//尾插
void add(Node *head, int data, int *len) {
	Node*node = creatNode(data);
	Node*curr = head;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = node;
	(*len)++;
}

//头插,Node *addHead声明函数返回类型addHead是一个返回结点地址的函数
Node *addHead(Node *head, int data, int *len) {
	Node*node = creatNode(data);
	node->next = head;
	(*len)++;
	return node;
}

//插入数据
Node *insert(Node *head, int index, int data, int *len) {
	//判断下表是否越界
	if (index < 0 || index > (*len)) {
		printf("index超出链表长度，插入失败\n");
		return NULL;
	}
	//利用函数创建结点
	Node *node = creatNode(data);
	//判断插入的位置是否是头结点
	if (index == 0) {
		//将表头给到新结点
		node->next = head;
		(*len)++;
		//返回新结点
		return node;
	}
	//头结点赋值给curr
	Node*curr = head;
	//遍历结点,找到下标为index-1的前驱结点
	for (int i = 0; i < index - 1; i++) {
		curr = curr->next;
	}
	node->next = curr->next;
	curr->next = node;
	//长度+1
	(*len)++;
	return head;
}

//删除指定位置的数据
Node *removeAt(Node *head, int index, int *len) {
	if (head == NULL || index < 0 || index > (*len)) {
		printf("index超出链表长度，插入失败\n");
		return head;
	}
	if (index == 0) {
		Node*next = head->next;
		free(head);
		(*len)--;
		return next;
	}
	Node *pre = head;
	for (int i = 0; i < index - 1; i++) {
		pre = pre->next;
	}
	Node*del = pre->next;
	pre->next = del->next;
	free(del);
	(*len)--;
	return head;
}

//删除指定数据
Node *removes(Node *head, int data, int *len) {
	Node*pre = NULL;
	Node*curr = head;
	while (curr != NULL) {
		if (curr->data == data) {
			if (pre == NULL) {
				head = curr->next;
			} else {
				pre->next = curr->next;
			}
			free(curr);
			(*len)--;
			return head;
		}
		pre = curr;
		curr = curr->next;
	}
	printf("没有找到数据 %d,删除失败\n", data);
	return head;
}

Node *removeAll(Node *head, int data, int *len) {
	Node*pre = NULL;
	Node*curr = head;
	int count = 0;
	while (curr != NULL) {
		if (curr->data == data) {
			Node*del = curr;
			curr = curr->next;
			if (curr = NULL) {
				head = curr;
			} else {
				pre->next = curr;
			}
			free(del);
			(*len)--;
			count++;
		} else {
			pre = curr;
			curr = curr->next;
		}
	}
	if (count == 0) {
		printf("没有找到%d，删除失败", data);
	}
	return head;
}

//查询：按下标查询
void findNode(Node *head, int index, int len) {
	if (index < 0 || index >= len) {
		printf("下标超出范围，查询失败\n");
		return;
	}
	Node*curr = head;
	for (int i = 0; i < index; i++) {
		curr = curr->next;
	}
	printf("下标%d的数据是%d\n", index, curr->data);
}

//查询：按数据查
void find(Node *head, int data) {
	Node *curr = head;
	int index = 0;
	int found = 0;
	while (curr != NULL) {
		if (curr->data == data) {
			printf("数据%d在下标%d\n", data, index);
			found = 1;
		}
		curr = curr->next;
		index++;
	}
	if (!found) {
		printf("没有找到数据%d\n", data);
	}
}

//修改数据
void change(Node *head, int index, int newData, int len) {
	if (index < 0 || index >= len) {
		printf("下标超出范围，查询失败\n");
		return;
	}
	Node*curr = head;
	for (int i = 0; i < index; i++) {
		curr = curr->next;
	}
	curr->data = newData;
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
	//调用add尾插函数
	add(head, 20, &len);
	add(head, 30, &len);
	add(head, 40, &len);
	add(head, 40, &len);
	//头插
	head = addHead(head, 5, &len);
	//insert函数把新的head用返回值交了回来，再用head=...接收，head不用取值符
	head = insert(head, index, data, &len);
	//删除指定位置
	head = removes(head, 30, &len);
	head = removeAll(head, 40, &len);
	findNode(head, 3, len);
	find(head, 25);
	change(head, 2, 99, len);
	//遍历结点
	printNode(head);
	return 0;
}
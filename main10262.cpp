#include <stdio.h>
#include <stdlib.h>

//结构体运用 链式结构初步
typedef struct Node {
	int data;//节点保存的数据
	struct Node *next; //保存下一个节点的指针
} Node;

int main() {
	//定义节点指针
	Node * node1 = (Node *)malloc(sizeof(Node));
	Node * node2 = (Node *)malloc(sizeof(Node));
	Node * node3 = (Node *)malloc(sizeof(Node));
	//给节点赋值
	node1->data = 10;
	node2->data = 20;
	node3->data = 30;
	//将所有的数据关联起来（最后一位置空）
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	//令node1为当前节点
	Node *curr = node1;
	//当当前的节点不为空，循环遍历
	while (curr != NULL) {
		printf("%d ", curr->data);
		//更迭下一个节点
		curr = curr->next;
	}
	printf("\n");
	//释放链表：先保存下一个节点，再释放当前节点
	curr = node1;
	while (curr != NULL) {
		Node *nextNode = curr->next;
		free(curr);
		curr = nextNode;
	}
	return 0;
}
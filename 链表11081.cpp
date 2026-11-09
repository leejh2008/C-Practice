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
//要拿到头结点的地址才能找到并修改真正的结点
//头结点不会变，所以不需要返回值，用void
//len：链表长度的地址（因为要修改它）
void add(Node *head, int data, int *len) {
	//调用函数创建新结点
	Node*node = creatNode(data);
	//定义curr指针用来移动（手指）
	Node*curr = head;
	//找到最后一个结点，它的next是NULL
	//curr->next != NULL：停在最后一个结点上
	while (curr->next != NULL) {
		//手指往后移一格
		curr = curr->next;
	}
	//让最后一个结点的next指向新结点，新结点就接到了链表的末尾
	curr->next = node;
	//链表多了一个结点，长度len就+1
	(*len)++;
}


//头插,Node *addHead声明函数返回类型addHead是一个返回结点地址的函数
void addHead(Node **head, int data, int *len) {
	Node*node = creatNode(data);
	Node*curr = *head;
	//新创建的结点变更为头结点
	node->next = curr;
	(*len)++;
	//必须要更新头结点
	*head = node;
}

//插入数据
void insert(Node **head, int index, int data, int *len) {
	//判断下表是否越界

	if (index < 0 || index > (*len)) {
		printf("index超出链表长度，插入失败\n");
		return;
	}
	//头结点赋值给curr
	Node* curr = *head;
	//利用函数创建结点
	Node *node = creatNode(data);
	//判断插入的位置是否是头结点

	if (index == 0) {
		//将表头给到新结点
		node->next = curr;
		*head = node;
		(*len)++;
		//返回新结点
		return;
	}
	//遍历结点,找到下标为index-1的前驱结点

	for (int i = 0; i < index - 1; i++) {
		curr = curr->next;
	}
	//将新结点挤进链表中间：先让新节点接上后半段，再让前半段接上新结点
	//（注意两行的顺序不可以调换）
	node->next = curr->next;
	curr->next = node;
	//长度+1
	(*len)++;
}

//删除指定位置的数据
void removeAt(Node **head, int index, int *len) {
	if (*head == NULL || index < 0 || index > (*len)) {
		printf("index超出链表长度，删除失败\n");
		return ;
	}
	//如果要删除头结点
	if (index == 0) {
		//记住第二个结点的地址
		Node*next = (*head)->next;
		//释放头结点
		free(*head);
		(*len)--;
		//第二个结点成为新的头结点
		*head = next;
		return;
	}
	Node *pre = *head;
	//遍历到下标-1位置处
	for (int i = 0; i < index - 1; i++) {
		//手指向后移一格
		pre = pre->next;
	}
	//当前指向的下一个结点为要删除的结点
	Node*del = pre->next;
	//要删除位置的下一个结点保存到当前的下一个结点
	pre->next = del->next;
	//释放要删除的结点
	free(del);
	(*len)--;
}

//删除指定数据
//头结点可能被删，会让head换人，所以返回Node*
void removes(Node **head, int data, int *len) {
	//pre是前驱指针，头结点没有前驱，所以一开始是NULL
	Node*pre = NULL;
	//curr是当前指针，用来逐个检查结点，从头结点开始
	Node*curr = *head;
	//curr走到NULL说明整条链表遍历完成

	while (curr != NULL) {
		//找到了要检查的数据

		if (curr->data == data) {
			//被删的是头结点

			if (pre == NULL) {
				//让head指向第二个结点
				*head = curr->next;

			} else {
				//前驱绕过curr直接指向curr的下一个结点
				pre->next = curr->next;
			}
			//释放curr
			free(curr);
			(*len)--;
			return;
		}
		//没找到，pre先指向当前结点
		pre = curr;
		//curr再后移到下一个结点
		curr = curr->next;
	}
	printf("没有找到数据 %d,删除失败\n", data);
}

//删除所有相同的结点
void removeAll(Node **head, int data, int *len) {
	Node*pre = NULL;
	Node*curr = *head;
	//统计相同结点的个数
	int count = 0;

	while (curr != NULL) {
		//当前结点是要删除的数据

		if (curr->data == data) {
			//用del记住要删的结点，因为马上要移动curr
			Node*del = curr;
			//curr先移动到下一个结点
			curr = curr->next;
			//删除的是下一个结点
			if (pre == NULL) {
				//head直接指向下一个
				*head = curr;
			} else {
				//前驱直接绕过del，指向curr
				pre->next = curr;
			}
			free(del);
			(*len)--;
			count++;

		} else {
			pre = curr;
			//curr后移到下一个结点
			curr = curr->next;
		}
	}
	//一个都没删，说明链表里面没有这个数据

	if (count == 0) {
		printf("没有找到%d，删除失败\n", data);
	}
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
		printf("下标超出范围，修改失败\n");
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
void reverse(Node **head) {
	Node *pre = NULL;
	Node *curr = *head;
	Node *next = NULL;
	while (curr != NULL) {
		next = curr->next;
		curr->next = pre;
		pre = curr;
		curr = next;
	}
	*head = pre;
}
int main() {
	int index = 2;
	int data = 25;
	int len = 1;
	//定义一个头结点，赋值为10
	Node*head = creatNode(10);
	//调用add尾插函数
	add(head, 20, &len);
	add(head, 30, &len);
	add(head, 40, &len);
	add(head, 40, &len);
	//头插
	addHead(&head, 5, &len);
	//insert函数把新的head用返回值交了回来，再用head=...接收，head不用取值符
	insert(&head, index, data, &len);
	//删除指定位置的数据
	removeAt(&head, 3, &len);
	//删除指定的数据
	removes(&head, 10, &len);
	//删除所有相同的数据
	removeAll(&head, 40, &len);
	change(head, 2, 99, len);
	//按下标查询数据
	findNode(head, 2, len);
	find(head, 99);
	//遍历结点:注意这里是先打印->反转->打印
	printNode(head);
	reverse(&head);
	printNode(head);
	return 0;
}
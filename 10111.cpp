#include <stdio.h>
#include <stdlib.h>

//动态数组功能实现
int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int *arrP = arr; //arr相当于&arr[0]，指针指向第一个元素
	int size = 5;//定义真实存放的元素个数
	int len = 5;//len为数组长度，用来判断数组是否需要扩容
	while (1) {//代表条件恒真，为死循环
		printf("====动态数组====\n");
		printf("====1.添加数据====\n");
		printf("====2.删除数据====\n");
		printf("====3.插入数据====\n");
		printf("====4.查询数据====\n");
		printf("====5.替换数据====\n");
		printf("====0.退出程序====\n");
		printf("====请输入编号====\n");

		int id = 0;//id代表上面的代码
		scanf("%d", &id);
		// 输入 0 表示退出程序
		if (id == 0)
			break;
		switch (id) {
			case 1: { //添加数据
				printf("====1.添加数据->请输入数据：====\n");
				int data = 0;
				//输入要添加的数据
				scanf("%d", &data);
				//如果存入数据的长度等于数组的长度
				if (size == len) {
					//就对原数组两倍扩容
					int nLen = len * 2;
					//使用开辟内存的函数
					int *nArrP = (int *)malloc(nLen *sizeof(int));
					//把旧内存的数据复制给新内存
					for (int i = 0; i < len; i++) {
						nArrP[i] = arrP[i];
					}
					//更新数组的头指针，从此arrP指向新的大内存
					arrP = nArrP;
					//更新容量为新容量
					len = nLen;

				}
				//把新数据存到第一个空位上
				arrP[size] = data;
				//有效数据个数+1
				size++;
				//跳出switch,回到while顶部重新显示菜单
				break;
			}
			case 2: { //删除数据，先保存被删除的数据，把删除位置后面的数据往前移
				printf("====2：删除数据->21：删除指定位置的数据 22：删除指定数据：====\n");
				//用户输入二级菜单编号
				int num = 0;
				scanf("%d", &num);
				//21：按下标删除
				if (num == 21) {
					printf("====21:删除指定位置的数据->请输入数据下标====\n");
					//用户输入下标
					int index = 0;
					scanf("%d", &index);
					// 越界判断
					if (index < 0 || index >= size) {
						printf("下标越界，删除失败\n");
						//没越界才删除

					} else {
						//将要删除的数据先保存起来
						int delData = arrP[index];
						//把删除位置以后的数据整体往前移动一位
						for (int i = index; i < size - 1; i++) {
							arrP[i] = arrP[i + 1];
						}
						//有效数据个数-1
						size--;
						//打印删除结果
						printf("已删除下标%d的数据：%d\n", index, delData);
					}
					//22：按指定数据删除                                        // ┘ B、B' 结束
				} else if (num == 22) {                       // ┘ A：21 分支结束，接 22 分支
					printf("====22:删除指定数据->请输入数据====\n");
					//用户输入要删除的数据
					int data = 0;
					scanf("%d", &data);
					//index设为-1，表示“还没找到”
					int index = -1;
					//从头开始遍历到有效数据末尾
					for (int i = 0; i < size; i++) {
						//如果数据是对应的
						if (arrP[i] == data) {
							//记下它的下标
							index = i;
							break;
						}
					}
					//如果没有找到，就跳出，显示删除失败
					if (index == -1) {
						printf("数据%d不存在，删除失败\n", data);
					} else {
						//找到了，用同样的方式前移删除
						for (int i = index; i < size - 1; i++) {
							arrP[i] = arrP[i + 1];
						}
						size--;
						printf("已删除数据：%d\n", data);
					}
				} else {
					// 既不是 21 也不是 22
					printf("编号错误!\n");
				}
				break;
			}
			case 3: {
				printf("====3:插入数据->请输入插入位置和数据：====\n");
				//定义下表和数据
				int index = 0;
				int data = 0;
				//输入要插入数据的下标和数据
				scanf("%d%d", &index, &data);
				//判断下标越界
				if (index < 0 || index > size) {
					printf("插入位置越界，请重新输入，合法范围是0~%d\n", size);

				} else {
					if (size == len) {
						int nLen = len * 2;
						//使用开辟内存的函数
						int *nArrP = (int *)malloc(nLen *sizeof(int));
						for (int i = 0; i < len; i++) {
							nArrP[i] = arrP[i];
						}
						arrP = nArrP;
						len = nLen;

					}
					//把插入位置后的数据整体后移一位（一定要从后往前移动，否则数据会被覆盖）
					for (int i = size; i > index; i--) {
						arrP[i] = arrP[i - 1];

					}
					//把输入的数据放进腾出来的index位置
					arrP[index] = data;
					//有效长度+1
					size++;
					printf("已在下标%d处插入：%d\n", index, data);

				}
				break;
			}
			case 4: { //查询数据
				printf("====4.查询数据-> 41.按下标查 42.按数据查 ====\n");
				int num = 0;
				scanf("%d", &num);
				if (num == 41) {
					printf("====41:按下标查->请输入下标====\n");
					int index = 0;
					scanf("%d", &index);
					if (index < 0 || index >= size) {
						printf("位置越界，请重新输入，合法范围是0~%d\n", size - 1);
					} else {
						printf("下标%d的数据是：%d\n", index, arrP[index]);
					}

				} else if (num == 42) {
					printf("====42:按数据查询->请输入数据====\n");
					int data = 0;
					scanf("%d", &data);
					int index = -1;
					for (int i = 0; i < size; i++) {
						if (arrP[i] == data) {
							index = i;
							break;
						}
					}
					if (index == -1) {
						printf("数据%d不存在\n", data);
					} else {
						printf("数据%d第一次出现在%d\n", data, index);
					}
				} else {
					printf("编号错误！\n");
				}

				break;

			}
			case 5: {
				printf("====5.替换数据->请输入下标和新数据：====\n");
				int index = 0;
				int data = 0;
				scanf("%d%d", &index, &data);
				if (index < 0 || index >= size) {
					printf("位置越界，请重新输入，合法范围是0~%d\n", size - 1);
				} else {
					printf("替换：下标%d %d->%d\n", index, arrP[index], data);
					arrP[index] = data;
				}

				break;
			}
		}
		printf("Arr当前数组是：");
		//遍历修改后的数组，方便查看修改
		for (int i = 0; i < size; i++) {
			printf("%d", arrP[i]);

		}
		printf("\n");


	}
	return 0;
}
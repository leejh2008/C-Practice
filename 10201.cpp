#include <stdio.h>
//引入标准库，malloc及free要用到
#include <stdlib.h>

//动态数组功能实现
//定义动态数组所需要的函数
//1 打印数据：只读，size传值即可
void println(int *arr, int size) {
	printf("Arr当前数据：");
	//遍历数组，打印有效数据
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//扩容并返回新的数组的首地址
//int *：新首地址用return带回
//*len：容量要改，所以要传地址
int *expand(int *arr, int *len) {
	//新容量=旧容量*2
	int nLen = (*len) * 2;
	//在堆上申请nLen个int空间
	int *nArr = (int *)malloc(nLen *sizeof(int));
	//把数据逐个加入新内存
	for (int i = 0; i < *len; i++) {
		//第i个元素：旧内存读，新内存写
		nArr[i] = arr[i];
	}
	//更新数组的头指针，从此arrP指向新的大内存
	arr = nArr;
	//通过地址修改main里的len
	*len = nLen;
	//将新首地址返回给调用者
	return arr;
}
//添加数据（尾插）
int *add(int *arr, int *size, int *len, int data) {
	//如果存入数据的长度等于数组的长度
	if (*size == *len) {
		//就调用扩容函数，对原数组两倍扩容
		arr = expand(arr, len);
	}
	//把新数据存到第一个空位上
	arr[(*size)] = data;
	//有效数据个数+1
	(*size)++;
	printf("添加数据成功\n");
	return arr;
}
//插入数据：在下标index处插入data
int *insert(int *arr, int *size, int *len, int index, int data) {
	//满了就先扩容
	if (*size == *len) {
		//调用扩容函数，接住扩容后的新首地址
		arr = expand(arr, len);
	}
	//把插入位置后的数据整体后移一位（一定要从后往前移动，否则数据会被覆盖）
	for (int i = *size - 1; i >= index; i--) {
		//前一个元素搬到后一位
		arr[i + 1] = arr[i];
	}
	//将数据放到腾进来的index处
	arr[index] = data;
	//有效长度+1
	(*size)++;
	printf("在%d位置，插入数据%d 操作成功\n", index, data);
	return arr;
}
//del按下标删除
int del(int *arr, int *size, int index) {
	// 越界判断
	if (index < 0 || index >= *size) {
		printf("下标越界，删除失败\n");
		return -1;
		//没越界才删除

	} else {
		//将要删除的数据先保存起来
		int delData = arr[index];
		//把删除位置以后的数据整体往前移动一位
		for (int i = index; i < *size - 1; i++) {
			arr[i] = arr[i + 1];
		}
		//有效数据个数-1
		(*size)--;
		//打印删除结果
		printf("已删除下标%d的数据：%d\n", index, delData);
		return delData;
	}
}
//按数据删除
int delVal(int *arr, int *size, int data) {
	//index设为-1，表示“还没找到”
	int index = -1;
	//从头开始遍历到有效数据末尾
	for (int i = 0; i < *size; i++) {
		//如果数据是对应的
		if (arr[i] == data) {
			//记下它的下标
			index = i;
			break;
		}
	}
	//如果没有找到，就跳出，显示删除失败
	if (index == -1) {
		printf("数据%d不存在，删除失败\n", data);
		return -1;
	}
	//找到了就复用按下标删除，size的地址继续往下传
	return del(arr, size, index);
}
//按下标查询：只读，全部传值
int get(int *arr, int size, int index) {
	if (index < 0 || index >= size) {
		printf("位置越界，请重新输入，合法范围是0~%d\n", size - 1);
		return -1;
	}
	printf("下标%d的数据是：%d\n", index, arr[index]);
	//返回查到的值，以便后期运用
	return arr[index];
}
//按数据查询
int find(int *arr, int size, int data) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == data) {
			printf("数据%d第一次出现在%d\n", data, i);
			return i;
		}
	}
	printf("数据%d不存在\n", data);
	return -1;
}
//替换数据：改数组内容，size不改，传值即可
void set(int *arr, int size, int index, int data) {
	if (index < 0 || index >= size) {
		printf("位置越界，请重新输入，合法范围是0~%d\n", size - 1);
		return;
	}
	printf("替换：下标%d %d->%d\n", index, arr[index], data);
	//用新数据覆盖原来的值
	arr[index] = data;
}

int main() {
	//初始数组
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
				//要写arrP，因为扩容后首地址会变，要接住返回值
				arrP = add(arrP, &size, &len, data);
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
					//调用按下标删除函数
					del(arrP, &size, index);

					//22：按指定数据删除                                        // ┘ B、B' 结束
				} else if (num == 22) {                       // ┘ A：21 分支结束，接 22 分支
					printf("====22:删除指定数据->请输入数据====\n");
					//用户输入要删除的数据
					int data = 0;
					scanf("%d", &data);
					//调用按数据删除函数
					delVal(arrP, &size, data);

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
					//越界时不能插入，正常才调用并接住新地址
					arrP = insert(arrP, &size, &len, index, data);
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
					//只读，传size的值
					get(arrP, size, index);


				} else if (num == 42) {
					printf("====42:按数据查询->请输入数据====\n");
					int data = 0;
					scanf("%d", &data);
					find(arrP, size, data);

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
				//只改数组内容，数组传值
				set(arrP, size, index, data);


				break;
			}
			//其他编号，当所有case都不匹配时进入
			default: {
				printf("编号错误，请输入0~5！\n");
				break;
			}
		}
//遍历修改后的数组，方便查看修改
		println(arrP, size);
	}

//扩容过，退出前释放堆内存
	if (arrP != arr) {
		free(arrP);
		//指针置空
		arrP = NULL;
	}


	return 0;
}
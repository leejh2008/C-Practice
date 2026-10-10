#include <stdio.h>

//选择排序
int main() {
	int arr[100];//定义数组，最多存放100个数
	int n = 0;//实际输入的元素个数
	scanf("%d", &n);//输入数字的个数
	for (int i = 0; i < n; i++) {//输入n个数
		scanf("%d", &arr[i]);
	}
	/*
	//选择排序
	for (int i = 0; i < n - 1; i++) {
		int min = i;//假设a[i]是未排序部分的最小值，记下下标
		//在i之后的元素中找到真正的最小值
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min]) {
				min = j;//发现更小的就更新下标
			}
		}
		//如果真实的最小值不是i，就把最小值换到位置i，假设的最小值换到min
		if (min != i) {
			//引入temp临时变量用来存放arr[i]
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
	//输出结果
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	*/
	//插入排序

	for (int i = 1; i < n; i++) {
		int key = arr[i];//取出待插入的元素
		int j = i - 1;//j指向已排序的最后一个元素
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];//比key大的元素后移一位
			j--;//从后往前
		}
		arr[j + 1] = key;//把key放到空出的位置
	}
	//输出结果
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
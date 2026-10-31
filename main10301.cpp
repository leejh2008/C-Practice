#include <stdio.h>

//Âå¹ÈP5738£º¸è³ª±ÈÈü
typedef struct {
	int score[20];
	double ave;
} Student;

int main() {
	int n, m;
	Student stu[100];
	double best = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int sum = 0;
		int max = 0;
		int min = 10;
		for (int j = 0; j < m; j++) {
			scanf("%d", &stu[i].score[j]);
			sum += stu[i].score[j];
			if (stu[i].score[j] > max)
				max = stu[i].score[j];
			if (stu[i].score[j] < min)
				min = stu[i].score[j];
		}
		stu[i].ave = (double)(sum - max - min) / (m - 2);
		if (stu[i].ave > best)
			best = stu[i].ave;
	}
	printf("%.2f\n", best);
	return 0;
}
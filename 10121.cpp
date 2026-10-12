#include <stdio.h>
#include <math.h>

double distance(double x1, double y1, double x2, double y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
	double x1, x2, x3, y1, y2, y3;
	scanf("%lf %lf", &x1, &y1);
	scanf("%lf %lf", &x2, &y2);
	scanf("%lf %lf", &x3, &y3);
	double ans = distance(x1, y1, x2, y2) + distance(x2, y2, x3, y3) + distance(x1, y1, x3, y3);
	printf("%.2f\n", ans);
	return 0;
}
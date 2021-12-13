#include<stdio.h>
int main()
{
	int m1, m2, r1, r2;
	int y = 0;
	double sum1 = 0.0, sum2 = 0.0,k=0.0;
	scanf("%d %d", &m1, &r1);
	scanf("%d %d", &m2, &r2);
	sum1 = m1 * r1 / 100;
	k = sum1;
	sum2 = m2 * r2 / 100;
	while (1)
	{
		if (sum2 > sum1)
			break;
		y++;
		sum1 += k;
		sum2 += ((m2 + sum2) * r2 / 100);
	}
	printf("%d\n", y);
	printf("%.2lf %.2lf", sum1, sum2);
}
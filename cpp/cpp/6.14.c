#include<stdio.h>
int main()
{
	int i, n;
	double s1[101], s2[101];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%lf", &s1[i]);
	for (i = 0; i < n; i++)
	{
		if (i == 0) s2[i] = s1[i];
		else s2[i] = s1[i] + s2[i - 1];
	}
	for (i = 0; i < n; i++)
		printf("%.2lf ", s1[i]);
	printf("\n");
	for (i = 0; i < n; i++)
		printf("%.2lf ", s2[i]);
}



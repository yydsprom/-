#include<stdio.h>
int main()
{
	int z, i, sum = 0, n;
	scanf("%d", &n);
	for (z = 2; z <= n; z++)//第一个循环遍历2~n间的数字
	{
		for (i = 2; i < z; i++)//第二个循环定义一个大于1的被除数,若i的初始值为1,则1的输出也是素数
			if (z % i == 0)
				break;
		if (z == i)
			printf("%-4d", z);
	}
	return 0;
}
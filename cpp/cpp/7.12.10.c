#include<stdio.h>
#define SF do{\
printf("请选择:\n");\
printf("1.单身\n");\
printf("2.户主\n");\
printf("3.已婚共有\n");\
printf("4.已婚离异\n");\
printf("0.eixt\n");\
scanf("%d",&flag);\
}while(0);

void Sum(double money);

int main()
{
	int flag = 1;
	double money;
	while (flag)
	{
		SF;
		switch (flag)
		{
		case 1:money = 17850.0;
			Sum(money);
			break;
		case 2:money = 23900.0;
			Sum(money);
			break;
		case 3:money = 29750.0;
			Sum(money);
			break;
		case 4:money = 14875.0;
			Sum(money);
			break;
		case 0:break;
		default:break;
		}
	}
}

void Sum(double money)
{
	double sum;
	double m;
	printf("请输入收入:");
	scanf("%lf", &m);
	if (m <= money) sum = m * 0.15;
	else sum = (money * 0.15) + (m - money) * 0.28;
	printf("%.2f\n\n", sum);
}

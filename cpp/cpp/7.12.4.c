#include<stdio.h>
#define STOP '#'
int main()
{
	char ch;
	int cnt = 0;
	while ((ch = getchar()) != STOP)
	{
		if (ch == '.')
		{
			printf("!");
			cnt++;
		}
		else if (ch == '!')
		{
			printf("!!");
			cnt++;
		}
	}
	printf("%d", cnt);
}
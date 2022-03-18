#include<stdio.h>

int main(void)
{
	int i = 0;
	while (getchar() != EOF)
	{		
		i++;
	}

	printf("%d", i);
	return 0;
}
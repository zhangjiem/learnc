#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(int argc, char** argv)
{
	int num;
//	puts("please input num:");
	printf("please input num:");
	scanf("%d", &num);
	printf("empty project.\n\rnum is %d.\n\r",num);
	return 0;
}
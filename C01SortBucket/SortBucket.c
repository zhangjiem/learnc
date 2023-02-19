#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXDATA 100
int main(int argc, char** argv) {

	int bucket[MAXDATA+1];
	int i;

	for (i = 0; i <= MAXDATA; i++) {
		bucket[i] = 0;
	}
	int num;
	int data;
	//	puts("please input num:");
	printf("please input number of bucket:");
	scanf("%d", &num);
	printf("please input %d buckets:\n\r", num);

	for (i = 1; i <= num; i++) {
		scanf("%d", &data);
		if (data > MAXDATA)data = MAXDATA;
		bucket[data]++;
	}

	for (i = 1; i <= MAXDATA; i++)
		while (bucket[i]) {
			printf("%d ", i);
			bucket[i]--;
		}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXDATA 100
#define NUMDATA 10

int datalistpre[NUMDATA] = { 23,98,23,21,75,3,32,23,90,61 };
int datalistpost[NUMDATA] = { 0 };

void SortBucket(int num) {
	int i;
	int j;
	int * pbucket=NULL;
	int tmp;

	pbucket = (int*)malloc((MAXDATA + 1) * sizeof(int));

	memset(pbucket, 0, (MAXDATA + 1) * sizeof(int));

	for (i = 0; i < NUMDATA; i++) {
		tmp = datalistpre[i];
		if (tmp > MAXDATA)tmp = MAXDATA;
		pbucket[tmp]++;
	}

	j = 0;
	for (i = 1; i <= MAXDATA; i++) {
		while (pbucket[i]--)datalistpost[j++] = i;
	}
	free(pbucket);	
}

void SortBubble(int num) {
	int i;
	int j;

	int tmp;

	for(i=0;i<num-1;i++)
		for (j = i + 1; j < num; j++) {
			if (datalistpost[j] < datalistpost[i]) {
				tmp = datalistpost[j];
				datalistpost[j] = datalistpost[i];
				datalistpost[i] = tmp;
			}
		}

}
void SortQuick(int begin, int end) {
	int i = begin;
	int j = end;
	int tmp;
	int flag;

	if (begin < end) {
		flag = datalistpost[i];
		while (i < j) {
			while ((i < j) && (datalistpost[j]>flag))
			{
				j--;
			}
			if (i < j) {
				datalistpost[i] = datalistpost[j];
				i++;
			}
			while ((i < j) && (datalistpost[i] < flag)) 
			{
				i++;
			}
			if (i < j) {
				datalistpost[j] = datalistpost[i];
				j--;
			}
		}
		datalistpost[i] = flag;
		SortQuick(begin, i - 1);
		SortQuick(i + 1, end);
	}

}

int main(int argc, char** argv) {

	int i;
	int num = NUMDATA;

	puts("data need to sort:");
	for (i = 0; i < num; i++) {
		printf("%d ", datalistpre[i]);
	}
	puts("\n\rdata sorted:");

	for (i = 0; i < num; i++) {
		datalistpost[i] = datalistpre[i];
	}

	//sort:bucket sort.
	//SortBucket(num);
	//sort:bubble sort.
	//SortBubble(num);
	//sort:quick sort.
	SortQuick(0,num-1);

	for (i = 0; i < num; i++) {
		printf("%d ", datalistpost[i]);
	}

	return 0;
}
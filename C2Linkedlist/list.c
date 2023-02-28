#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int data[100];
int left[100] = { 4,1,6,8,2,9,10,0,3,5,7,-1 };

void SortQuick(int * list,int begin, int end) {
	int i = begin;
	int j = end;
	int tmp;
	int flag;

	if (begin < end) {
		flag = list[i];
		while (i < j) {
			while ((i < j) && (list[j] > flag))
			{
				j--;
			}
			if (i < j) {
				list[i] = list[j];
				i++;
			}
			while ((i < j) && (list[i] < flag))
			{
				i++;
			}
			if (i < j) {
				list[j] = list[i];
				j--;
			}
		}
		list[i] = flag;
		SortQuick(list,begin, i - 1);
		SortQuick(list,i + 1, end);
	}

}

void main(int argc, char** argv) {

	int num;
	int i;
	int l;

	l = sizeof(left) / left[0];
	num = 0;
	for (i = 0; i < l; i++) { if (left[i] < 0)break; }
	num = i;
	printf("num of nodes is %d.\n\r",num);
	printf("list of data is:\n\r");
	for (i = 0; i < num; i++) {
		if (left[i] >= 0)scanf("%d", &data[left[i]]);
	}

	SortQuick(data, 0, num-1);
	printf("list nodes are:");
	for (i = 0; i < num; i++) {
		printf("%d ", data[i]);
	}

}
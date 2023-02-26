#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queue {
	int data[100];
	int head;
	int tail;
};

struct stack
{
	int data[21];
	int top;
};

int main(int argc, char** argv) {

	struct queue play1, play2;
	struct stack desktop;

	int card1[10] = { 3,5,9,2,3,7,8,5,1,6 };
	int card2[10] = { 7,1,9,4,5,2,9,4,7,4 };
	int mark[11] = { 0 };
	int i;
	int tmp;
	int tmp1;

	play1.head = 1;
	play1.tail = 1;
	play2.head = 1;
	play2.tail = 1;

	desktop.top = 0;
	for (i = 1; i <= 10; i++)mark[i] = 0;

	for (i = 0; i < 10; i++) { play1.data[play1.tail] = card1[i]; play1.tail++; }
	for (i = 0; i < 10; i++) { play2.data[play2.tail] = card2[i]; play2.tail++; }

	while (play1.head < play1.tail && play2.head < play2.tail) {
		//play1 take a card;
		tmp = play1.data[play1.head];
		if (mark[tmp] == 0) { //no mark card
			play1.head++;
			desktop.top++;
			desktop.data[desktop.top] = tmp;
			mark[tmp]++;
		}
		else {//have mark card
			play1.head++;
			play1.data[play1.tail] = tmp;
			play1.tail++;
			while (desktop.data[desktop.top] != tmp) {
				tmp1 = desktop.data[desktop.top];
				desktop.top--;
				mark[tmp1]--;
				play1.data[play1.tail] = tmp1;
				play1.tail++;
			}
			tmp1 = desktop.data[desktop.top];
			desktop.top--;
			mark[tmp1]--;
			play1.data[play1.tail] = tmp1;
			play1.tail++;
		}
		if (play1.head == play1.tail)break;
		//play2 take a card;
		tmp = play2.data[play2.head];
		if (mark[tmp] == 0) {
			play2.head++;
			desktop.top++;
			desktop.data[desktop.top] = tmp;
			mark[tmp]++;
		}
		else {
			play2.head++;
			play2.data[play2.tail] = tmp;
			play2.tail++;
			while (desktop.data[desktop.top] != tmp) {
				tmp1 = desktop.data[desktop.top];
				desktop.top--;
				mark[tmp1]--;
				play2.data[play2.tail] = tmp1;
				play2.tail++;
			}
			tmp1 = desktop.data[desktop.top];
			desktop.top--;
			mark[tmp1]--;
			play2.data[play2.tail] = tmp1;
			play2.tail++;
		}
		if (play2.head == play2.tail)break;
	}

	if (play2.head == play2.tail) {
		printf("play1 win.\ncard in play1 is ");
		for (i = play1.head; i < play1.tail; i++) { printf("%d ", play1.data[i]); }
		putchar('\n');
		if (desktop.top > 0) {
			printf("card in desktop is ");
			for(i=1;i<=desktop.top;i++){ printf("%d ", desktop.data[i]); }
		}
		else printf("no card in desktop.\n");
	}
	else {
		printf("play2 win.\ncard in play2 is ");
		for (i = play2.head; i < play2.tail; i++) { printf("%d ", play2.data[i]); }
		putchar('\n');
		if (desktop.top > 0) {
			printf("card in desktop is ");
			for (i = 1; i <= desktop.top; i++) { printf("%d ", desktop.data[i]); }
		}
		else printf("no card in desktop.\n");

	}
	return 0;
}
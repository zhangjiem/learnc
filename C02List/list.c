#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct listnode {
	int data;
	struct listnode* next;
};

void main(int argc, char** argv) {
	struct listnode* head, * p, * q;
	struct listnode* t;
	int num;
	int tmp;
	int i;

	head = NULL;
	p = NULL;
	q = NULL;

	printf("please input num of nodes:");
	scanf("%d", &num);
	printf("\n\r");
	for (i = 0; i < num; i++) {
		scanf("%d", &tmp);
		t = (struct listnode*)malloc(sizeof(struct listnode));
		t->data = tmp;
		t->next = NULL;
		if (head == NULL) { head = t; p = t; q = NULL; }
		else {
			p->next = t;
			p = t;
		}
	}

	printf("list nodes are:");
	for (t = head; t != NULL; t = t->next) {
		printf("%d ", t->data);
	}

}
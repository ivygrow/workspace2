//2.1 防止内存溢出
//2.2
#include<stdio.h>
#include<stdlib.h>
const int size_max = 1e5 + 10;

typedef struct SNode {
	struct SNode* next;
	int data;
}Stack;

Stack* creatStack() {
	Stack* head;
	head = (Stack*)malloc(sizeof(struct SNode));
	head->next = NULL;
	head->data = 0;
}

int isEmpty(Stack* p) {
	if (p->next == NULL) {
		return 1;
	}
	return 0;
}

int isFull(Stack* head) {
	if (head->data == size_max) {
		printf("The stack is full\n");
		return 1;
	}
	return 0;
}

void pu(Stack* head, int items) {
	if (isFull(head))return;
	Stack* tmp = (Stack*)malloc(sizeof(struct SNode));
	tmp->data = items;
	tmp->next = head->next;
	head->next = tmp;
	head->data++;
}

int pop(Stack* head) {
	head->data--;
	Stack* p = head->next;
	int res = p->data;
	head->next = p->next;
	free(p);
	return res;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	while (~scanf("%d", &n), n != -1) {
		Stack* ADT = creatStack();
		printf("%d--->", n);
		if (n == 0) {
			printf("0\n");
			return 0;
		}
		while (n > 0) {
			push(ADT, n % 2);
			n /= 2;
		}
		while (!isEmpty(ADT)) {
			printf("%d", pop(ADT));
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
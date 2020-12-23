#include "ArrayStack.h"

void error(char* str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
};

void initStack(Stack* s) {
	s->top = -1;
}

int isEmpty(Stack* s) {
	if (s->top == -1) return 1;
	else return 0;
}

int isFull(Stack* s) {
	if (s->top == MAX_STACK_SIZE) return 1;
	else return 0;
}

int size(Stack* s) {
	return s->top + 1;
}

void push(Stack* s, Element e) {
	if (isFull(s)) {
		printf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else {
		s->top++;
		s->data[(s->top)] = e;
	}
}

Element pop(Stack* s) {
	char ch2;
	if (isEmpty(s)) {
		printf(stderr, "���� ���� ����\n");
		return;
	}
	else {
		ch2 = s->data[s->top];
		s->top--;
		return ch2;
	}
}

Element peek(Stack* s) {
	if (isEmpty(s)) {
		printf(stderr, "���� ���� ����\n");
	}
	else return s->data[(s->top)];
}

void display(Stack* s, char* msg) {
	int i;
	printf("%s[%2d]= ", msg, size(s));
	for (i = 0; i <= s->top; i++)
		printElem(s->data[i]);
	printf("\n");
}

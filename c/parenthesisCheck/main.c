#include "ArrayStack.h"
#include "CommentChk.h"

int bracketChecker(char* filename) {
	// test {
	/* [[[ */

	int nLine = 1, nChar = 0,nCharLine = 0;	//��,�ܾ�,�� �ٴ� �ܾ�
	int commentChk = 0, commentsChkStart = 0, commentsChkEnd = 0, sQuotationChk = 0, dQuotationChk=0; //     //�ּ� üũ ,  /*  */ ���۰� �� üũ , ��������ǥ üũ, ū ����ǥ üũ
	char	ch, ch2;
	Stack	stack;

	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
		error("Error: The file does not exist.\n");

	initStack(&stack);										//���ü���
	while ((ch = getc(fp)) != EOF) {
		nChar++;											//�ѹ� ���� ������ �ܾ�� �߰�
		nCharLine++;										//�ѹ� ���� ������ �� �ٿ� �ִ� �ܾ� �� �߰�

		/*�ּ�����Ȯ���Լ��� �ΰ��� �Է��� �������� Ȯ���� �� ������ �ǹǷ� �տ��� ���� �����Ű��
		����ǥȮ���Լ��� �Ѱ��� ���ڸ� �޾Ƶ� ����ǹǷ� �ڷ� �ּ� �ּ������� ���� ���� ������� �ʵ��� �Ѵ�.*/

		if (commentLineChk(&commentChk, ch,&sQuotationChk,&dQuotationChk)) {	// //�ּ� üũ �Լ�
			continue;															// ���ϸ��� ����Ǵ� �Լ��̹Ƿ� ����ó���� �Լ������� ����ǥ�� ���ش�.
		}
		if (commentsChk(&commentsChkStart, &commentsChkEnd, ch,&sQuotationChk,&dQuotationChk)) {	// /**/ �ּ� üũ�Լ�
			commentChk = 0;													// /**/ �ּ����� //�� ���� �� �����Ƿ� �ּ�üũ������ ��� �ʱ�ȭ���ش�.
			continue;
		}
		if (singleQuotationChk(&sQuotationChk, ch, &dQuotationChk)) {
			commentChk = 0;													//����ǥ ���� //�� /**/�� ������ �� �����Ƿ� �ּ�üũ ������ ��� �ʱ�ȭ���ش�.
			commentsChkStart = 0;
			continue;
		}
		if (doubleQuotationChk(&dQuotationChk, ch)) {
			commentChk = 0;													//����ǥ ���� //�� /**/�� ������ �� �����Ƿ� �ּ�üũ ������ ��� �ʱ�ȭ���ش�.
			commentsChkStart = 0;
			continue;
		}

		if (ch == '\n') {													//���� �ٲ�� nLine++ �� ���κ����ڼ��� 0���� �ʱ�ȭ
			nLine++;
			nCharLine = 0;
		}

		if (ch == '(' || ch == '{' || ch == '[') {							//���� ���ڰ� ���� ��ȣ�Ͻ� push
			push(&stack, ch);
		}
		if (ch == ')') {													//������ ��ȣ�Ͻ� ch2�� ������pop��Ų�� ch2�� ¦�� �´��� Ȯ��
			ch2 = pop(&stack);
			if (ch2 == '(') {
				continue;
			} else break;
		}
		if (ch == '}') {
			ch2 = pop(&stack);
			if (ch2 == '{') {
				continue;
			}
			else break;
		}
		if (ch == ']') {
			ch2 = pop(&stack);
			if (ch2 == '[') {
				continue;
			} else break;
			}
		}
	fclose(fp);
	printf("[%s] File check result:\n", filename);
	if (isEmpty(&stack) == 0)													//������ ���� �˻��ߴµ� ������ ������������� ����
		printf("  Error found (#line=%d, #char=%d)\n\n", nLine, nCharLine);
	else
		printf("  Ok (#line=%d, #char=%d)\n\n", nLine, nChar);
	return isEmpty(&stack);
}
void main() {
	bracketChecker("ArrayStack.h");
	bracketChecker("ArrayStack.c");
	bracketChecker("BracketChecker.c");
}
#include "CommentChk.h"

bool commentLineChk(int* chk, char ch,int* singleQuotationChk,int* doubleQuotationChk) {	// //�ּ�üũ��,���繮��,Ȭ����ǥüũ��,�ֵ���ǥüũ��
	if ((*singleQuotationChk) == 1 || (*doubleQuotationChk) == 1) return false;				//����ǥ���θ� return  false

	switch (*chk) {																			// //�ּ�üũ���� ����  0: �ּ��� ������� ���� 1:���� ���ڰ� /�� ���� 2:�������� /�� �ΰ� �޾Ƽ� �ּ� ����
	case 0:																					// 0�϶� ���繮�ڰ� / ��� �ּ�üũ�� 1����
		if (ch == '/') (*chk)++;
		return false;
	case 1:																					// 1�϶� ���繮�ڰ� /��� �ּ�üũ�� 1���� �ƴҰ�� 0���� ����
		if (ch == '/') (*chk)++;
		else *chk=0;
		return false;
	case 2:																					// 2�϶� ���繮�ڰ� \n�̶�� �ּ�üũ�� 0���� �ʱ�ȭ \n�� �ƴ϶�� return true;
		if (ch == '\n') {
			*chk = 0;
			return true;
		}
		else return true;
	}
}

bool commentsChk(int* ChkStart,int* ChkEnd,char ch, int* singleQuotationChk, int* doubleQuotationChk) { // /**/�ּ�üũ���۰���,���繮��,Ȭ����ǥüũ��,�ֵ���ǥüũ��
	if ((*singleQuotationChk) == 1 || (*doubleQuotationChk) == 1) return false;							//����ǥ ���θ� return false;

	switch (*ChkStart) {																				// /* �񱳽��� 0: �ּ��� ���þ��� ���� 1:�������ڰ� /�λ��� 2: �������� /*�� �Է¹޾Ƽ� �ּ�����
	case 0:																								//0�϶� ���繮�ڰ� /��� �ּ�üũ�� 1����
		if (ch == '/') (*ChkStart)++;			
		return false;
	case 1:																								//1�϶� ���繮�ڰ� *�̶�� �ּ�üũ�� 1���� �ƴҰ�� 0���� ����
		if (ch == '*') (*ChkStart)++;
		else *ChkStart=0;
		return false;
	case 2:																								//2�϶� End���� 0�̰� ���繮�ڰ� *�̶�� end�� 1����
		if ((*ChkEnd)==0 && ch == '*') {																//end���� 1�̰� ���繮�ڰ� / ��� chk�� ���� 0���� �ʱ�ȭ �ƴҰ�� end�� 0���� ���� �� return true;
			*ChkEnd = 1;
			return true;
		}

		if ((*ChkEnd) == 1 && ch == '/') {
			*ChkStart = 0;
			*ChkEnd = 0;
			return true;
		}
		else *ChkEnd = 0;
		return true;
	}
}

bool singleQuotationChk(int* chk, char ch, int* doubleQuotationChk) {									//üũ�� ���繮�� �ֵ���ǥüũ��
	if ((*doubleQuotationChk) == 1) return false;														//�ֵ���ǥ ���θ� return false;
																										
	switch(*chk) {																						//üũ���񱳽��� 0: ����ǥ�� ���þ��� ���� 1:����ǥ����
	case 0:																								//0�ϰ�� ���繮�ڰ� '��� üũ�� 1���� return true;
		if (ch == "'") {
			(*chk)++;
			return true;
		}
		else return false;
	case 1:																								//1�ϰ�� ���繮�ڰ� '��� üũ�� 1���� �ƴҰ�� return true;
		if (ch == "'") {
			*chk = 0;
			return true;
		}
		else return true;
		}
}

bool doubleQuotationChk(int* chk, char ch) {									//üũ�� ���繮�� Ȭ����ǥüũ�Լ��� true�϶� �� �Լ��� ������� �����Ƿ� Ȭ����ǥüũ���� ������ �ʿ䰡 ����.
	
	switch (*chk) {																//üũ�� �� ���� 0: ����ǥ�� ���þ��� ���� 1:����ǥ����
	case 0:																		//0�ϰ�� ���繮�ڰ� '��� üũ�� 1���� return true;
		if (ch == '"') {	
			(*chk)++;
			return true;
		}
		else return false;
	case 1:																		//1�ϰ�� ���繮�ڰ� '��� üũ�� 1���� �ƴҰ�� return true;
		if (ch == '"') {
			*chk = 0;
			return true;
		}
		else return true;
	}
}
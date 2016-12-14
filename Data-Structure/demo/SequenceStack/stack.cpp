#include "stdio.h"
#include "string.h"
#include "malloc.h"
#include "SequenceStack.h"
#include "sequenceStack.cpp"

int main(int argc, char const *argv[])
{
	SqStack S;
	ElemType e;

	// ��ʼ��ջ
	InitStack_Sq(S, 5, 5);

	// ��ջ
	printf("%s\n", "\n--- ��ջ ---");
	printf("%s\n", "abcba ��ջ");
	Push_Sq(S, 'a');
	Push_Sq(S, 'b');
	Push_Sq(S, 'c');
	Push_Sq(S, 'b');
	Push_Sq(S, 'a');
	printf("%s", "��ӡջ ");
	Print_Sq(S);

	// ȡջ��Ԫ��
	printf("%s\n", "\n--- ȡջ��Ԫ�� ---");
	GetTop_Sq(S, e);
	printf("ջ��Ԫ��Ϊ %c\n", e);

	// �ж��Ƿ����
	printf("%s\n", "\n--- �������ж� ---");
	printf("�Ƿ�Ϊ������ %s\n", IsPalNumber_Sq(S) ? "yes" : "no");

	// ��ջ
	printf("%s\n", "\n--- ��ջ ---");
	Pop_Sq(S, e);
	printf("��ջԪ��Ϊ %c\n", e);
	printf("%s", "��ӡջ ");
	Print_Sq(S);

 
	// ��ջ
	printf("%s\n", "\n--- ��ջ ---");
	printf("%s\n", "a554789 ��ջ");
	Status p1 = Push_Sq(S, 'a');
	Status p2 = Push_Sq(S, '5');
	Status p3 = Push_Sq(S, '5');
	Status p4 = Push_Sq(S, '4');
	Status p5 = Push_Sq(S, '7');
	Status p6 = Push_Sq(S, '8');
	Status p7 = Push_Sq(S, '9');
	printf("%s", "��ӡջ ");
	Print_Sq(S);

	getchar();
	return 0;
}
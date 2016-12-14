#include "stdio.h"
#include "string.h"
#include "malloc.h"
#include "SequenceStack.h"
#include "sequenceStack.cpp"

int main(int argc, char const *argv[])
{
	SqStack S;
	ElemType e;

	// 初始化栈
	InitStack_Sq(S, 5, 5);

	// 入栈
	printf("%s\n", "\n--- 入栈 ---");
	printf("%s\n", "abcba 入栈");
	Push_Sq(S, 'a');
	Push_Sq(S, 'b');
	Push_Sq(S, 'c');
	Push_Sq(S, 'b');
	Push_Sq(S, 'a');
	printf("%s", "打印栈 ");
	Print_Sq(S);

	// 取栈顶元素
	printf("%s\n", "\n--- 取栈顶元素 ---");
	GetTop_Sq(S, e);
	printf("栈顶元素为 %c\n", e);

	// 判断是否回文
	printf("%s\n", "\n--- 回文数判断 ---");
	printf("是否为回文数 %s\n", IsPalNumber_Sq(S) ? "yes" : "no");

	// 出栈
	printf("%s\n", "\n--- 出栈 ---");
	Pop_Sq(S, e);
	printf("出栈元素为 %c\n", e);
	printf("%s", "打印栈 ");
	Print_Sq(S);

 
	// 入栈
	printf("%s\n", "\n--- 入栈 ---");
	printf("%s\n", "a554789 入栈");
	Status p1 = Push_Sq(S, 'a');
	Status p2 = Push_Sq(S, '5');
	Status p3 = Push_Sq(S, '5');
	Status p4 = Push_Sq(S, '4');
	Status p5 = Push_Sq(S, '7');
	Status p6 = Push_Sq(S, '8');
	Status p7 = Push_Sq(S, '9');
	printf("%s", "打印栈 ");
	Print_Sq(S);

	getchar();
	return 0;
}
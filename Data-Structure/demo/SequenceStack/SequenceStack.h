#define TRUE 1;
#define FALSE 0;
#define OK 1;
#define ERROR 0;
#define OVERFLOW -1; //�ڴ治��

// �� ElemType ������ַ�
typedef char ElemType;

// ����״̬��
typedef int Status;

// ����ʵ��˳��ջ�����ݽṹ SqStack
typedef struct {
	ElemType *elem; // ����ռ��ַ
	int top;	// ջ��Ԫ�ص���һ��λ�ã�ע�⣬����һ��λ�ã�
	int size;	// ��ǰ����Ĵ�������
	int increment; // ����ʱ������
} SqStack;
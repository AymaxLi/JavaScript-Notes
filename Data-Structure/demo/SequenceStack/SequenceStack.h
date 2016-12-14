#define TRUE 1;
#define FALSE 0;
#define OK 1;
#define ERROR 0;
#define OVERFLOW -1; //内存不足

// 把 ElemType 定义成字符
typedef char ElemType;

// 定义状态量
typedef int Status;

// 定义实现顺序栈的数据结构 SqStack
typedef struct {
	ElemType *elem; // 储存空间基址
	int top;	// 栈顶元素的下一个位置（注意，是下一个位置）
	int size;	// 当前分配的储存容量
	int increment; // 扩容时的增量
} SqStack;
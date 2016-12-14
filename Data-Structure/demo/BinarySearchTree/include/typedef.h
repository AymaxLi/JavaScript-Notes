typedef int Status;
typedef int KeyType;
typedef struct RcdType {
	KeyType key;
} RcdType;

typedef struct BSTNode {
	RcdType data;
	BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

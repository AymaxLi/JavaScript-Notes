
typedef int GraphKind;
typedef int Status;

typedef struct VexType {
	char name[20];
	char id[4];
	int level;
	char introduce[100];
} VexType;

typedef struct ArcType {
	VexType v, w;
	int distance;
	char name[20];
} ArcType;

typedef struct AdjVexNode {
	int vexsIndex;
	VexType vex;
	ArcType arc;
	AdjVexNode *nextArc; // next AdjVexNode
} AdjVexNode, *AdjVexNodeP;

typedef struct VexNode {
	VexType vex;
	ArcType arc;
	int degree;
	struct AdjVexNode *firstArc; // first AdjVexNode
} VexNode;

typedef struct {
	VexNode *vexsNodes; // vexsNode array
	int n, e; // vexs count adnd Arc count
	GraphKind kind;
	int *tags; // tagged array
} ALGraph;

typedef struct {
	int prev; // the index of prev node
	int lowcost; // 当前最短路径的长度
} DistInfo;
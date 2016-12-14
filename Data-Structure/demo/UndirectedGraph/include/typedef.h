typedef int VexType;
typedef int GraphKind;
typedef int Status;
typedef int ArcInfo;

typedef struct AdjVexNode {
	int adjvex; // location in the vexs array
	AdjVexNode *nextArc; // next AdjVexNode
	ArcInfo info; // weighted value
} AdjVexNode, *AdjVexNodeP;

typedef struct VexNode {
	VexType data;
	struct AdjVexNode *firstArc; // first AdjVexNode
} VexNode;

typedef struct {
	VexNode *vexs; // vexs array
	int n, e; // vexs count adnd Arc count
	GraphKind kind;
	int *tags; // tagged array
} ALGraph;
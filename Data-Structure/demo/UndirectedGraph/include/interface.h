Status createGraph_AL(ALGraph &G, GraphKind kind, VexType *vexs, int n, ArcType *arcs, int e);
VexType searchVex_AL(ALGraph G, char *name);
Status Dijkstra(ALGraph &G, int i, DistInfo Dist[]);
void OutputPath(ALGraph G, DistInfo *Dist, int k);
int getVexIndexByName(char name[], VexNode *vexNodes, int n);
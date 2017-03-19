/**
 * get vex from a vex array
 * @param  id   id of the vex
 * @param  vexs vexs' array
 * @param  n    count of vexs
 * @return      the vex
 */
VexType getVex(char id[], VexType *vexs, int n) {
	for (int i = 0; i < n; ++i) {
		if(strcmp(vexs[i].id, id) == 0) return vexs[i];
		// else printf("%s %s %s \n", "haha找不到", id, vexs[i].id);
	}
	// return NULL;
}

/**
 * get vex's index in vexs' array
 * @param  id   id of the vex
 * @param  vexs vexs' array
 * @param  n    count of vexs
 * @return      the index
 */
int getVexIndex(char id[], VexType *vexs, int n) {
		for (int i = 0; i < n; ++i) {
		if(strcmp(vexs[i].id, id) == 0) return i;
		// else printf("%s %s %s \n", "haha找不到", id, vexs[i].id);
	}
}

int getVexIndexByName(char name[], VexNode *vexNodes, int n) {
		for (int i = 0; i < n; ++i) {
		if(strcmp(vexNodes[i].vex.name, name) == 0) return i;
		// else printf("%s %s %s \n", "haha找不到", id, vexs[i].id);
	}
}

/**
 * create a AdjVexNode
 * @param  id   id of the vex
 * @param  vexs the vexs' array
 * @param  n    count of vexs
 * @param  arcs the arcs' array
 * @param  e    count of arcs
 * @return      the AdjVexNode
 */
AdjVexNode* createAdjVexNode(char id[] ,VexType *vexs, int n, ArcType *arcs, int e) {
	AdjVexNode *temp;
	temp = (AdjVexNode*)malloc(sizeof(AdjVexNode));
	temp->vex = getVex(id, vexs, n);
	// printf("%s\n", temp->vex.id);
	temp->vexsIndex = getVexIndex(id, vexs, n);
	return temp;
}


/**
 * create a Grahp
 * @param  G    container
 * @param  kind kind of the Graph
 * @param  vexs vexs' array
 * @param  n    count of vexs
 * @param  arcs arcs' array
 * @param  e    count of arcs
 * @return      a status code
 */
Status createGraph_AL(ALGraph &G, GraphKind kind, VexType *vexs, int n, ArcType *arcs, int e) {
	G.kind = kind;
	G.n = n;
	G.e = e;
	G.tags = (int*)malloc(sizeof(int) * n);
	G.vexsNodes = (VexNode*)malloc(sizeof(VexNode) * n);
	for (int i = 0; i < n; ++i) {
		G.vexsNodes[i].vex = vexs[i];
		G.vexsNodes[i].degree = 0;
		for (int j = 0; j < e; ++j) {
			// printf("%s %s %d\n", G.vexsNodes[i].vex.id, arcs[j].v.id, strcmp(G.vexsNodes[i].vex.id, arcs[j].v.id));
			char *thisId, *nextId;
			thisId = G.vexsNodes[i].vex.id;
			nextId = (strcmp(thisId, arcs[j].v.id) == 0) ? arcs[j].w.id
								: (strcmp(thisId, arcs[j].w.id) == 0) ? arcs[j].v.id
								:	NULL;
			if(nextId){
			// printf("%s  %s\n", thisId, nextId);
				if(G.vexsNodes[i].degree > 0) {
					G.vexsNodes[i].degree ++;
					AdjVexNodeP p = G.vexsNodes[i].firstArc;
					while(p->nextArc != NULL) {
						p = p->nextArc;
					}
					p->nextArc = createAdjVexNode(nextId, vexs, n, arcs, e);
					p->nextArc->arc = arcs[j];
					// printf("%s   %s   %s\n", G.vexsNodes[i].vex.name, "add", p->nextArc->vex.name);
				} else {
					G.vexsNodes[i].degree ++;
					G.vexsNodes[i].firstArc = createAdjVexNode(nextId, vexs, n, arcs, e);
					G.vexsNodes[i].firstArc->arc = arcs[j];
					// printf("%s   %s   %s\n", G.vexsNodes[i].vex.name, "init and add ", G.vexsNodes[i].firstArc->vex.name);
				}
			}
		}
	}
}

/**
 * search a vex in Graph
 * @param  G    the Graph
 * @param  name the name of vex
 * @return      teh vex
 */
VexType searchVex_AL(ALGraph G, char *name) {
	for (int i = 0; i < G.n; ++i) {
		if (strcmp(G.vexsNodes[i].vex.name, name) == 0) {
			return G.vexsNodes[i].vex;
		}
	}
}

/**
 * get the shortest path by Dijkstra
 * @param  G    the ALGraph
 * @param  i    the index of start node
 * @param  Dist 
 * @return      a status code
 */
Status Dijkstra(ALGraph &G, int i, DistInfo Dist[]) {
	int j, m, k, min;
	AdjVexNodeP p;
	// Dist = (DistInfo*)malloc(*G.n * sizeof(DistInfo));
	if(Dist == NULL) return OVERFLOW;

	for(j = 0; j < G.n; j++) {
		Dist[j].lowcost = INFINITY;
		G.tags[j] = UNSELECTED;
	}
	for(p = G.vexsNodes[i].firstArc; p != NULL; p = p->nextArc) {
		Dist[p->vexsIndex].prev = i;
		Dist[p->vexsIndex].lowcost = p->arc.distance;
	}
	Dist[i].prev = -1;
	Dist[i].lowcost = 0;
	G.tags[i] = SELECTED;
	for(m = 1; m < G.n; m++) {
		min = INFINITY;
		k = 0;

		for(j = 0; j < G.n; j++) {
			// printf("%d\n", Dist[j].lowcost);
			if(G.tags[j] == UNSELECTED && Dist[j].lowcost < min) {
				k = j;
				min = Dist[k].lowcost;
			}
		}
		// printf("%d\n", k);
		G.tags[k] = SELECTED;
		for(p = G.vexsNodes[k].firstArc; p != NULL; p = p->nextArc) {
			j = p->vexsIndex;
			if(G.tags[j] == UNSELECTED && Dist[k].lowcost + p->arc.distance < Dist[j].lowcost) {
				Dist[j].lowcost = Dist[k].lowcost + p->arc.distance;
				Dist[j].prev = k;
			}
		}
	}
	return OK;
}

/**
 * print the road
 */
void OutputPath(ALGraph G, DistInfo *Dist, int k) {
	if (-1 == k) return;
	OutputPath(G, Dist, Dist[k].prev);
	printf("-> %s ", G.vexsNodes[k].vex.name);
}
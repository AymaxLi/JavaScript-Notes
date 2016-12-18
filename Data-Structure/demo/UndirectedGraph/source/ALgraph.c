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
					printf("%s   %s   %s\n", G.vexsNodes[i].vex.name, "add", p->nextArc->vex.name);
				} else {
					G.vexsNodes[i].degree ++;
					G.vexsNodes[i].firstArc = createAdjVexNode(nextId, vexs, n, arcs, e);
					G.vexsNodes[i].firstArc->arc = arcs[j];
					printf("%s   %s   %s\n", G.vexsNodes[i].vex.name, "init and add ", G.vexsNodes[i].firstArc->vex.name);
				}
			}
		}
	}
}

VexType searchVex_AL(ALGraph G, char *name) {
	for (int i = 0; i < G.n; ++i) {
		if (strcmp(G.vexsNodes[i].vex.name, name) == 0) {
			return G.vexsNodes[i].vex;
		}
	}
}
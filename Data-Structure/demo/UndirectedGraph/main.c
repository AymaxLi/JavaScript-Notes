#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "./include/define.h"
#include "./include/typedef.h"
#include "./include/interface.h"
#include "./source/ALgraph.c"
#include "./view/view.c"

void initTestData(ALGraph &G) {
	VexType vexs[10];
	strcpy(vexs[0].id, "0011");
	strcpy(vexs[0].name, "聪神直播间");
	strcpy(vexs[0].introduce, "充满激情的地方");	
	vexs[0].level = 4;
	strcpy(vexs[1].id, "0203");
	strcpy(vexs[1].name, "papi酱的小黑屋");
	strcpy(vexs[1].introduce, "神秘的小黑屋");
	vexs[1].level = 5;
	strcpy(vexs[2].id, "0255");
	strcpy(vexs[2].name, "工一");
	strcpy(vexs[2].introduce, "打码的地方");
	vexs[2].level = 5;
	strcpy(vexs[3].id, "0256");
	strcpy(vexs[3].name, "工二");
	strcpy(vexs[3].introduce, "工一隔壁");
	vexs[3].level = 3;


	ArcType arcs[10];
	arcs[0] = {
		.v = vexs[0],
		.w = vexs[1],
		.distance = 25
	};
	strcpy(arcs[0].name, "heihei路");
	arcs[1] = {
		.v = vexs[1],
		.w = vexs[2],
		.distance = 25
	};
	strcpy(arcs[1].name, "哈哈路");
	arcs[2] = {
		.v = vexs[1],
		.w = vexs[3],
		.distance = 7
	};
	strcpy(arcs[1].name, "嘿嘿路");


	createGraph_AL(G, Undirected, vexs, 4, arcs, 3);
}

int main(int argc, char const *argv[]) {
	ALGraph G;

	initTestData(G);

	// printf("%s\n", "--- --- ---");
	// printf("%s\n", 	G.vexsNodes[3].firstArc->vex.name);

	welcome();
	operate(G);

	// getchar();
	return 0;
}
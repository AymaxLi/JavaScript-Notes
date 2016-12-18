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
	strcpy(vexs[0].name, "����ֱ����");
	strcpy(vexs[0].introduce, "��������ĵط�");	
	vexs[0].level = 4;
	strcpy(vexs[1].id, "0203");
	strcpy(vexs[1].name, "papi����С����");
	strcpy(vexs[1].introduce, "���ص�С����");
	vexs[1].level = 5;
	strcpy(vexs[2].id, "0255");
	strcpy(vexs[2].name, "��һ");
	strcpy(vexs[2].introduce, "����ĵط�");
	vexs[2].level = 5;
	strcpy(vexs[3].id, "0256");
	strcpy(vexs[3].name, "����");
	strcpy(vexs[3].introduce, "��һ����");
	vexs[3].level = 3;


	ArcType arcs[10];
	arcs[0] = {
		.v = vexs[0],
		.w = vexs[1],
		.distance = 25
	};
	strcpy(arcs[0].name, "heihei·");
	arcs[1] = {
		.v = vexs[1],
		.w = vexs[2],
		.distance = 25
	};
	strcpy(arcs[1].name, "����·");
	arcs[2] = {
		.v = vexs[1],
		.w = vexs[3],
		.distance = 7
	};
	strcpy(arcs[1].name, "�ٺ�·");


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
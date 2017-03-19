#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "./include/define.h"
#include "./include/typedef.h"
#include "./include/interface.h"
#include "./source/ALgraph.c"
#include "./view/view.c"

void initTestData(ALGraph &G);

int main(int argc, char const *argv[]) {
	ALGraph G;

	initTestData(G);
	welcome();
	operate(G);

	return 0;
}

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
	strcpy(vexs[4].id, "0257");
	strcpy(vexs[4].name, "����");
	strcpy(vexs[4].introduce, "��������");
	vexs[4].level = 3;
	strcpy(vexs[5].id, "0258");
	strcpy(vexs[5].name, "����");
	strcpy(vexs[5].introduce, "���ǹ���");
	vexs[5].level = 2;
	strcpy(vexs[6].id, "0259");
	strcpy(vexs[6].name, "����");
	strcpy(vexs[6].introduce, "���ǹ���");
	vexs[6].level = 1;
	strcpy(vexs[7].id, "0260");
	strcpy(vexs[7].name, "�̵���");
	strcpy(vexs[7].introduce, "�����̵���");
	vexs[7].level = 5;
	strcpy(vexs[8].id, "0261");
	strcpy(vexs[8].name, "У�ſ�");
	strcpy(vexs[8].introduce, "������");
	vexs[8].level = 5;
	strcpy(vexs[9].id, "0262");
	strcpy(vexs[9].name, "ͣ����");
	strcpy(vexs[9].introduce, "�ö೵��");
	vexs[9].level = 5;

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
		.distance = 24
	};
	strcpy(arcs[1].name, "����·");
	arcs[2] = {
		.v = vexs[1],
		.w = vexs[3],
		.distance = 7
	};
	strcpy(arcs[2].name, "�ٺ�·");
	arcs[3] = {
		.v = vexs[2],
		.w = vexs[4],
		.distance = 5
	};
	strcpy(arcs[3].name, "�㹤һ·");
	arcs[4] = {
		.v = vexs[3],
		.w = vexs[4],
		.distance = 5
	};
	strcpy(arcs[4].name, "�㹤��·");
	arcs[5] = {
		.v = vexs[1],
		.w = vexs[5],
		.distance = 36
	};
	strcpy(arcs[5].name, "����·");
	arcs[6] = {
		.v = vexs[3],
		.w = vexs[5],
		.distance = 49
	};
	strcpy(arcs[6].name, "С��Χ");
	arcs[7] = {
		.v = vexs[3],
		.w = vexs[6],
		.distance = 23
	};
	strcpy(arcs[7].name, "���Χ");
	arcs[8] = {
		.v = vexs[4],
		.w = vexs[7],
		.distance = 2
	};
	strcpy(arcs[8].name, "����Χ");
	arcs[9] = {
		.v = vexs[6],
		.w = vexs[7],
		.distance = 6
	};
	strcpy(arcs[9].name, "��С��Χ");
	arcs[10] = {
		.v = vexs[5],
		.w = vexs[8],
		.distance = 44
	};
	strcpy(arcs[10].name, "�������չ�Χ");
	arcs[11] = {
		.v = vexs[8],
		.w = vexs[9],
		.distance = 14
	};
	strcpy(arcs[11].name, "�������մ����Χ");
	arcs[12] = {
		.v = vexs[6],
		.w = vexs[9],
		.distance = 5
	};
	strcpy(arcs[12].name, "�������մ����Χ");

	createGraph_AL(G, Undirected, vexs, 10, arcs, 13);
}

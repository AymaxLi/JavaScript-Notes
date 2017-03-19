void welcome() {
	printf("%s\n", "--- --- --- --- ---");
	printf("%s\n", "��ӭ�����㶫��ҵ��ѧ");
	printf("%s\n", "����У԰���� Aymax");
}

void searchVex(ALGraph G);
void getRoad(ALGraph G);
void operate(ALGraph &G) {
	printf("%s\n", "--- --- --- --- ---");
	printf("%s\n", "���������²�������в���");
	printf("%s\n", "[1] ��ѯ������Ϣ");
	printf("%s\n", "[2] ����·��");
	printf("%s\n", "[0]�˳�ϵͳ");
	int op;
	// while(scanf("%d", &op) <= 0);
	op = 1;
	printf("%d\n", op);
	switch(op) {
		case 0 :
			printf("%s\n", "--- �˳�ϵͳ ---");
			return;
		case 1 :
			printf("%s\n", "--- ��ѯ������Ϣ ---");
			searchVex(G);
			break;
		case 2 :
			printf("%s\n", "--- ��ѯ·�� ---");
			getRoad(G);
			break;
		default :
			printf("%s\n", "��������ȷ�Ĳ�����");
			break;
	}
}

void searchVex(ALGraph G) {
	printf("%s\n", "������Ҫ���ҵľ�������");
	char name[10];
	// while(scanf("%s", name) <= 0);
	strcpy(name, "����ֱ����");
	printf("%s\n", name);
	VexType v = searchVex_AL(G, name);
	printf("--- %s ---\n",v.name);
	printf("%s%d\n", "���͵ȼ���", v.level);
	printf("%s%s\n", "��飺", v.introduce);
}

void getRoad(ALGraph G) {
	printf("%s\n", "������Ҫ���ҵľ�������");
	char nameA[10];
	char nameB[10];
	printf("%s\n", "��������㾰������");
	strcpy(nameA, "����ֱ����");
	printf("%s\n", nameA);	
	// while(scanf("%s", nameA) <= 0);
	printf("%s\n", "�������յ㾰������");
	// while(scanf("%s", nameB) <= 0);
	strcpy(nameB, "����");
	printf("%s\n", nameB);
	int a, b;
	a = getVexIndexByName(nameA, G.vexsNodes, G.n);
	b = getVexIndexByName(nameB, G.vexsNodes, G.n);
	DistInfo Dist[G.n];
	DistInfo *D = Dist;
	Dijkstra(G, a, D);
	printf("���·����\n");
	OutputPath(G, D, b);
}
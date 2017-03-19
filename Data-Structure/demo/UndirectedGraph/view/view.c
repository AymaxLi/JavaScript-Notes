void welcome() {
	printf("%s\n", "--- --- --- --- ---");
	printf("%s\n", "欢迎来到广东工业大学");
	printf("%s\n", "我是校园导游 Aymax");
}

void searchVex(ALGraph G);
void getRoad(ALGraph G);
void operate(ALGraph &G) {
	printf("%s\n", "--- --- --- --- ---");
	printf("%s\n", "请输入以下操作码进行操作");
	printf("%s\n", "[1] 查询景点信息");
	printf("%s\n", "[2] 查找路径");
	printf("%s\n", "[0]退出系统");
	int op;
	// while(scanf("%d", &op) <= 0);
	op = 1;
	printf("%d\n", op);
	switch(op) {
		case 0 :
			printf("%s\n", "--- 退出系统 ---");
			return;
		case 1 :
			printf("%s\n", "--- 查询景点信息 ---");
			searchVex(G);
			break;
		case 2 :
			printf("%s\n", "--- 查询路径 ---");
			getRoad(G);
			break;
		default :
			printf("%s\n", "请输入正确的操作码");
			break;
	}
}

void searchVex(ALGraph G) {
	printf("%s\n", "请输入要查找的景点名字");
	char name[10];
	// while(scanf("%s", name) <= 0);
	strcpy(name, "聪神直播间");
	printf("%s\n", name);
	VexType v = searchVex_AL(G, name);
	printf("--- %s ---\n",v.name);
	printf("%s%d\n", "观赏等级：", v.level);
	printf("%s%s\n", "简介：", v.introduce);
}

void getRoad(ALGraph G) {
	printf("%s\n", "请输入要查找的景点名字");
	char nameA[10];
	char nameB[10];
	printf("%s\n", "请输入起点景点名字");
	strcpy(nameA, "聪神直播间");
	printf("%s\n", nameA);	
	// while(scanf("%s", nameA) <= 0);
	printf("%s\n", "请输入终点景点名字");
	// while(scanf("%s", nameB) <= 0);
	strcpy(nameB, "工二");
	printf("%s\n", nameB);
	int a, b;
	a = getVexIndexByName(nameA, G.vexsNodes, G.n);
	b = getVexIndexByName(nameB, G.vexsNodes, G.n);
	DistInfo Dist[G.n];
	DistInfo *D = Dist;
	Dijkstra(G, a, D);
	printf("最短路径：\n");
	OutputPath(G, D, b);
}
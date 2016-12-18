void welcome() {
	printf("%s\n", "--- --- --- --- ---");
	printf("%s\n", "欢迎来到广东工业大学");
	printf("%s\n", "我是校园导游 Aymax");
}

void searchVex(ALGraph G);
void operate(ALGraph &G) {
	printf("%s\n", "--- --- --- --- ---");
	printf("%s\n", "请输入以下操作码进行操作");
	printf("%s\n", "[1] 查询景点信息");
	printf("%s\n", "[0]退出系统");
	int op;
	while(scanf("%d", &op) <= 0);
	switch(op) {
		case 0 :
			printf("%s\n", "--- 退出系统 ---");
			return;
		case 1 :
			printf("%s\n", "--- 查询景点信息 ---");
			searchVex(G);
			break;
		default :
			printf("%s\n", "请输入正确的操作码");
			break;
	}
}

void searchVex(ALGraph G) {
	printf("%s\n", "请输入要查找的景点名字");
	char name[10];
	while(scanf("%s", name) <= 0);
	VexType v = searchVex_AL(G, name);
	printf("--- %s ---\n",v.name);
	printf("%s%d\n", "观赏等级：", v.level);
	printf("%s%s\n", "简介：", v.introduce);
}
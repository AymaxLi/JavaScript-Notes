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
	printf("%s\n", "[0]�˳�ϵͳ");
	int op;
	while(scanf("%d", &op) <= 0);
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
		default :
			printf("%s\n", "��������ȷ�Ĳ�����");
			break;
	}
}

void searchVex(ALGraph G) {
	printf("%s\n", "������Ҫ���ҵľ�������");
	char name[10];
	while(scanf("%s", name) <= 0);
	VexType v = searchVex_AL(G, name);
	printf("--- %s ---\n",v.name);
	printf("%s%d\n", "���͵ȼ���", v.level);
	printf("%s%s\n", "��飺", v.introduce);
}

void getRoad(ALGraph G) {
	printf("%s\n", "������Ҫ���ҵľ�������");
	char nameA[10];
	char nameB[10];
	while(scanf("%s", name) <= 0);
	printf("%s\n", );
}
#include "stdio.h"
#include "stdlib.h"
#include "../include/define.h"
#include "../include/typedef.h"
#include "../include/interface.h"
#include "../source/function.c"

int main(int argc, char const *argv[])
{
	BSTree T = NULL;
	Status res;
	RcdType e;

	printf("%s\n", "--- 初始化 ---");
	e = {
		.key = 5
	};
	res = initBST(T, e);
	printf("%s\n", res?"成功":"失败");
	printf("根节点为 %d\n", T->data.key);

	printf("\n%s\n", "--- 插入 ---");
	e.key = 6;
	res = insertBSTNode(T, e);
	printf("插入6%s\n", res?"成功":"失败");
	e.key = 3;
	res = insertBSTNode(T, e);
	printf("插入3%s\n", res?"成功":"失败");
	e.key = 2;
	res = insertBSTNode(T, e);
	printf("插入2%s\n", res?"成功":"失败");

	printf("\n%s\n", "--- 查找 ---");
	printf("%s\n", "查找key为3的节点");
	BSTree bst = searchBSTNode(T, 3);
	printf("%s\n", (bst->data.key == 3)?"成功":"失败");

	printf("\n%s\n", "--- 删除节点 ---");
	printf("%s\n", "删除key为3的节点");
	deleteBSTNode(T, 3);
	bst = searchBSTNode(T, 3);
	printf("%s\n", (!bst)?"成功":"失败");

	printf("\n%s\n", "--- 销毁 ---");
	res = destroyBST(T);
	printf("%s\n", res?"成功":"失败");
	return 7;
}
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
	res = initBST(T);
	printf("%d\n", res);
	res = destroyBST(T);
	printf("%d\n", res);
	printf("%d\n", 5 == 5 ^ 6 ==6);
	return 7;
}
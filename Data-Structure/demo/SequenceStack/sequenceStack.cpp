
/**
 * 初始化顺序栈
 * @param  S    要初始化的顺序栈
 * @param  size 顺序栈的初始容量
 * @param  inc  初始增量值
 * @return      状态值
 */
Status InitStack_Sq(SqStack &S, int size, int inc) {
	S.elem = (ElemType*)malloc(size * sizeof(ElemType)); // 分配储存空间
	if (S.elem == NULL)	{
		return OVERFLOW;
	} else {
		S.top = 0; // 设为空栈
		S.size = size;
		S.increment = inc;
		return OK;
	}
}

/**
 * 入栈
 * @param  S 栈
 * @param  e 准备入栈的元素
 * @return   状态值
 */
Status Push_Sq(SqStack &S, ElemType e) {
	if (S.top >= S.size) {
		// 如果满栈
		ElemType *newBase;
		newBase = (ElemType*)realloc(S.elem, (S.size + S.increment) * sizeof(ElemType));
		if (newBase == NULL) return OVERFLOW;
		S.elem = newBase;
		S.size += S.increment;
	}
	S.elem[S.top ++] = e;
	return OK;
}

/**
 * 出栈（使栈顶元素出栈，并赋值给 e）
 * @param  S 栈
 * @param  e 栈顶元素的赋值对象
 * @return   状态值
 */
Status Pop_Sq(SqStack &S, ElemType &e) {
	// 判空
	if (S.top < 1) {
		return ERROR;
	} else {
		S.size --;
		S.top --;
		// 取出栈顶元素
		e = S.elem[S.top];
		// 清空被取出元素
		S.elem[S.top] = NULL;
		return OK;
	}
}

/**
 * 取栈顶元素的值
 * @param  S 栈
 * @param  e 栈顶元素的赋值对象
 * @return   状态值
 */
Status GetTop_Sq(SqStack S, ElemType &e) {
	// 判空
	if (S.top <= 1) {
		return ERROR;
	} else {
		e = S.elem[S.top - 1];
		return OK;
	}
}

Status Print_Sq(SqStack S) {
	for (int i = 0; i < S.top; ++i) printf("%c ", S.elem[i]);
	printf("\n");
}

/**
 * 判断字符串栈是否为回文数
 * @param  S 待判断的栈
 * @return   布尔值
 */
Status IsPalNumber_Sq(SqStack S) {
	//判空
	if (S.top <= 1) {
		return ERROR;
	} else {
		for (int i = 0, count = S.top - 1; i <= count / 2; ++i) {
			// 只要找到一组不相等就返回 false
			if (S.elem[i] != S.elem[count - i]) return FALSE;
		}
		// 循环做完，每组都相等，是回文数
		return TRUE;
	}
}
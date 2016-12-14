
/**
 * ��ʼ��˳��ջ
 * @param  S    Ҫ��ʼ����˳��ջ
 * @param  size ˳��ջ�ĳ�ʼ����
 * @param  inc  ��ʼ����ֵ
 * @return      ״ֵ̬
 */
Status InitStack_Sq(SqStack &S, int size, int inc) {
	S.elem = (ElemType*)malloc(size * sizeof(ElemType)); // ���䴢��ռ�
	if (S.elem == NULL)	{
		return OVERFLOW;
	} else {
		S.top = 0; // ��Ϊ��ջ
		S.size = size;
		S.increment = inc;
		return OK;
	}
}

/**
 * ��ջ
 * @param  S ջ
 * @param  e ׼����ջ��Ԫ��
 * @return   ״ֵ̬
 */
Status Push_Sq(SqStack &S, ElemType e) {
	if (S.top >= S.size) {
		// �����ջ
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
 * ��ջ��ʹջ��Ԫ�س�ջ������ֵ�� e��
 * @param  S ջ
 * @param  e ջ��Ԫ�صĸ�ֵ����
 * @return   ״ֵ̬
 */
Status Pop_Sq(SqStack &S, ElemType &e) {
	// �п�
	if (S.top < 1) {
		return ERROR;
	} else {
		S.size --;
		S.top --;
		// ȡ��ջ��Ԫ��
		e = S.elem[S.top];
		// ��ձ�ȡ��Ԫ��
		S.elem[S.top] = NULL;
		return OK;
	}
}

/**
 * ȡջ��Ԫ�ص�ֵ
 * @param  S ջ
 * @param  e ջ��Ԫ�صĸ�ֵ����
 * @return   ״ֵ̬
 */
Status GetTop_Sq(SqStack S, ElemType &e) {
	// �п�
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
 * �ж��ַ���ջ�Ƿ�Ϊ������
 * @param  S ���жϵ�ջ
 * @return   ����ֵ
 */
Status IsPalNumber_Sq(SqStack S) {
	//�п�
	if (S.top <= 1) {
		return ERROR;
	} else {
		for (int i = 0, count = S.top - 1; i <= count / 2; ++i) {
			// ֻҪ�ҵ�һ�鲻��Ⱦͷ��� false
			if (S.elem[i] != S.elem[count - i]) return FALSE;
		}
		// ѭ�����꣬ÿ�鶼��ȣ��ǻ�����
		return TRUE;
	}
}
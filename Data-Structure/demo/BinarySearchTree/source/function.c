/**
 * init a BSTree
 * @param  T - the BSTree to be inited
 * @return OK - done
 *         OVERFLOW - RAM overflow
 *           
 */
Status initBST(BSTree &T) {
	T = (BSTree)malloc(sizeof(BSTNode));
	return T ? OK : OVERFLOW;
}

/**
 * destroy a BSTree
 * @param  T - the BSTree to be destroyed
 * @return OK - done
 *         ERROR - the BSTree is NULL
 */
Status destroyBST(BSTree &T) {
	if(T == NULL) return ERROR;
	free(T);
	T = NULL;
	return OK;
}

/**
 * insert a node to BSTree
 * @param  T - the BSTree
 * @param  e - the node
 * @return OK - done
 *         ERROR - the node has existed
 */
Status insertBSTNode(BSTree &T, RcdType e) {
	if(T == NULL) {
		BSTree s;
		s = (BSTree)malloc(sizeof(BSTNode));
		if(s == NULL) return OVERFLOW;
		s->data = e;
		s->lchild = NULL;
		s->rchild = NULL;
		T = s;
		return OK;
	} else if(T->data.key == e.key) {
		return ERROR;
	} else if(T->data.key > e.key) {
		return insertBSTNode(T->lchild, e);
	} else {
		return insertBSTNode(T->rchild, e);
	}
}

/**
 * search BSTNode with the key
 * @param  T   - the BSTree
 * @param  key - the searching key
 * @return the searching BSTNode
 */
BSTree searchBSTNode(BSTree T, KeyType key) {
	if(T == NULL) return NULL;
	if(T->data.key == key) return T;
	if(T->data.key > key) return searchBSTNode(T->lchild, key);
	else return searchBSTNode(T->rchild, key);
}

/**
 * assistant function
 * @param p - the node to be deleted
 */
void deleteNode(BSTree &p) {
	BSTNode *q, *s;
	q = p;
	if(p->rchild == NULL) {
		p = p->lchild;
		free(q);
	} else if(p->lchild == NULL) {
		p = p->rchild;
		free(q);
	} else {
		s = p->lchild;
		while(s->rchild != NULL) {
			q = s;
			s = s->rchild;
		}
		p->data = s->data;
		if(q == p) q->lchild = s->lchild;
		else q->rchild = s->lchild;

		free(s);
	}
}

/**
 * delete the BSTNode with the key
 * @param  T   - the BSTree
 * @param  key - the key
 * @return OK - done
 *         ERROR - the BSTNode is NULL
 */
Status deleteBSTNode(BSTree &T, KeyType key) {
	if(T == NULL) return ERROR;
	if(T->data.key == key) {
		deleteNode(T);
		T = NULL;
		return OK;
	} else if(T->data.key > key) {
		return deleteBSTNode(T->lchild, key);
	} else {
		return deleteBSTNode(T->rchild, key);
	}
}


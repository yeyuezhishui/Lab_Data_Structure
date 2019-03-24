#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "BiTree.h"


int main(void) {
	int i, j, op = 1,num;
	SqList L;
	TElemType x[100], y[100], e, v;
	char t, LR, c[20];
	L.elem = (Tree *)malloc(LIST_INIT_SIZE * sizeof(Tree));  
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	if (ReadElem(L) == ERROR) printf("数据加载失败..........");    
	else printf("数据加载成功......");    
	while (op) {
		system("cls");
		printf("\n\n");
		printf("         Menu for BiTree On Sequence Structure \n\n");
		printf("    	  1. InitBiTree        11. LeftChild    \n");
		printf("    	  2. DestroyBiTree     12. RightChild    \n");
		printf("    	  3. CreateBiTree      13. LeftSibling    \n");
		printf("    	  4. ClearBiTree       14. RightSibling          \n");
		printf("    	  5. BiTreeEmpty       15. InsertChild        \n");
		printf("    	  6. BiTreeDepth       16. DeleteChild    \n");
		printf("    	  7. Root              17. PreOrderTraverse\n");
		printf("    	  8. Value             18. InOrderTraverse  \n");
		printf("    	  9. Assign            19. PostOrderTraverse \n");

		printf("    	 10. Parent            20. LevelOrderTraverse\n");
		printf("    	                        0. Exit\n \n");
		printf("-------------------------------------------------------------\n");
		printf("    请选择你的操作[0~23]:");
		scanf("%d", &op);
		switch (op) {
		case 1:
			printf("请输入你想构造的空二叉树的名称：\n");
			getchar();
			scanf("%s", c);  //输入构造的树的的名称
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //遍历寻找是否存在这样的二叉树
			}
			if (i <= L.length) {
				printf("名称已存在！\n");  //不存在，跳出
				system("pause");
				break;
			}
			if (InitBiTree(L, c) == OK) printf("操作成功！\n"); //调用函数，构造成功
			else printf("操作失败!\n");
			system("pause");
			break;
		case 2:
			printf("请输入你想销毁的二叉树的名称：\n");
			getchar();
			scanf("%s", c);  //输入查找的树的名称
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //遍历寻找是否存在这样的树
			}
			if (i>L.length) {
				printf("二叉树不存在!\n");
				system("pause");
				break;
			}
			if (DestroyBiTree(L.elem[i - 1].HeadNode) == OK) {  //调用函数，销毁成功
				for (;i<L.length;i++) {  //顺序表之后的元素移动
					strcpy(L.elem[i - 1].name, L.elem[i].name);
					L.elem[i - 1].HeadNode = L.elem[i].HeadNode;
				}
				printf("二叉树销毁成功！\n");
				(L.length)--;   //销毁成功，顺序表表长减1
			}
			else printf("二叉树销毁失败！\n");  //销毁失败
			system("pause");
			break;
		case 3:
			printf("请输入你想构造的二叉树的名称：\n");
			getchar();
			scanf("%s", c);  //输入查找的树的名称
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //遍历寻找是否存在这样的二叉树
			}
			if (i <= L.length) {
				printf("名称已存在！\n");  //不存在，跳出
				system("pause");
				break;
			}
			printf("请按先序输入各结点的数据，0表示不存在此节点！\n");
			getchar();
			i = 0;
			while ((t = getchar()) != '\n') {
				x[i] = t;
				i++;
			}
			x[i] = '\n';
			i = CreateBiTree(L, c, x);
			if (i == OK) printf("构造成功！\n"); //调用函数，构造成功
			else if (i == INFEASTABLE) printf("构造成功，所构造树为空二叉树!\n");
			else if (i == FALSE) printf("构造失败\n");
			system("pause");
			break;
		case 4:
			printf("请输入你想置空的二叉树的名称：\n");
			getchar();
			scanf("%s", c);  //输入查找的树的名称
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //遍历寻找是否存在这样的树
			}
			if (i>L.length) {
				printf("二叉树不存在!\n");
				system("pause");
				break;
			}
			if (ClearBiTree(L.elem[i - 1].HeadNode) == OK) printf("置空失败!\n");  //调用函数，置空成功
			else printf("置空失败!\n");
			system("pause");
			break;
		case 5:
			printf("请输入你想判空的二叉树的名称：\n");
			getchar();
			scanf("%s", c);  //输入查找的树的名称
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //遍历寻找是否存在这样的树
			}
			if (i>L.length) {
				printf("二叉树不存在!\n");
				system("pause");
				break;
			}
			if (BiTreeEmpty(L.elem[i - 1].HeadNode) == OK) printf("当前二叉树为空!\n");
			else printf("当前二叉树不为空!\n");
			system("pause");
			break;
		case 6:
			printf("请输入你想知道其深度的二叉树的名称：\n");
			getchar();
			scanf("%s", c);  //输入查找的树的名称
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //遍历寻找是否存在这样的树
			}
			if (i>L.length) {
				printf("二叉树不存在!\n");
				system("pause");
				break;
			}
			if (BiTreeDepth(L.elem[i - 1].HeadNode->lchild) == 0) printf("当前二叉树为空!\n");
			else printf("当前二叉树深度为:%d!\n", BiTreeDepth(L.elem[i - 1].HeadNode->lchild));
			system("pause");
			break;
		case 7:
			printf("请输入你想知道其根值的二叉树的名称：\n");
			getchar();
			scanf("%s", c);  //输入查找的链的名称
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //遍历寻找是否存在这样的链
			}
			if (i>L.length) {
				printf("二叉树不存在!\n");
				system("pause");
				break;
			}
			if (root(L.elem[i - 1].HeadNode) == NULL) printf("当前二叉树为空,无根!\n");  //二叉树为空
			else printf("当前二叉树根值为%c!\n", root(L.elem[i - 1].HeadNode)->data);
			system("pause");
			break;
		case 8:
			printf("请输入你想知道某结点所在的二叉树的名称：\n");
			getchar();
			scanf("%s", c);  //输入查找的树的名称
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //遍历寻找是否存在这样的树
			}
			if (i>L.length) {
				printf("二叉树不存在!\n");
				system("pause");
				break;
			}
			printf("请输入此结点的mark值:\n");
			getchar();
			scanf("%d",&num);
			if (Value(L.elem[i - 1].HeadNode, num) == '0') printf("此二叉树中无此元素!\n");
			else printf("当前二叉树中，此结点data为%c!\n", Value(L.elem[i - 1].HeadNode, num));
			system("pause");
			break;
		case 9:
			printf("请输入你想其中某个节点值的二叉树的名称：\n");
			getchar();
			scanf("%s", c);  //输入查找的链的名称
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //遍历寻找是否存在这样的树
			}
			if (i>L.length) {
				printf("二叉树不存在!\n");
				system("pause");
				break;
			}
			printf("请输入你想修改结点的值\n");
			getchar();e = getchar();
			printf("请输入修改后的值:\n"); 
			getchar();v = getchar();
			if (Assign(L.elem[i - 1].HeadNode, e, v) == OK) printf("修改成功!\n");
			else printf("修改失败，此二叉树中无此结点!\n");
			system("pause");
			break;
		case 10:
			printf("请输入你要操作的二叉树的名称：\n");
			getchar();
			scanf("%s", c);  //输入查找的树的名称
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //遍历寻找是否存在这样的树
			}
			if (i>L.length) {
				printf("二叉树不存在!\n");
				system("pause");
				break;
			}
			printf("请输入你想找到其双亲结点的结点的值:\n");
			getchar();e = getchar();
			if (Parent(L.elem[i - 1].HeadNode, e) == NULL) printf("此节点为此树的根，无双亲结点或此树中无此结点!\n");
			else printf("此结点的双亲结点的值为：%c!\n", Parent(L.elem[i - 1].HeadNode, e)->data);
			system("pause");
			break;
		case 11:
			printf("请输入你要操作的二叉树的名称：\n");
			getchar();
			scanf("%s", c);  //输入查找的树的名称
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //遍历寻找是否存在这样的树
			}
			if (i>L.length) {
				printf("二叉树不存在!\n");
				system("pause");
				break;
			}
			printf("请输入你想找到其左孩子的结点的值：\n");
			getchar();e = getchar();
			if (LeftChild(L.elem[i - 1].HeadNode, e) == NULL) printf("该结点无左孩子或此二叉树中无此结点！\n");
			else printf("此结点的左孩子的值为：%c！\n", LeftChild(L.elem[i - 1].HeadNode, e)->data);
			system("pause");
			break;
		case 12:
			printf("请输入你要操作的二叉树的名称：\n");
			getchar();
			scanf("%s", c);  //输入查找的树的名称
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //遍历寻找是否存在这样的树
			}
			if (i>L.length) {
				printf("二叉树不存在!\n");
				system("pause");
				break;
			}
			printf("请输入你想找到其右孩子的结点的值：\n");
			getchar();e = getchar();
			if (RightChild(L.elem[i - 1].HeadNode, e) == NULL) printf("该结点无右孩子或此二叉树中无此结点！\n");
			else printf("此结点的右孩子的值为：%c", RightChild(L.elem[i - 1].HeadNode, e)->data);
			system("pause");
			break;
		case 13:
			printf("请输入你要操作的二叉树的名称：\n");
			getchar();
			scanf("%s", c);  //输入查找的树的名称
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //遍历寻找是否存在这样的树
			}
			if (i>L.length) {
				printf("二叉树不存在!\n");
				system("pause");
				break;
			}
			printf("请输入你想找到其左兄弟的结点的值：\n");
			getchar();e = getchar();
			if (LeftSibling(L.elem[i - 1].HeadNode, e) == NULL) printf("该结点无左兄弟或此二叉树中无此结点！\n");
			else printf("此结点的左兄弟的值为：%c！\n", LeftSibling(L.elem[i - 1].HeadNode, e)->data);
			system("pause");
			break;
		case 14:
			printf("请输入你要操作的二叉树的名称：\n");
			getchar();
			scanf("%s", c);  //输入查找的树的名称
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //遍历寻找是否存在这样的树
			}
			if (i>L.length) {
				printf("二叉树不存在!\n");
				system("pause");
				break;
			}
			printf("请输入你想找到其右兄弟的结点的值：\n");
			getchar();e = getchar();
			if (RightSibling(L.elem[i - 1].HeadNode, e) == NULL) printf("该结点无右兄弟或此二叉树中无此结点！\n");
			else printf("此结点的右兄弟的值为：%c！\n", RightSibling(L.elem[i - 1].HeadNode, e)->data);
			system("pause");
			break;
		case 15:
			printf("请输入你想执行插入功能的二叉树的名称：\n");
			getchar();
			scanf("%s", c);  //输入查找的树的名称
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //遍历寻找是否存在这样的二叉树
			}
			if (i>L.length) {
				printf("二叉树不存在!\n");
				system("pause");
				break;
			}
			printf("请问你想插入到哪个节点下（字符）\n");
			getchar();e = getchar();
			printf("插入左子树键入 0 \n插入右子树键入 1\n");
			getchar();LR = getchar();
			printf("请按先序输入插入的树各结点的数据，0表示不存在此节点！\n");
			getchar();
			j = 0;
			while ((t = getchar()) != '\n') {
				y[j] = t;
				j++;
			}
			y[j] = '\n';
			j = InsertChild(L, i - 1, e, LR, y);
			if (j == INFEASTABLE) printf("二叉树为空！\n");
			else if (j == OVERFLOW) printf("插入的子树不合理，插入失败！\n");
			else if (j == OK) printf("插入成功！\n");
			else printf("插入失败,二叉树%s中不存在节点%c！\n", L.elem[i - 1].name, e);
			system("pause");
			break;
		case 16:
			printf("请输入你想执行删除功能的二叉树的名称：\n");
			getchar();
			scanf("%s", c);  //输入查找的树的名称
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //遍历寻找是否存在这样的二叉树
			}
			if (i>L.length) {
				printf("二叉树不存在!\n");
				system("pause");
				break;
			}
			printf("请问你想删除到哪个节点下\n");
			getchar();e = getchar();
			printf("删除左子树键入 0\n删除右子树键入 1\n");
			getchar();LR = getchar();
			j = DeleteChild(L, i - 1, e, LR);
			if (j == OK) printf("删除成功！\n");
			else if (j == INFEASTABLE) printf("删除的二叉树为空！\n");
			else printf("删除失败,二叉树%s中不存在节点%c！\n", L.elem[i - 1].name, e);
			system("pause");
			break;
		case 17:
			printf("请输入你要操作的二叉树的名称：\n");
			getchar();
			scanf("%s", c);  //输入查找的树的名称
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //遍历寻找是否存在这样的树
			}
			if (i>L.length) {
				printf("二叉树不存在!\n");
				system("pause");
				break;
			}
			if (PreOrderTraverse(L.elem[i - 1].HeadNode) == FALSE) printf("此二叉树是空树！");
			printf("\n");
			system("pause");
			break;
		case 18:
			printf("请输入你要操作的二叉树的名称：\n");
			getchar();
			scanf("%s", c);  //输入查找的树的名称
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //遍历寻找是否存在这样的树
			}
			if (i>L.length) {
				printf("二叉树不存在!\n");
				system("pause");
				break;
			}
			if (InOrderTraverse(L.elem[i - 1].HeadNode->lchild) == FALSE) printf("此二叉树是空树！");
			
			system("pause");
			break;
		case 19:
			printf("请输入你要操作的二叉树的名称：\n");
			getchar();
			scanf("%s", c);  //输入查找的树的名称
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //遍历寻找是否存在这样的树
			}
			if (i>L.length) {
				printf("二叉树不存在!\n");
				system("pause");
				break;
			}
			
			if (PostOrderTraverse(L.elem[i - 1].HeadNode->lchild) == FALSE) printf("此二叉树是空树！");
			
			printf("\n");
			system("pause");
			break;
		case 20:
			printf("请输入你要操作的二叉树的名称：\n");
			getchar();
			scanf("%s", c);  //输入查找的树的名称
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //遍历寻找是否存在这样的树
			}
			if (i>L.length) {
				printf("二叉树不存在!\n");
				system("pause");
				break;
			}
			if (LevelOrderTraverse(L.elem[i - 1].HeadNode->lchild) == FALSE) printf("此二叉树是空树！");
			printf("\n");
			system("pause");
			break;
		
		case 0:
			break;
		}//end of switch
	}//end of while
	if (SaveElem(L) == TRUE) printf("数据已自动保存！\n");
	else printf("数据保存失败！\n");
	printf("欢迎下次再使用本系统！\n");
}






status InitBiTree(SqList &L, char c[20]) {
	Tree *newbase;
	if (L.length >= L.listsize) 
	{
		newbase = (Tree *)realloc(L.elem, (L.listsize + LISTINCREMENT)*sizeof(Tree));  
		if (!newbase)exit(OVERFLOW);    
		L.listsize += LISTINCREMENT;
		L.elem = newbase;
	}
	strcpy(L.elem[L.length].name, c);
	L.elem[L.length].HeadNode = (BiTree)malloc(sizeof(BiTNode));  
	L.elem[L.length].HeadNode->data = 0; 
	L.elem[L.length].HeadNode->mark = 0; 
	L.elem[L.length].HeadNode->lchild = L.elem[L.length].HeadNode->rchild = NULL;
	(L.length)++; 
	return OK;
}

status DestroyBiTree(BiTree &T) {
	int top = -1;
	TNode stack[100], p, q;
	p = T->lchild;  
	if (p == NULL) {  
		free(T);
		return OK;
	}
	stack[++top] = T->lchild;
	while (top>-1) 
	{
		p = stack[top--];
		q = p;
		if (p->rchild) stack[++top] = p->rchild;
		if (p->lchild) stack[++top] = p->lchild;
		free(q);
	}
	free(T);
	return OK;
}

status CreateBiTree(SqList &L, char c[20], char x[100]) {
	TNode stack[100], p, q;
	Tree *newbase;
	int i = 1, top = -1, n = 1;
	if (L.length >= L.listsize) 
	{
		newbase = (Tree *)realloc(L.elem, (L.listsize + LISTINCREMENT)*sizeof(Tree)); 
		if (!newbase)exit(OVERFLOW);   
		L.elem = newbase;            
		L.listsize += LISTINCREMENT;   
	}
	strcpy(L.elem[L.length].name, c);
	L.elem[L.length].HeadNode = (BiTree)malloc(sizeof(BiTNode));
	L.elem[L.length].HeadNode->data = 0;
	L.elem[L.length].HeadNode->mark = 0;
	L.elem[L.length].HeadNode->lchild = L.elem[L.length].HeadNode->rchild = NULL;
	if (x[0] == '0') 
	{
		L.length++;
		return INFEASTABLE;
	}
	p = (BiTree)malloc(sizeof(BiTNode));
	p->data = x[0];  
	p->mark = 1; 
	p->lchild = p->rchild = NULL;
	L.elem[L.length].HeadNode->lchild = p;
	stack[++top] = p;
	while (x[i] != '\n') 
	{
		if (x[i] != '0') 
		{  
			p = (BiTree)malloc(sizeof(BiTNode)); 
			p->data = x[i]; 
			p->mark = n+1; 
			p->lchild = p->rchild = NULL; 
			
			while (stack[top]->rchild != NULL) top--; 
			if (top <= -1) return FALSE;
			
			q = stack[top];  
			stack[++top] = p; 
			
			if (x[i - 1] != '0')
				q->lchild = p;  
			else 
			{
				q->rchild = p;  
			}
			n++;  
		}
		else 
		{  
			while (stack[top]->rchild != NULL) top--; 
			q = stack[top];  
			if (x[i - 1] != '0')
				q->lchild = NULL;  
			else 
			{
				q->rchild = NULL;   
				top--;
			}
		}
		i++;  //下一个
	}
	L.elem[L.length].HeadNode->data = n;  
	L.length++;
	return OK;
}

status ClearBiTree(BiTree &T) {
	TNode stack[100], p, q;
	int top = -1;
	p = T->lchild;  
	stack[++top] = T->lchild;  
	while (top>-1) {
		p = stack[top--]; 
		q = p;
		if (p->rchild) stack[++top] = p->rchild; 
		if (p->lchild) stack[++top] = p->lchild; 
		free(q); 
	}
	T->data = 0;  
	T->lchild = NULL;
	return OK;
}

status BiTreeEmpty(BiTree T) {
	if (T->lchild == NULL) return OK;
	return FALSE;
}

int BiTreeDepth(BiTree T) {
	int i, j;
	if (T == NULL) return 0;
	i = BiTreeDepth(T->lchild); 
	j = BiTreeDepth(T->rchild);  
	if (i>j) return (i + 1);  
	return (j + 1);
}

TNode root(BiTree T) {
	return T->lchild;
}

TElemType Value(BiTree &T, int e) {
	int top = -1;
	TNode stack[100], p;
	p = T->lchild;
	stack[++top] = T->lchild;
	while (top>-1) {
		p = stack[top--];
		if (p->mark == e) return p->data;
		if (p->rchild) stack[++top] = p->rchild;
		if (p->lchild) stack[++top] = p->lchild;
	}
	return ERROR;
}

status Assign(BiTree T, char e, TElemType v) {
	int top = -1;
	TNode stack[100], p;
	p = T->lchild;
	stack[++top] = T->lchild;
	while (top>-1) {
		p = stack[top--];
		if (p->data == e) break;
		if (p->rchild) stack[++top] = p->rchild;
		if (p->lchild) stack[++top] = p->lchild;
	}
	if (p->data != e) return FALSE;
	else p->data = v;
	return OK;
}

TNode Parent(BiTree T, char e) {
	int top = -1;
	TNode stack[100], p;
	p = T->lchild;
	stack[++top] = T->lchild;
	while (top>-1) 
	{
		p = stack[top--];
		if (p->rchild) 
		{
			if (p->rchild->data == e) break;
			stack[++top] = p->rchild;
		}
		if (p->lchild) 
		{
			if (p->lchild->data == e) break;
			stack[++top] = p->lchild;
		}
	}
	if (top<=-1) return NULL;
	return p;
}

TNode LeftChild(BiTree T, char e) {
	int top = -1;
	TNode stack[100], p;
	p = T->lchild;
	stack[++top] = T->lchild;
	while (top>-1) 
	{
		p = stack[top--];
		if (p->data == e) return p->lchild;
		if (p->rchild) stack[++top] = p->rchild;
		if (p->lchild) stack[++top] = p->lchild;
	}
	return NULL;
}

TNode RightChild(BiTree T, char e) {
	int top = -1;
	TNode stack[100], p;
	p = T->lchild;
	stack[++top] = T->lchild;
	while (top>-1) 
	{
		p = stack[top--];
		if (p->data == e) return p->rchild;
		if (p->rchild) stack[++top] = p->rchild;
		if (p->lchild) stack[++top] = p->lchild;
	}
	return NULL;
}

TNode LeftSibling(BiTree T, char e) {
	int top = -1;
	TNode stack[100], p;
	p = T->lchild;
	stack[++top] = T->lchild;
	while (top>-1) 
	{
		p = stack[top--];
		if (p->rchild) 
		{
			if (p->rchild->data == e) return p->lchild;
			stack[++top] = p->rchild;
		}
		if (p->lchild) 
		{
			if (p->lchild->data == e) return NULL;
			stack[++top] = p->lchild;
		}
	}
	return NULL;
}

TNode RightSibling(BiTree T, char e) {
	int top = -1;
	TNode stack[100], p;
	p = T->lchild;
	stack[++top] = T->lchild;
	while (top>-1) {
		p = stack[top--];
		if (p->rchild) 
		{
			if (p->rchild->data == e) return NULL;
			stack[++top] = p->rchild;
		}
		if (p->lchild) 
		{
			if (p->lchild->data == e) return p->rchild;
			stack[++top] = p->lchild;
		}
	}
	return NULL;
}

status InsertChild(SqList &L, int j, TElemType e, char LR, TElemType y[100]) {
	int i, n, top;
	TNode stack[100], p, q, CT, T;
	i = 1, n = 0, top = -1;
	stack[++top] = L.elem[j].HeadNode->lchild;
	if (L.elem[j].HeadNode->data == 0) return INFEASTABLE;
	while (top>-1) 
	{  //遍历寻找要执行插入的结点
		p = stack[top--];
		if (p->data == e) break;
		if (p->rchild) stack[++top] = p->rchild;
		if (p->lchild) stack[++top] = p->lchild;
	}
	if (p->data != e) return FALSE;  //没找到结点
	T = p;
	if (y[0] == '0') return OVERFLOW;  //插入的子树为空
	p = (BiTree)malloc(sizeof(BiTNode));
	n++;
	p->data = y[0];
	p->lchild = p->rchild = NULL;
	CT = p;
	top = -1;
	stack[++top] = p;
	while (y[i] != '\n') 
	{  //构造子树
		if (y[i] != '0') 
		{
			p = (BiTree)malloc(sizeof(BiTNode));
			n++;
			p->data = y[i];
			p->lchild = p->rchild = NULL;
			while (stack[top]->rchild != NULL) top--;//该结点右子树安排完毕出栈 
			
			if (top <= -1) return FALSE;//输入错误 
			
			q = stack[top];
			stack[++top] = p;
			if (y[i - 1] != '0')
				q->lchild = p;
			else {
				q->rchild = p;
			}
		}
		else 
		{
			while (stack[top]->rchild != NULL) top--;
			q = stack[top];
			if (y[i - 1] != '0')
				q->lchild = NULL;
			else 
			{
				q->rchild = NULL;
				top--;
			}
		}
		i++;
	}
	if (CT->rchild != NULL) return OVERFLOW;  
	if (LR == '0') 
	{
		q = T->lchild;
		CT->rchild = q;
		T->lchild = CT;
	}
	else 
	{
		q = T->rchild;
		CT->rchild = q;
		T->rchild = CT;
	}
	L.elem[j].HeadNode->data = L.elem[j].HeadNode->data + n;  //更改头结点记录元素数目 
	return OK;
}

status DeleteChild(SqList &L, int j, TElemType e, int LR) {
	int top = -1, i = 0;
	TNode stack[100], p, q;
	stack[++top] = L.elem[j].HeadNode->lchild;
	if (L.elem[j].HeadNode->data == 0) return INFEASTABLE;
	while (top>-1) {  //找到对应结点
		p = stack[top--];
		if (p->data == e) break;
		if (p->rchild) stack[++top] = p->rchild;
		if (p->lchild) stack[++top] = p->lchild;
	}
	if (p->data != e) return FALSE;
	top = -1;
	if (LR == '0') {
		stack[++top] = p->lchild;
		p->lchild = NULL;
	}
	else {
		stack[++top] = p->rchild;
		p->rchild = NULL;
	}
	//计算删除多少个结点 
	while (top>-1) {
		q = stack[top--];
		i++;
		if (q->rchild) stack[++top] = q->rchild;
		if (q->lchild) stack[++top] = q->lchild;
	}
	L.elem[j].HeadNode->data = L.elem[j].HeadNode->data - i;  //二叉树的结点数减少
	return OK;
}

status PreOrderTraverse(BiTree T) {
	TNode stack[100], p;
	int top = -1;
	p = T->lchild;
	stack[++top] = T->lchild;
	if (T->lchild == NULL) return FALSE;
	while (top>-1) 
	{
		p = stack[top--];
		printf("%c", p->data);
		if (p->rchild) stack[++top] = p->rchild;
		if (p->lchild) stack[++top] = p->lchild;
	}
	return OK;
}

status InOrderTraverse(BiTree T) {
	if (T != NULL) {
		InOrderTraverse(T->lchild);
		printf("%c", T->data);
		InOrderTraverse(T->rchild);
		return OK;
	}
	return FALSE;
}

status PostOrderTraverse(BiTree T) {
	if (T != NULL) {
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c", T->data);
		return OK;
	}
	return FALSE;
}

status LevelOrderTraverse(BiTree T) {
	int i = 0, n = -1;
	TNode queue[100], p;
	if (T == NULL) return FALSE;
	queue[++n] = T;
	while (i <= n) 
	{
		p = queue[i];
		printf("%c", p->data);
		if (p->lchild) queue[++n] = p->lchild;
		if (p->rchild) queue[++n] = p->rchild;
		i++;
	}
	return OK;
}

status AllInOrderTraverse(SqList L) {
	int i;
	for (i = 0;i<L.length;i++) 
	{
		printf("%s", L.elem[i].name);
		printf("\n-----------all elements -----------------------\n");
		PreOrderTraverse(L.elem[i].HeadNode);
		printf("\n------------------ end ------------------------\n\n");
	}
	return OK;
}

int TNodeQuantity(BiTree T) {
	return T->data;
}

status InsertNullTree(SqList &L, int i, TElemType x[100]) {
	int j, top, n;
	TNode stack[100], p, q;
	j = 1, top = -1, n = 1;
	if (x[0] == '0') return FALSE;
	p = (BiTree)malloc(sizeof(BiTNode));
	p->data = x[0];
	p->lchild = p->rchild = NULL;
	L.elem[i].HeadNode->lchild = p;
	stack[++top] = p;
	while (x[j] != '\n') {
		if (x[j] != '0') {
			p = (BiTree)malloc(sizeof(BiTNode));
			p->data = x[j];
			p->lchild = p->rchild = NULL;
			while (stack[top]->rchild != NULL) top--;
			if (top <= -1) return FALSE;
			q = stack[top];
			stack[++top] = p;
			if (x[j - 1] != '0')
				q->lchild = p;
			else {
				q->rchild = p;
			}
			n++;
		}
		else {
			while (stack[top]->rchild != NULL) top--;
			q = stack[top];
			if (x[j - 1] != '0')
				q->lchild = NULL;
			else {
				q->rchild = NULL;
				top--;
			}
		}
		j++;
	}
	L.elem[i].HeadNode->data = n;
	return OK;
}

status SaveElem(SqList &L) {
	int i, j, n, top;
	FILE *f1, *f2;
	TElemType x[100];
	TNode stack[100], p, T;
	if ((f1 = fopen("List.dat", "wb")) == NULL) return ERROR;    //创建文件失败
	if ((f2 = fopen("Tree.dat", "wb")) == NULL) return ERROR;    //创建文件失败
	fwrite(&L, sizeof(SqList), 1, f1);           //将线性结构L存入文件中，保存其当前长度和当前分配的存储容量
	fwrite(L.elem, sizeof(Tree), L.length, f1);      //将顺序表元素写入文件f1中
	for (i = 1;i <= L.length;i++) {   //循环将单线性链的数据元素写入文件f2中
		top = -1;
		j = -1;
		T = L.elem[i - 1].HeadNode;
		if (T->lchild == NULL) {
			x[0] = '0';
			j++;
		}
		else {
			stack[++top] = T->lchild;
			while (top>-1) {
				p = stack[top--];
				if (p == NULL) x[++j] = '0';
				else x[++j] = p->data;
				if (p) {
					stack[++top] = p->rchild;
					stack[++top] = p->lchild;
				}
			}
		}
		j++;
		fwrite(&j, sizeof(int), 1, f2);
		for (n = 0;n<j;n++)
			fwrite(&x[n], sizeof(TElemType), 1, f2);
	}   
	fclose(f1);   
	fclose(f2);   
	return TRUE;
}

status ReadElem(SqList &L) {
	int i, j, n, k, m, top = -1;
	FILE *f1, *f2;
	TElemType x[100];
	TNode stack[100], p, q;
	if ((f1 = fopen("List.dat", "rb")) == NULL) return ERROR;  //打开文件失败
	if ((f2 = fopen("Tree.dat", "rb")) == NULL) return ERROR;  //打开文件失败
	fread(&L, sizeof(SqList), 1, f1);   //读取线性结构L
	L.elem = (Tree*)malloc(L.listsize*sizeof(Tree));   //分配储存容量
	fread(L.elem, sizeof(Tree), L.length, f1);     //读入数据元素
	for (k = 1;k <= L.length;k++) {
		m = 0;
		fread(&j, sizeof(int), 1, f2);
		for (n = 0;n<j;n++) {
			fread(&x[n], sizeof(TElemType), 1, f2);
		}
		x[n] = '\n';
		L.elem[k - 1].HeadNode = (BiTree)malloc(sizeof(BiTNode));  //为新插入的链的链头分配储存
		L.elem[k - 1].HeadNode->data = 0;
		L.elem[k - 1].HeadNode->lchild = L.elem[k - 1].HeadNode->rchild = NULL;  //新链链头为空
		if (x[0] != '0') {
			i = 1;
			p = (BiTree)malloc(sizeof(BiTNode));
			m++;
			p->data = x[0];
			p->lchild = p->rchild = NULL;
			L.elem[k - 1].HeadNode->lchild = p;
			stack[++top] = p;
			while (x[i] != '\n') {
				if (x[i] != '0') {
					p = (BiTree)malloc(sizeof(BiTNode));
					m++;
					p->data = x[i];
					p->lchild = p->rchild = NULL;
					while (stack[top]->rchild != NULL) top--;
					if (top <= -1) return FALSE;
					q = stack[top];
					stack[++top] = p;
					if (x[i - 1] != '0')
						q->lchild = p;
					else {
						q->rchild = p;
					}
				}
				else {
					while (stack[top]->rchild != NULL) top--;
					q = stack[top];
					if (x[i - 1] != '0')
						q->lchild = NULL;
					else {
						q->rchild = NULL;
						top--;
					}
				}
				i++;
			}
			L.elem[k - 1].HeadNode->data = m;
		}
	}
	fclose(f1);    //关闭文件
	fclose(f2);    //关闭文件
	return TRUE;
}



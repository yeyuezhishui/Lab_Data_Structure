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
	if (ReadElem(L) == ERROR) printf("���ݼ���ʧ��..........");    
	else printf("���ݼ��سɹ�......");    
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
		printf("    ��ѡ����Ĳ���[0~23]:");
		scanf("%d", &op);
		switch (op) {
		case 1:
			printf("���������빹��Ŀն����������ƣ�\n");
			getchar();
			scanf("%s", c);  //���빹������ĵ�����
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //����Ѱ���Ƿ���������Ķ�����
			}
			if (i <= L.length) {
				printf("�����Ѵ��ڣ�\n");  //�����ڣ�����
				system("pause");
				break;
			}
			if (InitBiTree(L, c) == OK) printf("�����ɹ���\n"); //���ú���������ɹ�
			else printf("����ʧ��!\n");
			system("pause");
			break;
		case 2:
			printf("�������������ٵĶ����������ƣ�\n");
			getchar();
			scanf("%s", c);  //������ҵ���������
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //����Ѱ���Ƿ������������
			}
			if (i>L.length) {
				printf("������������!\n");
				system("pause");
				break;
			}
			if (DestroyBiTree(L.elem[i - 1].HeadNode) == OK) {  //���ú��������ٳɹ�
				for (;i<L.length;i++) {  //˳���֮���Ԫ���ƶ�
					strcpy(L.elem[i - 1].name, L.elem[i].name);
					L.elem[i - 1].HeadNode = L.elem[i].HeadNode;
				}
				printf("���������ٳɹ���\n");
				(L.length)--;   //���ٳɹ���˳������1
			}
			else printf("����������ʧ�ܣ�\n");  //����ʧ��
			system("pause");
			break;
		case 3:
			printf("���������빹��Ķ����������ƣ�\n");
			getchar();
			scanf("%s", c);  //������ҵ���������
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //����Ѱ���Ƿ���������Ķ�����
			}
			if (i <= L.length) {
				printf("�����Ѵ��ڣ�\n");  //�����ڣ�����
				system("pause");
				break;
			}
			printf("�밴����������������ݣ�0��ʾ�����ڴ˽ڵ㣡\n");
			getchar();
			i = 0;
			while ((t = getchar()) != '\n') {
				x[i] = t;
				i++;
			}
			x[i] = '\n';
			i = CreateBiTree(L, c, x);
			if (i == OK) printf("����ɹ���\n"); //���ú���������ɹ�
			else if (i == INFEASTABLE) printf("����ɹ�����������Ϊ�ն�����!\n");
			else if (i == FALSE) printf("����ʧ��\n");
			system("pause");
			break;
		case 4:
			printf("�����������ÿյĶ����������ƣ�\n");
			getchar();
			scanf("%s", c);  //������ҵ���������
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //����Ѱ���Ƿ������������
			}
			if (i>L.length) {
				printf("������������!\n");
				system("pause");
				break;
			}
			if (ClearBiTree(L.elem[i - 1].HeadNode) == OK) printf("�ÿ�ʧ��!\n");  //���ú������ÿճɹ�
			else printf("�ÿ�ʧ��!\n");
			system("pause");
			break;
		case 5:
			printf("�����������пյĶ����������ƣ�\n");
			getchar();
			scanf("%s", c);  //������ҵ���������
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //����Ѱ���Ƿ������������
			}
			if (i>L.length) {
				printf("������������!\n");
				system("pause");
				break;
			}
			if (BiTreeEmpty(L.elem[i - 1].HeadNode) == OK) printf("��ǰ������Ϊ��!\n");
			else printf("��ǰ��������Ϊ��!\n");
			system("pause");
			break;
		case 6:
			printf("����������֪������ȵĶ����������ƣ�\n");
			getchar();
			scanf("%s", c);  //������ҵ���������
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //����Ѱ���Ƿ������������
			}
			if (i>L.length) {
				printf("������������!\n");
				system("pause");
				break;
			}
			if (BiTreeDepth(L.elem[i - 1].HeadNode->lchild) == 0) printf("��ǰ������Ϊ��!\n");
			else printf("��ǰ���������Ϊ:%d!\n", BiTreeDepth(L.elem[i - 1].HeadNode->lchild));
			system("pause");
			break;
		case 7:
			printf("����������֪�����ֵ�Ķ����������ƣ�\n");
			getchar();
			scanf("%s", c);  //������ҵ���������
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //����Ѱ���Ƿ������������
			}
			if (i>L.length) {
				printf("������������!\n");
				system("pause");
				break;
			}
			if (root(L.elem[i - 1].HeadNode) == NULL) printf("��ǰ������Ϊ��,�޸�!\n");  //������Ϊ��
			else printf("��ǰ��������ֵΪ%c!\n", root(L.elem[i - 1].HeadNode)->data);
			system("pause");
			break;
		case 8:
			printf("����������֪��ĳ������ڵĶ����������ƣ�\n");
			getchar();
			scanf("%s", c);  //������ҵ���������
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //����Ѱ���Ƿ������������
			}
			if (i>L.length) {
				printf("������������!\n");
				system("pause");
				break;
			}
			printf("������˽���markֵ:\n");
			getchar();
			scanf("%d",&num);
			if (Value(L.elem[i - 1].HeadNode, num) == '0') printf("�˶��������޴�Ԫ��!\n");
			else printf("��ǰ�������У��˽��dataΪ%c!\n", Value(L.elem[i - 1].HeadNode, num));
			system("pause");
			break;
		case 9:
			printf("��������������ĳ���ڵ�ֵ�Ķ����������ƣ�\n");
			getchar();
			scanf("%s", c);  //������ҵ���������
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //����Ѱ���Ƿ������������
			}
			if (i>L.length) {
				printf("������������!\n");
				system("pause");
				break;
			}
			printf("�����������޸Ľ���ֵ\n");
			getchar();e = getchar();
			printf("�������޸ĺ��ֵ:\n"); 
			getchar();v = getchar();
			if (Assign(L.elem[i - 1].HeadNode, e, v) == OK) printf("�޸ĳɹ�!\n");
			else printf("�޸�ʧ�ܣ��˶��������޴˽��!\n");
			system("pause");
			break;
		case 10:
			printf("��������Ҫ�����Ķ����������ƣ�\n");
			getchar();
			scanf("%s", c);  //������ҵ���������
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //����Ѱ���Ƿ������������
			}
			if (i>L.length) {
				printf("������������!\n");
				system("pause");
				break;
			}
			printf("�����������ҵ���˫�׽��Ľ���ֵ:\n");
			getchar();e = getchar();
			if (Parent(L.elem[i - 1].HeadNode, e) == NULL) printf("�˽ڵ�Ϊ�����ĸ�����˫�׽���������޴˽��!\n");
			else printf("�˽���˫�׽���ֵΪ��%c!\n", Parent(L.elem[i - 1].HeadNode, e)->data);
			system("pause");
			break;
		case 11:
			printf("��������Ҫ�����Ķ����������ƣ�\n");
			getchar();
			scanf("%s", c);  //������ҵ���������
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //����Ѱ���Ƿ������������
			}
			if (i>L.length) {
				printf("������������!\n");
				system("pause");
				break;
			}
			printf("�����������ҵ������ӵĽ���ֵ��\n");
			getchar();e = getchar();
			if (LeftChild(L.elem[i - 1].HeadNode, e) == NULL) printf("�ý�������ӻ�˶��������޴˽�㣡\n");
			else printf("�˽������ӵ�ֵΪ��%c��\n", LeftChild(L.elem[i - 1].HeadNode, e)->data);
			system("pause");
			break;
		case 12:
			printf("��������Ҫ�����Ķ����������ƣ�\n");
			getchar();
			scanf("%s", c);  //������ҵ���������
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //����Ѱ���Ƿ������������
			}
			if (i>L.length) {
				printf("������������!\n");
				system("pause");
				break;
			}
			printf("�����������ҵ����Һ��ӵĽ���ֵ��\n");
			getchar();e = getchar();
			if (RightChild(L.elem[i - 1].HeadNode, e) == NULL) printf("�ý�����Һ��ӻ�˶��������޴˽�㣡\n");
			else printf("�˽����Һ��ӵ�ֵΪ��%c", RightChild(L.elem[i - 1].HeadNode, e)->data);
			system("pause");
			break;
		case 13:
			printf("��������Ҫ�����Ķ����������ƣ�\n");
			getchar();
			scanf("%s", c);  //������ҵ���������
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //����Ѱ���Ƿ������������
			}
			if (i>L.length) {
				printf("������������!\n");
				system("pause");
				break;
			}
			printf("�����������ҵ������ֵܵĽ���ֵ��\n");
			getchar();e = getchar();
			if (LeftSibling(L.elem[i - 1].HeadNode, e) == NULL) printf("�ý�������ֵܻ�˶��������޴˽�㣡\n");
			else printf("�˽������ֵܵ�ֵΪ��%c��\n", LeftSibling(L.elem[i - 1].HeadNode, e)->data);
			system("pause");
			break;
		case 14:
			printf("��������Ҫ�����Ķ����������ƣ�\n");
			getchar();
			scanf("%s", c);  //������ҵ���������
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //����Ѱ���Ƿ������������
			}
			if (i>L.length) {
				printf("������������!\n");
				system("pause");
				break;
			}
			printf("�����������ҵ������ֵܵĽ���ֵ��\n");
			getchar();e = getchar();
			if (RightSibling(L.elem[i - 1].HeadNode, e) == NULL) printf("�ý�������ֵܻ�˶��������޴˽�㣡\n");
			else printf("�˽������ֵܵ�ֵΪ��%c��\n", RightSibling(L.elem[i - 1].HeadNode, e)->data);
			system("pause");
			break;
		case 15:
			printf("����������ִ�в��빦�ܵĶ����������ƣ�\n");
			getchar();
			scanf("%s", c);  //������ҵ���������
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //����Ѱ���Ƿ���������Ķ�����
			}
			if (i>L.length) {
				printf("������������!\n");
				system("pause");
				break;
			}
			printf("����������뵽�ĸ��ڵ��£��ַ���\n");
			getchar();e = getchar();
			printf("�������������� 0 \n�������������� 1\n");
			getchar();LR = getchar();
			printf("�밴�����������������������ݣ�0��ʾ�����ڴ˽ڵ㣡\n");
			getchar();
			j = 0;
			while ((t = getchar()) != '\n') {
				y[j] = t;
				j++;
			}
			y[j] = '\n';
			j = InsertChild(L, i - 1, e, LR, y);
			if (j == INFEASTABLE) printf("������Ϊ�գ�\n");
			else if (j == OVERFLOW) printf("�������������������ʧ�ܣ�\n");
			else if (j == OK) printf("����ɹ���\n");
			else printf("����ʧ��,������%s�в����ڽڵ�%c��\n", L.elem[i - 1].name, e);
			system("pause");
			break;
		case 16:
			printf("����������ִ��ɾ�����ܵĶ����������ƣ�\n");
			getchar();
			scanf("%s", c);  //������ҵ���������
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //����Ѱ���Ƿ���������Ķ�����
			}
			if (i>L.length) {
				printf("������������!\n");
				system("pause");
				break;
			}
			printf("��������ɾ�����ĸ��ڵ���\n");
			getchar();e = getchar();
			printf("ɾ������������ 0\nɾ������������ 1\n");
			getchar();LR = getchar();
			j = DeleteChild(L, i - 1, e, LR);
			if (j == OK) printf("ɾ���ɹ���\n");
			else if (j == INFEASTABLE) printf("ɾ���Ķ�����Ϊ�գ�\n");
			else printf("ɾ��ʧ��,������%s�в����ڽڵ�%c��\n", L.elem[i - 1].name, e);
			system("pause");
			break;
		case 17:
			printf("��������Ҫ�����Ķ����������ƣ�\n");
			getchar();
			scanf("%s", c);  //������ҵ���������
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //����Ѱ���Ƿ������������
			}
			if (i>L.length) {
				printf("������������!\n");
				system("pause");
				break;
			}
			if (PreOrderTraverse(L.elem[i - 1].HeadNode) == FALSE) printf("�˶������ǿ�����");
			printf("\n");
			system("pause");
			break;
		case 18:
			printf("��������Ҫ�����Ķ����������ƣ�\n");
			getchar();
			scanf("%s", c);  //������ҵ���������
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //����Ѱ���Ƿ������������
			}
			if (i>L.length) {
				printf("������������!\n");
				system("pause");
				break;
			}
			if (InOrderTraverse(L.elem[i - 1].HeadNode->lchild) == FALSE) printf("�˶������ǿ�����");
			
			system("pause");
			break;
		case 19:
			printf("��������Ҫ�����Ķ����������ƣ�\n");
			getchar();
			scanf("%s", c);  //������ҵ���������
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //����Ѱ���Ƿ������������
			}
			if (i>L.length) {
				printf("������������!\n");
				system("pause");
				break;
			}
			
			if (PostOrderTraverse(L.elem[i - 1].HeadNode->lchild) == FALSE) printf("�˶������ǿ�����");
			
			printf("\n");
			system("pause");
			break;
		case 20:
			printf("��������Ҫ�����Ķ����������ƣ�\n");
			getchar();
			scanf("%s", c);  //������ҵ���������
			for (i = 1;i <= L.length;i++) {
				if (strcmp(L.elem[i - 1].name, c) == 0) break;   //����Ѱ���Ƿ������������
			}
			if (i>L.length) {
				printf("������������!\n");
				system("pause");
				break;
			}
			if (LevelOrderTraverse(L.elem[i - 1].HeadNode->lchild) == FALSE) printf("�˶������ǿ�����");
			printf("\n");
			system("pause");
			break;
		
		case 0:
			break;
		}//end of switch
	}//end of while
	if (SaveElem(L) == TRUE) printf("�������Զ����棡\n");
	else printf("���ݱ���ʧ�ܣ�\n");
	printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
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
		i++;  //��һ��
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
	{  //����Ѱ��Ҫִ�в���Ľ��
		p = stack[top--];
		if (p->data == e) break;
		if (p->rchild) stack[++top] = p->rchild;
		if (p->lchild) stack[++top] = p->lchild;
	}
	if (p->data != e) return FALSE;  //û�ҵ����
	T = p;
	if (y[0] == '0') return OVERFLOW;  //���������Ϊ��
	p = (BiTree)malloc(sizeof(BiTNode));
	n++;
	p->data = y[0];
	p->lchild = p->rchild = NULL;
	CT = p;
	top = -1;
	stack[++top] = p;
	while (y[i] != '\n') 
	{  //��������
		if (y[i] != '0') 
		{
			p = (BiTree)malloc(sizeof(BiTNode));
			n++;
			p->data = y[i];
			p->lchild = p->rchild = NULL;
			while (stack[top]->rchild != NULL) top--;//�ý��������������ϳ�ջ 
			
			if (top <= -1) return FALSE;//������� 
			
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
	L.elem[j].HeadNode->data = L.elem[j].HeadNode->data + n;  //����ͷ����¼Ԫ����Ŀ 
	return OK;
}

status DeleteChild(SqList &L, int j, TElemType e, int LR) {
	int top = -1, i = 0;
	TNode stack[100], p, q;
	stack[++top] = L.elem[j].HeadNode->lchild;
	if (L.elem[j].HeadNode->data == 0) return INFEASTABLE;
	while (top>-1) {  //�ҵ���Ӧ���
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
	//����ɾ�����ٸ���� 
	while (top>-1) {
		q = stack[top--];
		i++;
		if (q->rchild) stack[++top] = q->rchild;
		if (q->lchild) stack[++top] = q->lchild;
	}
	L.elem[j].HeadNode->data = L.elem[j].HeadNode->data - i;  //�������Ľ��������
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
	if ((f1 = fopen("List.dat", "wb")) == NULL) return ERROR;    //�����ļ�ʧ��
	if ((f2 = fopen("Tree.dat", "wb")) == NULL) return ERROR;    //�����ļ�ʧ��
	fwrite(&L, sizeof(SqList), 1, f1);           //�����ԽṹL�����ļ��У������䵱ǰ���Ⱥ͵�ǰ����Ĵ洢����
	fwrite(L.elem, sizeof(Tree), L.length, f1);      //��˳���Ԫ��д���ļ�f1��
	for (i = 1;i <= L.length;i++) {   //ѭ������������������Ԫ��д���ļ�f2��
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
	if ((f1 = fopen("List.dat", "rb")) == NULL) return ERROR;  //���ļ�ʧ��
	if ((f2 = fopen("Tree.dat", "rb")) == NULL) return ERROR;  //���ļ�ʧ��
	fread(&L, sizeof(SqList), 1, f1);   //��ȡ���ԽṹL
	L.elem = (Tree*)malloc(L.listsize*sizeof(Tree));   //���䴢������
	fread(L.elem, sizeof(Tree), L.length, f1);     //��������Ԫ��
	for (k = 1;k <= L.length;k++) {
		m = 0;
		fread(&j, sizeof(int), 1, f2);
		for (n = 0;n<j;n++) {
			fread(&x[n], sizeof(TElemType), 1, f2);
		}
		x[n] = '\n';
		L.elem[k - 1].HeadNode = (BiTree)malloc(sizeof(BiTNode));  //Ϊ�²����������ͷ���䴢��
		L.elem[k - 1].HeadNode->data = 0;
		L.elem[k - 1].HeadNode->lchild = L.elem[k - 1].HeadNode->rchild = NULL;  //������ͷΪ��
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
	fclose(f1);    //�ر��ļ�
	fclose(f2);    //�ر��ļ�
	return TRUE;
}



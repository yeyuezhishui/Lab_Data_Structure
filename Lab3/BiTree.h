#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

typedef int status;
typedef char TElemType; 

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10

typedef struct BiTNode {  
	TElemType data;  
	int mark; 
	struct BiTNode *lchild, *rchild; 
}BiTNode, *TNode, *BiTree;

typedef struct Tree {
	char name[20];
	struct BiTNode *HeadNode;
}Tree;

typedef struct {
	struct Tree *elem;
	int length;
	int listsize;
}SqList;

status InitBiTree(SqList &L, char c[20]);
status DestroyBiTree(BiTree &T);
status CreateBiTree(SqList &L, char c[20], char x[100]);
status ClearBiTree(BiTree &T);
status BiTreeEmpty(BiTree T);
int BiTreeDepth(BiTree T);
TNode root(BiTree T);
TElemType Value(BiTree &T, int e);
status Assign(BiTree T, char e, TElemType v);
TNode Parent(BiTree T, char e);
TNode LeftChild(BiTree T, char e);
TNode RightChild(BiTree T, char e);
TNode LeftSibling(BiTree T, char e);
TNode RightSibling(BiTree T, char e);
status InsertChild(SqList &L, int j, TElemType e, char LR, TElemType y[100]);
status DeleteChild(SqList &L, int j, TElemType e, int LR);
status PreOrderTraverse(BiTree T);
status InOrderTraverse(BiTree T);
status PostOrderTraverse(BiTree T);
status LevelOrderTraverse(BiTree T);
status AllInOrderTraverse(SqList L);
int TNodeQuantity(BiTree T);
status InsertNullTree(SqList &L, int i, TElemType x[100]);
status SaveElem(SqList &L);
status ReadElem(SqList &L);


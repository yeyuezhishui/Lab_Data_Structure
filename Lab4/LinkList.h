#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
#define MAX_MULTI_SIZE 10

typedef int status; 
typedef int ElemType; //数据元素类型定义


typedef struct node{
	ElemType data;
	struct node * next;
}Node;

typedef Node * LinkList;

typedef struct multi
{
	struct multi * mnext;
	Node * snext;
}MultiNode;

typedef MultiNode * MultiList;

status MutiList(LinkList * L, MultiList * M);
status Upload(LinkList * L);
status Download(LinkList L);
status IntiaList(LinkList * L);
status DestroyList(LinkList * L);
status ClearList(LinkList * L);
status ListEmpty(LinkList L);
int ListLength(LinkList L);
status GetElem(LinkList L, int i, ElemType * e);
int LocateElem(LinkList L, ElemType e);
status PriorElem(LinkList L,ElemType cur,ElemType * pre_e);
status NextElem(LinkList L,ElemType cur,ElemType * next_e);
status ListInsert(LinkList * L,int i,ElemType e);
status ListDelete(LinkList * L,int i,ElemType * e);
status ListTrabverse(LinkList L);  

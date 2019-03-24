#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10

typedef int status; 
typedef int ElemType; //数据元素类型定义


typedef struct{  //顺序表（顺序结构）的定义
	ElemType * elem;
	int length;
	int listsize;
}SqList;

status Upload(SqList * L);
status IntiaList(SqList * L);
status DestroyList(SqList * L);
status ClearList(SqList * L);
status ListEmpty(SqList L);
int ListLength(SqList L);
status GetElem(SqList L, int i, ElemType * e);
status LocateElem(SqList L, ElemType e);
status PriorElem(SqList L,ElemType cur,ElemType * pre_e);
status NextElem(SqList L,ElemType cur,ElemType * next_e);
status ListInsert(SqList * L,int i,ElemType e);
status ListDelete(SqList * L,int i,ElemType * e);
status ListTrabverse(SqList L);  

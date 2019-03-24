/* Linear Table On Linked Storage Structure */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "LinkList.h"

FILE *fp;

int main(void)
{ 
  LinkList L;  
  int op=1;
  int i;
  int ListNum;
  int flag = 0;
  
  MultiList M;
  M = (MultiList)malloc(sizeof (MultiNode));
  M->mnext = NULL;
  M->snext = NULL;
  if(M == NULL) exit(OVERFLOW); 

  ElemType e, cur, pre_e, next_e;
    printf("\n\n");
	printf("      Menu for Linear Table On Sequence Structure \n");
	printf("-------------------------------------------------\n");
	printf("    	  1. IntiaList       7. LocateElem\n");
	printf("    	  2. DestroyList     8. PriorElem\n");
	printf("    	  3. ClearList       9. NextElem \n");
	printf("    	  4. ListEmpty       10. ListInsert\n");
	printf("    	  5. ListLength      11. ListDelete\n");
	printf("    	  6. GetElem         12. ListTrabverse\n");
	printf("    	  13. Upload         14. Download\n");
	printf("          15. MutiList       0.Exit\n");
	printf("-------------------------------------------------\n");
	printf("请选择你的操作[0~15]:");
  while(op)
  {
	scanf("%d",&op);
	if (flag==0 && op!=1 && op!=13)
	{
		printf("请在进行其他操作之前先\n1. 初始化线性表 或 13. 加载线性表文件\n");
		printf("\n\n请选择你的操作[0~13]:"); 
		continue;
	}
    switch(op){
	   case 1:
		if(IntiaList(&L) == OK) 
		{
		    printf("线性表创建成功\n");
		    flag++;
	    }
		else printf("线性表创建失败\n");
		break;
	   case 2:
		if(DestroyList(&L) == OK) 
		{
			printf("线性表销毁成功\n");
			flag = 0;
		}
		else printf("线性表销毁失败\n");
		break;
	   case 3:
		if(ClearList(&L) == OK) printf("线性表清空成功\n");
		else printf("线性表清空失败\n");        
		break;
	   case 4:
		if(ListEmpty(L) == TRUE) printf("该线性表为空\n"); 
		else printf("线性表非空\n");        
		break;
	   case 5:
        printf("该线性表长度为：%d",ListLength(L));
        break;
	   case 6:
        printf("请输入想要获取的元素在线性表的位置"); 
		getchar();
		scanf("%d",&i);
		if (GetElem(L, i, &e) == OK)
		{
		    printf("该线性表第%d个元素为%d\n",i,e);
		}
		break;
	   case 7:
	   	printf("请输入想要定位的元素：");
	   	getchar();
		scanf("%d",&e);
        if (LocateElem(L, e) != ERROR)
        {
        	printf("该元素在线性表第%d位上\n",LocateElem(L, e));
		}
		break;
	   case 8:
        printf("请输入需要查找前驱的元素: ");
		getchar();
		scanf("%d",&cur);
		if (PriorElem(L, cur, &pre_e) != ERROR)
		{
		    printf("该元素的前驱元素为%d\n",pre_e);	
		} 
		break;
	   case 9:
        printf("请输入需要查找后继的元素: ");
		getchar();
		scanf("%d",&cur);
		if (NextElem(L, cur, &next_e) != ERROR)
		{
		    printf("该元素的后继元素为%d\n",next_e);	
		} 
		break;
	   case 10:
        printf("请输入要插入的位置：");
        getchar();
		scanf("%d",&i);
		printf("请输入要插入的元素：");
		getchar();
		scanf("%d",&e);
		if(ListInsert(&L, i, e) != ERROR) 
		{
			printf("元素插入成功\n");
		}
		else
		{
			printf("元素插入失败\n");
		}
		break;
	   case 11:
        printf("请输入要删除元素的位置：");
        getchar();
		scanf("%d",&i);
		if(ListDelete(&L, i, &e) != ERROR) 
		{
			printf("元素删除成功\n");
		}
		else
		{
			printf("元素删除失败\n");
		}
		break;
	   case 12:
        if (ListTrabverse(L) == ERROR)
        {
        	printf("遍历失败\n");
		}
		 break;
	   case 13:
	   	if (Upload(&L) == ERROR)
		{
			printf("线性表文件加载失败\n");
		}
		else
		{
			printf("线性表文件加载成功\n");
			flag++;
		} 
		break;
	   case 14:
	   	Download(L);
	   	printf("线性表已下载到文件\n");
	   	break;
	   case 15:
        MutiList(&L, &M);
	   	printf("请继续操作\n");
	   	break;
	   case 0:
        break;
	}//end of switch
	printf("\n\n请选择下一个要执行的操作[0~13]:");
  }//end of while
  printf("\n欢迎下次再使用本系统！\n");
  return OK;
}//end of main()

status Upload(LinkList * L)
{
	LinkList p, pre;
	*L = (Node *)malloc(sizeof(Node));
	if( (*L) == NULL ) 
	{
		exit(OVERFLOW);
	}
    if ((fp=fopen("text.txt","r"))==NULL)
	{
	    printf("文件打开失败\n");
	    return ERROR;
	}
	p = (Node *)malloc(sizeof(Node));
	(*L)->next = p;
    while (fread(&(p->data), sizeof(p->data), 1, fp))
    {
    	pre = p;
    	p->next = (Node *)malloc(sizeof(Node));
    	p = p->next;
	}
	fclose(fp);
	free(p);
	pre->next = NULL;
    return OK;
}

status Download(LinkList L)
{
	if ( ListEmpty(L) )
	{
		printf("该线性表为空，无法进行此操作\n");
		return ERROR;
	}
	if ((fp=fopen("text.txt","w"))==NULL)
	{
		printf("文件打开失败\n");
		return ERROR;
	}
	L = L->next;
	while (L)
	{
		fwrite(&(L->data), sizeof(L->data), 1, fp);
		L = L->next;
	}
	fclose(fp);
	return OK;
}

status IntiaList(LinkList * L)
{
	* L = (LinkList)malloc(sizeof (Node));
	(* L)->next = NULL;
	if( * L == NULL) exit(OVERFLOW);   
	return OK;
}//IntiaList

status DestroyList(LinkList * L)
{
	if(*L == NULL)
	{
		printf("该线性表不存在\n");
		return ERROR; 
	}
	else
	{
		Node * p;
		Node * pre;
		pre = *L;
		while (p)
		{
			p = pre->next;
			free(pre);
			pre = p;
		}
		return OK;
	}
} 

status ClearList(LinkList * L)
{
	if(ListEmpty(*L) == TRUE)
	{
		printf("该线性表已空\n"); 
		return OK; 
	}                          //判断该链表是否已空 
    Node * p;
    Node * pre;
    pre = (* L)->next;
    while (p)
    {
    	p = pre->next;
    	free (pre);
    	pre = p;
	}
	(* L)->next = NULL;
	return OK;
} 

status ListEmpty(LinkList L)
{
	if ( !(L->next) ) return TRUE;  //判断空表返回TRUE，非空返回FALSE 
	else return FALSE;
}

int ListLength(LinkList L)
{
	int count = 0;
	while (L->next)
	{
		count++;
		L = L->next;
	}
	return count;
}

status GetElem(LinkList L,int i,ElemType * e)
{
	if(i<1 || i>ListLength(L))
	{
		printf("参数i值不合法\n");
		return ERROR; 
	}
	if( ListEmpty(L) )
	{
		printf("该线性表为空\n"); 
		return ERROR;
	}
	while (i)
	{
		L = L->next;
		i--;
	}
	* e = L->data;
	return OK;
} 

int LocateElem(LinkList L, ElemType e)
{
	if( ListEmpty(L) )
	{
		printf("该线性表为空\n");
		return ERROR;
	}
	L = L->next;
	int count = 1;
    while(L)
    {
    	if (L->data == e)
    	{
    		return count;
		}
		L = L->next;
		count++;
	}
	printf("该元素不在线性表内\n");
	return 0;
}

status PriorElem(LinkList L, ElemType cur, ElemType * pre_e)
{
	if ( ListEmpty(L) )
	{
		printf("该线性表为空\n"); 
		return ERROR;
	}
	if ( ListLength(L) == 1)
	{
		printf("该线性表只有一个元素不存在前驱\n");
		return ERROR;
	}
    L = L->next;
    int count = 0;
    LinkList pre = NULL;
	while(L)
	{
		count++;
		if (L->data == cur)
		{
			break;
		}
		else
		{
			pre = L;
			L =  L->next;
		}
	 }
	 if (!L)
	 {
	 	printf("无此元素\n");
	 	return ERROR;
	 }
	 if (count == 1)
	 {
	 	printf("该元素为首元素，不存在前驱\n");
		return ERROR; 
	 }
	 * pre_e = pre->data;
	 return OK;
}

status NextElem(LinkList L,ElemType cur,ElemType * next_e)
{
	if( ListEmpty(L) )
	{
		printf("该线性表为空\n");
		return ERROR;
	}
	L = L->next;
	while (L)
	{
		if (L->data == cur)
		{
			break;
		}
		else
		{
			L = L->next;
		}
	 }
	 if (!L)
	 {
	 	printf("无此元素\n");
	 	return ERROR;
	 }
	 if (!(L->next))
	 {
	 	printf("该元素为尾元素，不存在后继\n");
		return ERROR; 
	 }
	 * next_e = L->next->data;
	 return OK;
}

status ListInsert(LinkList * L,int i,ElemType e) 
{
	if ( i<1 || i>ListLength(*L)+1 )
	{
		printf("输入参数i不合法\n");
		return ERROR;
	}
	LinkList p,q;
	p = (Node *)malloc(sizeof(Node));
	q = (*L);
	i--;
	while(i)
	{
		q = q->next;
		i--;
	}
	p->data = e;
	p->next = q->next;
	q->next = p;
	return OK;
}

status ListDelete(LinkList * L,int i,ElemType * e)
{
	if ( ListEmpty(*L) )
	{
		printf("线性表为空\n无法进行删除操作\n"); 
		return ERROR; 
	}
	if (i<1 || i>ListLength(*L))
	{
		printf("输入参数i信息不合法\n");
		return ERROR;
	}
    LinkList p,pre;
    p = *L;
    pre = NULL;
    while(i)
    {
    	pre = p;
    	p = p->next;
    	i--;
	}
	pre->next = p->next;
	*e = p->data;
	free(p);
	return OK;
}

status ListTrabverse(LinkList L)
{
	if ( ListEmpty(L) )
	{
		printf("该线性表为空，遍历失败\n");
		return ERROR;
	}
	L = L->next;
	int i = 1;
    while (L)
    {
    	printf("线性表第%d个元素为%d\n", i, L->data);
        L = L->next;
        i++;
	}
	return OK;
}

status MutiList(LinkList * L, MultiList * M)
{
	int op;
    printf("请选择需要的操作：1.加载当前表到多表  2.读取表\n");
	scanf("%d",&op);
	if(op == 1)
	{
		MultiList m,p;
		p = *M;
	    m = (MultiList)malloc(sizeof (MultiNode));
		while(1)
		{
			if (p->mnext == NULL) break;
			p = p->mnext;
	    }
		m->snext = *L;
		m->mnext = NULL;
		p->mnext = m;
		return OK;
	 } 
	 else if (op == 2)
	 {
	 	int i;
	 	printf("请输入想要操作第几个表:"); 
	 	scanf("%d", &i);
	 	MultiList q;
	 	q = *M;
	 	while (i)
	 	{
	 		q = q->mnext;
	 		i--;
		}
		free(*L);
        *L = (LinkList)malloc(sizeof (Node));
	    if( *L == NULL) exit(OVERFLOW);
		*L = q->snext;
		return OK;
	 }
}

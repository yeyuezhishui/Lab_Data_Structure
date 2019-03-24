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
	printf("��ѡ����Ĳ���[0~15]:");
  while(op)
  {
	scanf("%d",&op);
	if (flag==0 && op!=1 && op!=13)
	{
		printf("���ڽ�����������֮ǰ��\n1. ��ʼ�����Ա� �� 13. �������Ա��ļ�\n");
		printf("\n\n��ѡ����Ĳ���[0~13]:"); 
		continue;
	}
    switch(op){
	   case 1:
		if(IntiaList(&L) == OK) 
		{
		    printf("���Ա����ɹ�\n");
		    flag++;
	    }
		else printf("���Ա���ʧ��\n");
		break;
	   case 2:
		if(DestroyList(&L) == OK) 
		{
			printf("���Ա����ٳɹ�\n");
			flag = 0;
		}
		else printf("���Ա�����ʧ��\n");
		break;
	   case 3:
		if(ClearList(&L) == OK) printf("���Ա���ճɹ�\n");
		else printf("���Ա����ʧ��\n");        
		break;
	   case 4:
		if(ListEmpty(L) == TRUE) printf("�����Ա�Ϊ��\n"); 
		else printf("���Ա�ǿ�\n");        
		break;
	   case 5:
        printf("�����Ա���Ϊ��%d",ListLength(L));
        break;
	   case 6:
        printf("��������Ҫ��ȡ��Ԫ�������Ա��λ��"); 
		getchar();
		scanf("%d",&i);
		if (GetElem(L, i, &e) == OK)
		{
		    printf("�����Ա��%d��Ԫ��Ϊ%d\n",i,e);
		}
		break;
	   case 7:
	   	printf("��������Ҫ��λ��Ԫ�أ�");
	   	getchar();
		scanf("%d",&e);
        if (LocateElem(L, e) != ERROR)
        {
        	printf("��Ԫ�������Ա��%dλ��\n",LocateElem(L, e));
		}
		break;
	   case 8:
        printf("��������Ҫ����ǰ����Ԫ��: ");
		getchar();
		scanf("%d",&cur);
		if (PriorElem(L, cur, &pre_e) != ERROR)
		{
		    printf("��Ԫ�ص�ǰ��Ԫ��Ϊ%d\n",pre_e);	
		} 
		break;
	   case 9:
        printf("��������Ҫ���Һ�̵�Ԫ��: ");
		getchar();
		scanf("%d",&cur);
		if (NextElem(L, cur, &next_e) != ERROR)
		{
		    printf("��Ԫ�صĺ��Ԫ��Ϊ%d\n",next_e);	
		} 
		break;
	   case 10:
        printf("������Ҫ�����λ�ã�");
        getchar();
		scanf("%d",&i);
		printf("������Ҫ�����Ԫ�أ�");
		getchar();
		scanf("%d",&e);
		if(ListInsert(&L, i, e) != ERROR) 
		{
			printf("Ԫ�ز���ɹ�\n");
		}
		else
		{
			printf("Ԫ�ز���ʧ��\n");
		}
		break;
	   case 11:
        printf("������Ҫɾ��Ԫ�ص�λ�ã�");
        getchar();
		scanf("%d",&i);
		if(ListDelete(&L, i, &e) != ERROR) 
		{
			printf("Ԫ��ɾ���ɹ�\n");
		}
		else
		{
			printf("Ԫ��ɾ��ʧ��\n");
		}
		break;
	   case 12:
        if (ListTrabverse(L) == ERROR)
        {
        	printf("����ʧ��\n");
		}
		 break;
	   case 13:
	   	if (Upload(&L) == ERROR)
		{
			printf("���Ա��ļ�����ʧ��\n");
		}
		else
		{
			printf("���Ա��ļ����سɹ�\n");
			flag++;
		} 
		break;
	   case 14:
	   	Download(L);
	   	printf("���Ա������ص��ļ�\n");
	   	break;
	   case 15:
        MutiList(&L, &M);
	   	printf("���������\n");
	   	break;
	   case 0:
        break;
	}//end of switch
	printf("\n\n��ѡ����һ��Ҫִ�еĲ���[0~13]:");
  }//end of while
  printf("\n��ӭ�´���ʹ�ñ�ϵͳ��\n");
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
	    printf("�ļ���ʧ��\n");
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
		printf("�����Ա�Ϊ�գ��޷����д˲���\n");
		return ERROR;
	}
	if ((fp=fopen("text.txt","w"))==NULL)
	{
		printf("�ļ���ʧ��\n");
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
		printf("�����Ա�����\n");
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
		printf("�����Ա��ѿ�\n"); 
		return OK; 
	}                          //�жϸ������Ƿ��ѿ� 
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
	if ( !(L->next) ) return TRUE;  //�жϿձ���TRUE���ǿշ���FALSE 
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
		printf("����iֵ���Ϸ�\n");
		return ERROR; 
	}
	if( ListEmpty(L) )
	{
		printf("�����Ա�Ϊ��\n"); 
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
		printf("�����Ա�Ϊ��\n");
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
	printf("��Ԫ�ز������Ա���\n");
	return 0;
}

status PriorElem(LinkList L, ElemType cur, ElemType * pre_e)
{
	if ( ListEmpty(L) )
	{
		printf("�����Ա�Ϊ��\n"); 
		return ERROR;
	}
	if ( ListLength(L) == 1)
	{
		printf("�����Ա�ֻ��һ��Ԫ�ز�����ǰ��\n");
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
	 	printf("�޴�Ԫ��\n");
	 	return ERROR;
	 }
	 if (count == 1)
	 {
	 	printf("��Ԫ��Ϊ��Ԫ�أ�������ǰ��\n");
		return ERROR; 
	 }
	 * pre_e = pre->data;
	 return OK;
}

status NextElem(LinkList L,ElemType cur,ElemType * next_e)
{
	if( ListEmpty(L) )
	{
		printf("�����Ա�Ϊ��\n");
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
	 	printf("�޴�Ԫ��\n");
	 	return ERROR;
	 }
	 if (!(L->next))
	 {
	 	printf("��Ԫ��ΪβԪ�أ������ں��\n");
		return ERROR; 
	 }
	 * next_e = L->next->data;
	 return OK;
}

status ListInsert(LinkList * L,int i,ElemType e) 
{
	if ( i<1 || i>ListLength(*L)+1 )
	{
		printf("�������i���Ϸ�\n");
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
		printf("���Ա�Ϊ��\n�޷�����ɾ������\n"); 
		return ERROR; 
	}
	if (i<1 || i>ListLength(*L))
	{
		printf("�������i��Ϣ���Ϸ�\n");
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
		printf("�����Ա�Ϊ�գ�����ʧ��\n");
		return ERROR;
	}
	L = L->next;
	int i = 1;
    while (L)
    {
    	printf("���Ա��%d��Ԫ��Ϊ%d\n", i, L->data);
        L = L->next;
        i++;
	}
	return OK;
}

status MutiList(LinkList * L, MultiList * M)
{
	int op;
    printf("��ѡ����Ҫ�Ĳ�����1.���ص�ǰ�����  2.��ȡ��\n");
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
	 	printf("��������Ҫ�����ڼ�����:"); 
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

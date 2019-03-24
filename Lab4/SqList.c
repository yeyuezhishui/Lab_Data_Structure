/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "SqList.h"

FILE * fp;


int main(void)
{ 
  SqList L;  
  int op=1;
  int i;
  int ListNum;
  int flag = 0;

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
	printf("    	  13. Upload          0. Exit\n");
	printf("-------------------------------------------------\n");
	printf("��ѡ����Ĳ���[0~13]:");
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
	   case 0:
        break;
	}//end of switch
	printf("\n\n��ѡ����һ��Ҫִ�еĲ���[0~13]:");
  }//end of while
  printf("\n��ӭ�´���ʹ�ñ�ϵͳ��\n");
  return OK;
}//end of main()


status Upload(SqList * L)
{
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if((L->elem) == NULL) exit(OVERFLOW);
	L->listsize = LIST_INIT_SIZE; 
	L->length = 0;
    if ((fp=fopen("text.txt","r"))==NULL)
	{
	    printf("�ļ���ʧ��\n ");
	    return ERROR;
	}
    while (fread(&L->elem[L->length], sizeof(ElemType), 1, fp))
        L->length++;
    return OK;
}

status IntiaList(SqList * L)
{
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if((L->elem) == NULL) exit(OVERFLOW);   //����ʧ�ܣ��˳����� 
	L->length = 0;                         //��ʼ����Ϊ0 
	L->listsize = LIST_INIT_SIZE;          //����Ϊ LIST_INIT_SIZE
	if((fp = fopen("text.txt","wb")) == NULL)  
	{
		printf("�ļ���ʧ��\n"); 
		return ERROR;
	}                                     //���ļ� 
	fwrite(L->elem, sizeof(ElemType), L->length, fp);//��ʼ��������Ա�д���ļ� 
	fclose(fp);                           //�ر��ļ� 
	return OK;
}//IntiaList

status DestroyList(SqList * L)
{
	free(L->elem);                //�ͷ�����Ԫ�ش洢 
	free(L);                      //�ͷŽṹ�����洢 
	return OK;
} 

status ClearList(SqList * L)
{
	if(ListEmpty(*L) == TRUE)
	{
		printf("�����Ա��ѿ�\n"); 
		return OK; 
	}                          //�жϸ������Ƿ��ѿ� 
	int count;                 //ѭ��ɾ���������� 
	ElemType e;
	for(count=1; count<=L->length; count++)
	{
		ListDelete(L, count, &e);
	}                         //ִ��ѭ��ɾ�� 
	L->length = 0;            //�޸ĵ�ǰ�� 
	return OK;
} 

status ListEmpty(SqList L)
{
	if(L.length == 0) return TRUE;  //�жϿձ���TRUE���ǿշ���FALSE 
	else return FALSE;
}

int ListLength(SqList L)
{
	return(L.length);      //���ر� 
}

status GetElem(SqList L,int i,ElemType * e)
{
	if(i<1 || i>L.length)
	{
		printf("����iֵ���Ϸ�\n");
		return ERROR; 
	}
	if(L.length == 0)
	{
		printf("�����Ա�Ϊ��\n"); 
		return ERROR;
	}
	*e = L.elem[i-1];
	return OK;
} 

status LocateElem(SqList L, ElemType e)
{
	if(L.length == 0)
	{
		printf("�����Ա�Ϊ��\n");
		return ERROR;
	}
	int count;
	for(count=1; count<=L.length; count++)
	{
		if(e == L.elem[count-1])
		{
			return count;
		}
	}
	if(count > L.length)
	{
		printf("δ�ҵ�����������Ԫ��\n");
		return ERROR; 
	}
}

status PriorElem(SqList L, ElemType cur, ElemType * pre_e)
{
	if(L.length == 0)
	{
		printf("�����Ա�Ϊ��\n"); 
		return ERROR;
	}
	if(L.length == 1)
	{
		printf("�����Ա�ֻ��һ��Ԫ�ز�����ǰ��\n");
		return ERROR;
	}
	int pre = -1;
	int count = 0;
	for(; count<=L.length; count++)
	{
		if(cur == L.elem[count]) break;
		else pre++;
	}
	if(pre<0)
	{
		printf("��Ԫ�������Ա��һ��Ԫ��\n������ǰ��Ԫ��\n");
		return ERROR; 
	}
	if(count>L.length)
	{
		printf("��Ԫ�ز������Ա���\n");
		return ERROR;
	}
	*pre_e = L.elem[pre];
	return OK;
}

status NextElem(SqList L,ElemType cur,ElemType * next_e)
{
	if(L.length == 0)
	{
		printf("�����Ա�Ϊ��\n");
		return ERROR;
	}
	int next = 1;
	int count = 0;
	for(; count<=L.length-1; count++)
	{
		if(cur == L.elem[count]) break;
		else next++;
	}
	if(count == L.length-1)
	{
		printf("��Ԫ�������Ա����һ��Ԫ��\n�����ں��Ԫ��\n");
		return ERROR; 
	}
	if(count>L.length-1)
	{
		printf("��Ԫ�ز������Ա���\n");
		return ERROR;
	}
	*next_e = L.elem[next];
	return OK;
}

status ListInsert(SqList * L,int i,ElemType e) 
{
	int k;
	char jud;
	if (L->length == L->listsize)
	{
		ElemType * newbase;
		printf("�����Ա�����\n��Ҫ���������ڴ棬�Ƿ�����Y/N:");
		getchar();
		scanf("%c",&jud);
		if (jud == 'Y')
		{
			newbase = (ElemType *)realloc(L->elem, (L->listsize+LISTINCREMENT) * sizeof(ElemType));
			if (newbase == NULL)
			{
				exit(OVERFLOW);
			}
			L->elem = newbase;
            L->listsize += LISTINCREMENT;
		}
		else return ERROR;
	}
	if (i<1 || i>L->length+1)
	{
		printf("�������i��Ϣ���Ϸ�\n");
		return ERROR;
	} 
	if (i!=L->length+1)
	{
		for (k=L->length-1; k>=i-1; k--)
		{
			L->elem[k+1] = L->elem[k];
		}
	}
	L->elem[i-1] = e;
	L->length++; 
    if ((fp = fopen("text.txt","wb")) == NULL)
    {
    	printf("���ļ�ʧ��\n");
    	return ERROR;
	}
	fwrite(L->elem, sizeof(ElemType), L->length, fp);
	fclose(fp);
	return OK;
}

status ListDelete(SqList * L,int i,ElemType * e)
{
	int k;
	if (L->length == 0)
	{
		printf("����Ϊ��\n�޷�����ɾ������\n"); 
		return ERROR; 
	}
	if (i<1 || i>L->length)
	{
		printf("�������i��Ϣ���Ϸ�\n");
		return ERROR;
	}
	*e = L->elem[i-1];
	if (i<L->length)
	{
		for(k=i-1; k<=L->length; k++)
		{
			L->elem[k] = L->elem[k+1];
		}
	}
	L->length--;
	if ((fp = fopen("text.txt","wb")) == NULL)
    {
    	printf("���ļ�ʧ��\n");
    	return ERROR;
	}
	fwrite(L->elem, sizeof(ElemType), L->length, fp);
	fclose(fp);
	return OK;
}

status ListTrabverse(SqList L)
{
	if (L.length == 0)
	{
		printf("�����Ա�Ϊ�գ�����ʧ��\n");
		return ERROR;
	}
	int k;
	int sum = 0;
	for (k=1; k<=L.length; k++)
	{
		printf("���Ա�� %d λ��Ԫ���� %d \n",k,L.elem[k-1]);
		sum += L.elem[k-1];
	}
	printf("���Ա�����Ԫ�صĺ�Ϊ: %d",sum);
	return OK;
}

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
	printf("请选择你的操作[0~13]:");
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
	   case 0:
        break;
	}//end of switch
	printf("\n\n请选择下一个要执行的操作[0~13]:");
  }//end of while
  printf("\n欢迎下次再使用本系统！\n");
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
	    printf("文件打开失败\n ");
	    return ERROR;
	}
    while (fread(&L->elem[L->length], sizeof(ElemType), 1, fp))
        L->length++;
    return OK;
}

status IntiaList(SqList * L)
{
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if((L->elem) == NULL) exit(OVERFLOW);   //申请失败，退出程序 
	L->length = 0;                         //初始化表长为0 
	L->listsize = LIST_INIT_SIZE;          //容量为 LIST_INIT_SIZE
	if((fp = fopen("text.txt","wb")) == NULL)  
	{
		printf("文件打开失败\n"); 
		return ERROR;
	}                                     //打开文件 
	fwrite(L->elem, sizeof(ElemType), L->length, fp);//初始化后的线性表写入文件 
	fclose(fp);                           //关闭文件 
	return OK;
}//IntiaList

status DestroyList(SqList * L)
{
	free(L->elem);                //释放数据元素存储 
	free(L);                      //释放结构变量存储 
	return OK;
} 

status ClearList(SqList * L)
{
	if(ListEmpty(*L) == TRUE)
	{
		printf("该线性表已空\n"); 
		return OK; 
	}                          //判断该链表是否已空 
	int count;                 //循环删除计数变量 
	ElemType e;
	for(count=1; count<=L->length; count++)
	{
		ListDelete(L, count, &e);
	}                         //执行循环删除 
	L->length = 0;            //修改当前表长 
	return OK;
} 

status ListEmpty(SqList L)
{
	if(L.length == 0) return TRUE;  //判断空表返回TRUE，非空返回FALSE 
	else return FALSE;
}

int ListLength(SqList L)
{
	return(L.length);      //返回表长 
}

status GetElem(SqList L,int i,ElemType * e)
{
	if(i<1 || i>L.length)
	{
		printf("参数i值不合法\n");
		return ERROR; 
	}
	if(L.length == 0)
	{
		printf("该线性表为空\n"); 
		return ERROR;
	}
	*e = L.elem[i-1];
	return OK;
} 

status LocateElem(SqList L, ElemType e)
{
	if(L.length == 0)
	{
		printf("该线性表为空\n");
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
		printf("未找到符合条件的元素\n");
		return ERROR; 
	}
}

status PriorElem(SqList L, ElemType cur, ElemType * pre_e)
{
	if(L.length == 0)
	{
		printf("该线性表为空\n"); 
		return ERROR;
	}
	if(L.length == 1)
	{
		printf("该线性表只有一个元素不存在前驱\n");
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
		printf("此元素是线性表第一个元素\n不存在前驱元素\n");
		return ERROR; 
	}
	if(count>L.length)
	{
		printf("此元素不在线性表中\n");
		return ERROR;
	}
	*pre_e = L.elem[pre];
	return OK;
}

status NextElem(SqList L,ElemType cur,ElemType * next_e)
{
	if(L.length == 0)
	{
		printf("该线性表为空\n");
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
		printf("此元素是线性表最后一个元素\n不存在后继元素\n");
		return ERROR; 
	}
	if(count>L.length-1)
	{
		printf("此元素不在线性表中\n");
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
		printf("该线性表已满\n需要重新申请内存，是否申请Y/N:");
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
		printf("输入参数i信息不合法\n");
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
    	printf("打开文件失败\n");
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
		printf("链表为空\n无法进行删除操作\n"); 
		return ERROR; 
	}
	if (i<1 || i>L->length)
	{
		printf("输入参数i信息不合法\n");
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
    	printf("打开文件失败\n");
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
		printf("该线性表为空，遍历失败\n");
		return ERROR;
	}
	int k;
	int sum = 0;
	for (k=1; k<=L.length; k++)
	{
		printf("线性表第 %d 位的元素是 %d \n",k,L.elem[k-1]);
		sum += L.elem[k-1];
	}
	printf("线性表所有元素的和为: %d",sum);
	return OK;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Graph.h" 
int main(){
    int op=1;
    int v1 = 0, v2 = 0;
    VertexType e,v,w;
    ALGraph G;
    G.arcnum = 0;
    G.kind = 0;
    G.vexnum = 0;
    while(op){
    A:       system("cls");
        printf("\n\n");
        printf("    	  1. CreateGraph      8. InsertVex\n");
        printf("    	  2. DestroyGraph     9. DeleteVex\n");
        printf("    	  3. LocateVex        10. InsertArc\n");
        printf("    	  4. GetVex           11. DeleteArc\n");
        printf("    	  5. PutVex           12. DfsTraverse\n");
        printf("    	  6. FirstAdjVex      13. BFSTraverse\n");
        printf("    	  7. NextAdjVex       14. Save\n");
        printf("    	  15.Load             0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("    请选择你的操作[0~13]:");
        scanf("%d",&op);
        getchar();
        switch(op){
            case 1:
                if(CreateGraph(&G)==OK) printf("图构建成功 \n");
                else
                    printf("图构建失败 \n");
                break;
            case 2:
                if(DestroyGraph(&G)==OK) printf("图销毁成功 \n");
                else
                    printf("图销毁失败 \n");
                break;
            case 3:
                printf("请输入要查找的顶点e: ");
//                fflush(stdin);
                scanf("%s",e);
                getchar();
                if(LocateVex(G,e)==INFEASTABLE) printf("不存在此顶点 \n");
                else printf("该顶点在图或网中的序号为%d \n",LocateVex(G,e) );
                break;
            case 4:
                printf("请输入结点编号v1：\n");
                scanf("%d",&v1);
                getchar();
                if(v1<0||v1>=G.vexnum)
                {
                    printf("输入参数不合法\n");
                    break;
                }
                printf("该结点的信息为%s\n",GetVex(G, v1));
                break;
            case 5:
                printf("请输入结点编号v：\n");
                scanf("%d",&v2);
                getchar();
                PutVex(&G, v2);
                break;
            case 6:
                printf("请输入要查找的顶点e: ");
//                fflush(stdin);
                scanf("%s",e);
                getchar();
                if(FirstAdjVex(G,e)==INFEASTABLE) printf("v没有邻接顶点 \n");
                else if(FirstAdjVex(G,e)==-2) printf("不存在此顶点 \n");
                else printf("v的第一个邻接顶点的序号为%d \n",FirstAdjVex(G,e) );
                break;
            case 7:
                printf("请输入要查找的顶点v和其相对的顶点w: ");
//                fflush(stdin);
                scanf("%s",v);
                getchar();
                scanf("%s",w);
                getchar();
                if(NextAdjVex(G,v,w)==INFEASTABLE) printf("w是v的最后一个邻接顶点 \n");
                else if(NextAdjVex(G,v,w)==-2) printf("顶点v或w不存在 \n");
                else if(NextAdjVex(G,v,w)==-3) printf("w不是v的邻接顶点 \n");
                else printf("v相对于w的下一个邻接顶点的序号为%d \n",NextAdjVex(G,v,w) );
                break;
            case 8:
                printf("请输入要添加的顶点v: ");
//                fflush(stdin);
                scanf("%s",v);
                getchar();
                if(InsertVex(&G,v)==OK) printf("添加成功 \n");
                else printf("添加失败\n");
                break;
            case 9:
                printf("请输入要删除的顶点v: ");
//                fflush(stdin);
                scanf("%s",v);
                getchar();
                if(DeleteVex(&G,v)==ERROR) printf("不存在此顶点 \n");
                else printf("删除成功 \n");
                break;
            case 10:
                printf("请输入要添加弧的顶点v和顶点w: ");
//                fflush(stdin);
                scanf("%s",v);
                getchar();
                scanf("%s",w);
                getchar();
                if(InsertArc(&G,v,w)==ERROR) printf("顶点v或w不存在\n");
                else printf("添加成功\n");
                break;
            case 11:
                printf("请输入要删除弧的顶点v和顶点w: ");
//                fflush(stdin);
                scanf("%s",v);
                getchar();
                scanf("%s",w);
                getchar();
                if(DeleteArc(&G,v,w)==ERROR) printf("顶点v或w不存在 \n");
                else printf("弧删除成功或已不存在 \n");
                break;
            case 12:
                DFSTraverse(G,print);
                break;
            case 13:
                BFSTraverse(G,print);
                break;
            case 14:
            	Save(&G);
            case 15:
            	Load(&G);
            case 0:
                break;
            default:
                goto A;
                
        }
        system("pause");
    }
    return 0;
}

void print(char *i){
    printf("%s ",i);
}

status CreateGraph(ALGraph *G){ /* 采用邻接表存储结构,构造没有相关信息的图G(用一个函数构造4种图) */
    int i,j,k;
    int w = 0; /* 权值 */
    VertexType va,vb;
    ArcNode *p;
    printf("请输入图的类型(有向图:0,有向网:1,无向图:2,无向网:3): \n");
    scanf("%d",&(*G).kind);
    getchar();
    printf("请输入图的顶点数,边数:\n");
    scanf("%d",&(*G).vexnum);
    getchar();
    scanf("%d",&(*G).arcnum);
    getchar();
    printf("请输入%d个顶点的值(<%d个字符):\n",(*G).vexnum,MAX_NAME);
    for(i=0;i<(*G).vexnum;++i) /* 构造顶点向量 */{
        scanf("%s",(*G).vertices[i].data);
        (*G).vertices[i].firstarc=NULL;
    }
    if((*G).kind==1||(*G).kind==3) /* 网 */
        printf("请顺序输入每条弧(边)的权值、弧尾和弧头(以空格作为间隔):\n");
    else /* 图 */
        printf("请顺序输入每条弧(边)的弧尾和弧头(以空格作为间隔):\n");
    for(k=0;k<(*G).arcnum;++k) /* 构造表结点链表 */{
        if((*G).kind==1||(*G).kind==3) /* 网 */
            scanf("%d%s%s",&w,va,vb);
        else /* 图 */
            scanf("%s%s",va,vb);
        i=LocateVex(*G,va); /* 弧尾 */
        j=LocateVex(*G,vb); /* 弧头 */
        p=(ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex=j;
        if((*G).kind==1||(*G).kind==3) /* 网 */{
            p->info=(int *)malloc(sizeof(int));
            *(p->info)=w;
        }
        else
            p->info=NULL; /* 图 */
        p->nextarc=(*G).vertices[i].firstarc; /* 插在表头 */
        (*G).vertices[i].firstarc=p;
        if((*G).kind>=2) /* 无向图或网,产生第二个表结点 */{
            p=(ArcNode*)malloc(sizeof(ArcNode));
            p->adjvex=i;
            if((*G).kind==3) /* 无向网 */{
                p->info=(int*)malloc(sizeof(int));
                *(p->info)=w;
            }
            else
                p->info=NULL; /* 无向图 */
            p->nextarc=(*G).vertices[j].firstarc; /* 插在表头 */
            (*G).vertices[j].firstarc=p;
        }
    }
    return OK;
}

status DestroyGraph(ALGraph *G){
    /* 初始条件: 图G存在。操作结果: 销毁图G */
    if (G == NULL) {
        printf("图不存在.\n");
        return ERROR;
    }
    if (G->vexnum == 0) {
        printf("图为空.\n");
        return ERROR;
    }
    
    ArcNode *p,*q;
    (*G).vexnum=0;
    (*G).arcnum=0;
    int i;
    for(i=0;i<(*G).vexnum;++i){
        p=(*G).vertices[i].firstarc;
        while(p){
            q=p->nextarc;
            if((*G).kind%2) /* 网 */
                free(p->info);
            free(p);
            p=q;
        }
    }
    return OK;
}

status LocateVex(ALGraph G,VertexType u){ /* 初始条件: 图G存在,u和G中顶点有相同特征 */
    /* 操作结果: 若G中存在顶点u,则返回该顶点在图中位置;否则返回-1 */
    if (G.vexnum == 0) {
        printf("图为空.\n");
        return ERROR;
    }
    
    int i;
    for(i=0;i<G.vexnum;++i)
        if(strcmp(u,G.vertices[i].data)==0)
            return i;
    return -1;
}

status FirstAdjVex(ALGraph G,VertexType v){ /* 初始条件: 图G存在,v是G中某个顶点 */
    /* 操作结果: 返回v的第一个邻接顶点的序号。若顶点在G中没有邻接顶点,则返回-1 */
    if (G.vexnum == 0) {
        printf("图为空.\n");
        return ERROR;
    }
    
    ArcNode *p;
    int v1;
    v1=LocateVex(G,v); /* v1为顶点v在图G中的序号 */
    if(v1==-1)
        return -2;
    else{
        p=G.vertices[v1].firstarc;
        if(p)
            return p->adjvex;
        else
            return -1;
    }
}

status PutVex(ALGraph *G, int i){
    if (G == NULL) {
        printf("Graph doesn't exist.\n");
        return ERROR;
    }
    if (G->vexnum == 0) {
        printf("图为空.\n");
        return ERROR;
    }
    
    int j;
    if(i<0||i>=G->vexnum)
    {
        printf("参数i的值不合法\n");
        return ERROR;
    }
    ArcNode * p=NULL;
    for(j=0; j<G->vexnum; j++)
    {
        if (j==i)
        {
            printf("请输入改变后的值\n");
            getchar();
            scanf("%s",G->vertices[i].data);
            return OK;
        }
    }
    return OK;
}

status NextAdjVex(ALGraph G,VertexType v,VertexType w){ /* 初始条件: 图G存在,v是G中某个顶点,w是v的邻接顶点 */
    /* 操作结果: 返回v的(相对于w的)下一个邻接顶点的序号。 */
    /*           若w是v的最后一个邻接点,则返回-1 */
    if (G.vexnum == 0) {
        printf("图为空.\n");
        return ERROR;
    }
    
    ArcNode *p;
    int v1,w1;
    v1=LocateVex(G,v); /* v1为顶点v在图G中的序号 */
    w1=LocateVex(G,w); /* w1为顶点w在图G中的序号 */
    if(v1==-1||w1==-1)
        return -2;
    p=G.vertices[v1].firstarc;
    while(p&&p->adjvex!=w1) /* 指针p不空且所指表结点不是w */
        p=p->nextarc;
    if(!p)
        return -3;
    else if(!p->nextarc) /* 没找到w或w是最后一个邻接点 */
        return -1;
    else /* p->adjvex==w */
        return p->nextarc->adjvex; /* 返回v的(相对于w的)下一个邻接顶点的序号 */
}

status InsertVex(ALGraph *G,VertexType v){ /* 初始条件: 图G存在,v和图中顶点有相同特征 */
    /* 操作结果: 在图G中增添新顶点v(不增添与顶点相关的弧,留待InsertArc()去做)*/
    if (G == NULL) {
        printf("Graph doesn't exist.\n");
        return ERROR;
    }
    if (G->vexnum == 0) {
        printf("图为空.\n");
        return ERROR;
    }
    
    strcpy((*G).vertices[(*G).vexnum].data,v); /* 构造新顶点向量 */
    (*G).vertices[(*G).vexnum].firstarc=NULL;
    (*G).vexnum++; /* 图G的顶点数加1 */
    return OK;
}

status DeleteVex(ALGraph *G,VertexType v){ /* 初始条件: 图G存在,v是G中某个顶点 */
    /* 操作结果: 删除G中顶点v及其相关的弧*/
    if (G == NULL) {
        printf("Graph doesn't exist.\n");
        return ERROR;
    }
    if (G->vexnum == 0) {
        printf("图为空.\n");
        return ERROR;
    }
    
    ArcNode *p,qq;
    ArcNode *q=&qq;
    int i, j;
    j=LocateVex(*G,v); /* j是顶点v的序号 */
    if(j<0) /* v不是图G的顶点 */
        return ERROR;
    p=(*G).vertices[j].firstarc; /* 删除以v为出度的弧或边 */
    while(p){
        q=p;
        p=p->nextarc;
        if((*G).kind%2) /* 网 */
            free(q->info);
        free(q);
        (*G).arcnum--; /* 弧或边数减1 */
    }
    (*G).vexnum--; /* 顶点数减1 */
    for(i=j;i<(*G).vexnum;i++) /* 顶点v后面的顶点前移 */
        (*G).vertices[i]=(*G).vertices[i+1];
    for(i=0;i<(*G).vexnum;i++) /* 删除以v为入度的弧或边且必要时修改表结点的顶点位置值 */{
        p=(*G).vertices[i].firstarc; /* 指向第1条弧或边 */
        while(p) /* 有弧 */{
            if(p->adjvex==j){
                if(p==(*G).vertices[i].firstarc) /* 待删结点是第1个结点 */{
                    (*G).vertices[i].firstarc=p->nextarc;
                    if((*G).kind%2) /* 网 */
                        free(p->info);
                    free(p);
                    p=(*G).vertices[i].firstarc;
                    if((*G).kind<2) /* 有向 */
                        (*G).arcnum--; /* 弧或边数减1 */
                }
                else{
                    q->nextarc=p->nextarc;
                    if((*G).kind%2) /* 网 */
                        free(p->info);
                    free(p);
                    p=q->nextarc;
                    if((*G).kind<2) /* 有向 */
                        (*G).arcnum--; /* 弧或边数减1 */
                }
            }
            else{
                if(p->adjvex>j)
                    p->adjvex--; /* 修改表结点的顶点位置值(序号) */
                q=p;
                p=p->nextarc;
            }
        }
    }
    return OK;
}

status InsertArc(ALGraph *G,VertexType v,VertexType w){ /* 初始条件: 图G存在,v和w是G中两个顶点 */
    /* 操作结果: 在G中增添弧<v,w>,若G是无向的,则还增添对称弧<w,v>*/
    if (G == NULL) {
        printf("Graph doesn't exist.\n");
        return ERROR;
    }
    if (G->vexnum == 0) {
        printf("图为空.\n");
        return ERROR;
    }
    
    ArcNode *p;
    int w1 = 0,i,j;
    i=LocateVex(*G,v); /* 弧尾或边的序号 */
    j=LocateVex(*G,w); /* 弧头或边的序号 */
    if(i<0||j<0)
        return ERROR;
    (*G).arcnum++; /* 图G的弧或边的数目加1 */
    if((*G).kind%2) /* 网 */{
        printf("请输入弧(边)%s→%s的权值: ",v,w);
        scanf("%d",&w1);
    }
    p=(ArcNode*)malloc(sizeof(ArcNode));
    p->adjvex=j;
    if((*G).kind%2) /* 网 */{
        p->info=(int*)malloc(sizeof(int));
        *(p->info)=w1;
    }
    else
        p->info=NULL;
    p->nextarc=(*G).vertices[i].firstarc; /* 插在表头 */
    (*G).vertices[i].firstarc=p;
    if((*G).kind>=2) /* 无向,生成另一个表结点 */{
        p=(ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex=i;
        if((*G).kind==3) /* 无向网 */{
            p->info=(int*)malloc(sizeof(int));
            *(p->info)=w1;
        }
        else
            p->info=NULL;
        p->nextarc=(*G).vertices[j].firstarc; /* 插在表头 */
        (*G).vertices[j].firstarc=p;
    }
    return OK;
}

status DeleteArc(ALGraph *G,VertexType v,VertexType w){ /* 初始条件: 图G存在,v和w是G中两个顶点 */
    /* 操作结果: 在G中删除弧<v,w>,若G是无向的,则还删除对称弧<w,v> */
    if (G == NULL) {
        printf("Graph doesn't exist.\n");
        return ERROR;
    }
    if (G->vexnum == 0) {
        printf("图为空.\n");
        return ERROR;
    }
    
    int i, j;
    ArcNode *p,qq;
    ArcNode *q = &qq;
    i=LocateVex(*G,v); /* i是顶点v(弧尾)的序号 */
    j=LocateVex(*G,w); /* j是顶点w(弧头)的序号 */
    if(i<0||j<0||i==j)
        return ERROR;
    p=(*G).vertices[i].firstarc; /* p指向顶点v的第一条出弧 */
    while(p&&p->adjvex!=j) /* p不空且所指之弧不是待删除弧<v,w> */{ /* p指向下一条弧 */
        q=p;
        p=p->nextarc;
    }
    if(p&&p->adjvex==j) /* 找到弧<v,w> */{
        if(p==(*G).vertices[i].firstarc) /* p所指是第1条弧 */
            (*G).vertices[i].firstarc=p->nextarc; /* 指向下一条弧 */
        else
            q->nextarc=p->nextarc; /* 指向下一条弧 */
        if((*G).kind%2) /* 网 */
            free(p->info);
        free(p); /* 释放此结点 */
        (*G).arcnum--; /* 弧或边数减1 */
    }
    if((*G).kind>=2) /* 无向,删除对称弧<w,v> */{
        p=(*G).vertices[j].firstarc; /* p指隙サ鉾的第一条出弧 */
        while(p&&p->adjvex!=i) /* p不空且所指之弧不是待删除弧<w,v> */{ /* p指向下一条弧 */
            q=p;
            p=p->nextarc;
        }
        if(p&&p->adjvex==i) /* 找到弧<w,v> */{
            if(p==(*G).vertices[j].firstarc) /* p所指是第1条弧 */
                (*G).vertices[j].firstarc=p->nextarc; /* 指向下一条弧 */
            else
                q->nextarc=p->nextarc; /* 指向下一条弧 */
            if((*G).kind==3) /* 无向网 */
                free(p->info);
            free(p); /* 释放此结点 */
        }
    }
    return OK;
}

status DFS(ALGraph G,int v){ /* 从第v个顶点出发递归地深度优先遍历图G。算法7.5*/
    if (G.vexnum == 0) {
        printf("图为空.\n");
        return ERROR;
    }
    
    VertexType v1,w1;
    strcpy(v1,*GetVex(G,v));
    visited[v]=TRUE; /* 设置访问标志为TRUE(已访问) */
    visitFunc(G.vertices[v].data); /* 访问第v个顶点 */
    int w;
    for(w=FirstAdjVex(G,v1);w>=0;w=NextAdjVex(G,v1,strcpy(w1,*GetVex(G,w))))
        if(!visited[w])
            DFS(G,w); /* 对v的尚未访问的邻接点w递归调用DFS */
    return OK;
}

VertexType* GetVex(ALGraph G,int v){ /* 初始条件: 图G存在,v是G中某个顶点的序号。操作结果: 返回v的值 */
    if(v>=G.vexnum||v<0)
        exit(ERROR);
    return &G.vertices[v].data;
}

status DFSTraverse(ALGraph G,void(*visit)(char*)){ /* 对图G作深度优先遍历。算法7.4 */
    visitFunc=visit; /* 使用全局变量VisitFunc,使DFS不必设函数指针参数 */
    if (G.vexnum == 0) {
        printf("图为空.\n");
        return ERROR;
    }
    int v;
    for(v=0;v<G.vexnum;v++)
        visited[v]=FALSE; /* 访问标志数组初始化 */
    for(v=0;v<G.vexnum;v++)
        if(!visited[v])
            DFS(G,v); /* 对尚未访问的顶点调用DFS */
    printf("\n");
    return OK;
}
typedef int QElemType;

typedef struct QNode
{
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct{
    QueuePtr front, rear; /* 队头、队尾指针 */
}LinkQueue;

status InitQueue(LinkQueue *Q){
    /* 构造一个空队列Q */
    (*Q).front = (*Q).rear = (QueuePtr)malloc(sizeof(QNode));
    if (!(*Q).front)
        exit(OVERFLOW);
    (*Q).front->next = NULL;
    return OK;
}

status DestroyQueue(LinkQueue *Q){
    /* 销毁队列Q(无论空否均可) */
    while ((*Q).front)
    {
        (*Q).rear = (*Q).front->next;
        free((*Q).front);
        (*Q).front = (*Q).rear;
    }
    return OK;
}

status ClearQueue(LinkQueue *Q)
{ /* 将Q清为空队列 */
    QueuePtr p, q;
    (*Q).rear = (*Q).front;
    p = (*Q).front->next;
    (*Q).front->next = NULL;
    while (p)
    {
        q = p;
        p = p->next;
        free(q);
    }
    return OK;
}

status QueueEmpty(LinkQueue Q)
{ /* 若Q为空队列,则返回TRUE,否则返回FALSE */
    if (Q.front == Q.rear)
        return TRUE;
    else
        return FALSE;
}

int QueueLength(LinkQueue Q)
{ /* 求队列的长度 */
    QueuePtr p;
    p = Q.front;
    int i = 0;
    while (Q.rear != p)
    {
        i++;
        p = p->next;
    }
    return i;
}
status GetHead_Q(LinkQueue Q, QElemType *e) /* 避免与bo2-6.c重名 */
{ /* 若队列不空,则用e返回Q的队头元素,并返回OK,否则返回ERROR */
    QueuePtr p;
    if (Q.front == Q.rear)
        return ERROR;
    p = Q.front->next;
    *e = p->data;
    return OK;
}

status EnQueue(LinkQueue *Q, QElemType e)
{ /* 插入元素e为Q的新的队尾元素 */
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if (!p) /* 存储分配失败 */
        exit(OVERFLOW);
    p->data = e;
    p->next = NULL;
    (*Q).rear->next = p;
    (*Q).rear = p;
    return OK;
}

status DeQueue(LinkQueue *Q, QElemType *e)
{ /* 若队列不空,删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR */
    QueuePtr p;
    if ((*Q).front == (*Q).rear)
        return ERROR;
    p = (*Q).front->next;
    *e = p->data;
    (*Q).front->next = p->next;
    if ((*Q).rear == p)
        (*Q).rear = (*Q).front;
    free(p);
    return OK;
}

status QueueTraverse(LinkQueue Q, void(*vi)(QElemType))
{ /* 从队头到队尾依次对队列Q中每个元素调用函数vi()。一旦vi失败,则操作失败 */
    QueuePtr p;
    p = Q.front->next;
    while (p)
    {
        vi(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

status BFSTraverse(ALGraph G,void(*visit)(char*)){/*按广度优先非递归遍历图G。使用辅助队列Q和访问标志数组visited。算法7.6 */
    if (G.vexnum == 0) {
        printf("图为空.\n");
        return ERROR;
    }
    VertexType u1,w1;
    LinkQueue Q;
    int v, u, w;
    for(v=0;v<G.vexnum;++v)
        visited[v]=FALSE; /* 置初值 */
    InitQueue(&Q); /* 置空的辅助队列Q */
    for(v=0;v<G.vexnum;v++) /* 如果是连通图,只v=0就遍历全图 */
        if(!visited[v]) /* v尚未访问 */{
            visited[v]=TRUE;
            visit(G.vertices[v].data);
            EnQueue(&Q,v); /* v入队列 */
            while(!QueueEmpty(Q)) /* 队列不空 */{
                DeQueue(&Q,&u); /* 队头元素出队并置为u */
                strcpy(u1,*GetVex(G,u));
                for(w=FirstAdjVex(G,u1);w>=0;w=NextAdjVex(G,u1,strcpy(w1,*GetVex(G,w))))
                    if(!visited[w]) /* w为u的尚未访问的邻接顶点 */{
                        visited[w]=TRUE;
                        visit(G.vertices[w].data);
                        EnQueue(&Q,w); /* w入队 */
                    }
            }
        }
    return OK;
}

int Save(ALGraph *G){
    int indicator = 0, count = 0;
    ArcNode *temp = NULL;
    FILE *fp;
    if ((fp=fopen("text.dat","wb"))==NULL){
        printf("Fail to open file\n ");
        return ERROR;
    }
    
    fwrite(&(G->vexnum), sizeof(int), 1, fp);//写入顶点个数，便于读取
    fwrite(&(G->arcnum), sizeof(int), 1, fp);
    fwrite(&(G->kind), sizeof(int), 1, fp);
    
    for (indicator=0; indicator<G->vexnum; indicator++) {
        fwrite(&G->vertices[indicator].data,sizeof(VertexType), 1,fp);
        
        for (temp=G->vertices[indicator].firstarc; temp!=NULL; temp=temp->nextarc) {
            count++;
        }
        fwrite(&count, sizeof(int), 1, fp);//写入此顶点弧的个数
        
        for (temp=G->vertices[indicator].firstarc; temp!=NULL; temp=temp->nextarc) {
//            写入弧的信息
            fwrite(&(temp->adjvex), sizeof(int), 1, fp);
            fwrite(&(temp->info), sizeof(int), 1, fp);
        }
    }
    fclose(fp);
    return OK;
}

int Load(ALGraph *G){
    int vexNum = 0, arcNum = 0, kind = 0;
    int indicator = 0, arc_sum = 0;
    int temp = 0;
    ArcNode **temp_arc = NULL;
    FILE *fp;
    if ((fp=fopen("text.dat","rb"))==NULL){
        printf("Fail to open file\n ");
        return ERROR;
    }
    
    fread(&vexNum, sizeof(int), 1, fp);
    fread(&arcNum, sizeof(int), 1, fp);
    fread(&kind, sizeof(int), 1, fp);
    G->vexnum = vexNum;
    G->arcnum = arcNum;
    G->kind = kind;
    
    for (; indicator<vexNum; indicator++) {
//        G->vertices[indicator].data
        fread(&(G->vertices[indicator].data), sizeof(VertexType), 1, fp);
        fread(&arc_sum, sizeof(int), 1, fp);
        
        for (temp = 0; temp<arc_sum; temp++) {
            if (temp==0) {
                G->vertices[indicator].firstarc = (ArcNode*)malloc(sizeof(ArcNode));
//                temp_arc = G->vertices[indicator].firstarc;
                fread(&( G->vertices[indicator].firstarc->adjvex), sizeof(int), 1, fp);
                fread(&( G->vertices[indicator].firstarc->info), sizeof(int), 1, fp);
                G->vertices[indicator].firstarc->nextarc = NULL;
                temp_arc = &(G->vertices[indicator].firstarc);
            }
            else{
                (*temp_arc)->nextarc = (ArcNode*)malloc(sizeof(ArcNode));
                *temp_arc = (*temp_arc)->nextarc;
                fread(&((*temp_arc)->adjvex), sizeof(int), 1, fp);
                fread(&((*temp_arc)->info), sizeof(int), 1, fp);
                (*temp_arc)->nextarc = NULL;
            }
        }
    }
    fclose(fp);
    return OK;
}







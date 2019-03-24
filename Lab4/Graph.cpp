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
        printf("    ��ѡ����Ĳ���[0~13]:");
        scanf("%d",&op);
        getchar();
        switch(op){
            case 1:
                if(CreateGraph(&G)==OK) printf("ͼ�����ɹ� \n");
                else
                    printf("ͼ����ʧ�� \n");
                break;
            case 2:
                if(DestroyGraph(&G)==OK) printf("ͼ���ٳɹ� \n");
                else
                    printf("ͼ����ʧ�� \n");
                break;
            case 3:
                printf("������Ҫ���ҵĶ���e: ");
//                fflush(stdin);
                scanf("%s",e);
                getchar();
                if(LocateVex(G,e)==INFEASTABLE) printf("�����ڴ˶��� \n");
                else printf("�ö�����ͼ�����е����Ϊ%d \n",LocateVex(G,e) );
                break;
            case 4:
                printf("����������v1��\n");
                scanf("%d",&v1);
                getchar();
                if(v1<0||v1>=G.vexnum)
                {
                    printf("����������Ϸ�\n");
                    break;
                }
                printf("�ý�����ϢΪ%s\n",GetVex(G, v1));
                break;
            case 5:
                printf("����������v��\n");
                scanf("%d",&v2);
                getchar();
                PutVex(&G, v2);
                break;
            case 6:
                printf("������Ҫ���ҵĶ���e: ");
//                fflush(stdin);
                scanf("%s",e);
                getchar();
                if(FirstAdjVex(G,e)==INFEASTABLE) printf("vû���ڽӶ��� \n");
                else if(FirstAdjVex(G,e)==-2) printf("�����ڴ˶��� \n");
                else printf("v�ĵ�һ���ڽӶ�������Ϊ%d \n",FirstAdjVex(G,e) );
                break;
            case 7:
                printf("������Ҫ���ҵĶ���v������ԵĶ���w: ");
//                fflush(stdin);
                scanf("%s",v);
                getchar();
                scanf("%s",w);
                getchar();
                if(NextAdjVex(G,v,w)==INFEASTABLE) printf("w��v�����һ���ڽӶ��� \n");
                else if(NextAdjVex(G,v,w)==-2) printf("����v��w������ \n");
                else if(NextAdjVex(G,v,w)==-3) printf("w����v���ڽӶ��� \n");
                else printf("v�����w����һ���ڽӶ�������Ϊ%d \n",NextAdjVex(G,v,w) );
                break;
            case 8:
                printf("������Ҫ��ӵĶ���v: ");
//                fflush(stdin);
                scanf("%s",v);
                getchar();
                if(InsertVex(&G,v)==OK) printf("��ӳɹ� \n");
                else printf("���ʧ��\n");
                break;
            case 9:
                printf("������Ҫɾ���Ķ���v: ");
//                fflush(stdin);
                scanf("%s",v);
                getchar();
                if(DeleteVex(&G,v)==ERROR) printf("�����ڴ˶��� \n");
                else printf("ɾ���ɹ� \n");
                break;
            case 10:
                printf("������Ҫ��ӻ��Ķ���v�Ͷ���w: ");
//                fflush(stdin);
                scanf("%s",v);
                getchar();
                scanf("%s",w);
                getchar();
                if(InsertArc(&G,v,w)==ERROR) printf("����v��w������\n");
                else printf("��ӳɹ�\n");
                break;
            case 11:
                printf("������Ҫɾ�����Ķ���v�Ͷ���w: ");
//                fflush(stdin);
                scanf("%s",v);
                getchar();
                scanf("%s",w);
                getchar();
                if(DeleteArc(&G,v,w)==ERROR) printf("����v��w������ \n");
                else printf("��ɾ���ɹ����Ѳ����� \n");
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

status CreateGraph(ALGraph *G){ /* �����ڽӱ�洢�ṹ,����û�������Ϣ��ͼG(��һ����������4��ͼ) */
    int i,j,k;
    int w = 0; /* Ȩֵ */
    VertexType va,vb;
    ArcNode *p;
    printf("������ͼ������(����ͼ:0,������:1,����ͼ:2,������:3): \n");
    scanf("%d",&(*G).kind);
    getchar();
    printf("������ͼ�Ķ�����,����:\n");
    scanf("%d",&(*G).vexnum);
    getchar();
    scanf("%d",&(*G).arcnum);
    getchar();
    printf("������%d�������ֵ(<%d���ַ�):\n",(*G).vexnum,MAX_NAME);
    for(i=0;i<(*G).vexnum;++i) /* ���춥������ */{
        scanf("%s",(*G).vertices[i].data);
        (*G).vertices[i].firstarc=NULL;
    }
    if((*G).kind==1||(*G).kind==3) /* �� */
        printf("��˳������ÿ����(��)��Ȩֵ����β�ͻ�ͷ(�Կո���Ϊ���):\n");
    else /* ͼ */
        printf("��˳������ÿ����(��)�Ļ�β�ͻ�ͷ(�Կո���Ϊ���):\n");
    for(k=0;k<(*G).arcnum;++k) /* ����������� */{
        if((*G).kind==1||(*G).kind==3) /* �� */
            scanf("%d%s%s",&w,va,vb);
        else /* ͼ */
            scanf("%s%s",va,vb);
        i=LocateVex(*G,va); /* ��β */
        j=LocateVex(*G,vb); /* ��ͷ */
        p=(ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex=j;
        if((*G).kind==1||(*G).kind==3) /* �� */{
            p->info=(int *)malloc(sizeof(int));
            *(p->info)=w;
        }
        else
            p->info=NULL; /* ͼ */
        p->nextarc=(*G).vertices[i].firstarc; /* ���ڱ�ͷ */
        (*G).vertices[i].firstarc=p;
        if((*G).kind>=2) /* ����ͼ����,�����ڶ������� */{
            p=(ArcNode*)malloc(sizeof(ArcNode));
            p->adjvex=i;
            if((*G).kind==3) /* ������ */{
                p->info=(int*)malloc(sizeof(int));
                *(p->info)=w;
            }
            else
                p->info=NULL; /* ����ͼ */
            p->nextarc=(*G).vertices[j].firstarc; /* ���ڱ�ͷ */
            (*G).vertices[j].firstarc=p;
        }
    }
    return OK;
}

status DestroyGraph(ALGraph *G){
    /* ��ʼ����: ͼG���ڡ��������: ����ͼG */
    if (G == NULL) {
        printf("ͼ������.\n");
        return ERROR;
    }
    if (G->vexnum == 0) {
        printf("ͼΪ��.\n");
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
            if((*G).kind%2) /* �� */
                free(p->info);
            free(p);
            p=q;
        }
    }
    return OK;
}

status LocateVex(ALGraph G,VertexType u){ /* ��ʼ����: ͼG����,u��G�ж�������ͬ���� */
    /* �������: ��G�д��ڶ���u,�򷵻ظö�����ͼ��λ��;���򷵻�-1 */
    if (G.vexnum == 0) {
        printf("ͼΪ��.\n");
        return ERROR;
    }
    
    int i;
    for(i=0;i<G.vexnum;++i)
        if(strcmp(u,G.vertices[i].data)==0)
            return i;
    return -1;
}

status FirstAdjVex(ALGraph G,VertexType v){ /* ��ʼ����: ͼG����,v��G��ĳ������ */
    /* �������: ����v�ĵ�һ���ڽӶ������š���������G��û���ڽӶ���,�򷵻�-1 */
    if (G.vexnum == 0) {
        printf("ͼΪ��.\n");
        return ERROR;
    }
    
    ArcNode *p;
    int v1;
    v1=LocateVex(G,v); /* v1Ϊ����v��ͼG�е���� */
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
        printf("ͼΪ��.\n");
        return ERROR;
    }
    
    int j;
    if(i<0||i>=G->vexnum)
    {
        printf("����i��ֵ���Ϸ�\n");
        return ERROR;
    }
    ArcNode * p=NULL;
    for(j=0; j<G->vexnum; j++)
    {
        if (j==i)
        {
            printf("������ı���ֵ\n");
            getchar();
            scanf("%s",G->vertices[i].data);
            return OK;
        }
    }
    return OK;
}

status NextAdjVex(ALGraph G,VertexType v,VertexType w){ /* ��ʼ����: ͼG����,v��G��ĳ������,w��v���ڽӶ��� */
    /* �������: ����v��(�����w��)��һ���ڽӶ������š� */
    /*           ��w��v�����һ���ڽӵ�,�򷵻�-1 */
    if (G.vexnum == 0) {
        printf("ͼΪ��.\n");
        return ERROR;
    }
    
    ArcNode *p;
    int v1,w1;
    v1=LocateVex(G,v); /* v1Ϊ����v��ͼG�е���� */
    w1=LocateVex(G,w); /* w1Ϊ����w��ͼG�е���� */
    if(v1==-1||w1==-1)
        return -2;
    p=G.vertices[v1].firstarc;
    while(p&&p->adjvex!=w1) /* ָ��p��������ָ���㲻��w */
        p=p->nextarc;
    if(!p)
        return -3;
    else if(!p->nextarc) /* û�ҵ�w��w�����һ���ڽӵ� */
        return -1;
    else /* p->adjvex==w */
        return p->nextarc->adjvex; /* ����v��(�����w��)��һ���ڽӶ������� */
}

status InsertVex(ALGraph *G,VertexType v){ /* ��ʼ����: ͼG����,v��ͼ�ж�������ͬ���� */
    /* �������: ��ͼG�������¶���v(�������붥����صĻ�,����InsertArc()ȥ��)*/
    if (G == NULL) {
        printf("Graph doesn't exist.\n");
        return ERROR;
    }
    if (G->vexnum == 0) {
        printf("ͼΪ��.\n");
        return ERROR;
    }
    
    strcpy((*G).vertices[(*G).vexnum].data,v); /* �����¶������� */
    (*G).vertices[(*G).vexnum].firstarc=NULL;
    (*G).vexnum++; /* ͼG�Ķ�������1 */
    return OK;
}

status DeleteVex(ALGraph *G,VertexType v){ /* ��ʼ����: ͼG����,v��G��ĳ������ */
    /* �������: ɾ��G�ж���v������صĻ�*/
    if (G == NULL) {
        printf("Graph doesn't exist.\n");
        return ERROR;
    }
    if (G->vexnum == 0) {
        printf("ͼΪ��.\n");
        return ERROR;
    }
    
    ArcNode *p,qq;
    ArcNode *q=&qq;
    int i, j;
    j=LocateVex(*G,v); /* j�Ƕ���v����� */
    if(j<0) /* v����ͼG�Ķ��� */
        return ERROR;
    p=(*G).vertices[j].firstarc; /* ɾ����vΪ���ȵĻ���� */
    while(p){
        q=p;
        p=p->nextarc;
        if((*G).kind%2) /* �� */
            free(q->info);
        free(q);
        (*G).arcnum--; /* ���������1 */
    }
    (*G).vexnum--; /* ��������1 */
    for(i=j;i<(*G).vexnum;i++) /* ����v����Ķ���ǰ�� */
        (*G).vertices[i]=(*G).vertices[i+1];
    for(i=0;i<(*G).vexnum;i++) /* ɾ����vΪ��ȵĻ�����ұ�Ҫʱ�޸ı���Ķ���λ��ֵ */{
        p=(*G).vertices[i].firstarc; /* ָ���1������� */
        while(p) /* �л� */{
            if(p->adjvex==j){
                if(p==(*G).vertices[i].firstarc) /* ��ɾ����ǵ�1����� */{
                    (*G).vertices[i].firstarc=p->nextarc;
                    if((*G).kind%2) /* �� */
                        free(p->info);
                    free(p);
                    p=(*G).vertices[i].firstarc;
                    if((*G).kind<2) /* ���� */
                        (*G).arcnum--; /* ���������1 */
                }
                else{
                    q->nextarc=p->nextarc;
                    if((*G).kind%2) /* �� */
                        free(p->info);
                    free(p);
                    p=q->nextarc;
                    if((*G).kind<2) /* ���� */
                        (*G).arcnum--; /* ���������1 */
                }
            }
            else{
                if(p->adjvex>j)
                    p->adjvex--; /* �޸ı���Ķ���λ��ֵ(���) */
                q=p;
                p=p->nextarc;
            }
        }
    }
    return OK;
}

status InsertArc(ALGraph *G,VertexType v,VertexType w){ /* ��ʼ����: ͼG����,v��w��G���������� */
    /* �������: ��G������<v,w>,��G�������,������Գƻ�<w,v>*/
    if (G == NULL) {
        printf("Graph doesn't exist.\n");
        return ERROR;
    }
    if (G->vexnum == 0) {
        printf("ͼΪ��.\n");
        return ERROR;
    }
    
    ArcNode *p;
    int w1 = 0,i,j;
    i=LocateVex(*G,v); /* ��β��ߵ���� */
    j=LocateVex(*G,w); /* ��ͷ��ߵ���� */
    if(i<0||j<0)
        return ERROR;
    (*G).arcnum++; /* ͼG�Ļ���ߵ���Ŀ��1 */
    if((*G).kind%2) /* �� */{
        printf("�����뻡(��)%s��%s��Ȩֵ: ",v,w);
        scanf("%d",&w1);
    }
    p=(ArcNode*)malloc(sizeof(ArcNode));
    p->adjvex=j;
    if((*G).kind%2) /* �� */{
        p->info=(int*)malloc(sizeof(int));
        *(p->info)=w1;
    }
    else
        p->info=NULL;
    p->nextarc=(*G).vertices[i].firstarc; /* ���ڱ�ͷ */
    (*G).vertices[i].firstarc=p;
    if((*G).kind>=2) /* ����,������һ������ */{
        p=(ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex=i;
        if((*G).kind==3) /* ������ */{
            p->info=(int*)malloc(sizeof(int));
            *(p->info)=w1;
        }
        else
            p->info=NULL;
        p->nextarc=(*G).vertices[j].firstarc; /* ���ڱ�ͷ */
        (*G).vertices[j].firstarc=p;
    }
    return OK;
}

status DeleteArc(ALGraph *G,VertexType v,VertexType w){ /* ��ʼ����: ͼG����,v��w��G���������� */
    /* �������: ��G��ɾ����<v,w>,��G�������,��ɾ���Գƻ�<w,v> */
    if (G == NULL) {
        printf("Graph doesn't exist.\n");
        return ERROR;
    }
    if (G->vexnum == 0) {
        printf("ͼΪ��.\n");
        return ERROR;
    }
    
    int i, j;
    ArcNode *p,qq;
    ArcNode *q = &qq;
    i=LocateVex(*G,v); /* i�Ƕ���v(��β)����� */
    j=LocateVex(*G,w); /* j�Ƕ���w(��ͷ)����� */
    if(i<0||j<0||i==j)
        return ERROR;
    p=(*G).vertices[i].firstarc; /* pָ�򶥵�v�ĵ�һ������ */
    while(p&&p->adjvex!=j) /* p��������ָ֮�����Ǵ�ɾ����<v,w> */{ /* pָ����һ���� */
        q=p;
        p=p->nextarc;
    }
    if(p&&p->adjvex==j) /* �ҵ���<v,w> */{
        if(p==(*G).vertices[i].firstarc) /* p��ָ�ǵ�1���� */
            (*G).vertices[i].firstarc=p->nextarc; /* ָ����һ���� */
        else
            q->nextarc=p->nextarc; /* ָ����һ���� */
        if((*G).kind%2) /* �� */
            free(p->info);
        free(p); /* �ͷŴ˽�� */
        (*G).arcnum--; /* ���������1 */
    }
    if((*G).kind>=2) /* ����,ɾ���Գƻ�<w,v> */{
        p=(*G).vertices[j].firstarc; /* pָ϶���w�ĵ�һ������ */
        while(p&&p->adjvex!=i) /* p��������ָ֮�����Ǵ�ɾ����<w,v> */{ /* pָ����һ���� */
            q=p;
            p=p->nextarc;
        }
        if(p&&p->adjvex==i) /* �ҵ���<w,v> */{
            if(p==(*G).vertices[j].firstarc) /* p��ָ�ǵ�1���� */
                (*G).vertices[j].firstarc=p->nextarc; /* ָ����һ���� */
            else
                q->nextarc=p->nextarc; /* ָ����һ���� */
            if((*G).kind==3) /* ������ */
                free(p->info);
            free(p); /* �ͷŴ˽�� */
        }
    }
    return OK;
}

status DFS(ALGraph G,int v){ /* �ӵ�v����������ݹ��������ȱ���ͼG���㷨7.5*/
    if (G.vexnum == 0) {
        printf("ͼΪ��.\n");
        return ERROR;
    }
    
    VertexType v1,w1;
    strcpy(v1,*GetVex(G,v));
    visited[v]=TRUE; /* ���÷��ʱ�־ΪTRUE(�ѷ���) */
    visitFunc(G.vertices[v].data); /* ���ʵ�v������ */
    int w;
    for(w=FirstAdjVex(G,v1);w>=0;w=NextAdjVex(G,v1,strcpy(w1,*GetVex(G,w))))
        if(!visited[w])
            DFS(G,w); /* ��v����δ���ʵ��ڽӵ�w�ݹ����DFS */
    return OK;
}

VertexType* GetVex(ALGraph G,int v){ /* ��ʼ����: ͼG����,v��G��ĳ���������š��������: ����v��ֵ */
    if(v>=G.vexnum||v<0)
        exit(ERROR);
    return &G.vertices[v].data;
}

status DFSTraverse(ALGraph G,void(*visit)(char*)){ /* ��ͼG��������ȱ������㷨7.4 */
    visitFunc=visit; /* ʹ��ȫ�ֱ���VisitFunc,ʹDFS�����躯��ָ����� */
    if (G.vexnum == 0) {
        printf("ͼΪ��.\n");
        return ERROR;
    }
    int v;
    for(v=0;v<G.vexnum;v++)
        visited[v]=FALSE; /* ���ʱ�־�����ʼ�� */
    for(v=0;v<G.vexnum;v++)
        if(!visited[v])
            DFS(G,v); /* ����δ���ʵĶ������DFS */
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
    QueuePtr front, rear; /* ��ͷ����βָ�� */
}LinkQueue;

status InitQueue(LinkQueue *Q){
    /* ����һ���ն���Q */
    (*Q).front = (*Q).rear = (QueuePtr)malloc(sizeof(QNode));
    if (!(*Q).front)
        exit(OVERFLOW);
    (*Q).front->next = NULL;
    return OK;
}

status DestroyQueue(LinkQueue *Q){
    /* ���ٶ���Q(���ۿշ����) */
    while ((*Q).front)
    {
        (*Q).rear = (*Q).front->next;
        free((*Q).front);
        (*Q).front = (*Q).rear;
    }
    return OK;
}

status ClearQueue(LinkQueue *Q)
{ /* ��Q��Ϊ�ն��� */
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
{ /* ��QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE */
    if (Q.front == Q.rear)
        return TRUE;
    else
        return FALSE;
}

int QueueLength(LinkQueue Q)
{ /* ����еĳ��� */
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
status GetHead_Q(LinkQueue Q, QElemType *e) /* ������bo2-6.c���� */
{ /* �����в���,����e����Q�Ķ�ͷԪ��,������OK,���򷵻�ERROR */
    QueuePtr p;
    if (Q.front == Q.rear)
        return ERROR;
    p = Q.front->next;
    *e = p->data;
    return OK;
}

status EnQueue(LinkQueue *Q, QElemType e)
{ /* ����Ԫ��eΪQ���µĶ�βԪ�� */
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if (!p) /* �洢����ʧ�� */
        exit(OVERFLOW);
    p->data = e;
    p->next = NULL;
    (*Q).rear->next = p;
    (*Q).rear = p;
    return OK;
}

status DeQueue(LinkQueue *Q, QElemType *e)
{ /* �����в���,ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK,���򷵻�ERROR */
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
{ /* �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���vi()��һ��viʧ��,�����ʧ�� */
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

status BFSTraverse(ALGraph G,void(*visit)(char*)){/*��������ȷǵݹ����ͼG��ʹ�ø�������Q�ͷ��ʱ�־����visited���㷨7.6 */
    if (G.vexnum == 0) {
        printf("ͼΪ��.\n");
        return ERROR;
    }
    VertexType u1,w1;
    LinkQueue Q;
    int v, u, w;
    for(v=0;v<G.vexnum;++v)
        visited[v]=FALSE; /* �ó�ֵ */
    InitQueue(&Q); /* �ÿյĸ�������Q */
    for(v=0;v<G.vexnum;v++) /* �������ͨͼ,ֻv=0�ͱ���ȫͼ */
        if(!visited[v]) /* v��δ���� */{
            visited[v]=TRUE;
            visit(G.vertices[v].data);
            EnQueue(&Q,v); /* v����� */
            while(!QueueEmpty(Q)) /* ���в��� */{
                DeQueue(&Q,&u); /* ��ͷԪ�س��Ӳ���Ϊu */
                strcpy(u1,*GetVex(G,u));
                for(w=FirstAdjVex(G,u1);w>=0;w=NextAdjVex(G,u1,strcpy(w1,*GetVex(G,w))))
                    if(!visited[w]) /* wΪu����δ���ʵ��ڽӶ��� */{
                        visited[w]=TRUE;
                        visit(G.vertices[w].data);
                        EnQueue(&Q,w); /* w��� */
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
    
    fwrite(&(G->vexnum), sizeof(int), 1, fp);//д�붥����������ڶ�ȡ
    fwrite(&(G->arcnum), sizeof(int), 1, fp);
    fwrite(&(G->kind), sizeof(int), 1, fp);
    
    for (indicator=0; indicator<G->vexnum; indicator++) {
        fwrite(&G->vertices[indicator].data,sizeof(VertexType), 1,fp);
        
        for (temp=G->vertices[indicator].firstarc; temp!=NULL; temp=temp->nextarc) {
            count++;
        }
        fwrite(&count, sizeof(int), 1, fp);//д��˶��㻡�ĸ���
        
        for (temp=G->vertices[indicator].firstarc; temp!=NULL; temp=temp->nextarc) {
//            д�뻡����Ϣ
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







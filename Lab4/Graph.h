#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
#define MAX_VERTEX_NUM 20
#define MAX_NAME 3 /* �����ַ�������󳤶�+1 */

typedef enum { DG, DN, AG, AN }GraphKind; /* {����ͼ,������,����ͼ,������} */
typedef int status;
typedef char VertexType[MAX_NAME];
typedef int InfoType;

typedef struct ArcNode {
    int adjvex; /* �û���ָ��Ķ����λ�� */
    struct ArcNode *nextarc; /* ָ����һ������ָ�� */
    InfoType *info; /* ����Ȩֵָ�룩 */
}ArcNode;

typedef struct {
    VertexType data; /* ������Ϣ */
    ArcNode *firstarc; /* ��һ������ĵ�ַ,ָ���һ�������ö���Ļ���ָ�� */
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct {
    AdjList vertices;
    int vexnum, arcnum; /* ͼ�ĵ�ǰ�������ͻ��� */
    int kind; /* ͼ�������־ */
}ALGraph;

status CreateGraph(ALGraph *G);
status DestroyGraph(ALGraph *G);
status LocateVex(ALGraph G,VertexType u);
status FirstAdjVex(ALGraph G,VertexType v);
status NextAdjVex(ALGraph G,VertexType v,VertexType w);
status InsertVex(ALGraph *G,VertexType v);
status DeleteVex(ALGraph *G,VertexType v);
status InsertArc(ALGraph *G,VertexType v,VertexType w);
status DeleteArc(ALGraph *G,VertexType v,VertexType w);
status DFSTraverse(ALGraph G,void (*visit)(char*));
status BFSTraverse(ALGraph G,void (*visit)(char *));
VertexType* GetVex(ALGraph G,int v);
status PutVex(ALGraph *G, int i);
int Load(ALGraph *G);
int Save(ALGraph *G);

void (*visitFunc)(char* v);
bool visited[MAX_VERTEX_NUM];
int DFS(ALGraph G,int v);
void print(char *i);
int Save(ALGraph *G);
int Load(ALGraph *G);

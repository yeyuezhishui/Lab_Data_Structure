#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
#define MAX_VERTEX_NUM 20
#define MAX_NAME 3 /* 顶点字符串的最大长度+1 */

typedef enum { DG, DN, AG, AN }GraphKind; /* {有向图,有向网,无向图,无向网} */
typedef int status;
typedef char VertexType[MAX_NAME];
typedef int InfoType;

typedef struct ArcNode {
    int adjvex; /* 该弧所指向的顶点的位置 */
    struct ArcNode *nextarc; /* 指向下一条弧的指针 */
    InfoType *info; /* 网的权值指针） */
}ArcNode;

typedef struct {
    VertexType data; /* 顶点信息 */
    ArcNode *firstarc; /* 第一个表结点的地址,指向第一条依附该顶点的弧的指针 */
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct {
    AdjList vertices;
    int vexnum, arcnum; /* 图的当前顶点数和弧数 */
    int kind; /* 图的种类标志 */
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

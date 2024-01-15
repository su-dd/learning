#include "Head.h"
#include <iostream>
#include "Graph.h"

namespace MiniSpanTree
{
/*Prim算法生成最小生成树*/
void MiniSpanTree_Prim(MatrixGraph& G) {
    int adjVertex[MaxVertexNum];	//保存相关顶点下标；adjvex数组的值是当前节点，adjvex数组的下标 为指向的节点
    int lowcost[MaxVertexNum];	//保存相关顶点间边的权值
    lowcost[0] = 0;	//初始化第一个权值为0，即v0加入生成树
    //lowcost的值为0，在这里就是此下标的顶点已经加入生成树
    adjVertex[0] = 0;	//初始化第一个顶点下标为0

    for(int i=1; i<G.vexnum; i++) {
        lowcost[i] = G.arc[0][i];	//将v0顶点与之组成边的权值存入数组
        adjVertex[i] = 0;	//初始化都为v0的下标
    }

    for(int i=1; i<G.vexnum; i++){
        int min = INF;	//初始化最下权值为∞，通常设置一个不可能的很大的数字
        int j = 1, k = 0;
        //循环全部顶点
        while(j < G.vexnum){
            //如果权值不为0且权值小于min
            if(lowcost[j] != 0 && lowcost[j] < min){
                min = lowcost[j];	//则让当前权值成为最小值
                k = j;	//将当前最小值的下标存入k
            }
            j++;
        }

        printf("(%d->%d, cost %d) \n", adjVertex[k], k, min);	//打印当前顶点边中权值的最小边

        for(int i=1; i<G.vexnum; i++){
            //若下标为k顶点各边权值小于此前这些顶点未被加入生成树权值
            if(lowcost[i] != 0 && G.arc[k][i] < lowcost[i]){
                lowcost[i] = G.arc[k][i];	//将较小权值存入lowcost ； 这里会将G.arc[k][K]的值 0 做赋值；让已经输出的值不再输出
                adjVertex[i] = k;	//将下标为k的顶点存入adjvex
            }
        }
    }
}

/*查找连线顶点的尾部下标*/
int Find(int* parent, int f) {
    while (parent[f] > 0) {
        f = parent[f];
    }
    return f;
}

/*Kruskar算法生成最小生成树*/
void MiniSpanTree_Kruskal(EdgesGraph G) {
    int parent[MaxVertexNum];	//定义一数组用来判断边与边是否形成环路
    for (int i = 0; i < G.vexnum; i++) {
        parent[i] = 0;	//初始化数组为0
    }
    for (int i = 0; i < G.edgenum; i++) {
        int n = Find(parent, G.edges[i].begin);
        int m = Find(parent, G.edges[i].end);
        /*假如n与m不等，说明此边没有与现有生成树形成环路*/
        if (n != m) {
            /*将此边的结尾顶点放入下标为起点的parent中，表示此顶点已经在生成树集合中*/
            parent[n] = m;
            printf("(%d->%d, cost %d) \n", G.edges[i].begin, G.edges[i].end, G.edges[i].weight);
        }
    }
}

int test()
{
    MatrixGraph MG;
    MG.vexnum = 9;
    VertexType vertex[9] = { "V0", "V1", "V2", "V3", "V4", "V5", "V6", "V7", "V8" };
    EdgeType arc[9][9] = {
            {  0,  10, INF, INF, INF,  11, INF, INF, INF},
            { 10,   0,  18, INF, INF, INF,  16, INF,  12},
            {INF,  18,   0,  22, INF, INF, INF, INF,   8},
            {INF, INF,  22,   0,  20, INF, INF,  16,  21},
            {INF, INF, INF,  20,   0,  26, INF,   7, INF},
            { 11, INF, INF, INF,  26,   0,  17, INF, INF},
            {INF,  16, INF, INF, INF,  17,   0,  19, INF},
            {INF, INF, INF,  16,   7, INF,  19,   0, INF},
            {INF,  12,   8,  21, INF, INF, INF, INF,   0},
    };
        
    for (int i = 0; i < MG.vexnum; i++)
    {
        MG.vertex[i] = vertex[i];
    }

    int arcnum = 1;
    for (int i = 0; i < MG.vexnum; i++)
    {
        for (int j = 0; j < MG.vexnum; j++)
        {
            MG.arc[i][j] = arc[i][j];
            if (arc[i][j] != 0 && arc[i][j] != INF)
            {
                arcnum++;
            }
        }
    }
    MG.arcnum = arcnum / 2;

    std::cout << "Prim 最小生成树： " << std::endl;
    MiniSpanTree_Prim(MG);
    std::cout << std::endl;

    std::cout << "Kruskal 最小生成树： " << std::endl;
    EdgesGraph EG = MatrixGraph2EdgesGraph(MG);
    MiniSpanTree_Kruskal(EG);
    std::cout << std::endl;
    return 0;
}
}

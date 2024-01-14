# include "Head.h"
#include <iostream>

namespace Prim
{
#define MaxVertexNum 100	//顶点数目的最大值
#define INFINITY 65535      //无限一般用的 很大、特定 的值来表示
typedef char VertexType;	//顶点的数据类型
typedef int EdgeType;	//带权图中边上权值的数据类型

typedef struct{
    VertexType Vex[MaxVertexNum];	//顶点表
    EdgeType arc[MaxVertexNum][MaxVertexNum];	//邻接矩阵，边表
    int vexnum, arcnum;	//图的当前顶点数和弧树
}MGraph;

/*Prim算法生成最小生成树*/
void MiniSpanTree_Prim(MGraph G) {
    int min, i, j, k;
    int adjvex[MaxVertexNum];	//保存相关顶点下标
    int lowcost[MaxVertexNum];	//保存相关顶点间边的权值
    lowcost[0] = 0;	//初始化第一个权值为0，即v0加入生成树
    //lowcost的值为0，在这里就是此下标的顶点已经加入生成树
    adjvex[0] = 0;	//初始化第一个顶点下标为0

    for(i=1; i<G.vexnum; i++){
        lowcost[i] = G.arc[0][i];	//将v0顶点与之组成边的权值存入数组
        adjvex[i] = 0;	//初始化都为v0的下标
    }

    for(i=1; i<G.vexnum; i++){
        min = INFINITY;	//初始化最下权值为∞，通常设置一个不可能的很大的数字
        j = 1; k = 0;
        //循环全部顶点
        while(j < G.vexnum){
            //如果权值不为0且权值小于min
            if(lowcost[j] != 0 && lowcost[j] < min){
                min = lowcost[j];	//则让当前权值成为最小值
                k = j;	//将当前最小值的下标存入k
            }
            j++;
        }
        printf("(%d, %d)", adjvex[k], k);	//打印当前顶点边中权值的最小边

        for(j=1; j<G.vexnum; j++){
            //若下标为k顶点各边权值小于此前这些顶点未被加入生成树权值
            if(lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
            {
                lowcost[j] = G.arc[k][j];	//将较小权值存入lowcost
                adjvex[j] = k;	//将下标为k的顶点存入adjvex
            }
        }
    }
}
int test()
{
    return 0;
}
}

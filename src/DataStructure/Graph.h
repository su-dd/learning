#ifndef Graph_H
#define Graph_H

#include <iostream>
#define MaxVertexNum 100  	//顶点数目的最大值
#define MAXEDGE 1000        //边数目的最大值
#define INF 65535           //无限一般用的 很大、特定 的值来表示
typedef std::string VertexType;	//顶点的数据类型
typedef int EdgeType;	//带权图中边上权值的数据类型

// 邻接矩阵表示图
struct MatrixGraph {
    VertexType vertex[MaxVertexNum];	//顶点表
    EdgeType arc[MaxVertexNum][MaxVertexNum];	//邻接矩阵
    int vexnum, arcnum;	//图的当前顶点数和弧数
};


struct EdgesGraph // 定义边集数组
{
    // 边定义
    struct Edge {
        int begin;	// 起点下标
        int end;	// 终点下标
        int weight;	// 权重
    };

    VertexType vertex[MaxVertexNum];	//顶点表
    Edge edges[MAXEDGE];	// 边集数组
    int vexnum, edgenum;	//图的当前顶点数和弧数
};


// 邻接矩阵 转 边集数组
EdgesGraph MatrixGraph2EdgesGraph(MatrixGraph& MGraph);

#endif // !Graph_H

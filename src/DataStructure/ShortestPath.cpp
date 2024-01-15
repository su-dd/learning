#include "Head.h"
#include "Graph.h"
#include <iostream>
#include <string>
namespace ShortestPath {

    struct Path {
        std::string path = "V0";   // 路径
        int distance;       // 距离起点的距离
        bool visit = false; // 是否已经被访问
    };

    /* 最短路径：迪杰斯特拉( Dijkstra )算法（单源最短路径）*/
    void ShortestPath_Dijkstra(MatrixGraph &MG)
    {
        Path* node = new Path[MG.vexnum]; // node的下标为顶点下标

        for (int i = 0; i < MG.vexnum; i++)
        {
            node[i].distance = MG.arc[0][i];
            node[i].path = "V0->V" + std::to_string(i);
        }
        node[0].visit = true;



        do
        {
            int minLoc = 1;
            for (int i = 1; i < MG.vexnum; i++) // 获取 
            {
                if (!node[minLoc].visit && node[minLoc].distance > node[i].distance)
                {
                    minLoc = i;
                }
            }
            node[minLoc].visit = true;

            for (int i = 1; i < MG.vexnum; i++)
            {
                if (MG.arc[i][minLoc] != INF && MG.arc[i][minLoc] != 0) // 排除 “不可连通” 和 “自己”
                {
                    if (node[minLoc].distance + MG.arc[i][minLoc] < node[i].distance)
                    {
                        node[i].distance = node[minLoc].distance + MG.arc[i][minLoc];
                        node[i].path = node[minLoc].path + "->V" + std::to_string(i);
                    }
                }
            }


        } while (true)；
    }

    /* 最短路径：弗洛伊德( Floyd )算法（多源最短路径）*/
    void ShortestPath_Floyd(MatrixGraph &MG)
    {

    }

    int test()
    {
        MatrixGraph MG;
        MG.vexnum = 9;
        VertexType vertex[9] = { "V0", "V1", "V2", "V3", "V4", "V5", "V6", "V7", "V8" };
        EdgeType arc[9][9] = 
        {
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
    }
}


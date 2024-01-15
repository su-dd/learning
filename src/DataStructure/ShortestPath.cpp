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

    struct FloydPath
    {
        int D[9][9] = { 0 };
        int P[9][9] = { 0 };
    };

    /* 最短路径：迪杰斯特拉( Dijkstra )算法（单源最短路径）*/
    void ShortestPath_Dijkstra(MatrixGraph &G)
    {
        Path *node = new Path[G.vexnum]; // node的下标为顶点下标

        for (int i = 0; i < G.vexnum; i++)
        {
            node[i].distance = G.arc[0][i];
            node[i].path = "V0->V" + std::to_string(i);
        }
        node[0].visit = true;


        int num = 1;
        do
        {
            int minLoc = 1;
            for (int i = 1; i < G.vexnum; i++) // 获取当前最短的路径
            {
                if (node[minLoc].visit && !node[i].visit)
                {
                    minLoc = i;
                }
                else if (!node[i].visit && node[minLoc].distance > node[i].distance)
                {
                    minLoc = i;
                }
            }
            node[minLoc].visit = true;

            for (int i = 1; i < G.vexnum; i++)
            {
                if (G.arc[i][minLoc] != INF && G.arc[i][minLoc] != 0) // 排除 “不可连通” 和 “自己”
                {
                    if (node[minLoc].distance + G.arc[i][minLoc] < node[i].distance)
                    {
                        node[i].distance = node[minLoc].distance + G.arc[i][minLoc];
                        node[i].path = node[minLoc].path + "->V" + std::to_string(i);
                    }
                }
            }

        } while (num++ < G.vexnum);

        for (int i = 0; i < G.vexnum; i++)
        {
            std::cout << node[i].path << " distance:" << node[i].distance << std::endl;
        }
        delete[] node;
    }

    /* 最短路径：弗洛伊德( Floyd )算法（多源最短路径）*/
    void ShortestPath_Floyd(MatrixGraph &G, FloydPath &path)
    {
        // 初始化矩阵
        for (int v = 0; v < G.vexnum; v++)
        {
            for (int w = 0; w < G.vexnum; w++)
            {
                path.D[v][w] = G.arc[v][w];
                path.P[v][w] = w;   // 设置为w，代步的事
            }
        }

        // 3重循环核心算法
        for (int k = 0; k < G.vexnum; k++)//k为中间点 
        {
            for (int v = 0; v < G.vexnum; v++) //v为起点
            {
                for (int w = 0; w < G.vexnum; w++) //w为终点
                {
                    if (path.D[v][w] > path.D[v][k] + path.D[k][w])
                    {
                        path.D[v][w] = path.D[v][k] + path.D[k][w]; // 更新最小路径
                        path.P[v][w] = path.P[v][k];                // 更新最小路径中间顶点
                    }
                }
            }
        }
    }

    /* 通过 弗洛伊德( Floyd )算法的结果，输出 节点间 的路径和 权重*/
    void print_Floyd(MatrixGraph& G, FloydPath& path, int begin, int end)
    {
        std::string str = G.vertex[begin];
        int k = begin;
        do
        {
            k = path.P[k][end];
            str = str + "->" + G.vertex[k];
        } while (k != end);

        std::cout << "path: " << str << " value: " << path.D[begin][end] << std::endl;
    }

    int test()
    {
        MatrixGraph G;
        G.vexnum = 9;
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

        for (int i = 0; i < G.vexnum; i++)
        {
            G.vertex[i] = vertex[i];
        }

        int arcnum = 1;
        for (int i = 0; i < G.vexnum; i++)
        {
            for (int j = 0; j < G.vexnum; j++)
            {
                G.arc[i][j] = arc[i][j];
                if (arc[i][j] != 0 && arc[i][j] != INF)
                {
                    arcnum++;
                }
            }
        }
        G.arcnum = arcnum / 2;
        std::cout << "最短路径算法：迪杰斯特拉( Dijkstra )" << std::endl;
        ShortestPath_Dijkstra(G);
        std::cout << std::endl;


        std::cout << "最短路径算法：弗洛伊德( Floyd )" << std::endl;
        FloydPath path;
        ShortestPath_Floyd(G, path);
        print_Floyd(G, path, 0, 7); // 输出V0到V7 的路径和 权重
        std::cout << std::endl;

        return 0;
    }
}


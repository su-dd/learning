#include <stdio.h>

void Floyd(MatGraph MG)
{
    int i, j, k;
    int A[MAXV][MAXV];
    int path[MAXV][MAXV];
    for (i = 0; i < MG.n; i++)
    {
        for (j = 0; j < MG.n; j++)
        {
            A[i][j] = MG.adjMat[i][j];
            if (i != j && MG.adjMat[i][j] < INF)
            {
                path[i][j] = i; // 顶点 i 到顶点 j 有边时
            }
            else
            {
                path[i][j] = -1; // 顶点 i 到顶点 j 无边时
            }
        }
    }
    for (k = 0; k < MG.n; k++)
    { // 一次考察所有顶点
        for (i = 0; i < MG.n; i++)
        {
            for (j = 0; j < MG.n; j++)
            {
                if (A[i][j] > A[i][k] + A[k][j])
                {
                    A[i][j] = A[i][k] + A[k][j]; // 修改最短路径长度
                    path[i][j] = path[k][j];     // 修改最短路径
                }
            }
        }
    }
    displayPath(MG, A, path); // 输出最短路径
}

void displayPath(MatGraph MG, int A[MAXV][MAXV], int path[MAXV][MAXV])
{
    int i, j, k;
    int s;
    int aPath[MAXV]; // 存放一条最短路径（逆向）
    int d;           // 顶点个数
    for (i = 0; i < MG.n; i++)
    {
        for (j = 0; j < MG.n; j++)
        {
            if (A[i][j] != INF && i != j)
            { // 若顶点 i 和 顶点 j 之间存在路径
                printf("从 %d 到 %d 的路径为：", i, j);
                k = path[i][j];
                d = 0;
                aPath[d] = j; // 路径上添加终点
                while (k != -1 && k != i)
                { // 路劲上添加中间点
                    d++;
                    aPath[d] = k;
                    k = path[i][k];
                }
                d++;
                aPath[d] = i;           // 路径上添加起点
                printf("%d", aPath[d]); // 输出起点
                for (s = d - 1; s >= 0; s--)
                { // 输出路径上其他顶点
                    printf("->%d", aPath[s]);
                }
                printf("\t\t");
                printf("路径长度为：%d\n", A[i][j]);
            }
        }
    }
}

#include "Graph.h"

EdgesGraph MatrixGraph2EdgesGraph(MatrixGraph& MGraph)
{
    EdgesGraph EGraph;
    EGraph.vexnum = MGraph.vexnum;
    for (int i = 0; i < MGraph.vexnum; i++)
    {
        EGraph.vertex[i] = MGraph.vertex[i];
    }
    int k = 0;
    for (int i = 0; i < MGraph.vexnum; i++)
    {
        for (int j = i + 1; j < MGraph.vexnum; j++)
        {
            if (MGraph.arc[i][j] != INF)
            {
                EGraph.edges[k++] = EdgesGraph::Edge{ i, j, MGraph.arc[i][j] };
            }
        }
    }
    EGraph.edgenum = k;

    // ͨ��ѡ��������ʵ�� ��С����������
    for (int i = 0; i < EGraph.edgenum; i++)
    {
        int min = i;
        for (int j = i + 1; j < EGraph.edgenum; j++)
        {
            if (EGraph.edges[min].weight > EGraph.edges[j].weight)
            {
                min = j;
            }
        }

        if (i != min)
        {
            std::swap(EGraph.edges[min], EGraph.edges[i]); // swapͨ��move��ʵ�֣�Ч�ʸ���
        }
    }

    return EGraph;
}
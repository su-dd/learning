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

    // 通过选择排序来实现 先小，后大的排序
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
            std::swap(EGraph.edges[min], EGraph.edges[i]); // swap通过move来实现，效率更高
        }
    }

    return EGraph;
}
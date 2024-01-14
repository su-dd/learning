using System;

/**
* Dijkstra�㷨��ȡ���·��
*/
public class Dijkstra
{
    public static int MAX = int.MaxValue;

    // �ڽӱ��б��Ӧ������Ķ���
    public class ENode
    {
        public int ivex;       // �ñ���ָ��Ķ����λ��
        public int weight;     // �ñߵ�Ȩ
        public ENode nextEdge; // ָ����һ������ָ��
    }

    // �ڽӱ��б�Ķ���
    public class VNode
    {
        public char data;          // ������Ϣ
        public ENode firstEdge;    // ָ���һ�������ö���Ļ�
    }

    // �ߵĽṹ��
    public class EData
    {
        public char start; // �ߵ����
        public char end;   // �ߵ��յ�
        public int weight; // �ߵ�Ȩ��

        public EData(char start, char end, int weight)
        {
            this.start = start;
            this.end = end;
            this.weight = weight;
        }
    }

    public int mEdgNum;    // �ߵ�����
    public VNode[] mVexs;  // ��������

    /*
     * ����ͼ
     *
     * ����˵����
     *     vexs  -- ��������
     *     edges -- ��
     */
    public Dijkstra(char[] vexs, EData[] edges)
    {

        // ��ʼ��"������"��"����"
        int vlen = vexs.Length;
        int elen = edges.Length;

        // ��ʼ��"����"
        mVexs = new VNode[vlen];
        for (int i = 0; i < mVexs.Length; i++)
        {
            mVexs[i] = new VNode();
            mVexs[i].data = vexs[i];
            mVexs[i].firstEdge = null;
        }

        // ��ʼ��"��"
        mEdgNum = elen;
        for (int i = 0; i < elen; i++)
        {
            // ��ȡ�ߵ���ʼ����ͽ�������
            char c1 = edges[i].start;
            char c2 = edges[i].end;
            int weight = edges[i].weight;

            // ��ȡ�ߵ���ʼ����ͽ�������
            int p1 = GetPosition(c1);
            int p2 = GetPosition(c2);
            // ��ʼ��node1
            ENode node1 = new ENode();
            node1.ivex = p2;
            node1.weight = weight;
            // ��node1���ӵ�"p1���������ĩβ"
            if (mVexs[p1].firstEdge == null)
                mVexs[p1].firstEdge = node1;
            else
                LinkLast(mVexs[p1].firstEdge, node1);
            // ��ʼ��node2
            ENode node2 = new ENode();
            node2.ivex = p1;
            node2.weight = weight;
            // ��node2���ӵ�"p2���������ĩβ"
            if (mVexs[p2].firstEdge == null)
                mVexs[p2].firstEdge = node2;
            else
                LinkLast(mVexs[p2].firstEdge, node2);
        }
    }

    /*
     * ��node�ڵ����ӵ�list�����
     */
    private void LinkLast(ENode list, ENode node)
    {
        ENode p = list;

        while (p.nextEdge != null)
            p = p.nextEdge;
        p.nextEdge = node;
    }

    /*
     * ����chλ��
     */
    private int GetPosition(char ch)
    {
        for (int i = 0; i < mVexs.Length; i++)
            if (mVexs[i].data == ch)
                return i;
        return -1;
    }

    /*
     * ��ȡ��<start, end>��Ȩֵ����start��end������ͨ�ģ��򷵻������
     */
    private int GetWeight(int start, int end)
    {
        if (start == end)
            return 0;

        ENode node = mVexs[start].firstEdge;
        while (node != null)
        {
            if (end == node.ivex)
                return node.weight;
            node = node.nextEdge;
        }

        return MAX;
    }

    /*
     * Dijkstra���·����
     * ����ͳ��ͼ��"���D"������������������·����
     *
     * ����˵����
     *       vs -- ��ʼ����(start vertex)��
     *     prev -- ǰ���������顣����prev[i]��ֵ��"���D"��"����i"�����·����������ȫ�������У�λ��"����i"֮ǰ���Ǹ����㡣
     *     dist -- �������顣����dist[i]��"���D"��"����i"�����·���ĳ��ȡ�
     */
    public void CalcDijkstra(int vs, int[] prev, int[] dist)
    {
        // flag[i]=true��ʾ"���D"��"����i"�����·���ѳɹ���ȡ��
        bool[] flag = new bool[mVexs.Length];

        // ��ʼ��
        for (int i = 0; i < mVexs.Length; i++)
        {
            flag[i] = false;            // ����i�����·����û��ȡ����
            prev[i] = 0;                // ����i��ǰ������Ϊ0��
            dist[i] = GetWeight(vs, i); // ����i�����·��Ϊ"���D"��"����i"��Ȩ��
        }

        // ��"���D"������г�ʼ��
        flag[vs] = true;
        dist[vs] = 0;

        // ����mVexs.Length-1�Σ�ÿ���ҳ�һ����������·����
        int k = 0;
        for (int i = 1; i < mVexs.Length; i++)
        {
            // Ѱ�ҵ�ǰ��С��·��
            // ������δ��ȡ���·���Ķ����У��ҵ������D����Ķ���(k)��
            int min = MAX;
            for (int j = 0; j < mVexs.Length; j++)
            {
                if (flag[j] == false && dist[j] < min)
                {
                    min = dist[j];
                    k = j;
                }
            }
            // ���"����k"Ϊ�Ѿ���ȡ�����·��
            flag[k] = true;

            // ���µ�ǰ���·����ǰ������
            // ��������"δ��ȡ���·���Ķ�������·����ǰ������"��
            for (int j = 0; j < mVexs.Length; j++)
            {
                int tmp = GetWeight(k, j);
                tmp = (tmp == MAX ? MAX : (min + tmp)); // ��ֹ���
                if (flag[j] == false && (tmp < dist[j]))
                {
                    dist[j] = tmp;
                    prev[j] = k;
                }
            }
        }

        // ��ӡdijkstra���·���Ľ��
        Console.WriteLine("dijkstra({0}): \n", mVexs[vs].data);
        for (int i = 0; i < mVexs.Length; i++)
        {
            Console.WriteLine("shortest({0}, {1})={2}\n", mVexs[vs].data, mVexs[i].data, dist[i]);
        }
    }


    public static void Main(string[] args)
    {
        char[] vexs = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
        EData[] edges = {
            // ��� �յ� Ȩ��
            new EData('A', 'B', 12),
            new EData('A', 'F', 16),
            new EData('A', 'G', 14),
            new EData('B', 'C', 10),
            new EData('B', 'F',  7),
            new EData('C', 'D',  3),
            new EData('C', 'E',  5),
            new EData('C', 'F',  6),
            new EData('D', 'E',  4),
            new EData('E', 'F',  2),
            new EData('E', 'G',  8),
            new EData('F', 'G',  9),
        };
        Dijkstra pG = new Dijkstra(vexs, edges);
        // dijkstra�㷨��ȡ"���D"�����������������̾���
        int[] prev = new int[pG.mVexs.Length];
        int[] dist = new int[pG.mVexs.Length];
        pG.CalcDijkstra(3, prev, dist);

        Console.ReadKey();
    }
}
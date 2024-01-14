# include "Head.h"
#include <iostream>

namespace Prim
{
#define MaxVertexNum 100	//������Ŀ�����ֵ
#define INFINITY 65535      //����һ���õ� �ܴ��ض� ��ֵ����ʾ
typedef char VertexType;	//�������������
typedef int EdgeType;	//��Ȩͼ�б���Ȩֵ����������

typedef struct{
    VertexType Vex[MaxVertexNum];	//�����
    EdgeType arc[MaxVertexNum][MaxVertexNum];	//�ڽӾ��󣬱߱�
    int vexnum, arcnum;	//ͼ�ĵ�ǰ�������ͻ���
}MGraph;

/*Prim�㷨������С������*/
void MiniSpanTree_Prim(MGraph G) {
    int min, i, j, k;
    int adjvex[MaxVertexNum];	//������ض����±�
    int lowcost[MaxVertexNum];	//������ض����ߵ�Ȩֵ
    lowcost[0] = 0;	//��ʼ����һ��ȨֵΪ0����v0����������
    //lowcost��ֵΪ0����������Ǵ��±�Ķ����Ѿ�����������
    adjvex[0] = 0;	//��ʼ����һ�������±�Ϊ0

    for(i=1; i<G.vexnum; i++){
        lowcost[i] = G.arc[0][i];	//��v0������֮��ɱߵ�Ȩֵ��������
        adjvex[i] = 0;	//��ʼ����Ϊv0���±�
    }

    for(i=1; i<G.vexnum; i++){
        min = INFINITY;	//��ʼ������ȨֵΪ�ޣ�ͨ������һ�������ܵĺܴ������
        j = 1; k = 0;
        //ѭ��ȫ������
        while(j < G.vexnum){
            //���Ȩֵ��Ϊ0��ȨֵС��min
            if(lowcost[j] != 0 && lowcost[j] < min){
                min = lowcost[j];	//���õ�ǰȨֵ��Ϊ��Сֵ
                k = j;	//����ǰ��Сֵ���±����k
            }
            j++;
        }
        printf("(%d, %d)", adjvex[k], k);	//��ӡ��ǰ�������Ȩֵ����С��

        for(j=1; j<G.vexnum; j++){
            //���±�Ϊk�������ȨֵС�ڴ�ǰ��Щ����δ������������Ȩֵ
            if(lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
            {
                lowcost[j] = G.arc[k][j];	//����СȨֵ����lowcost
                adjvex[j] = k;	//���±�Ϊk�Ķ������adjvex
            }
        }
    }
}
int test()
{
    return 0;
}
}

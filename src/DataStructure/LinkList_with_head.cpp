#include "SqHead.h"
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

namespace LinkList_with_head {
//5����������
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1

//���Ͷ���
typedef int Status;
typedef int ElemType;

//���Գ��򳤶ȶ���
#define LONGTH 5

//���������
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

//��������n��Ԫ�ص�����L��Ԫ��ֵ�洢��data������
Status create(LinkList &L, ElemType *data, int n) {
    LNode *p, *q;
    int i;
    if (n < 0) return ERROR;
    p = L = NULL;

    q = (LNode *)malloc(sizeof(LNode));
    if (NULL == q) return OVERFLOW;
    q->next = NULL;
    p = L = q;

    for (i = 0; i < n; i++)
    {
        q = (LNode *)malloc(sizeof(LNode));
        if (NULL == q) return OVERFLOW;
        q->data = data[i];
        q->next = NULL;
        p->next = q;
        p = q;
    }
    return OK;
}

//e������ĩβ������
Status EnQueue_LQ(LinkList &L, ElemType &e) {
    LinkList p, q;

    if (NULL == (q = (LNode *)malloc(sizeof(LNode)))) return OVERFLOW;
    q->data = e;
    q->next = NULL;
    if (NULL == L)
    {
        L = (LNode *)malloc(sizeof(LNode));
        if (NULL == L) return OVERFLOW;
        L->next = q;
    }
    else if (NULL == L->next)
    {
        L->next = q;
    }
    else
    {
        p = L;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = q;
    }
    return OK;
}


//������ͷ�ڵ������e
Status DeQueue_LQ(LinkList &L, ElemType &e) {
    if (NULL == L || NULL == L->next) return ERROR;
    LinkList p;
    p = L->next;
    e = p->data;
    L->next = p->next;
    free(p);
    return OK;
}

//��������
Status visit(ElemType e) {
    printf("%d\t", e);
    return OK;
}

//����������
void ListTraverse_L(LinkList L, Status(*visit)(ElemType e))
{
    if (NULL == L || NULL == L->next) return;
    for (LinkList p = L->next; NULL != p; p = p->next) {
        visit(p->data);
    }
}

int test() {
    int i;
    ElemType e, data[LONGTH] = { 1, 2, 3, 4, 5 };
    LinkList L;

    //��ʾ����ֵ
    printf("---����ͷ���ĵ�����---\n");
    printf("������Ԫ��Ϊ��\n");
    for (i = 0; i < LONGTH; i++) printf("%d\t", data[i]);
    printf("\n");

    //��������L
    printf("��������L\n");
    if (ERROR == create(L, data, LONGTH))
    {
        printf("��������Lʧ��\n");
        return -1;
    }
    printf("�ɹ���������1��ͷ��㡢%d��Ԫ�ص�����L\nԪ��ֵ�洢��data������\n", LONGTH);

    //����������
    printf("��ʱ������Ԫ��Ϊ��\n");
    ListTraverse_L(L, visit);

    //������ͷ�ڵ������e
    printf("\n������e\n");
    DeQueue_LQ(L, e);
    printf("�������Ԫ��Ϊ��%d\n", e);
    printf("��ʱ������Ԫ��Ϊ��\n");

    //����������
    ListTraverse_L(L, visit);

    //e������ĩβ������
    printf("\ne������\n");
    EnQueue_LQ(L, e);
    printf("�������Ԫ��Ϊ��%d\n", e);
    printf("��ʱ������Ԫ��Ϊ��\n");

    //����������
    ListTraverse_L(L, visit);
    printf("\n");

    getchar();
    return 0;
}
}

#include "SqHead.h"
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

namespace SqList {
//5����������
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1

//���Գ��򳤶ȶ���
#define LONGTH 5

//���Ͷ���
typedef int Status;
typedef int ElemType;

//˳���б������
typedef struct {
    ElemType *elem; // ������ָ��
    int length;     // ������Ԫ�ظ���
    int size;       // ���д�С
    int increment;  // ������С
} SqList;

//��ʼ��˳���L
Status InitList_Sq(SqList &L, int size, int inc) {
    L.elem = (ElemType *)malloc(size * sizeof(ElemType));
    if (NULL == L.elem) return OVERFLOW;
    L.length = 0;
    L.size = size;
    L.increment = inc;
    return OK;
}

//����˳���L
Status DestroyList_Sq(SqList &L) {
    free(L.elem);
    L.elem = NULL;
    return OK;
}

//��˳���L���
Status ClearList_Sq(SqList &L) {
    if (0 != L.length) L.length = 0;
    return OK;
}

//��˳���LΪ�ձ��򷵻�TRUE������FALSE
Status ListEmpty_Sq(SqList L) {
    if (0 == L.length) return TRUE;
    return FALSE;
}

//����˳���L��Ԫ�ظ���
int ListLength_Sq(SqList L) {
    return L.length;
}

// ��e����˳���L�е�i��Ԫ�ص�ֵ
Status GetElem_Sq(SqList L, int i, ElemType &e) {
    e = L.elem[--i];
    return OK;
}


// ��˳���L˳�����Ԫ��e���ɹ�ʱ���ظ�Ԫ���ڱ��е�һ�γ��ֵ�λ�ã����򷵻� - 1
int Search_Sq(SqList L, ElemType e) {
    int i = 0;
    while (i < L.length && L.elem[i] != e) i++;
    if (i < L.length) return i;
    else return -1;
}

//��������
Status visit(ElemType e) {
    printf("%d\t", e);
    return OK;
}

//����˳���L�����ζ�ÿ��Ԫ�ص��ú���visit()
Status ListTraverse_Sq(SqList L, Status(*visit)(ElemType e)) {
    if (0 == L.length) return ERROR;
    for (int i = 0; i < L.length; i++) {
        visit(L.elem[i]);
    }
    return OK;
}

//��˳���L�е�i��Ԫ�ظ�ֵΪe
Status PutElem_Sq(SqList &L, int i, ElemType e) {
    if (i > L.length) return ERROR;
    e = L.elem[--i];
    return OK;

}

//��˳���L��β���Ԫ��e
Status Append_Sq(SqList &L, ElemType e) {
    ElemType *newBase;
    if (L.length >= L.size) // ���������������
    {
        newBase = (ElemType *)realloc(L.elem, (L.size + L.increment) * sizeof(ElemType));
        if (NULL == newBase) return OVERFLOW;
        L.elem = newBase;
        L.size += L.increment;
    }
    L.elem[L.length] = e;
    L.length++;
    return OK;
}

//ɾ��˳���L�ı�βԪ�أ����ò���e������ֵ
Status DeleteLast_Sq(SqList &L, ElemType &e) {
    if (0 == L.length) return ERROR;
    e = L.elem[L.length - 1];
    L.length--;
    return OK;
}

int test() {
    //�����L
    SqList L;

    //�������ֵ
    int size, increment, i;

    //��ʼ������ֵ
    size = LONGTH;
    increment = LONGTH;
    ElemType e, eArray[LONGTH] = { 1, 2, 3, 4, 5 };

    //��ʾ����ֵ
    printf("---��˳��ջ��---\n");
    printf("��L��sizeΪ��%d\n��L��incrementΪ��%d\n", size, increment);
    printf("������Ԫ��Ϊ��\n");
    for (i = 0; i < LONGTH; i++) {
        printf("%d\t", eArray[i]);
    }
    printf("\n");

    //��ʼ��˳���
    if (!InitList_Sq(L, size, increment)) {
        printf("��ʼ��˳���ʧ��\n");
        exit(0);
    }
    printf("�ѳ�ʼ��˳���\n");

    //�п�
    if (TRUE == ListEmpty_Sq(L)) printf("�˱�Ϊ�ձ�\n");
    else printf("�˱��ǿձ�\n");

    //���
    printf("������Ԫ�����\n");
    for (i = 0; i < LONGTH; i++) {
        if (ERROR == Append_Sq(L, eArray[i])) printf("���ʧ��\n");;
    }
    printf("���ɹ�\n");

    Append_Sq(L, 6);

    //����˳���L
    printf("��ʱ����Ԫ��Ϊ��\n");
    ListTraverse_Sq(L, visit);

    //����
    printf("\n����βԪ�����e��\n");
    if (ERROR == DeleteLast_Sq(L, e)) printf("����ʧ��\n");
    printf("����ɹ�\n����Ԫ��Ϊ%d\n", e);

    //����˳���L
    printf("��ʱ����Ԫ��Ϊ��\n");
    ListTraverse_Sq(L, visit);

    //����˳���
    printf("\n����˳���\n");
    if (OK == DestroyList_Sq(L)) printf("���ٳɹ�\n");
    else printf("����ʧ��\n");

    getchar();
    return 0;
}

}

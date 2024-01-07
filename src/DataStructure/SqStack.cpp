#include "SqStack.h"
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

namespace SqStack
{
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

//˳��ջ������
typedef struct {
    ElemType *elem; // ջ��ָ��
    int top;        // ջ��
    int size;       // ��ǰ��С
    int increment;  // ����
} SqSrack;

//��ʼ��˳��ջ
Status InitStack_Sq(SqSrack &S, int size, int inc) {
    S.elem = (ElemType *)malloc(size * sizeof(ElemType));
    if (NULL == S.elem) return OVERFLOW;
    S.top = 0;
    S.size = size;
    S.increment = inc;
    return OK;
}

//����˳��ջ
Status DestroyStack_Sq(SqSrack &S) {
    free(S.elem);
    S.elem = NULL;
    return OK;
}

//�ж�S�Ƿ�գ������򷵻�TRUE�����򷵻�FALSE
Status StackEmpty_Sq(SqSrack S) {
    if (0 == S.top) return TRUE;
    return FALSE;
}

//���ջS
void ClearStack_Sq(SqSrack &S) {
    if (0 == S.top) return;
    S.size = 0;
    S.top = 0;
}

//Ԫ��eѹ��ջS
Status Push_Sq(SqSrack &S, ElemType e) {
    ElemType *newbase;
    // �����С���ޣ��ͽ�������
    if (S.top >= S.size) {
        newbase = (ElemType *)realloc(S.elem, (S.size + S.increment) * sizeof(ElemType));
        if (NULL == newbase) return OVERFLOW;
        S.elem = newbase;
        S.size += S.increment;
    }
    S.elem[S.top++] = e;
    return OK;
}

//ȡջS��ջ��Ԫ�أ�����e����
Status GetTop_Sq(SqSrack S, ElemType &e) {
    if (0 == S.top) return ERROR;
    e = S.elem[S.top - 1];
    return e;
}

//ջS��ջ��Ԫ�س�ջ������e����
Status Pop_Sq(SqSrack &S, ElemType &e) {
    if (0 == S.top) return ERROR;
    e = S.elem[S.top - 1];
    S.top--;
    return e;
}

int test() {
    //����ջS
    SqSrack S;

    //�������ֵ
    int size, increment, i;

    //��ʼ������ֵ
    size = LONGTH;
    increment = LONGTH;
    ElemType e, eArray[LONGTH] = { 1, 2, 3, 4, 5 };

    //��ʾ����ֵ
    printf("---��˳��ջ��---\n");
    printf("ջS��sizeΪ��%d\nջS��incrementΪ��%d\n", size, increment);
    printf("������Ԫ��Ϊ��\n");
    for (i = 0; i < LONGTH; i++) {
        printf("%d\t", eArray[i]);
    }
    printf("\n");

    //��ʼ��˳��ջ
    if (!InitStack_Sq(S, size, increment)) {
        printf("��ʼ��˳��ջʧ��\n");
        exit(0);
    }
    printf("�ѳ�ʼ��˳��ջ\n");

    //��ջ
    for (i = 0; i < S.size; i++) {
        if (!Push_Sq(S, eArray[i])) {
            printf("%d��ջʧ��\n", eArray[i]);
            exit(0);
        }
    }
    printf("����ջ\n");

    //�жϷǿ�
    if (StackEmpty_Sq(S)) printf("SջΪ��\n");
    else printf("Sջ�ǿ�\n");

    //ȡջS��ջ��Ԫ��
    printf("ջS��ջ��Ԫ��Ϊ��\n");
    printf("%d\n", GetTop_Sq(S, e));

    //ջSԪ�س�ջ
    printf("ջSԪ�س�ջΪ��\n");
    for (i = 0, e = 0; i < S.size; i++) {
        printf("%d\t", Pop_Sq(S, e));
    }
    printf("\n");

    //���ջS
    ClearStack_Sq(S);
    printf("�����ջS\n");

    getchar();
    return 0;
}
}

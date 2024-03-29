#include "Head.h"

#include <stdio.h>
#include <stdlib.h>
namespace BinaryTree
{
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define SUCCESS 1
#define UNSUCCESS 0
#define dataNum 5
    int i = 0;
    int dep = 0;
    char data[dataNum] = {'A', 'B', 'C', 'D', 'E'};

    typedef int Status;
    typedef char TElemType;

    // 二叉树结构
    typedef struct BiTNode
    {
        TElemType data;
        struct BiTNode *lchild, *rchild;
    } BiTNode, *BiTree;

    // 初始化一个空树
    void InitBiTree(BiTree &T)
    {
        T = nullptr;
    }

    // 构建二叉树
    BiTree MakeBiTree(TElemType e, BiTree L, BiTree R)
    {
        BiTree t;
        t = (BiTree)malloc(sizeof(BiTNode));
        if (nullptr == t)
            return nullptr;
        t->data = e;
        t->lchild = L;
        t->rchild = R;
        return t;
    }

    // 访问结点
    Status visit(TElemType e)
    {
        printf("%c", e);
        return OK;
    }

    // 对二叉树T求叶子结点数目
    int Leaves(BiTree T)
    {
        int l = 0, r = 0;
        if (nullptr == T)
            return 0;
        if (nullptr == T->lchild && nullptr == T->rchild)
            return 1;

        // 求左子树叶子数目
        l = Leaves(T->lchild);
        // 求右子树叶子数目
        r = Leaves(T->rchild);
        // 组合
        return r + l;
    }

    // 层次遍历：dep是个全局变量,高度
    int depTraverse(BiTree T)
    {
        if (nullptr == T)
            return ERROR;
        // ERROR 为0 ，保证dep每次都被从0开始复制，保证了dep+1的计算正确
        dep = (depTraverse(T->lchild) > depTraverse(T->rchild)) ? depTraverse(T->lchild) : depTraverse(T->rchild);

        return dep + 1;
    }

    // 高度遍历：lev是局部变量，层次
    void levTraverse(BiTree T, Status (*visit)(TElemType e), int lev)
    {
        if (nullptr == T)
            return;
        visit(T->data);
        printf("的层次是%d\n", lev);

        levTraverse(T->lchild, visit, ++lev);
        levTraverse(T->rchild, visit, lev);
    }

    // num是个全局变量
    void InOrderTraverse(BiTree T, Status (*visit)(TElemType e), int &num)
    {
        if (nullptr == T)
            return;
        visit(T->data);
        if (nullptr == T->lchild && nullptr == T->rchild)
        {
            printf("是叶子结点");
            num++;
        }
        else
            printf("不是叶子结点");
        printf("\n");
        InOrderTraverse(T->lchild, visit, num);
        InOrderTraverse(T->rchild, visit, num);
    }

    // 二叉树判空
    Status BiTreeEmpty(BiTree T)
    {
        if (nullptr == T)
            return TRUE;
        return FALSE;
    }

    // 打断二叉树：置空二叉树的左右子树
    Status BreakBiTree(BiTree &T, BiTree &L, BiTree &R)
    {
        if (nullptr == T)
            return ERROR;
        L = T->lchild;
        R = T->rchild;
        T->lchild = nullptr;
        T->rchild = nullptr;
        return OK;
    }

    // 替换左子树
    Status ReplaceLeft(BiTree &T, BiTree &LT)
    {
        BiTree temp;
        if (nullptr == T)
            return ERROR;
        temp = T->lchild;
        T->lchild = LT;
        LT = temp;
        return OK;
    }

    // 替换右子树
    Status ReplaceRight(BiTree &T, BiTree &RT)
    {
        BiTree temp;
        if (nullptr == T)
            return ERROR;
        temp = T->rchild;
        T->rchild = RT;
        RT = temp;
        return OK;
    }

    // 合并二叉树
    void UnionBiTree(BiTree &Ttemp)
    {
        BiTree L = nullptr, R = nullptr;
        L = MakeBiTree(data[i++], nullptr, nullptr);
        R = MakeBiTree(data[i++], nullptr, nullptr);
        ReplaceLeft(Ttemp, L);
        ReplaceRight(Ttemp, R);
    }

    void pre_order(BiTree Node) // 前序遍历递归算法，父->左->右
    {
        if (Node == nullptr)
            return;
        printf("%c ", Node->data); // 显示节点数据，可以更改为其他操作。在前面
        pre_order(Node->lchild);
        pre_order(Node->rchild);
    }

    void middle_order(BiTree Node) // 中序遍历递归算法，左->父->右
    {
        if (Node == nullptr)
            return;
        middle_order(Node->lchild);
        printf("%c ", Node->data); // 在中间
        middle_order(Node->rchild);
    }

    void post_order(BiTree Node) // 后序遍历递归算法,左->右->父
    {
        if (Node == nullptr)
            return;
        post_order(Node->lchild);
        post_order(Node->rchild);
        printf("%c ", Node->data); // 在最后
    }

    int test()
    {
        BiTree T = nullptr, Ttemp = nullptr;

        InitBiTree(T);
        if (TRUE == BiTreeEmpty(T))
            printf("初始化T为空\n");
        else
            printf("初始化T不为空\n");

        T = MakeBiTree(data[i++], nullptr, nullptr);

        Ttemp = T;
        UnionBiTree(Ttemp);

        Ttemp = T->lchild;
        UnionBiTree(Ttemp);

        Status (*visit1)(TElemType);
        visit1 = visit;
        int num = 0;
        InOrderTraverse(T, visit1, num);
        printf("叶子结点是 %d\n", num);

        printf("叶子结点是 %d\n", Leaves(T));

        int lev = 1;
        levTraverse(T, visit1, lev);

        printf("高度是 %d\n", depTraverse(T));

        printf("前序遍历：");
        pre_order(T);
        printf("中序遍历：");
        middle_order(T);
        printf("后序遍历：");
        post_order(T);

        getchar();
        return 0;
    }
}
#ifndef Sort_Quick_H
#define Sort_Quick_H

/**
    快速排序算法：
        数据：（小数，基准元素，大数）。
        在区间中随机挑选一个元素作基准，将小于基准的元素放在基准之前，大于基准的元素放在基准之后，再分别对小数区与大数区进行排序。

    步骤：
        1. 选取第一个数为基准
        2. 将比基准小的数交换到前面，比基准大的数交换到后面
        3. 对左右区间重复第二步，直到各区间只有一个数
*/

#include <vector>
#include <stack>

// 快速排序（递归）
template <typename T>
void sort_quick_recursive(std::vector<T> &array, int start, int end)
{
    if (start >= end)
        return;
    T mid = array[end]; // 标志数据
    int left = start, right = end - 1;
    while (left < right)
    {
        while (array[left] < mid && left < right)
            left++;

        while (array[right] >= mid && left < right)
            right--;
        if (left < right)
            std::swap(array[left], array[right]);
    }

    // 这时 left和right的值相同，判断当前值和mid（标志数据）的大小；做交换，保障顺序
    if (array[left] > mid)
        std::swap(array[left], array[end]);

    sort_quick_recursive(array, start, left - 1);
    sort_quick_recursive(array, left + 1, end);
}

template <typename T>
void sort_quick_recursion(std::vector<T> &array)
{
    sort_quick_recursive<int>(array, 0, array.size() - 1);
}

/*
    快速排序本质上是二叉树的前序遍历，可以使用栈来模拟
*/

// 快速排序（迭代）
struct Range
{
    int start, end;
    Range(int s = 0, int e = 0)
    {
        start = s, end = e;
    }
};

// 整数或浮点数皆可使用,若要使用物件(class)时必须设定"小于"(<)、"大于"(>)、"不小于"(>=)的运算子功能
template <typename T>
void sort_quick_iterate(std::vector<T> &array)
{
    int len = array.size();
    std::stack<Range> rangeStack;
    rangeStack.emplace(0, len - 1);

    while (!rangeStack.empty())
    {
        Range curRange = rangeStack.top();
        rangeStack.pop();

        if (curRange.start >= curRange.end)
            continue;

        T mid = array[curRange.end]; // 标志数据

        int left = curRange.start, right = curRange.end - 1;

        while (left < right)
        {
            while (array[left] < mid && left < right)
                left++;
            while (array[right] >= mid && left < right)
                right--;

            if (left < right)
                std::swap(array[left], array[right]);
        }

        // 这时 left和right的值相同，判断当前值和mid（标志数据）的大小；做交换，保障顺序
        if (array[left] > mid)
            std::swap(array[left], array[curRange.end]);

        // 模拟递归
        rangeStack.emplace(curRange.start, left - 1);
        rangeStack.emplace(left + 1, curRange.end);
    }
}

#endif // !Sort_Quick_H

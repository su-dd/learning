#ifndef Sort_Merge_H
#define Sort_Merge_H

/**
*    归并排序算法：
*
        把数据分为两段，从两段中逐个选最小的元素移入新数据段的末尾。

        可从上到下或从下到上进行

    递归法（Top-down）
        1. 申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列
        2. 设定两个指针，最初位置分别为两个已经排序序列的起始位置
        3. 比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置
        4. 重复步骤3直到某一指针到达序列尾
        5. 将另一序列剩下的所有元素直接复制到合并序列尾


    迭代法（Bottom-up）

    原理如下（假设序列共有n个元素）：
        1. 将序列每相邻两个数字进行归并操作，形成ceil(n/2)个序列，排序后每个序列包含两/一个元素
        2. 若此时序列数不是1个则将上述序列再次归并，形成ceil(n/4)个序列，每个序列包含四/三个元素
        3. 重复步骤2，直到所有元素排序完毕，即序列数为1

*/

#include <vector>

/*****************
    递归版
*****************/
template <typename T>
void sort_merge_recursive(std::vector<T> &array, std::vector<T> &temp, int start, int end)
{
    if (start >= end)
        return;

    int len = end - start;
    int mid = len / 2 + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    sort_merge_recursive(array, temp, start1, end1);
    sort_merge_recursive(array, temp, start2, end2);

    int k = start;
    while (start1 <= end1 && start2 <= end2)
        temp[k++] = (array[start1] <= array[start2] ? array[start1++] : array[start2++]);

    while (start1 <= end1)
        temp[k++] = array[start1++];

    while (start2 <= end2)
        temp[k++] = array[start2++];

    for (int k = start; k <= end; k++) // 将排序好的数据，回到array中，以便后续使用
        array[k] = temp[k];
}

// 整数或浮点数皆可使用,若要使用物件(class)时必须设定"小于"(<)的运算子功能
template <typename T>
void sort_merge_recursion(std::vector<T> &array)
{
    std::vector<T> temp(array);
    sort_merge_recursive(array, temp, 0, array.size() - 1);
}

/*****************
    迭代版
*****************/

// 整数或浮点数皆可使用,若要使用物件(class)时必须设定"小于"(<)的运算子功能
template <typename T>
void sort_merge_iterate(std::vector<T> &array)
{
    std::vector<T> temp(array);
    int len = array.size();
    // seg 为合并的区间大小，从1开始，后面每次乘2
    for (int seg = 1; seg < len; seg += seg)
    {
        for (int start = 0; start < len; start += seg + seg)
        {
            int low = start;
            int mid = std::min(start + seg, len);
            int high = std::min(start + seg + seg, len);

            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;

            int k = low;
            while (start1 < end1 && start2 < end2)
                temp[k++] = array[start1] <= array[start2] ? array[start1++] : array[start2++];
            while (start1 < end1)
                temp[k++] = array[start1++];
            while (start2 < end2)
                temp[k++] = array[start2++];

            // 将排序好的数据，回到array中，以便后续使用
            for (int k = low; k < high; k++)
                array[k] = temp[k];
        }
    }
}

#endif // !Sort_Merge_H
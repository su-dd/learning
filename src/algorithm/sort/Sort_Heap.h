#ifndef Sort_Heap_H
#define Sort_Heap_H

/**
*	堆排序算法：
		数据：（最大堆，有序区）  
		从堆顶把根卸出来放在有序区之前，再恢复堆

    通堆是通过一维数组来实现的，在数组起始位置为0的情形中：
        1. 父节点i的左子节点在位置(2i+1)
        2. 父节点i的右子节点在位置(2i+2)
        3. 子节点i的父节点在位置 (i-1)/2

	步骤：
		1. 将当前排序调整为堆的结构
        2. 将堆定数据取出，交换到有序取的最前面
        3. 将剩下的堆回复到堆的结构
        4. 重复2~3步骤
*/

#include <vector>

template<typename T>
void max_heapify(std::vector<T> &array, int parentIndex)    // 大顶堆调整
{
    // 建立 父节点指针位置 和 子节点指针位置
    int dadIndex = parentIndex;
    int sonIndex = dadIndex * 2 + 1;
    int maxIndex = array.size() - 1;
    while (sonIndex <= maxIndex)
    { // 若 子节点指针位置 在范围內才做比较
        if (sonIndex + 1 <= maxIndex && array[sonIndex] > array[sonIndex + 1]) // 先比较两个子节点大小，选择小的
            sonIndex++;
        if (array[dadIndex] < array[sonIndex]) // 如果 父节点 < 子节点 代表调整完成，直接跳出函数
            return;
        else 
        {   // 否则较换父子內容再继续子节点和孙节点比较
            std::swap(array[dadIndex], array[sonIndex]);
            // 因为这里的循环是从树的叶子节点开始的，但当处理dadIndex时，他下面已经是堆了，所以只需要对dadIndex的值进行处理
            dadIndex = sonIndex;                
            sonIndex = dadIndex * 2 + 1;
        }
    }
}


template<typename T>
void sort_heap(std::vector<T>& array)
{   
    // 建立堆结构
    // 初始化，i从最后一个父节点开始调整
    int maxIndex = array.size() - 1;
    for (int i = (maxIndex - 1) / 2; i >= 0; i--)
        max_heapify(array, i);

    // 先将第一个元素和已经排好的元素前一位做较换，再从新调整(刚调整的元素之前的元素)，直到排序完成
    for (int i = maxIndex; i > 0; i--)
    {
        std::swap(array[0], array[i]);  // 取堆定数据交换到有序区
        max_heapify(array, 0);
    }
}

#endif // !Sort_Heap_H

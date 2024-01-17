#ifndef Sort_Merge_H
#define Sort_Merge_H

/**
*	归并排序算法：
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

// 递归
template<typename T>
void Merge(std::vector<T>& array, int front, int mid, int end) {
    // preconditions:
    // array[front...mid] is sorted
    // array[mid+1 ... end] is sorted
    // Copy array[front ... mid] to LeftSubArray
    // Copy array[mid+1 ... end] to RightSubArray
    std::vector<T> LeftSubArray(array.begin() + front, array.begin() + mid + 1);
    std::vector<T> RightSubArray(array.begin() + mid + 1, array.begin() + end + 1);
    int idxLeft = 0, idxRight = 0;
    LeftSubArray.insert(LeftSubArray.end(), numeric_limits<int>::max());
    RightSubArray.insert(RightSubArray.end(), numeric_limits<int>::max());

    // Pick min of LeftSubArray[idxLeft] and RightSubArray[idxRight], and put into array[i]
    for (int i = front; i <= end; i++)
    {
        if (LeftSubArray[idxLeft] < RightSubArray[idxRight]) 
        {
            array[i] = LeftSubArray[idxLeft];
            idxLeft++;
        }
        else
        {
            array[i] = RightSubArray[idxRight];
            idxRight++;
        }
    }
}

template<typename T>
void sort_merge_recursion(std::vector<T>& array, int front, int end)
{
    if (front >= end)
        return;

    int mid = front + (end - front) / 2;
    sort_merge_recursion(array, front, mid);
    sort_merge_recursion(array, mid + 1, end);
    Merge(array, front, mid, end);
}




#endif // !Sort_Merge_H
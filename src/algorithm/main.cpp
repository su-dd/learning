#include <iostream>

// 十大排序
#include "sort/Sort_Bubble.h" // 冒泡
// #include "sort/Sort_Select.h" // 选择
// #include "sort/Sort_Insert.h" // 插入
// #include "sort/Sort_Quick.h" // 快速
// #include "sort/Sort_Heap.h" // 堆
// #include "sort/Sort_Merge.h" // 归并
// #include "sort/Sort_Bucket.h" // 桶
// #include "sort/Sort_Radix.h" // 基数
// #include "sort/Sort_Count.h" // 记数
// #include "sort/Sort_Shell.h" // 希尔

int main()
{
    std::vector<int> array{1, 2, 5, 3, 9, 7, 4, 8, 6};
    sort_bubble<int>(array);
    // sort_select<int>(array);
    // sort_insert<int>(array);
    // sort_quick_recursion<int>(array);
    // sort_quick_iterate<int>(array);
    // sort_heap<int>(array);
    // sort_merge_recursion<int>(array);
    // sort_merge_iterate<int>(array);
    // sort_bucket(array);
    for (int i = 0; i < array.size(); i++)
    {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;
    return 0;
}

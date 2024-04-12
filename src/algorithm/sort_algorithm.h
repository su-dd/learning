#ifndef C07A091B_3CC3_46B0_9825_6A7FC17B6A33
#define C07A091B_3CC3_46B0_9825_6A7FC17B6A33
#include <vector>
#include <stack>
#include <functional>
#include <algorithm>

/** 冒泡排序算法：
        数据：（无序区，有序区）。
        从无序区通过交换找出最大元素放到有序区前端。

    步骤：
        1. 比较相邻的元素。如果第一个比第二个大，就交换它们两个。
        2. 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。
        3. 针对所有的元素重复以上的步骤，除了最后一个。
        4. 持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。

    助记码：

        i∈[0,N-1)               //循环N-1遍
            j∈[0,N-1-i)         //每遍循环要处理的无序部分
                swap(j,j+1)     //两两排序（升序/降序）

    时间复杂度：O(N^2)

    空间复杂度：O(1)

    稳定性：稳定
*/

// 冒泡排序
template <typename T>
void sort_bubble(std::vector<T> &array)
{
    int len = array.size();
    for (int i = 0; i < len - 1; i++) // i 的区间是 [0, len-1)
    {
        for (int j = 0; j < len - 1 - i; j++) // j 的区间是 [0, len-1-i)
        {
            if (array[j] > array[j + 1]) // 将大的元素交换到后面
            {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

// 冒泡排序优化
template <typename T>
void sort_bullbe_tuning(std::vector<T> &array)
{
    int orderly = false; // 标识是否已经有序
    int len = array.size();
    for (int i = 0; (i < len - 1) && !orderly; i++) // i 的区间是 [0, len-1)
    {
        orderly = true;
        for (int j = 0; j < len - 1 - i; j++) // j 的区间是 [0, len-1-i)
        {
            if (array[j] > array[j + 1]) // 将大的元素交换到后面
            {
                orderly = false;
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

/** 选择排序算法：
        数据：（有序区，无序区）
        在无序区里找一个最小的元素跟在有序区的后面。对数组：比较得多，换得少

    步骤：
        1. 在未排序序列中找到最小（大）元素，存放到排序序列的起始位置
        2. 从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾
        3. 以此类推，直到所有元素均排序完毕

    助记码：

        i∈[0,N-1)               //循环N-1遍
            minIndex=i              //初始化最小值
            for j∈[i+1,N)      //寻找最小值
                if array[j]<array[minIndex]
                    minIndex=j
            if i!=minIndex          //如果最小值不是当前位置，则交换
                swap(array[i],array[minIndex])

    时间复杂度：O(N^2)

    空间复杂度：O(1)

    稳定性：不稳定
*/
template <typename T>
void sort_select(std::vector<T> &array)
{
    int len = array.size();
    for (int i = 0; i < len - 1; i++) // i 的区间是 [0, len-1)
    {
        int minIndex = i;
        for (int j = i + 1; j < len; j++) // j 的区间是 [i+1, len)
        {
            if (array[j] < array[minIndex]) // 寻找最小值
                minIndex = j;
        }
        if (i != minIndex) // 如果最小值不是当前位置，则交换
            std::swap(array[i], array[minIndex]);
    }
}

/** 插入排序算法：
        数据：（有序区，无序区）。
        把无序区的第一个元素插入到有序区的合适的位置。对数组：比较得少，换得多。

    步骤：
        1. 从第一个元素开始，该元素可以认为已经被排序
        2. 取出下一个元素，在已经排序的元素序列中从后向前扫描
        3. 如果该元素（已排序）大于新元素，将该元素移到下一位置
        4. 重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
        5. 将新元素插入到该位置后
        6. 重复步骤2~5，直到排序完成

    助记码：

        for i∈[1,N)               //循环N-1遍
            temp=array[i]           //保存当前元素
            j=i-1                   //从前往后扫描
            while j>=0 and array[j]>temp
                array[j+1]=array[j]  //元素后移
                j--
            array[j+1]=temp          //插入新元素

    时间复杂度：O(N^2)

    空间复杂度：O(1)

    稳定性：稳定
*/

template <typename T>
void sort_insert(std::vector<T> &array)
{
    for (int i = 1; i < array.size(); i++)
    {
        T temp = array[i];
        int j = i - 1;                    // j 的区间是 [0, i-1]
        while (j >= 0 && array[j] > temp) // 从后往前扫描
        {
            array[j + 1] = array[j]; // 元素后移
            j--;
        }
        array[j + 1] = temp; // 这时j+1的值是插入位置，将temp插入
    }
}

/** 快速排序算法：
        数据：（小数，基准元素，大数）。
        在区间中随机挑选一个元素作基准，将小于基准的元素放在基准之前，大于基准的元素放在基准之后，再分别对小数区与大数区进行排序。

    步骤：
        1. 选取第一个数为基准
        2. 将比基准小的数交换到前面，比基准大的数交换到后面
        3. 对左右区间重复第二步，直到各区间只有一个数

    助记码：
        partition(array,start,end)
            pivot=array[end]
            i=start-1
            for j=start to end-1
                if array[j]<pivot
                    i++
                    swap(array[i],array[j])
            swap(array[i+1],array[end])
            return i+1

        quicksort(array,start,end)
            if start<end
                pivotIndex=partition(array,start,end)
                quicksort(array,start,pivotIndex-1)
                quicksort(array,pivotIndex+1,end)

    时间复杂度：O(NlogN)

    空间复杂度：O(logN)

    稳定性：不稳定
*/

// 快速排序（递归）
template <typename T>
void sort_quick_recursion(std::vector<T> &array, int start, int end)
{
    auto partition = [](std::vector<T> &array, const int start, const int end) -> int
    {
        T pivot = array[end];             // 选取基准
        int i = start - 1;                // i 指向小于基准的元素的位置
        for (int j = start; j < end; j++) // j 指向待比较的元素
        {
            if (array[j] < pivot) // 小于基准的元素
            {
                i++;
                std::swap(array[i], array[j]);
            }
        }
        std::swap(array[i + 1], array[end]); // 基准元素归位
        return i + 1;
    };

    if (start < end)
    {
        int pivotIndex = partition(array, start, end);      // 分区，返回基准索引
        sort_quick_recursion(array, start, pivotIndex - 1); // 左区间
        sort_quick_recursion(array, pivotIndex + 1, end);   // 右区间
    }
}

/*
    快速排序本质上是二叉树的前序遍历，可以使用栈来模拟
*/

// 快速排序（迭代）
template <typename T>
void sort_quick_iterate(std::vector<T> &array)
{
    struct Range
    {
        int start, end;
        Range(int s = 0, int e = 0) { start = s, end = e; }
    };

    auto partition = [](std::vector<T> &array, const int start, const int end) -> int
    {
        T pivot = array[end];             // 选取基准
        int i = start - 1;                // i 指向小于基准的元素的位置
        for (int j = start; j < end; j++) // j 指向待比较的元素
        {
            if (array[j] < pivot) // 小于基准的元素
            {
                i++;
                std::swap(array[i], array[j]);
            }
        }
        std::swap(array[i + 1], array[end]); // 基准元素归位
        return i + 1;
    };

    std::stack<Range> rangeStack;
    rangeStack.emplace(0, array.size() - 1);

    while (!rangeStack.empty())
    {
        Range curRange = rangeStack.top();
        rangeStack.pop();

        if (curRange.start >= curRange.end)
            continue;

        int pivotIndex = partition(array, curRange.start, curRange.end);

        // 模拟递归
        rangeStack.emplace(curRange.start, pivotIndex - 1);
        rangeStack.emplace(pivotIndex + 1, curRange.end);
    }
}

/** 堆排序算法：
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

    助记码：

        // 调整堆
        heapify(array,i,size)
            left=2i+1
            right=2i+2
            largest=i
            if left<size and array[left]>array[largest]
                largest=left
            if right<size and array[right]>array[largest]
                largest=right
            if largest!=i
                swap(array[i],array[largest])
                heapify(array,largest,size)
        // 建堆
        buildMaxHeap(array)
            for i=(array.size()-1)/2 to 0
                heapify(array,i,array.size())
        // 堆排序
        heapSort(array)
            buildMaxHeap(array)
            for i=array.size()-1 to 1
                swap(array[0],array[i])
                heapify(array,0,i)

    时间复杂度：O(NlogN)

    空间复杂度：O(1)

    稳定性：不稳定
*/

template <typename T>
void sort_heap(std::vector<T> &array)
{
    // 调整堆 i为父节点索引，size为堆大小
    std::function<void(std::vector<T> &, int, int)> heapify;
    heapify = [&heapify](std::vector<T> &array, int i, int size)
    {
        int left = 2 * i + 1;  // 左子节点索引
        int right = 2 * i + 2; // 右子节点索引
        int largest = i;       // 最大值索引，默认为父节点

        // 找出最大值
        if (left < size && array[left] > array[largest]) // 左子节点大于最大值
            largest = left;
        if (right < size && array[right] > array[largest]) // 右子节点大于最大值
            largest = right;
        if (largest != i) // 最大值不是父节点
        {
            std::swap(array[i], array[largest]); // 交换父节点与最大值
            heapify(array, largest, size);       // 递归调整刚被改变的子树
        }
    };

    // 建堆 目的：将数组转换为堆 时间复杂度：O(N)
    // 从最后一个非叶子节点开始, 依次向上调整, 逐渐建立堆，直到根节点
    for (int i = ((int)array.size() - 1) / 2; i >= 0; i--)
        heapify(array, i, int(array.size()));

    // 堆排序 目的：将数组排序 时间复杂度：O(NlogN)
    // 每次将最大的元素放到数组末尾，然后调整堆，使其成为最大堆
    for (int i = int(array.size()) - 1; i >= 1; i--)
    {
        std::swap(array[0], array[i]);
        // 调整堆, 这里成功的关键：swap后，除了index为0的元素，其他元素都还在堆中，所以不需要再次调整
        heapify(array, 0, i);
    }
}

/** 归并排序算法：

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

    时间复杂度：O(NlogN)

    空间复杂度：O(N)

    稳定性：稳定
*/

// 递归法
template <typename T>
void sort_merge_recursion(std::vector<T> &array, std::vector<T> &temp, int startIndex, int endIndex) // 递归法
{
    if (startIndex < endIndex)
    {
        int midIndex = (startIndex + endIndex) / 2;                // 取中间位置
        sort_merge_recursion(array, temp, startIndex, midIndex);   // 左半部分递归排序
        sort_merge_recursion(array, temp, midIndex + 1, endIndex); // 右半部分递归排序
        int left = startIndex, right = midIndex + 1;               // 左右指针

        for (int k = startIndex; k <= endIndex; k++) // 合并两个有序数组
        {
            if (left > midIndex) // 左半部分无剩余元素
            {
                temp[k] = array[right];
                right++;
            }
            else if (right > endIndex) // 右半部分无剩余元素
            {
                temp[k] = array[left];
                left++;
            }
            else if (array[left] <= array[right]) // 左半部分最小元素
            {
                temp[k] = array[left];
                left++;
            }
            else // 右半部分最小元素
            {
                temp[k] = array[right];
                right++;
            }
        }

        for (int i = startIndex; i <= endIndex; i++)
        {
            array[i] = temp[i];
        }
    }
}

// 迭代法
template <typename T>
void sort_merge_iterate(std::vector<T> &array)
{
    int size = (int)array.size();
    std::vector<T> temp(size); // 临时数组

    // 迭代法
    for (int seg = 1; seg < size; seg *= 2) // 子数组大小
    {
        for (int start = 0; start < size - seg; start += 2 * seg) // 子数组起始位置
        {
            int mid = start + seg - 1;                         // 子数组中间位置
            int end = std::min(start + 2 * seg - 1, size - 1); // 子数组结束位置

            // 合并两个子数组
            int left = start, right = mid + 1;

            for (int index = start; index <= end; index++) // 合并两个子数组
            {
                if (left > mid) // 左半部分无剩余元素
                {
                    temp[index] = array[right];
                    right++;
                }
                else if (right > end) // 右半部分无剩余元素
                {
                    temp[index] = array[left];
                    left++;
                }
                else if (array[left] <= array[right]) // 左半部分最小元素
                {
                    temp[index] = array[left];
                    left++;
                }
                else // 右半部分最小元素
                {
                    temp[index] = array[right];
                    right++;
                }
            }
            // 复制合并结果
            for (int i = start; i <= end; i++)
            {
                array[i] = temp[i];
            }
        }
    }
}

/* 桶排序：
        将数组分到有限数量的桶里。每个桶再个别排序（有可能再使用别的排序算法或是以递归方式继续使用桶排序进行排序）。

        当要被排序的数组内的数值是均匀分配的时候，桶排序使用线性时间 Θ(n)

    步骤：

        1. 设置一个定量的数组当作空桶子。
        2. 寻访序列，并且把项目一个一个放到对应的桶子去。
        3. 对每个不是空的桶子进行排序。
        4. 从不是空的桶子里把项目再放回原来的序列中。

    助记码：

        bucketSort(array, size)
            create n empty buckets (or lists)
            for i = 0 to size-1
                insert array[i] into bucket[array[i]]
            for i = 0 to n-1
                sort bucket[i] using any sorting algorithm
            concatenate the sorted buckets into a single sorted array

    时间复杂度：O(n+k) k为桶的个数，最坏情况下为O(n^2)

    空间复杂度：O(n+k)

    稳定性：不稳定
*****************/

template <typename T>
void sort_bucket(std::vector<T> &array, int bucketSize) // 桶排序
{
    std::vector<std::vector<T>> buckets(bucketSize);

    int size = (int)array.size();
    // 寻访序列，并且把项目一个一个放到对应的桶子去
    for (int i = 0; i < size; i++)
    {
        int index = (int)(array[i] / bucketSize); // 计算索引, 取倍数可以保障桶数据分级：个十百千万 。。。
        if (index >= bucketSize)                  // 防止溢出
            index = bucketSize - 1;
        buckets[index].push_back(array[i]); // 放入桶子
    }

    // 对每个不是空的桶子进行排序
    for (int i = 0; i < bucketSize; i++)
    {
        if (!buckets[i].empty())
        {
            std::sort(buckets[i].begin(), buckets[i].end()); // 排序
        }
    }

    // 从不是空的桶子里把项目再放回原来的序列中
    int index = 0;
    for (int i = 0; i < bucketSize; i++)
    {
        if (!buckets[i].empty())
        {
            for (int j = 0; j < (int)buckets[i].size(); j++)
            {
                array[index] = buckets[i][j];
                index++;
            }
        }
    }
}

/* 基数排序：

        一种多关键字的排序算法，是桶排序的扩展。

        基本思想是：取得所有数的数位并统一为相同的长度，数位较短的数字前面补零。
        从低位开始排序，分别放入0~9个队列中，然后采用先进先出的原则进行收集；
        在按照高位排序，然后在收集；依次类推，直到最高位，最终得到排好序的数列。
        对于数值偏小的一组序列，该算法速度非常快，时间复杂度可以达到线性。

    理解：

        1、没一次的排序，都是一次分组排序；使得当前位上的数据有序；
        2、高位比低位权重更重，所以防止后面。

    步骤：

        1. 取得数组中的最大数并取得位数；
        2. 对数位较短的数进行前面补零；
        3. 从个位开始分配，根据位值（0-9）分别放在（0-9）号桶中；
        4. 收集数据放在（0~9）号桶中的数据按顺序放到数组中；
        5. 重复3~4过程，直到最高位，即可完成排序。

*/

#endif /* C07A091B_3CC3_46B0_9825_6A7FC17B6A33 */

#ifndef Sort_Shell_H
#define Sort_Shell_H

/**
    算法：
        先将整个待排元素序列分割成若干个子序列（由相隔某个“增量”的元素组成的）分别进行直接插入排序，
        然后依次缩减增量再进行排序，待整个序列中的元素基本有序（增量足够小）时，
        再对全体元素进行一次直接插入排序

    步骤：
        1. 先取一个小于n的整数d1作为第一个增量，把文件的全部记录分成d1个组。
        2. 所有距离为d1的倍数的记录放在同一个组中，在各组内进行直接插入排序。
        3. 取第二个增量d2小于d1重复上述的分组和排序，直至所取的增量dt=1(dt小于dt-l小于…小于d2小于d1)，
           即所有记录放在同一组中进行直接插入排序为止。
*/

#include <vector>

template <typename T>
void shell_sort(std::vector<T> array)
{
    int len = array.size();

    int h = 1;
    while (h < len / 3) // 寻找一个合适的增量
    {
        h = 3 * h + 1;
    }

    while (h >= 1)
    {
        for (int i = h; i < len; i++) // 共划分出 （len - 1 - h）个数组
        {
            // 按h作为增量，划分的子序列中做插入排序;
            // 这里的插入排序，是最开始只取两个保证有序，再慢慢添加
            for (int j = i; j >= h && temp < array[j - h]; j -= h)
            {
                std::swap(array[j], array[j - h]);
            }
        }
        h = h / 3;
    }
}

#endif // !Sort_Shell_H

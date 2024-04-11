#ifndef Sort_Radix_H
#define Sort_Radix_H

/*****************

    基数排序：

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

*****************/

// 辅助函数，求数据的最大位数
int maxbit(int data[], int n)
{
    int maxData = data[0]; ///< 最大数
    /// 先求出最大数，再求其位数，这样有原先依次每个数判断其位数，稍微优化点。
    for (int i = 1; i < n; ++i)
    {
        if (maxData < data[i])
            maxData = data[i];
    }

    int d = 1;
    int p = 10;
    while (maxData >= p)
    {
        // p *= 10; // Maybe overflow
        maxData /= 10;
        ++d;
    }
    return d;
}

// 基数排序
void sort_radix(int data[], int n)
{
    int d = maxbit(data, n);
    int *tmp = new int[n];
    int *count = new int[10]; // 计数器
    int index = 0;
    int radix = 1;
    for (int i = 1; i <= d; i++) // 进行d次排序
    {
        // 每次分配前清空计数器
        for (int j = 0; j < 10; j++)
            count[j] = 0;

        for (int j = 0; j < n; j++)
        {
            index = (data[j] / radix) % 10; // 统计每个桶中的记录数
            count[index]++;
        }

        for (int j = 1; j < 10; j++)
        {
            count[j] = count[j - 1] + count[j]; // 将tmp中的位置依次分配给每个桶
        }

        for (int j = n - 1; j >= 0; j--) // 将所有桶中记录依次收集到tmp中
        {
            index = (data[j] / radix) % 10;
            tmp[count[index] - 1] = data[j];
            count[index]--;
        }

        for (int j = 0; j < n; j++) // 将临时数组的内容复制到data中
        {
            data[j] = tmp[j];
        }
        radix = radix * 10;
    }
    delete[] tmp;
    delete[] count;
}

#endif // ! Sort_Radix_H
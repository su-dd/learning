﻿#ifndef Sort_Select_H
#define Sort_Select_H

/**
*	选择排序算法：
		数据：（有序区，无序区）
		在无序区里找一个最小的元素跟在有序区的后面。对数组：比较得多，换得少

	步骤：
		1. 在未排序序列中找到最小（大）元素，存放到排序序列的起始位置
		2. 从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾
		3. 以此类推，直到所有元素均排序完毕

*/

// 升序的选择排序
template<typename T>
void sort_select(std::vector<T>& array)
{
	int len = array.size();
	for (int i = 0; i < len - 1; i++) {
		int min = i;
		for (int j = i + 1; j < len; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (i != min)
			std::swap(array[i], array[min]);
	}
}

#endif // !Sort_Select_H

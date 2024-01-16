#ifndef Sort_Bubble_H
#define Sort_Bubble_H

/**
*	冒泡排序算法：
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
*/
#include <vector>

// 模板方法实现冒泡
template<typename T>
void sort_bubble(std::vector<T> &array)
{
	int len = array.size();
	for (int i = 0; i < len - 1; i ++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				std::swap(array[j], array[j + 1]);
			}
		}
	}
}

// 模板方法实现冒泡算法调优
template<typename T>
void sort_bullbe_tuning(std::vector<T> &array)
{
	int orderly = false;	// 标识是否已经有序
	int len = array.size();
	for (int i = 0; (i < len - 1) && !orderly; i++)
	{
		orderly = true;
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				orderly = false;
				std::swap(array[j], array[j + 1]);
			}
		}
	}
}

#endif // Sort_Bubble_H
// algorithm.cpp: 定义应用程序的入口点。
//

#include "algorithm.h"
#include <iostream>
#include "sort/Sort_Bubble.h"
#include "sort/Sort_Select.h"
#include "sort/Sort_Insert.h"
#include "sort/Sort_Quick.h"
#include "sort/Sort_Heap.h"

int main()
{
	std::vector<int> array{1, 2, 5, 3, 9, 7, 4, 8, 6};
	//sort_bubble<int>(array);
	//sort_bullbe_tuning<int>(array);
	//sort_select<int>(array);
	//sort_insert<int>(array);
	//sort_quick_recursive<int>(array, 0, array.size() - 1);
	sort_heap<int>(array);
	for (int i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << " ";
	}

	return 0;
}

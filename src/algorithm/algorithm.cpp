// algorithm.cpp: 定义应用程序的入口点。
//

#include "algorithm.h"
#include <iostream>
#include "sort/Sort_Bubble.h"
#include "sort/Sort_Selection.h"

int main()
{
	std::vector<int> array{1, 2, 5, 3, 9, 7, 4, 8, 6};
	// sort_bubble<int>(array);
	// sort_bullbe_tuning<int>(array);
	sort_selection<int>(array);
	for (int i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	return 0;
}

// algorithm.cpp: 定义应用程序的入口点。
//

#include "algorithm.h"
#include "sort/Sort_Bubble.h"
#include <iostream>
int main()
{
	std::vector<int> array{1, 2, 5, 3, 4};
	//sort_bubble<int>(array);
	sort_bullbe_tuning<int>(array);

	for (int i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	return 0;
}

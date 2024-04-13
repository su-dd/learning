#include <iostream>
#include <vector>
#include "sort_algorithm.h"

int main()
{
    std::vector<int> array{2, 5, 13, 59, 117, 44, 80, 6, 1000};
    // std::vector<int> temp(array.begin() + 0, array.begin() + 9);
    // std::vector<int> temp1(array.begin() + 0, array.begin() + 5);
    // std::vector<int> temp2(array.begin() + 5, array.begin() + 9);
    // sort_bubble<int>(array);
    // sort_select<int>(array);
    // sort_insert<int>(array);
    // sort_quick_recursion<int>(array, 0, (int)array.size() - 1);
    // sort_quick_iterate<int>(array);
    // sort_heap<int>(array);
    // sort_merge_recursion<int>(array, std::vector<int>((int)array.size()), 0, (int)array.size() - 1);
    // sort_merge_iterate<int>(array);
    // sort_bucket(array, 5);
    // sort_radix<int>(array);
    // sort_count<int>(array);
    sort_shell<int>(array);
    for (int i = 0; i < (int)array.size(); i++)
    {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;
    return 0;
}

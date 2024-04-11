#include <iostream>
#include <vector>
#include "sort_algorithm.h"

int main()
{
    std::vector<int> array{2, 5, 3, 9, 7, 4, 8, 6, 1};
    // sort_bubble<int>(array);
    // sort_select<int>(array);
    // sort_insert<int>(array);
    sort_quick_recursion<int>(array, 0, array.size() - 1);
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

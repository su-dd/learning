

// 斐波那契查找
#include "stdafx.h"
#include <memory>
#include <iostream>
using namespace std;

/*构造一个斐波那契数组*/
const static int FibonacciArray[47] = {
    0, 1, 1, 2, 3, 5, 8, 13, 21, 34,
    55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181,
    6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229,
    832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986,
    102334155, 165580141, 267914296, 433494437, 701408733, 1134903170, 1836311903};

/*定义斐波那契查找法*/
int FibonacciSearch(int *a, int n, int key) // a为要查找的数组,n为要查找的数组长度,key为要查找的关键字
{
    int low = 0;
    int high = n - 1;

    int index = 0;                        // 记录在斐波那契数列的位置
    while (n > FibonacciArray[index] - 1) // 计算n位于斐波那契数列的位置
        ++index;

    int *temp; // 将数组a扩展到F[k]-1的长度
    temp = new int[FibonacciArray[index] - 1];
    memcpy(temp, a, n * sizeof(int));
    for (int i = n; i < FibonacciArray[index] - 1; ++i)
        temp[i] = a[n - 1];

    while (low <= high)
    {
        int mid = low + FibonacciArray[index - 1] - 1;
        if (key < temp[mid])
        {
            high = mid - 1;
            index -= 1;
        }
        else if (key > temp[mid])
        {
            low = mid + 1;
            index -= 2;
        }
        else
        {
            if (mid < n)
                return mid; // 若相等则说明mid即为查找到的位置
            else
                return n - 1; // 若mid>=n则说明是扩展的数值,返回n-1
        }
    }
    delete[] temp;
    return -1;
}

int main()
{
    int a[] = {0, 16, 24, 35, 47, 59, 62, 73, 88, 99};
    int key = 100;
    int index = FibonacciSearch(a, sizeof(a) / sizeof(int), key);
    cout << key << " is located at:" << index;
    return 0;
}
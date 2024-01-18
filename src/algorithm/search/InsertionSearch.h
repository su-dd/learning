#ifndef InsertionSearch_H
#define InsertionSearch_H

//插值查找(递归)
int InsertionSearch(int a[], int value, int low, int high)
{
    if (low < high)
    {
        return -1;
    }
    int mid = low + (value - a[low]) / (a[high] - a[low]) * (high - low);
    if (a[mid] == value)
        return mid;
    if (a[mid] > value)
        return InsertionSearch(a, value, low, mid - 1);
    if (a[mid] < value)
        return InsertionSearch(a, value, mid + 1, high);
}

//插值查找(迭代)
int InsertionSearch2(int a[], int value, int low, int high)
{
    while (low < high)
    {
        int mid = low + (value - a[low]) / (a[high] - a[low]) * (high - low);
        if (a[mid]) == value)
        {
            return mid;
        }
        else if (a[mid] > value)
        {
            hig = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

#endif // ! InsertionSearch_H



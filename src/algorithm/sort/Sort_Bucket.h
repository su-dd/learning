#ifndef Sort_Bucket_H
#define Sort_Bucket_H

/*****************

    桶排序：
        将数组分到有限数量的桶里。每个桶再个别排序（有可能再使用别的排序算法或是以递归方式继续使用桶排序进行排序）。

        当要被排序的数组内的数值是均匀分配的时候，桶排序使用线性时间 Θ(n)

    步骤：

        1. 设置一个定量的数组当作空桶子。
        2. 寻访序列，并且把项目一个一个放到对应的桶子去。
        3. 对每个不是空的桶子进行排序。
        4. 从不是空的桶子里把项目再放回原来的序列中。

*****************/

#include <vector>
#include <iterator>

// 假设数据分布在[0，100)之间，每个桶内部用链表表示，在数据入桶的同时插入排序。然后把各个桶中的数据合并。

const int BUCKET_NUM = 10;

struct ListNode
{
    explicit ListNode(int i = 0) : mData(i), mNext(NULL) {}
    ListNode *mNext;
    int mData;
};

ListNode *insertBucket(ListNode *head, int val)
{
    ListNode dummyNode; // 引入空Node ，是为了解决val插在最前面的情况
    ListNode *newNode = new ListNode(val);
    ListNode *pre, *curr;
    dummyNode.mNext = head;
    pre = &dummyNode;
    curr = head;
    while (NULL != curr && curr->mData <= val) // 这里等号需要存在，否则就不稳定了
    {
        pre = curr;
        curr = curr->mNext;
    }
    newNode->mNext = curr;
    pre->mNext = newNode;
    return dummyNode.mNext;
}

ListNode *mergeBucket(ListNode *head1, ListNode *head2)
{
    ListNode dummyNode;
    ListNode *dummy = &dummyNode;
    while (NULL != head1 && NULL != head2)
    {
        // 相同是 数值 ，只能在同一个桶里； 所以这里的判断是否带等会，不重要
        if (head1->mData < head2->mData)
        {
            dummy->mNext = head1;
            head1 = head1->mNext;
        }
        else
        {
            dummy->mNext = head2;
            head2 = head2->mNext;
        }
        dummy = dummy->mNext;
    }
    if (NULL != head1)
        dummy->mNext = head1;
    if (NULL != head2)
        dummy->mNext = head2;

    return dummyNode.mNext;
}

void sort_bucket(std::vector<int> &array)
{
    int len = array.size();

    std::vector<ListNode *> buckets(BUCKET_NUM, (ListNode *)(0));

    for (int i = 0; i < len; ++i)
    {
        int index = array[i] / BUCKET_NUM;
        ListNode *head = buckets.at(index);
        buckets.at(index) = insertBucket(head, array[i]);
    }

    ListNode *head = buckets.at(0);
    for (int i = 1; i < BUCKET_NUM; ++i)
    {
        head = mergeBucket(head, buckets.at(i));
    }

    for (int i = 0; i < len; ++i)
    {
        array[i] = head->mData;
        head = head->mNext;
    }
}

#endif // !Sort_Bucket_H

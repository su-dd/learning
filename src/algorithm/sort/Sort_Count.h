/*****************

��������ͳ��С�ڵ��ڸ�Ԫ��ֵ��Ԫ�صĸ���i�����Ǹ�Ԫ�ؾͷ���Ŀ�����������iλ��i��0����

�����������һ�����裬���������е���������Ϊ�������ҳ����ڣ�0��k��������֮�ڡ�
��� k��������������ֵ�� �����������ϴ�Ŀռ临�Ӷȣ�һ������������ 0 �� 100 ֮������ֵ���õ��㷨�����������ʺϰ���ĸ˳������������
���������ǱȽ�����������ٶȿ����καȽ������㷨��
ʱ�临�Ӷ�Ϊ O��n+k�����ռ临�Ӷ�Ϊ O��n+k��

�㷨�Ĳ������£�

	1. �ҳ��������������������С��Ԫ��
	2. ͳ��������ÿ��ֵΪ i ��Ԫ�س��ֵĴ������������� C �ĵ� i ��
	3. �����еļ����ۼӣ��� C �еĵ�һ��Ԫ�ؿ�ʼ��ÿһ���ǰһ����ӣ�
	4. �������Ŀ�����飺��ÿ��Ԫ�� i ����������ĵ� C[i] �ÿ��һ��Ԫ�ؾͽ� C[i] ��ȥ 1

*****************/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ��������
void CountSort(vector<int>& vecRaw, vector<int>& vecObj)
{
	// ȷ�������������ǿ�
	if (vecRaw.size() == 0)
		return;

	// ʹ�� vecRaw �����ֵ + 1 ��Ϊ�������� countVec �Ĵ�С
	int vecCountLength = (*max_element(begin(vecRaw), end(vecRaw))) + 1;
	vector<int> vecCount(vecCountLength, 0);

	// ͳ��ÿ����ֵ���ֵĴ���
	for (int i = 0; i < vecRaw.size(); i++)
		vecCount[vecRaw[i]]++;

	// ����ļ�ֵ���ֵ�λ��Ϊǰ�����м�ֵ���ֵĴ���֮��
	for (int i = 1; i < vecCountLength; i++)
		vecCount[i] += vecCount[i - 1];

	// ����ֵ�ŵ�Ŀ��λ��
	for (int i = vecRaw.size(); i > 0; i--)	// �˴�������Ϊ�˱�����ͬ��ֵ���ȶ���
		vecObj[--vecCount[vecRaw[i - 1]]] = vecRaw[i - 1];
}
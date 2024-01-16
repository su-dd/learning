#ifndef Sort_Selection_H
#define Sort_Selection_H

/**
*	ѡ�������㷨��
		���ݣ�������������������
		������������һ����С��Ԫ�ظ����������ĺ��档�����飺�Ƚϵö࣬������

	���裺
		1. ��δ�����������ҵ���С����Ԫ�أ���ŵ��������е���ʼλ��
		2. ��ʣ��δ����Ԫ���м���Ѱ����С����Ԫ�أ�Ȼ��ŵ����������е�ĩβ
		3. �Դ����ƣ�ֱ������Ԫ�ؾ��������

	�����룺
		
*/

// �����ѡ������
template<typename T>
void sort_selection(std::vector<T>& array)
{
	int len = array.size();
	for (int i = 0; i < len - 1; i++) {
		int min = i;
		for (int j = i + 1; j < len; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (i != min)
			std::swap(array[i], array[min]);
	}
}

#endif // !Sort_Selection_H

// ��������һ�ֶ�ؼ��ֵ������㷨������Ͱ����ʵ�֡�

int maxbit(int data[], int n) //���������������ݵ����λ��
{
    int maxData = data[0];		///< �����
    /// ������������������λ����������ԭ������ÿ�����ж���λ������΢�Ż��㡣
    for (int i = 1; i < n; ++i)
    {
        if (maxData < data[i])
            maxData = data[i];
    }
    int d = 1;
    int p = 10;
    while (maxData >= p)
    {
        //p *= 10; // Maybe overflow
        maxData /= 10;
        ++d;
    }
    return d;
    /*    int d = 1; //��������λ��
        int p = 10;
        for(int i = 0; i < n; ++i)
        {
            while(data[i] >= p)
            {
                p *= 10;
                ++d;
            }
        }
        return d;*/
}
void radixsort(int data[], int n) //��������
{
    int d = maxbit(data, n);
    int* tmp = new int[n];
    int* count = new int[10]; //������
    int i, j, k;
    int radix = 1;
    for (i = 1; i <= d; i++) //����d������
    {
        for (j = 0; j < 10; j++)
            count[j] = 0; //ÿ�η���ǰ��ռ�����
        for (j = 0; j < n; j++)
        {
            k = (data[j] / radix) % 10; //ͳ��ÿ��Ͱ�еļ�¼��
            count[k]++;
        }
        for (j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; //��tmp�е�λ�����η����ÿ��Ͱ
        for (j = n - 1; j >= 0; j--) //������Ͱ�м�¼�����ռ���tmp��
        {
            k = (data[j] / radix) % 10;
            tmp[count[k] - 1] = data[j];
            count[k]--;
        }
        for (j = 0; j < n; j++) //����ʱ��������ݸ��Ƶ�data��
            data[j] = tmp[j];
        radix = radix * 10;
    }
    delete[]tmp;
    delete[]count;
}
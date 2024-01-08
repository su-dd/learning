#include "SqHead.h"
#include<stdio.h>
#include<stdlib.h>

namespace HashTable {

#define SUCCESS 1
#define UNSUCCESS 0
#define OVERFLOW -1
#define OK 1
#define ERROR -1
#define MAXNUM 9999		// ���ڳ�ʼ����ϣ��ļ�¼ key

	typedef int Status;
	typedef int KeyType;

	// ��ϣ���еļ�¼����
	typedef struct {
		KeyType key;
	}RcdType;

	// ��ϣ������
	typedef struct {
		RcdType* rcd;	// ��ϣ����ָ��
		int size;	// ����
		int count;	// ��ǰ��С
		int* tag;	// ���ձ�ʶ����ֵ1����ֵ0��ɾ��-1
	}HashTable;

	// ��ϣ��ÿ���ؽ�������Ĵ�С
	int hashsize[] = { 11, 31, 61, 127, 251, 503 };
	int index = 0;

	// ��ʼ��ϣ��
	Status InitHashTable(HashTable& H, int size) {
		int i;
		H.rcd = (RcdType*)malloc(sizeof(RcdType) * size);
		H.tag = (int*)malloc(sizeof(int) * size);
		if (NULL == H.rcd || NULL == H.tag) return OVERFLOW;
		KeyType maxNum = MAXNUM;
		for (i = 0; i < size; i++) {
			H.tag[i] = 0;
			H.rcd[i].key = maxNum;
		}
		H.size = size;
		H.count = 0;
		return OK;
	}

	// ��ϣ����������������
	int Hash(KeyType key, int m) {
		return (3 * key) % m;
	}

	// �����ϣ��ͻ������̽��
	void collision(int& p, int m) {
		p = (p + 1) % m;
	}

	// �ڹ�ϣ���в�ѯ
	Status SearchHash(HashTable H, KeyType key, int& p, int& c) {
		p = Hash(key, H.size);
		int h = p;
		c = 0;
		while ((1 == H.tag[p] && H.rcd[p].key != key) || -1 == H.tag[p]) {
			collision(p, H.size);  c++;
		}

		if (1 == H.tag[p] && key == H.rcd[p].key) return SUCCESS;
		else return UNSUCCESS;
	}

	//��ӡ��ϣ��
	void printHash(HashTable H)
	{
		int  i;
		printf("key : ");
		for (i = 0; i < H.size; i++)
			printf("%3d ", H.rcd[i].key);
		printf("\n");
		printf("tag : ");
		for (i = 0; i < H.size; i++)
			printf("%3d ", H.tag[i]);
		printf("\n\n");
	}

	// ���������������ϣ��
	Status InsertHash(HashTable& H, KeyType key);

	// �ؽ���ϣ��
	Status recreateHash(HashTable& H) {
		RcdType* orcd;
		int* otag, osize, i;
		orcd = H.rcd;
		otag = H.tag;
		osize = H.size;

		InitHashTable(H, hashsize[index++]);
		//������Ԫ�أ������¹�ϣ�����ŵ��±���
		for (i = 0; i < osize; i++) {
			if (1 == otag[i]) {
				InsertHash(H, orcd[i].key);
			}
		}
		return OK;
	}

	// �����ϣ��
	Status InsertHash(HashTable& H, KeyType key) {
		int p, c;
		if (UNSUCCESS == SearchHash(H, key, p, c)) { //û����ͬkey
			if (c * 1.0 / H.size < 0.5) { //��ͻ����δ�ﵽ����
				//�������
				H.rcd[p].key = key;
				H.tag[p] = 1;
				H.count++;
				return SUCCESS;
			}
			else recreateHash(H); //�ع���ϣ�� 
		}
		return UNSUCCESS;
	}

	// ɾ����ϣ��
	Status DeleteHash(HashTable& H, KeyType key) {
		int p, c;
		if (SUCCESS == SearchHash(H, key, p, c)) {
			//ɾ������
			H.tag[p] = -1;
			H.count--;
			return SUCCESS;
		}
		else return UNSUCCESS;
	}

	int test()
	{
		printf("-----��ϣ��-----\n");
		HashTable H;
		int i;
		int size = 11;
		KeyType array[8] = { 22, 41, 53, 46, 30, 13, 12, 67 };
		KeyType key;

		//��ʼ����ϣ��
		printf("��ʼ����ϣ��\n");
		if (SUCCESS == InitHashTable(H, hashsize[index++])) printf("��ʼ���ɹ�\n");

		//�����ϣ��
		printf("�����ϣ��\n");
		for (i = 0; i <= 7; i++) {
			key = array[i];
			InsertHash(H, key);
			printHash(H);
		}

		//ɾ����ϣ��
		printf("ɾ����ϣ����keyΪ12��Ԫ��\n");
		int p, c;
		if (SUCCESS == DeleteHash(H, 12)) {
			printf("ɾ���ɹ�����ʱ��ϣ��Ϊ��\n");
			printHash(H);
		}

		//��ѯ��ϣ��
		printf("��ѯ��ϣ����keyΪ67��Ԫ��\n");
		if (SUCCESS == SearchHash(H, 67, p, c)) printf("��ѯ�ɹ�\n");

		//�ٴβ��룬���Թ�ϣ����ؽ�
		printf("�ٴβ��룬���Թ�ϣ����ؽ���\n");
		KeyType array1[8] = { 27, 47, 57, 47, 37, 17, 93, 67 };
		for (i = 0; i <= 7; i++) {
			key = array1[i];
			InsertHash(H, key);
			printHash(H);
		}

		getchar();
		return 0;
	}
}
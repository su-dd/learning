void Floyd(MatGraph MG) {
	int i, j, k;
	int A[MAXV][MAXV];
	int path[MAXV][MAXV];
	for (i = 0; i < MG.n; i++) {
		for (j = 0; j < MG.n; j++) {
			A[i][j] = MG.adjMat[i][j];
			if (i != j && MG.adjMat[i][j] < INF) {
				path[i][j] = i;							//���� i ������ j �б�ʱ
			}
			else {
				path[i][j] = -1;						//���� i ������ j �ޱ�ʱ
			}
		}
	}
	for (k = 0; k < MG.n; k++) {						//һ�ο������ж���
		for (i = 0; i < MG.n; i++) {
			for (j = 0; j < MG.n; j++) {
				if (A[i][j] > A[i][k] + A[k][j]) {
					A[i][j] = A[i][k] + A[k][j];		//�޸����·������
					path[i][j] = path[k][j];			//�޸����·��
				}
			}
		}
	}
	displayPath(MG, A, path);							//������·��
}



void displayPath(MatGraph MG, int A[MAXV][MAXV], int path[MAXV][MAXV]) {
	int i, j, k;
	int s;
	int aPath[MAXV];										//���һ�����·��������
	int d;													//�������
	for (i = 0; i < MG.n; i++) {
		for (j = 0; j < MG.n; j++) {
			if (A[i][j] != INF && i != j) {					//������ i �� ���� j ֮�����·��
				printf("�� %d �� %d ��·��Ϊ��", i, j);
				k = path[i][j];
				d = 0;
				aPath[d] = j;								//·��������յ�
				while (k != -1 && k != i) {					//·��������м��
					d++;
					aPath[d] = k;
					k = path[i][k];
				}
				d++;
				aPath[d] = i;								//·����������
				printf("%d", aPath[d]);						//������
				for (s = d - 1; s >= 0; s--) {				//���·������������
					printf("->%d", aPath[s]);
				}
				printf("\t\t");
				printf("·������Ϊ��%d\n", A[i][j]);
			}
		}
	}
}

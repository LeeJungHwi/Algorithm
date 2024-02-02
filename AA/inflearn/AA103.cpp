#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// �÷��̵�ͼ�
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 5 8
	cin >> n >> m;

	vector<vector<int> > minDis(n + 1, vector<int>(n + 1, 5000)); // �׷��� : ���İ��� �߰���带 � ����ϴ����� ���� �ּҺ�� ����

	int v1, v2, c; // ���� �� ���

	// ���������� ����(i���� j�� ���������� �Ÿ�), i == j�� 0, �������� max������ �ʱ�ȭ
	/*
	Input =
			1 2 6
			1 3 3
			3 2 2
			2 4 1
			2 5 13
			3 4 5
			4 2 3
			4 5 7

	graph = 0 6 3 M M
			M 0 M 1 13
			M 2 0 5 M
			M 3 M 0 7
			M M M M 0
	*/
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2 >> c;

		minDis[v1][v2] = c;
	}

	for (int i = 1; i < n + 1; i++)
	{
		minDis[i][i] = 0;
	}

	// ���İ��� �߰���带 � ����ϴ����� ���� �ּҺ�� ���� -> k�� ���İ��� �߰����� 1������ ��尳����ŭ �÷����鼭 ���̳���
	for (int k = 1; k < n + 1; k++)
	{
		for (int i = 1; i < n + 1; i++)
		{
			for (int j = 1; j < n + 1; j++)
			{
				if (minDis[i][j] > minDis[i][k] + minDis[k][j])
				{
					minDis[i][j] = minDis[i][k] + minDis[k][j];
				}
			}
		}
	}

	// ���� i ���� ���� j �� ���� �ִܰŸ� ���
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (minDis[i][j] == 5000) // �������ٸ� M ���
			{
				cout << 'M' << ' ';
				continue;
			}

			cout << minDis[i][j] << ' ';
		}

		cout << '\n';
	}

	return 0;
}
// �ٽ�
// �÷��̵�ͼ�
/*
��� �������� ��� �������� ���� �ִܰŸ��� ����
minDis[i][j] = min(minDis[i][j], minDis[i][k] + minDis[k][j]) -> ���� i ���� ���� j �� ���� �ִܰŸ�, k�� ���İ��� �߰����
*/
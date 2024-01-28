#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// �������
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream cin;
	cin.open("input.txt");

	int n, m; // N, M
	cin >> n >> m;

	int vertex1; // ����1
	int vertex2; // ����2
	int cost; // �Ÿ����

	vector<vector<int> > adjacencyVec(n, vector<int>(n)); // �������

	// ������� �ʱ�ȭ
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> vertex1 >> vertex2 >> cost;

			adjacencyVec[vertex1 - 1][vertex2 - 1] = cost;
		}
	}

	// ������� ���
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << adjacencyVec[i][j] << ' ';
		}

		cout << '\n';
	}

	return 0;
}
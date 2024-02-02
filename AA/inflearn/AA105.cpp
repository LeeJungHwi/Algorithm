#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// ��������
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 6, 6
	cin >> n >> m;

	int v1, v2; // ���� 

	vector<vector<int> > graph(n + 1, vector<int>(n + 1)); // ���İ��� �׷���
	vector<int> inDegree(n + 1); // ������ ����
	queue<int> curWorks; // �������ؾ��ϴ� �� ����

	// ���� ��������
	/*
		input : 1 4 -> 1������ �ϰ��� 4������ �ؾ���
				5 4
				4 3
				2 5
				2 3
				6 2

		graph : 0 0 0 1 0 0
				0 0 1 0 1 0
				0 0 0 0 0 0
				0 0 1 0 0 0
				0 0 0 1 0 0
				0 1 0 0 0 0
	*/
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2;

		graph[v1][v2] = 1;

		inDegree[v2]++; // ������ ���� ���� -> 0 1 2 2 1 0
	}

	// ������ ������ 0�̸� ť�� ����
	for (int i = 1; i < n + 1; i++)
	{
		if (inDegree[i] == 0)
		{
			curWorks.push(i);
		}
	}

	// ť�� �������� BFS
	while (!curWorks.empty())
	{
		// �������ؾ��ϴ� �� ����
		int curWork = curWorks.front();
		curWorks.pop();

		cout << curWork << " ";

		// ������ �ϴ� ���� outDegree�� ���� ���� inDegree �����ϰ� ���� inDegree�� �ϳ��� ���������� ť�� ���� -> inDegree�� 0�ΰ��� �������ؾ��� �۾��� ���� �۾��̹Ƿ� ť�� ����
		for (int i = 1; i < n + 1; i++)
		{
			if (graph[curWork][i] == 1)
			{
				inDegree[i]--;

				if (inDegree[i] == 0)
				{
					curWorks.push(i);
				}
			}
		}
	}

	return 0;
}
// �ٽ�
// ��������
/*
������ ���� ���İ��谡 �����Ҷ� ���İ��踦 �����ϸ鼭 ��ü ���� ������ «
*/
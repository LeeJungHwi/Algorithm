#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// �ּҺ��
void SearchGraph(int vertex, int n, int &minDis, int sumDis, vector<vector<int> > &graph, vector<bool> &vis, vector<vector<int> > &dis)
{
	if (vertex == n - 1) // �������� : ������ ���� ����
	{
		if (minDis > sumDis) // �ּҺ�� ����
		{
			minDis = sumDis;
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (graph[vertex][i] == 1 && !vis[i]) // ���������鼭 ���� �湮�����������̸�
			{
				vis[i] = true; // �湮üũ
				sumDis += dis[vertex][i]; // �Ÿ� ����
				SearchGraph(i, n, minDis, sumDis, graph, vis, dis);
				vis[i] = false; // �湮����
				sumDis -= dis[vertex][i]; // �Ÿ� ����
			}
		}
	}
}

// �ּҺ��(�������)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M
	cin >> n >> m;

	int v1, v2, d; // ����, �Ÿ�
	int minDis = 0; // �ּҺ��
	int sumDis = 0; // �Ÿ� ����

	vector<vector<int> > graph(n, vector<int>(n)); // �׷���
	vector<bool> vis(n); // �湮üũ
	vector<vector<int> > dis(n, vector<int>(n)); // �Ÿ�

	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2 >> d;

		graph[v1 - 1][v2 - 1] = 1;
		dis[v1 - 1][v2 - 1] = d;
		minDis += d;
	}

	// ù ���� �湮üũ
	vis[0] = true;

	// DFS
	SearchGraph(0, n, minDis, sumDis, graph, vis, dis);

	cout << minDis << '\n';

	return 0;
}
// �ٽ�
// �Ÿ���� �߰�
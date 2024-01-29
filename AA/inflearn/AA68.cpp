#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// �ּҺ��
void SearchGraph(int vertex, int n, vector<pair<int, int> > graph[], vector<bool> &vis, int &minDis, int sumDis)
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
		for (int i = 0; i < graph[vertex].size(); i++)
		{
			if (!vis[graph[vertex][i].first]) // ���� �湮������������ üũ : ��������Ʈ�� �����ִ°��� �����ϹǷ�
			{
				vis[graph[vertex][i].first] = true; // �湮üũ
				sumDis += graph[vertex][i].second; // �Ÿ� ����
				SearchGraph(graph[vertex][i].first, n, graph, vis, minDis, sumDis);
				vis[graph[vertex][i].first] = false; // �湮üũ ����
				sumDis -= graph[vertex][i].second; // �Ÿ� ����
			}
		}
	}
}

// �ּҺ�� (��������Ʈ)
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

	vector<pair<int, int> > graph[20]; // �׷���
	vector<bool> vis(n); // �湮üũ

	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2 >> d;

		graph[v1 - 1].push_back({ v2 - 1, d });
		minDis += d;
	}

	// ù ���� �湮üũ
	vis[0] = true;

	// DFS
	SearchGraph(0, n, graph, vis, minDis, sumDis);

	cout << minDis << '\n';

	return 0;
}
// �ٽ�
// �Ÿ���� �߰�
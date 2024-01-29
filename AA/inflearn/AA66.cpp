#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// ���Ž�� (��������Ʈ)
void SearchGraph(int vertex, vector<int> graph[], int n, int &caseCnt, vector<bool> &vis)
{
	if (vertex == n - 1) // �������� : N ������ ������ ���
	{
		caseCnt++;
	}
	else
	{
		// out degree�� ������ �� �������� �����ִ� ������ ���ȣ��

		for (int i = 0; i < graph[vertex].size(); i++)
		{
			if (!vis[graph[vertex][i]]) // ��������Ʈ�� �湮���������������� üũ : �����ִ°��� �����س��� �����̹Ƿ�
			{
				vis[graph[vertex][i]] = true;
				SearchGraph(graph[vertex][i], graph, n, caseCnt, vis);
				vis[graph[vertex][i]] = false; // �ڷ� �ǵ��ư��� �湮üũ �����������
			}
		}
	}
}

// ���Ž��(��������Ʈ)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M
	cin >> n >> m;

	int v1, v2; // ����

	int caseCnt = 0; // ������ ��� ��

	vector<int> graph[20];
	vector<bool> vis(n); // �湮üũ

	//	1 2
	//	1 3
	//	1 4
	//	2 1
	//	2 3
	//	2 5
	//	3 4
	//	4 2
	//	4 5
	//  0 -> 1 -> 2 -> 3
	//  1 -> 0 -> 2 -> 4
	//  2 -> 3
	//  3 -> 1 -> 4
	//  ....
	//  19
	// ��������Ʈ
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2;

		graph[v1 - 1].push_back(v2 - 1);
	}

	// ù ���� �湮üũ
	vis[0] = true;

	// DFS
	SearchGraph(0, graph, n, caseCnt, vis);

	cout << caseCnt << '\n';

	return 0;
}
// �ٽ�
// DFS ��������Ʈ : �������� �����ִ� �����̸鼭 �湮���������� üũ, ���ȣ�� �� �湮üũ ����
// �޸𸮰��� �� Ž���ð� ����
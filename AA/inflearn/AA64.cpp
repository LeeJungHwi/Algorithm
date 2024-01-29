#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// ���Ž��(�������)
void SearchGraph(int vertex, vector<vector<int> > &graph, int n, int &caseCnt, vector<bool> &vis)
{
	if (vertex == n - 1) // �������� : N ������ ������ ���
	{
		caseCnt++;
	}
	else
	{
		// out degree�� ������ �� �������� �����ִ� ������ ���ȣ�� 
		// �Լ� ȣ�⽺��
		// DFS(0) i = 1
		// DFS(1) i = 2
		// DFS(2) i = 3
		// DFS(3) i = 4
		// DFS(4) cnt++ �� ���ÿ��� ����
		
		// DFS(0) i = 1
		// DFS(1) i = 2
		// DFS(2) i = 3
		// DFS(3) i = 4���� vis[4] = false �� ���ÿ��� ����

		// DFS(0) i = 1
		// DFS(1) i = 2
		// DFS(2) i = 3���� vis[3] = false �� i = 4�϶� �����Ƿ� ���ÿ��� ����

		// DFS(0) i = 1
		// DFS(1) i = 2���� vis[2] = false �� i = 3�϶� ������ i = 4�϶� �������� -> DFS(1) i = 4
		// DFS(4) cnt++ �� ���ÿ��� ����

		// DFS(0) i = 1
		// DFS(1) i = 4���� vis[4] = false �� ���ÿ��� ����

		// DFS(0) i = 1���� vis[1] = false �� i = 2�϶� �������� -> DFS(1) i = 2
		// DFS(2) ....

		for (int i = 0; i < n; i++)
		{
			if (graph[vertex][i] == 1 && !vis[i]) // ���������鼭 �湮�����������̸�
			{
				vis[i] = true;
				SearchGraph(i, graph, n, caseCnt, vis);
				vis[i] = false; // �ڷ� �ǵ��ư��� �湮üũ �����������
			}
		}
	}
}

// ���Ž��(�������)
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

	vector<vector<int> > graph(n, vector<int>(n)); // �׷��� ����
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
	// 0 1 1 1 0
	// 1 0 1 0 1
	// 0 0 0 1 0
	// 0 0 0 0 0
	// 0 1 0 0 1
	// �������
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2;

		graph[v1 - 1][v2 - 1] = 1;
	}

	// ù ���� �湮üũ
	vis[0] = true;

	// DFS
	SearchGraph(0, graph, n, caseCnt, vis);

	cout << caseCnt << '\n';

	return 0;
}
// �ٽ�
// DFS ������� : �������� �����ִ� �����̸鼭 �湮���������� üũ, ���ȣ�� �� �湮üũ ����
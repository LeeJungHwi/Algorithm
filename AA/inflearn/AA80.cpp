#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

vector<pair<int, int>> graph[30]; // �׷���
vector<int> dist(30, 2147000000); // �Ÿ��迭 �ʱ�ȭ : dist[i] -> 1���������� i���������� ���µ� �ּҺ��
vector<bool> vis1(30); // �湮üũ

// ���ͽ�Ʈ��
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 6, 9
	int v1, v2, c; // ���� �� ���
	int minIdx; // ���� ����� ���� �ε���

	cin >> n >> m;

	// �������� �ʱ�ȭ
	//	1 2 12
	//	1 3 4
	//	2 1 2
	//	2 3 5
	//	2 5 5
	//	3 4 5
	//	4 2 2
	//	4 5 5
	//	6 4 5
	for (int i = 1; i < m + 1; i++)
	{
		cin >> v1 >> v2 >> c;
		graph[v1].push_back({ v2, c });
	}

	// 1���������� 1���������� ���µ� �ּҺ�� 0
	dist[1] = 0;

	// ���ͽ�Ʈ�� : �������� ��� ����϶�
	// �� �������� �����ִ� ������ ���� �Ÿ��迭 �ּҰ� ����
	// �� ���� ���ϴ¹� : dist �迭�� �ּҰ�
	// dist : ���� ���� ���� ���� ���� ����
	// v1   : 0(vis) 12 4 ���� ���� ����
	// v3   : 0(vis) 12 4(vis) 9 ���� ����
	// v4   : 0(vis) 11 4(vis) 9(vis) 14 ����
	// v2   : 0(vis) 11(vis) 4(vis) 9(vis) 14 ����
	// v5   : 0(vis) 11(vis) 4(vis) 9(vis) 14(vis) ����
	for (int i = 1; i < n + 1; i++)
	{
		minIdx = 0;

		// �����ִ� ���� �� ���� �湮�������� �����߿� �Ÿ��� ���� ����� ���� ã��
		for (int j = 1; j < n + 1; j++)
		{
			if (!vis1[j] && dist[j] < dist[minIdx])
			{
				minIdx = j;
			}
		}

		vis1[minIdx] = true; // ���� ����� ���� �湮üũ

		for (int j = 0; j < graph[minIdx].size(); j++) // ���� ����� �������� �����ִ� ������ �ּҰ� ����
		{
			int vertex = graph[minIdx][j].first;
			int cost = graph[minIdx][j].second;

			if (dist[vertex] > dist[minIdx] + cost)
			{
				dist[vertex] = dist[minIdx] + cost;
			}
		}
	}

	// 2�� �������� �� �������� ���� �ּҺ�� ���
	for (int i = 2; i < n + 1; i++)
	{
		if (dist[i] != 2147000000)
		{
			cout << i << " : " << dist[i] << '\n';
		}
		else // �������� ����
		{
			cout << i << " : impossible\n";
		}
	}

	return 0;
}
// �ٽ�
// ���ͽ�Ʈ��

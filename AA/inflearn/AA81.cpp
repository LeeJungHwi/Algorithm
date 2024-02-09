#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<int> dist(101, 2147000000); // �Ÿ��迭 �ʱ�ȭ

// �������� ����ü
struct Edge
{
	int vertex1;
	int vertex2;
	int distance;

	Edge(int v1, int v2, int c)
	{
		vertex1 = v1;
		vertex2 = v2;
		distance = c;
	}
};

// ��������
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream cin;
	cin.open("input.txt");

	vector<Edge> graph; // �׷���

	int n, m; // N, M 5, 7
	cin >> n >> m;

	int v1, v2, c; // ���� �� ���

	// �������� �ʱ�ȭ
	//	1 2 5
	//	1 3 4
	//	2 3 - 3
	//	2 5 13
	//	3 4 5
	//	4 2 3
	//	4 5 7
	for (int i = 1; i < m + 1; i++)
	{
		cin >> v1 >> v2 >> c;
		graph.push_back(Edge(v1, v2, c));
	}

	int s, e; // S, E 1, 5
	cin >> s >> e;

	// ���۵��ÿ��� ���۵��ñ��� �ּҺ�� 0
	dist[s] = 0;

	// �������� : �׷����� ���� ����ġ�� ������, ���� ������ �ִ� ������ �Ѿ�� ��� ���� ����Ŭ�� ������
	// ������������ ������������ ������ ������ �÷����鼭 �ּҺ�� ����
	// ������ �ִ� ���� : �������� - �������� = 5 - 1 = 4
	/*
	 dist : ���� ���� ���� ���� ����
	 i=1  : 0    5    4    ���� ����
	 i=2  : 0    5    2    9    18
	 i=3  : 0    5    2    7    16
	 i=4  : 0    5    2    7    14
	*/
	for (int i = 1; i < n; i++) // ������ ������ �÷����鼭 �ּҺ�� ����
	{
		for (int j = 0; j < graph.size(); j++) // �� �������� �����ִ� ���� üũ
		{
			int vertex1 = graph[j].vertex1;
			int vertex2 = graph[j].vertex2;
			int cost = graph[j].distance;

			if (dist[vertex1] != 2147000000 && dist[vertex1] + cost < dist[vertex2]) // ����� ���Ѵ�� �������� �� Ŀ���Ƿ� ���žȵ�, �����ִ� ������ ���� ����� ���ߴ��� ���� ��뺸�� ������ ����
			{
				dist[vertex2] = dist[vertex1] + cost;
			}
		}
	}

	// �ѹ��� �ؼ� �ּҰ��� ���ŵǸ� ������ �ִ� ������ �Ѿ�� ����̹Ƿ� ���� ����Ŭ�� ������
	for (int j = 0; j < graph.size(); j++)
	{
		int vertex1 = graph[j].vertex1;
		int vertex2 = graph[j].vertex2;
		int cost = graph[j].distance;

		if (dist[vertex1] != 2147000000 && dist[vertex1] + cost < dist[vertex2])
		{
			cout << "-1\n";
			return 0;
		}
	}

	// ���۵��ÿ��� �������ñ��� �ּҺ�� ���
	cout << dist[e] << '\n';

	return 0;
}
// �ٽ�
// ��������

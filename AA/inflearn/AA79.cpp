#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

vector<bool> vis1(30); // �湮üũ

// �������� ����ü
struct Edge
{
	int vertex;
	int distance;

	Edge(int v, int c) // ������
	{
		vertex = v;
		distance = c;
	}

	bool operator<(const Edge &edge)const // �ּ��� ����
	{
		return distance > edge.distance;
	}
};

// ��������(����)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	priority_queue<Edge> minHeap; // �ּ���
	vector<pair<int, int> > graph[30]; // ����� �׷���

	int v, e; // V, E 9, 12
	cin >> v >> e;

	int v1, v2, c; // ���� �� ���
	int minCost = 0; // �ּҺ��

	// �������� �ʱ�ȭ
	for (int i = 0; i < e; i++)
	{
		cin >> v1 >> v2 >> c;

		// ����� �׷��� �ʱ�ȭ
		graph[v1 - 1].push_back({ v2 - 1, c });
		graph[v2 - 1].push_back({ v1 - 1, c });
	}

	// �ּ��� ���
	// �ּ����� (��������, ���) ����
	// �ּ������� �ּҺ�� ������ ��� ���� �� Ʈ���� ����, ���� �������κ��� �����ִ� ���� �ּ����� ����
	// ť�� ������� ����
	/*
	(0, 0) heap push
	(0, 0) heap pop (0, 0) tree push (1, 12),(8,25) heap push 0 cost
	(1, 12) heap pop (1, 12) tree push (8, 8),(7, 17),(2,10) heap push 12 cost
	(8, 8) heap pop (8, 8) tree push (7, 15) heap push 20 cost
	(2, 10) heap pop (2, 10) tree push (3, 18),(6, 55) heap push 30 cost
	(7, 15) heap pop (7, 15) tree push (6, 35) heap push 45 cost
	(3, 18) heap pop (3, 18) tree push (4, 44) heap push 63 cost
	(8, 25) heap pop Ʈ���� �����ϹǷ� pop���ϰ� ������
	(6, 35) heap pop (6, 35) tree push (4, 38) heap push 98 cost
	(4, 38) heap pop (4, 38) tree push (5, 60) heap push 136 cost
	(4, 44) heap pop Ʈ���� �����ϹǷ� pop���ϰ� ������
	(6, 55) heap pop Ʈ���� �����ϹǷ� pop���ϰ� ������
	(5, 60) heap pop (5, 60) tree push 196 cost
	*/

	minHeap.push(Edge(0, 0)); // (��������, ���) ����
	while (!minHeap.empty()) // ť�� ������� ����
	{
		Edge tmpEdge = minHeap.top(); // �ּҺ�� ���� ��
		minHeap.pop();

		int vertex = tmpEdge.vertex; // �ش� ���÷ΰ���
		int cost = tmpEdge.distance; // ���

		if (!vis1[vertex]) // ���� �湮���� �ʾ�����
		{
			minCost += cost; // ��� ����
			vis1[vertex] = true; // �湮 üũ

			for (int i = 0; i < graph[vertex].size(); i++) // �ش� ���÷κ��� �����ִ� �������� �ּ����� �߰�
			{
				minHeap.push(Edge(graph[vertex][i].first, graph[vertex][i].second));
			}
		}
	}

	// �ּҺ�� ���
	cout << minCost << '\n';

	return 0;
}
// �ٽ�
// ����
/*
������ ���� ������ �����ϰ� ������ �������� ������踦 ���鼭 ������ �߰��� �����ٰ� ������ n���� �Ǹ� �ּҺ�� -> �ּ��� ���
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

// ���Ͽ� ���ε� ����
vector<int> unf(10001);

// �������� ����ü
struct Edge
{
	int vertex1;
	int vertex2;
	int distance;

	Edge(int v1, int v2, int c) // ������
	{
		vertex1 = v1;
		vertex2 = v2;
		distance = c;
	}

	bool operator<(Edge &edge) // ���� ������� ���� �������� ����
	{
		return distance < edge.distance;
	}
};

// ���ε�
// ���ð� ���� ���� ��ȣ ��ȯ : ������ ��ȣ�� ������ ��Ʈ��ȣ
int Find(int v)
{
	if (v == unf[v])
	{
		return v;
	}
	else
	{
		return unf[v] = Find(unf[v]);
	}
}

// ���Ͽ�
// �� ���ð� ���� ���� ��ȣ�� �ٸ��� �ϳ��� ��ħ
void Union(int v1, int v2)
{
	v1 = Find(v1);
	v2 = Find(v2);
	
	if (v1 != v2)
	{
		unf[v1] = v2;
	}
}

// ��������(ũ�罺Į)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	vector<Edge> edge; // ��������

	int v, e; // V, E 9, 12
	cin >> v >> e;

	int v1, v2, c; // ���� �� ���
	int minCost = 0; // �ּҺ��

	// �������� �ʱ�ȭ
	/*	
			0 1 12
			0 8 25
			1 2 10
			1 7 17
			1 8 8
			2 3 18
			2 6 55
			3 4 44
			4 5 60
			4 6 38
			6 7 35
			7 8 15
	*/
	for (int i = 0; i < e; i++)
	{
		cin >> v1 >> v2 >> c;
		edge.push_back(Edge(v1 - 1, v2 - 1, c));
	}

	// ���� ������� �������� ����
	/*
			1 8 8
			1 2 10
			0 1 12
			7 8 15
			1 7 17
			2 3 18
			0 8 25
			6 7 35
			4 6 38
			3 4 44
			2 6 55
			4 5 60
	*/
	sort(edge.begin(), edge.end());

	// ���Ͽ� ���ε� ���� �ʱ�ȭ
	// 0 1 2 3 4 5 6 7 8
	for (int i = 0; i < v; i++)
	{
		unf[i] = i;
	}

	// ���Ͽ� ���ε� �����ϸ鼭 ����������� ����
	for (int i = 0; i < e; i++)
	{
		int findVertex1 = Find(edge[i].vertex1); // 1 1 0 7 1 2 0 6 4 3 2 4
		int findVertex2 = Find(edge[i].vertex2); // 8 2 1 8 7 3 8 7 6 4 6 5

		if (findVertex1 != findVertex2) // ���ð� ���� �ٸ����տ� ���ϸ�
		{
			minCost += edge[i].distance; // ��� ����
			Union(edge[i].vertex1, edge[i].vertex2); // ���� ��ħ
		}
	}

	// �ּҺ�� ���
	cout << minCost << '\n';

	return 0;
}
// �ٽ�
// ���Ͽ� ���ε�
/*
���Ͽ� : ������Ұ� �ִ� �� ������ ��ħ -> A = {1, 2} + B = {2, 3} = {1, 2, 3}
disjoint Set : ������Ұ� ���� �� ����
*/
// ũ�罺Į
/*
������ ����ġ���� ���� �������� ���� �� ȸ�ΰ� �߻����� �ʴ� �����Ͽ� ����ġ�� ���� �������� ������ �����ٰ� ������ n-1�� ���õǸ� �ּҺ��
*/

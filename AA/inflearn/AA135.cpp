#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// ���Ͽ� ���ε� ����
vector<int> unf(10001);

// �������� ����ü
struct Edge
{
	int vertex1; // ȣ��1
	int vertex2; // ȣ��2
	double distance; // �� ȣ���� �����ϴ� �Ÿ�

	Edge(int v1, int v2, double dis) // ������
	{
		vertex1 = v1;
		vertex2 = v2;
		distance = dis;
	}

	bool operator<(Edge &edge) // �Ÿ� ���� �������� ����
	{
		return distance < edge.distance;
	}
};

// ���ε�
// ȣ���� ���� ���� ��ȣ ��ȯ : ������ ��ȣ�� ������ ��Ʈ��ȣ
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
// �� ȣ���� ���� ���� ��ȣ�� �ٸ��� �ϳ��� ��ħ
void Union(int v1, int v2)
{
	v1 = Find(v1);
	v2 = Find(v2);

	if (v1 != v2)
	{
		unf[v1] = v2;
	}
}

// ȣ�ڿ���
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 5, 2
	cin >> n >> m;

	vector<Edge> edge; // ��������

	int v1, v2; // ����
	double minDis = 0; // �߰����� ������ �ּұ���

	vector<double> X, Y; // ȣ�� ��ǥ ����
	int x, y; // ��ǥ

	// �������� �ʱ�ȭ
	//	2 1
	//	4 1
	//	5 1
	//	4 3
	//	1 2
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;

		X.push_back(x);
		Y.push_back(y);

		unf[i] = i; // ���Ͽ����ε� ���� �ʱ�ȭ
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			double dis = sqrt((X[j] - X[i]) * (X[j] - X[i]) + (Y[j] - Y[i]) * (Y[j] - Y[i])); // i��ȣ�ڿ��� j���� �� ȣ�� ���� �Ÿ��� ����
			edge.push_back(Edge(i, j, dis)); // �������� ����
		}
	}

	// �̹� ����� �������� �ʱ�ȭ
	//	1 2
	//	2 3
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2;

		Union(v1 - 1, v2 - 1);
	}

	// ���� �Ÿ����� �������� ���� : ���� ���� �Ÿ����� ���ε��ϱ�����
	sort(edge.begin(), edge.end());

	// ���Ͽ� ���ε�� ȣ���� �����ϸ鼭 ���ΰŸ� ����
	for (int i = 0; i < edge.size(); i++)
	{
		int findVertex1 = Find(edge[i].vertex1);
		int findVertex2 = Find(edge[i].vertex2);

		if (findVertex1 != findVertex2) // ȣ���� ���� �ٸ����տ� ���ϸ� 
		{
			minDis += edge[i].distance; // �Ÿ� ����
			Union(edge[i].vertex1, edge[i].vertex2); // ���� ��ħ
		}
	}

	// �Ҽ� ��° �ڸ����� �ݿø� ���
	cout << fixed;
	cout.precision(2);
	cout << minDis;

	return 0;
}

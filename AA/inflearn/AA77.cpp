#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void IsFriend(int v1, int v2, vector<int> graph[], bool &isFriend, vector<bool> &vis)
{
	if (v1 == v2) // �������� : ����Ǿ������� ģ��
	{
		isFriend = true;
	}
	else
	{
		for (int i = 0; i < graph[v1].size(); i++) // �����ִ°� ��������� ���� �ϰ� �湮üũ��
		{
			if (!vis[graph[v1][i]])
			{
				vis[graph[v1][i]] = true; // �湮 üũ
				IsFriend(graph[v1][i], v2, graph, isFriend, vis);
				vis[graph[v1][i]] = false; // �湮 ����
			}
		}
	}
}

// ģ���ΰ�?
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 20, 22
	cin >> n >> m;

	int v1, v2; // ����

	vector<int> graph[1000]; // �׷���
	vector<bool> vis(1000); // �湮üũ

	bool isFriend = false; // ģ������ üũ

	//	17 -> 8
	//	3 -> 14
	//	11 -> 15
	//	8 -> 9
	//	9 -> 6
	//	13 -> 8
	//	12 -> 2
	//	16 -> 4
	//	5 -> 0
	//	0 -> 13
	//	11 -> 3
	//	8 -> 10
	//	6 -> 4
	//	16 -> 3
	//	5 -> 16
	//	11 -> 8
	//	17 -> 9
	//	16 -> 7
	//	10 -> 17
	//	6 -> 18
	//	3 -> 2
	//	2 -> 3

	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2;

		// ��������� ����
		graph[v1 - 1].push_back(v2 - 1);
		graph[v2 - 1].push_back(v1 - 1);
	}

	cin >> v1 >> v2; // 10, 15

	IsFriend(v1 - 1, v2 - 1, graph, isFriend, vis);

	if (isFriend) // ģ��
	{
		cout << "YES\n";

		return 0;
	}

	cout << "NO\n"; // ģ�� �ƴ�

	return 0;
}
// �ٽ�
// ��������� ����
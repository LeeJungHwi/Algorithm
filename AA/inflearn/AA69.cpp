#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

// ����Ʈ�� Ž��
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int v1, v2; // ����

	vector<int> graph[7]; // �׷���
	queue<int> checkVertex; // üũ�� ����

	// ��������Ʈ
	// 0 -> 1 -> 2
	// 1 -> 3 -> 4
	// 2 -> 5 -> 6
	for (int i = 0; i < 6; i++)
	{
		cin >> v1 >> v2;

		graph[v1 - 1].push_back(v2 - 1);
	}

	checkVertex.push(0);
	cout << 1 << ' '; // 1

	// BFS
	while (checkVertex.back() != 6)
	{
		int curVertex = checkVertex.front(); // ���� üũ�� ����
		checkVertex.pop(); // �������� pop

		for (int i = 0; i < graph[curVertex].size(); i++)
		{
			cout << graph[curVertex][i] + 1 << ' '; // ������ȣ ��� : 2 3 -> 4 5 -> 6 7
			checkVertex.push(graph[curVertex][i]); // ������ȣ ť�� push
		}
	}

	return 0;
}
// �ٽ�
// DFS�� ��ͷ� BFS�� �ݺ������� ����
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

// �׷��� �ִܰŸ�
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M
	cin >> n >> m;

	int v1, v2; // ����

	vector<int> graph[20];
	vector<int> vertexCnt(n); // �� �������� ���� �ּҰ��� ��
	queue<int> vertexCheck; // üũ�� ����
	int cntEdge = 0; // ���� ��
	int storeCnt = 0; // ������ Ƚ��
	bool isFinish = false; // ��� ������ �������� üũ

	// ��������Ʈ
	// 0 -> 2 -> 3
	// 1 -> 0 -> 4
	// 2 -> 3
	// 3 -> 4 -> 5
	// 5 -> 1 -> 4
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2;

		graph[v1 - 1].push_back(v2 - 1);
	}

	vertexCheck.push(0);

	// BFS
	while (!isFinish)
	{
		// üũ�� ���� ������
		int curVertex = vertexCheck.front();
		vertexCheck.pop();

		// ������ ���� �������� ������ ���� 1�� ����
		cntEdge = vertexCnt[curVertex] + 1;

		// ���� �������� �����ִ� ���� �ּҰ��� �� ���� �� ť�� �߰�
		for (int i = 0; i < graph[curVertex].size(); i++)
		{
			if (vertexCnt[graph[curVertex][i]] == 0) // ���� ���� ���� ������� ������츸 
			{
				vertexCnt[graph[curVertex][i]] = cntEdge; // ���� �� ����
				storeCnt++;

				if (storeCnt == n - 1) // �� �������� �ּҰŸ��� ��� ���������� ����
				{
					isFinish = true;

					break;
				}
			}

			vertexCheck.push(graph[curVertex][i]); // ť�� �߰�
		}
	}

	for (int i = 1; i < n; i++)
	{
		cout << i + 1 << " : " << vertexCnt[i] << '\n';
	}

	return 0;
}
// �ٽ�
// BFS �Ҷ����� ���� �� ���� X -> üũ�� ������ ���� �� + 1
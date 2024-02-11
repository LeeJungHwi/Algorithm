#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

int n, m, s, e; // N, M, S, E 5, 6, 1, 5
vector<pair<int, int> > graph[10001]; // �׷���

// �ѹ��� �̵����� �ű���ִ� ��ǰ�� �ִ빫������ üũ�ϴ� �Լ�
bool IsMove(int maxWeight)
{
	vector<bool> vis(n + 1); // �湮üũ
	queue<int> checkPos; // üũ �� ��

	// ���� ������ �ִ� ������ BFS ������
	vis[s] = true;
	checkPos.push(s);

	while (!checkPos.empty()) // ť�� ��������
	{
		// ������ġ ����
		int standardPos = checkPos.front();
		checkPos.pop();

		for (int i = 0; i < graph[standardPos].size(); i++)
		{
			// �湮üũ
			if (vis[graph[standardPos][i].first])
			{
				continue;
			}

			// ��ǰ�� �ִ빫�԰� �ٸ��� �߷����� ũ�� �� �ű�
			if (graph[standardPos][i].second < maxWeight)
			{
				continue;
			}

			// �ű���ִ� �����̸� �湮 üũ �� ť�� ����
			vis[graph[standardPos][i].first] = true;
			checkPos.push(graph[standardPos][i].first);
		}
	}

	return vis[e]; // ���� ������ �ִ� ������ �ű���ִ��� ����
}

// ��ǰ �̵�
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n >> m;

	int a, b, c; // A��, B��, A���� B���� �մ� �ٸ��� �̵��Ҽ��ִ� ��ǰ�� �ִ빫��
	int high; // �ѹ��� �̵����� �ű���ִ� ��ǰ�� �ִ빫�Դ� c �� �ִ밪

	// ���� �մ� �ٸ����� �ʱ�ȭ
	//	1 2 5
	//	1 3 3
	//	1 4 2
	//	2 4 2
	//	3 4 4
	//	4 5 3
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;

		// �׷��� ����� ����
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));

		high = max(high, c);
	}

	cin >> s >> e;

	int first = 1; // ó��
	int last = high; // ������
	int result = 0; // �ѹ��� �̵����� �ű���ִ� ��ǰ�� �ִ빫��

	// �ѹ��� �̵����� �ű���ִ� ��ǰ�� �ִ빫�� ã�Ƽ� ���
	while (first <= last) // first�� last�� �����Ǹ� ����
	{
		int avg = (first + last) / 2; // �ѹ��� �̵����� �ű���ִ� ��ǰ�� �ִ빫��

		if (IsMove(avg)) // ���԰� avg�϶� s���� e�� �ű�°� �����ϴٸ�
		{
			result = avg; // �ѹ��� �̵����� �ű���ִ� ��ǰ�� �ִ빫�� ����
			first = avg + 1; // ó�� ���� 
		}
		else // �Ұ����� ��ǰ�� �ִ빫��
		{
			last = avg - 1; // ������ ����
		}
	}

	cout << result;

	return 0;
}
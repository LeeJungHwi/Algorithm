#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// ��� ����
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 10
	cin >> n;

	vector<vector<int> > graph(n + 1, vector<int>(n + 1)); // �׷���
	vector<vector<int> > turnCnt(n + 1, vector<int>(n + 1)); // ������ȯ Ƚ��

	//	0 0 0 0 0 0 0 0 0 0
	//	0 1 1 0 0 0 0 1 1 1
	//	0 1 1 0 1 1 0 0 0 0
	//	0 1 1 0 0 1 0 1 1 0
	//	0 0 0 0 0 1 1 1 0 0
	//	0 1 0 0 0 0 0 0 0 0
	//	0 1 1 1 1 0 0 0 1 1
	//	0 1 0 0 0 0 0 0 0 0
	//	0 0 0 0 0 1 1 1 0 0
	//	0 1 1 1 1 0 0 0 0 0
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			cin >> graph[i][j];
		}
	}

	int x, y; // ������ ��ǥ

	cin >> x >> y;
	pair<int, int> tomPos = { x, y }; // 1 1

	cin >> x >> y;
	pair<int, int> jerryPos = { x, y }; // 10 9

	// BFS
	// �� ��ġ���� ���� ��ġ���� ���µ� ���� ��ȯ �ּҰ� ã��
	// ��質 ���� ���������� ���ʹ������� ���鼭 ���� ������ȯȽ���� �Ҵ���� �������� ������ġ�� ������ȯȽ�� + 1

	queue<pair<int, int> > checkPos; // üũ�� ��ġ
	vector<pair<int, int> > checkDir; // �����¿�
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	checkPos.push({ tomPos.first, tomPos.second }); // �� ��ǥ���� BFS

	while (!checkPos.empty()) // ť�� ��������
	{
		// ������ġ ����
		pair<int, int> standardPos = checkPos.front();
		checkPos.pop();

		// �����¿� üũ
		for (int i = 0; i < 4; i++)
		{
			// üũ�� ��ġ
			int checkI = standardPos.first + checkDir[i].first;
			int checkJ = standardPos.second + checkDir[i].second;

			while (true)
			{
				// ���üũ
				if (checkI < 1 || checkJ < 1 || checkI >= n + 1 || checkJ >= n + 1)
				{
					break;
				}

				// ��üũ
				if (graph[checkI][checkJ] == 1)
				{
					break;
				}

				// ���� ������ ������ȯȽ���� �Ҵ�Ǿ��ִ��� üũ�ϰ� ť�� ���� �� ������ġ�� ������ȯȽ�� + 1
				if (turnCnt[checkI][checkJ] == 0)
				{
					checkPos.push({ checkI, checkJ });
					turnCnt[checkI][checkJ] = turnCnt[standardPos.first][standardPos.second] + 1;
				}

				// ���ʹ������� �� ���ư�
				checkI += checkDir[i].first;
				checkJ += checkDir[i].second;
			}
		}
	}

	// ������������ ������ȯȽ���� �Ҵ�Ǿ����������� ��������
	if (turnCnt[jerryPos.first][jerryPos.second] == 0)
	{
		cout << "-1";

		return 0;
	}

	// ó�� �� ��ġ���� �������� �̵��Ҷ��� ������ȯ�� �ƴѵ� 1 �����ϹǷ� 1 ����
	cout << turnCnt[jerryPos.first][jerryPos.second] - 1;

	return 0;
}
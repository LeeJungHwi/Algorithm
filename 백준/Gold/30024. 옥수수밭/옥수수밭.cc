#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

struct Corn
{
	int value;
	pair<int, int> pos;

	Corn() {}
	Corn(int val, pair<int, int> p) : value(val), pos(p) {}

	bool operator<(const Corn &corn) const
	{
		return value < corn.value;
	}
};

// 옥수수밭
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 옥수수 구조체 => 가치, 위치
	// 우선순위 큐에 그래프 가장자리 옥수수 저장 => 가치 높은 순
	// 우선순위 큐에서 k번 꺼냄
	// 각 스텝에서 꺼낼 때 꺼낸 옥수수의 상하좌우 옥수수를 우선순위 큐에 저장

	// 초기화
	int n, m;
	cin >> n >> m;
	vector<vector<int> > graph(n + 2, vector<int>(m + 2));
	vector<vector<bool> > vis(n + 2, vector<bool>(m + 2));
	queue<pair<int, int> > checkInitPos;
	checkInitPos.push({ 0, 0 });
	vis[0][0] = true;
	priority_queue<Corn> checkPos;
	vector<pair<int, int> > checkDir;
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			cin >> graph[i][j];
		}
	}

	// 가장자리
	while (!checkInitPos.empty())
	{
		pair<int, int> standardPos = checkInitPos.front();
		checkInitPos.pop();

		for (int i = 0; i < 4; i++)
		{
			int checkI = standardPos.first + checkDir[i].first;
			int checkJ = standardPos.second + checkDir[i].second;

			if (checkI < 0 || checkJ < 0 || checkI >= n + 2 || checkJ >= m + 2) continue;
			if (vis[checkI][checkJ]) continue;

			if (graph[checkI][checkJ] == 0) checkInitPos.push({ checkI, checkJ });
			if (graph[checkI][checkJ] > 0) checkPos.push(Corn(graph[checkI][checkJ], { checkI, checkJ }));
			vis[checkI][checkJ] = true;
		}
	}

	//while (!checkPos.empty())
	//{
	//	cout << checkPos.top().value << '\n';
	//	checkPos.pop();
	//}

	int k;
	cin >> k;

	// 각 스텝
	while (k--)
	{
		pair<int, int> standardPos = checkPos.top().pos;
		checkPos.pop();
		cout << standardPos.first << ' ' << standardPos.second << '\n';

		for (int i = 0; i < 4; i++)
		{
			int checkI = standardPos.first + checkDir[i].first;
			int checkJ = standardPos.second + checkDir[i].second;

			if (checkI < 1 || checkJ < 1 || checkI >= n + 1 || checkJ >= m + 1) continue;
			if (vis[checkI][checkJ]) continue;

			checkPos.push(Corn(graph[checkI][checkJ], { checkI, checkJ }));
			vis[checkI][checkJ] = true;
		}
	}

	return 0;
}
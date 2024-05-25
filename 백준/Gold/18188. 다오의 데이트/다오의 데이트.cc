#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 다오의 데이트
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m;
	cin >> n >> m;

	vector<vector<char> > graph(n, vector<char>(m));
	queue<pair<pair<int, int>, pair<int, string> > > checkPos; // 위치, 스텝, 경로
	map<char, pair<int, int> > checkDir;
	checkDir['W'] = { -1, 0 };
	checkDir['S'] = { 1, 0 };
	checkDir['A'] = { 0, -1 };
	checkDir['D'] = { 0, 1 };

	// 그래프
	string inputString;
	pair<int, int> dizPos;
	for (int i = 0; i < n; i++)
	{
		cin >> inputString;
		for (int j = 0; j < m; j++)
		{
			graph[i][j] = inputString[j];
			if (graph[i][j] == 'D') checkPos.push({ { i, j }, {0, ""} });
			else if (graph[i][j] == 'Z') dizPos = { i, j };
		}
	}

	// 명령
	int k;
	cin >> k;
	vector<pair<char, char> > order(k);
	for (int i = 0; i < k; i++) cin >> order[i].first >> order[i].second;

	// BFS
	while (!checkPos.empty())
	{
		pair<pair<int, int>, pair<int, string> > standardPos = checkPos.front();
		checkPos.pop();

		// 디지니 만나면 경로 출력
		if (standardPos.first.first == dizPos.first && standardPos.first.second == dizPos.second)
		{
			cout << "YES" << '\n' << standardPos.second.second << '\n';
			return 0;
		}

		// 현재 스텝이 최대 명령이면 그만
		if (standardPos.second.first == k) continue;

		// 현재 스텝 첫 명령
		int checkI = standardPos.first.first + checkDir[order[standardPos.second.first].first].first;
		int checkJ = standardPos.first.second + checkDir[order[standardPos.second.first].first].second;
		bool isFirst = true;

		if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m) isFirst = false;
		if (isFirst && graph[checkI][checkJ] == '@') isFirst = false;

		if (isFirst) checkPos.push({ { checkI, checkJ }, { standardPos.second.first + 1,standardPos.second.second + order[standardPos.second.first].first } });

		// 현재 스텝 두번째 명령
		checkI = standardPos.first.first + checkDir[order[standardPos.second.first].second].first;
		checkJ = standardPos.first.second + checkDir[order[standardPos.second.first].second].second;

		if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m) continue;
		if (graph[checkI][checkJ] == '@') continue;

		checkPos.push({ { checkI, checkJ }, { standardPos.second.first + 1,standardPos.second.second + order[standardPos.second.first].second } });
	}

	cout << "NO" << '\n';

	return 0;
}
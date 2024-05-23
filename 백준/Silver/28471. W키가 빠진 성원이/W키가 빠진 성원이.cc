#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// W키가 빠진 성원이
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 상 빠진 7방향 BFS
	// 도착 부터 BFS 돌려서 빈 공간 만나면 카운팅 => F 부터 돌리므로 하 방향 뺌

	int n; // N 3
	cin >> n;
	vector<vector<char> > graph(n, vector<char>(n));
	vector<vector<bool> > vis(n, vector<bool>(n));
	queue<pair<int, int> > checkPos;
	vector<pair<int, int> > checkDir;
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });
	checkDir.push_back({ -1, -1 });
	checkDir.push_back({ 1, -1 });
	checkDir.push_back({ -1, 1 });
	checkDir.push_back({ 1, 1 });

	string inputString;
	for (int i = 0; i < n; i++)
	{
		cin >> inputString;
		for (int j = 0; j < n; j++)
		{
			graph[i][j] = inputString[j];
			if (graph[i][j] == 'F')
			{
				checkPos.push({ i, j });
				vis[i][j] = true;
			}
		}
	}

	int emptyPosCnt = 0;

	while (!checkPos.empty())
	{
		pair<int, int> standardPos = checkPos.front();
		checkPos.pop();

		for (int i = 0; i < 7; i++)
		{
			int checkI = standardPos.first + checkDir[i].first;
			int checkJ = standardPos.second + checkDir[i].second;

			if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= n) continue;
			if (vis[checkI][checkJ]) continue;
			if (graph[checkI][checkJ] == '#') continue;

			checkPos.push({ checkI, checkJ });
			vis[checkI][checkJ] = true;
			emptyPosCnt++;
		}
	}

	cout << emptyPosCnt << '\n';

	return 0;
}
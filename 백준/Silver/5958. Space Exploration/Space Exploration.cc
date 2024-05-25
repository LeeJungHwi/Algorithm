#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// Space Exploration
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n;
	cin >> n;

	vector<vector<int> > graph(n, vector<int>(n));
	queue<pair<int, int> > checkPos;
	vector<pair<int, int> > checkDir;
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	// 벽 -1 치환
	string inputString;
	for (int i = 0; i < n; i++)
	{
		cin >> inputString;
		for (int j = 0; j < n; j++) if (inputString[j] == '.') graph[i][j] = -1;
	}

	// 현재 라벨
	int curLabel = 0;

	// BFS 라벨링
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] == 0)
			{
				// Label : 1 => 2 => ...
				checkPos.push({ i, j });
				graph[i][j] = ++curLabel;

				while (!checkPos.empty())
				{
					pair<int, int> standardPos = checkPos.front();
					checkPos.pop();

					for (int k = 0; k < 4; k++)
					{
						int checkI = standardPos.first + checkDir[k].first;
						int checkJ = standardPos.second + checkDir[k].second;

						if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= n) continue;
						if (graph[checkI][checkJ] != 0) continue;

						checkPos.push({ checkI, checkJ });
						graph[checkI][checkJ] = curLabel;
					}
				}
			}
		}
	}

	cout << curLabel << '\n';

	return 0;
}
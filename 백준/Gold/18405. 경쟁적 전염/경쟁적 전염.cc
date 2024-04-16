#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 경쟁적 전염
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, k; // N, K 3, 3
	cin >> n >> k;

	map<int, vector<pair<int, int> > > virus; // (바이러스번호, 바이러스위치들) 맵핑
	vector<vector<int> > graph(n, vector<int>(n)); // 그래프
	vector<vector<bool> > vis(n, vector<bool>(n)); // 그래프
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	//	1 0 2
	//	0 0 0
	//	3 0 0
	// (바이러스번호, 바이러스위치들) 맵핑하고 방문체크
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];

			if (graph[i][j] != 0)
			{
				virus[graph[i][j]].push_back({i, j});
				vis[i][j] = true;
			}
		}
	}

	int time; // 2
	cin >> time;

	pair<int, int> xyPos; // (3, 2)
	cin >> xyPos.first >> xyPos.second;

	// 2 초후 종료
	while (time--)
	{
		map<int, vector<pair<int, int> > > tempVirus; // BFS 끝나고 virus 갱신할 맵

		// 맵 돌면서
		for (auto it = virus.begin(); it != virus.end(); it++)
		{
			for (int i = 0; i < it->second.size(); i++)
			{
				// 기준위치 꺼냄
				pair<int, int> standardPos = it->second[i];

				// 상하좌우
				for (int j = 0; j < 4; j++)
				{
					// 체크 할 위치
					int checkI = it->second[i].first + checkDir[j].first;
					int checkJ = it->second[i].second + checkDir[j].second;

					// 경계체크
					if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= n)
					{
						continue;
					}

					// 방문체크
					if (vis[checkI][checkJ])
					{
						continue;
					}

					// 바이러스저장, 바이러스맵핑, 방문체크
					graph[checkI][checkJ] = it->first;
					tempVirus[it->first].push_back({ checkI, checkJ });
					vis[checkI][checkJ] = true;
				}
			}
		}

		// 다음 BFS를 위해 갱신
		virus = tempVirus;
	}

	//for (auto a : graph)
	//{
	//	for (auto b : a)
	//	{
	//		cout << b << ' ';
	//	}
	//	cout << '\n';
	//}

	cout << graph[xyPos.first - 1][xyPos.second - 1] << '\n';

	return 0;
}
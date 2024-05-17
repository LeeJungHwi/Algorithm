#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 전쟁 - 전투
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int m, n; // M, N 5, 5
	cin >> m >> n;

	vector<vector<char> > graph(n, vector<char>(m)); // 그래프
	vector<vector<bool> > vis(n, vector<bool>(m)); // 방문체크
	queue<pair<int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	// 그래프 초기화
	string inputString;
	for (int i = 0; i < n; i++)
	{
		cin >> inputString;
		for (int j = 0; j < m; j++)
		{
			graph[i][j] = inputString[j];
		}
	}

	// 그래프 돌면서 BFS 돌림

	int teamPower = 0;
	int enemyPower = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (vis[i][j]) continue; // 방문한 곳이면 리턴

			checkPos.push({ i, j });
			vis[i][j] = true;
			char standardColor = graph[i][j];
			int soldierCnt = 1;

			// 큐가 빌때까지
			while (!checkPos.empty())
			{
				// 기준위치 꺼냄
				pair<int, int> standardPos = checkPos.front();
				checkPos.pop();

				// 상하좌우
				for (int k = 0; k < 4; k++)
				{
					// 체크 할 위치
					int checkI = standardPos.first + checkDir[k].first;
					int checkJ = standardPos.second + checkDir[k].second;

					// 경계체크
					if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m) continue;

					// 방문체크
					if (vis[checkI][checkJ]) continue;

					// 다른 팀 병사 체크
					if (graph[checkI][checkJ] != standardColor) continue;

					// 큐에저장, 방문체크, 병사 수 카운팅
					checkPos.push({ checkI, checkJ });
					vis[checkI][checkJ] = true;
					soldierCnt++;
				}
			}

			// 위력 누적
			if (standardColor == 'W') teamPower += soldierCnt * soldierCnt;
			else if (standardColor == 'B') enemyPower += soldierCnt * soldierCnt;
		}
	}
	
	cout << teamPower << ' ' << enemyPower << '\n';

	return 0;
}
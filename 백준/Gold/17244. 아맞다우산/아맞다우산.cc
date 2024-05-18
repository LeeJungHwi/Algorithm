#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

int m, n; // M, N 7, 6
vector<vector<char> > graph(50, vector<char>(50)); // 그래프
vector<vector<int> > dis(50, vector<int>(50)); // 거리
queue<pair<int, int> > checkPos; // 체크 할 위치
vector<pair<int, int> > checkDir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // 상하좌우
pair<int, int> startPos, endPos; // 시작위치, 도착위치

vector<pair<int, int> > objectPos; // 각 물건 위치
vector<int> order; // 물건 챙기는 순서
vector<bool> vis(5); // 물건 선택 체크
int minDis = 2147000000; // 모든 물건을 가지고 탈출하는 최단거리

// 1.DFS로 가지러 갈 물건 순서 정하기
void DFS(int L)
{
	if (L == objectPos.size())
	{
		// 2.BFS로 순서대로 물건을 가지고 탈출하는 최단거리 갱신

		// 마지막 도착위치로 탈출위치 추가
		objectPos.push_back(endPos);
		order.push_back(order.size());

		// 현재 물건 챙기는 순서로 갔을 때 거리 합
		int sumDis = 0; 

		// startPos 부터
		checkPos.push(startPos);
		dis[startPos.first][startPos.second] = 1;

		// startPos => 물건 0 => 물건 1 => ... => endPos
		for (int i = 0; i < order.size(); i++)
		{
			// 큐가 빌때까지
			while (!checkPos.empty())
			{
				// 기준위치 꺼냄
				pair<int, int> standardPos = checkPos.front();
				checkPos.pop();

				// 현재 목표 물건이면 거리 누적하고 break
				if (standardPos.first == objectPos[order[i]].first && standardPos.second == objectPos[order[i]].second)
				{
					sumDis += dis[standardPos.first][standardPos.second] - 1;
					break;
				}

				// 상하좌우
				for (int j = 0; j < 4; j++)
				{
					// 체크 할 위치
					int checkI = standardPos.first + checkDir[j].first;
					int checkJ = standardPos.second + checkDir[j].second;

					// 경계체크
					if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m) continue;

					// 방문체크(거리로)
					if (dis[checkI][checkJ] > 0) continue;

					// 벽체크
					if (graph[checkI][checkJ] == '#') continue;

					// 큐에저장, 거리저장
					checkPos.push({ checkI, checkJ });
					dis[checkI][checkJ] = dis[standardPos.first][standardPos.second] + 1;
				}
			}

			// 큐 초기화
			while (!checkPos.empty()) checkPos.pop();

			// 거리 초기화
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < m; k++)
				{
					dis[j][k] = 0;
				}
			}

			// 다음 물건 부터 BFS
			// 마지막 물건 => endPos는 ㄴ
			if (i != order.size() - 1)
			{
				checkPos.push(objectPos[order[i]]);
				dis[objectPos[order[i]].first][objectPos[order[i]].second] = 1;
			}
		}

		// 모든 물건을 가지고 탈출하는 최단거리 갱신
		minDis = min(minDis, sumDis);

		// 탈출위치 제거
		order.pop_back();
		objectPos.pop_back();
	}
	else
	{
		// 물건 순서
		for (int i = 0; i < objectPos.size(); i++)
		{
			if (!vis[i])
			{
				vis[i] = true;
				order.push_back(i);
				DFS(L + 1);
				order.pop_back();
				vis[i] = false;
			}
		}
	}
}

// 아맞다우산
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> m >> n;

	// 그래프 초기화
	// 시작위치 및 도착위치 저장
	// 물건 위치 저장
	string inputString;
	for (int i = 0; i < n; i++)
	{
		cin >> inputString;
		for (int j = 0; j < m; j++)
		{
			graph[i][j] = inputString[j];
			if (graph[i][j] == 'S') startPos = { i, j };
			else if (graph[i][j] == 'E') endPos = { i, j };
			else if (graph[i][j] == 'X') objectPos.push_back({ i, j });
		}
	}

	// 0.물건 수가 0개면 S => E 최단거리 출력
	// 1.DFS로 가지러 갈 물건 순서 정하기
	// 2.BFS로 순서대로 물건을 가지고 탈출하는 최단거리 갱신

	// 0.물건 수가 0개면 S => E 최단거리 출력
	if (objectPos.empty())
	{
		checkPos.push(startPos);
		dis[startPos.first][startPos.second] = 1;

		// 큐가 빌때까지
		while (!checkPos.empty())
		{
			// 기준위치 꺼냄
			pair<int, int> standardPos = checkPos.front();
			checkPos.pop();

			// 상하좌우
			for (int i = 0; i < 4; i++)
			{
				// 체크 할 위치
				int checkI = standardPos.first + checkDir[i].first;
				int checkJ = standardPos.second + checkDir[i].second;

				// 경계체크
				if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m) continue;

				// 방문체크(거리로)
				if (dis[checkI][checkJ] > 0) continue;

				// 벽체크
				if (graph[checkI][checkJ] == '#') continue;

				// 큐에저장, 거리저장
				checkPos.push({ checkI, checkJ });
				dis[checkI][checkJ] = dis[standardPos.first][standardPos.second] + 1;
			}
		}

		cout << dis[endPos.first][endPos.second] - 1 << '\n';

		return 0;
	}

	// 1.DFS로 가지러 갈 물건 순서 정하기
	// 2.BFS로 순서대로 물건을 가지고 탈출하는 최단거리 갱신
	DFS(0);

	cout << minDis << '\n';

	return 0;
}
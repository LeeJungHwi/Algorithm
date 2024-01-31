#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

// 미로의 최단거리 통로
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream cin;
	cin.open("input.txt");

	vector<vector<int> > graph(7, vector<int>(7)); // 그래프
	vector<vector<int> > dis(7, vector<int>(7)); // 거리
	vector<pair<int, int> > checkDir; // 상 하 좌 우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });
	queue<pair<int, int> > standardPos; // 기준위치

	//	0 0 0 0 0 0 0
	//	0 1 1 1 1 1 0
	//	0 0 0 1 0 0 0
	//	1 1 0 1 0 1 1
	//	1 1 0 1 0 0 0
	//	1 0 0 0 1 0 0
	//	1 0 1 0 0 0 0
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cin >> graph[i][j];
		}
	}

	// 첫 지점 초기화
	standardPos.push({ 0, 0 });
	dis[0][0] = 1; // 출력할때 1 빼줌

	// BFS
	while (!standardPos.empty()) // 큐가 비면 종료
	{
		// 기준 위치 꺼냄
		pair<int, int> curPos = standardPos.front();
		standardPos.pop();

		// 상 하 좌 우
		for (int i = 0; i < 4; i++)
		{
			int checkI = curPos.first + checkDir[i].first;
			int checkJ = curPos.second + checkDir[i].second;

			// 경계체크
			if (checkI < 0 || checkJ < 0 || checkI >= 7 || checkJ >= 7)
			{
				continue;
			}

			// 벽 체크
			if (graph[checkI][checkJ] == 1)
			{
				continue;
			}

			// 거리 할당 체크 : 거리가 할당되었다는건 이미 방문한 상태라는거
			if (dis[checkI][checkJ] != 0)
			{
				continue;
			}

			// 거리 증가
			dis[checkI][checkJ] = dis[curPos.first][curPos.second] + 1;

			// 큐에 저장
			standardPos.push({ checkI, checkJ });
		}
	}
	
	if (dis[6][6] == 0) // 도달할수없으면 -1 출력
	{
		cout << -1 << '\n';

		return 0;
	}

	cout << dis[6][6] - 1 << '\n'; // BFS는 거리가 저장되는 순간 최단거리

	return 0;
}
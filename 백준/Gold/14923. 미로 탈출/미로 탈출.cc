#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <fstream>
using namespace std;

// 미로 탈출
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 5, 6
	cin >> n >> m;

	int iPos, jPos;
	cin >> iPos >> jPos;
	tuple<int, int, int> hPos = make_tuple(iPos, jPos, 0); // 홍익 위치 1, 1, 0(벽 안 부순 상태)
	pair<int, int> ePos; // 탈출 위치 5, 6
	cin >> ePos.first >> ePos.second;

	vector<vector<int> > graph(n + 1, vector<int>(m + 1)); // 그래프
	vector<vector<vector<int> > > dis(n + 1, vector<vector<int> >(m + 1, vector<int>(2))); // 거리
	queue<tuple<int, int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	//	0 1 1 1 0 0
	//	0 1 1 0 0 0
	//	0 1 0 0 1 0
	//	0 1 0 0 1 0
	//	0 0 0 1 1 0
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			cin >> graph[i][j];
		}
	}

	// 홍익이 위치부터 BFS 돌리기
	// 경계체크, 방문체크(거리로)
	// 벽체크 : 벽을 부순적이 없다면 부순상태로 변환하고 큐에 저장, 거리증가 벽을 부순적이 있다면 continue
	// 빈칸체크 : 큐에 저장, 거리증가
	// BFS가 종료될때까지 도착못하면 -1 출력 BFS 내에서 타출위치에 도착하면 거리 -1 출력

	checkPos.push(hPos);
	dis[get<0>(hPos)][get<1>(hPos)][get<2>(hPos)] = 1;

	while (!checkPos.empty()) // 큐가 빌때까지
	{
		// 기준위치 꺼냄
		tuple<int, int, int> standardPos = checkPos.front();
		checkPos.pop();

		// BFS 내에서 타출위치에 도착하면 거리 -1 출력
		if (get<0>(standardPos) == ePos.first && get<1>(standardPos) == ePos.second)
		{
			cout << dis[ePos.first][ePos.second][get<2>(standardPos)] - 1 << '\n';

			return 0;
		}

		// 상하좌우
		for (int i = 0; i < 4; i++)
		{
			// 체크 할 위치
			int checkI = get<0>(standardPos) + checkDir[i].first;
			int checkJ = get<1>(standardPos) + checkDir[i].second;
			int checkS = get<2>(standardPos);

			// 경계체크
			if (checkI < 1 || checkJ < 1 || checkI >= n + 1 || checkJ >= m + 1)
			{
				continue;
			}

			// 방문체크(거리로)
			if (dis[checkI][checkJ][checkS] > 0)
			{
				continue;
			}

			// 벽체크
			// 벽을 부순적이 없다면 부순상태로 변환하고 큐에 저장 거리증가 continue
			// 벽을 부순적이 있다면 continue
			if (graph[checkI][checkJ] == 1)
			{
				if (checkS == 0)
				{
					checkPos.push({ checkI, checkJ, checkS + 1 });
					dis[checkI][checkJ][checkS + 1] = dis[get<0>(standardPos)][get<1>(standardPos)][checkS] + 1;
				}

				continue;
			}

			// 빈칸체크 : 큐에 저장, 거리증가
			checkPos.push({ checkI, checkJ, checkS });
			dis[checkI][checkJ][checkS] = dis[get<0>(standardPos)][get<1>(standardPos)][checkS] + 1;
		}
	}

	// BFS가 종료될때까지 도착못하면 -1 출력
	cout << -1 << '\n';

	return 0;
}

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <fstream>
//using namespace std;
//
//// 미로 탈출
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	//ifstream cin;
//	//cin.open("input.txt");
//
//	int n, m; // N, M 5, 6
//	cin >> n >> m;
//
//	pair<int, int> hPos; // 홍익이 위치 1, 1
//	pair<int, int> ePos; // 탈출 위치 5, 6
//
//	cin >> hPos.first >> hPos.second;
//	cin >> ePos.first >> ePos.second;
//
//	vector<vector<int> > graph(n + 1, vector<int>(m + 1)); // 그래프
//	vector<pair<int, int> > wallPos; // 벽 위치 저장
//	queue<pair<int, int> > checkPos; // 체크 할 위치
//	vector<pair<int, int> > checkDir; // 상하좌우
//	checkDir.push_back({ -1, 0 });
//	checkDir.push_back({ 1, 0 });
//	checkDir.push_back({ 0, -1 });
//	checkDir.push_back({ 0, 1 });
//
//	//	0 1 1 1 0 0
//	//	0 1 1 0 0 0
//	//	0 1 0 0 1 0
//	//	0 1 0 0 1 0
//	//	0 0 0 1 1 0
//	// 벽 위치 저장
//	for (int i = 1; i < n + 1; i++)
//	{
//		for (int j = 1; j < m + 1; j++)
//		{
//			cin >> graph[i][j];
//
//			if (graph[i][j] == 1)
//			{
//				wallPos.push_back({ i, j });
//			}
//		}
//	}
//
//	int minDis = 2147000000; // 최단시간
//
//	for (int i = 0; i < wallPos.size(); i++)
//	{
//		vector<vector<int> > dis(n + 1, vector<int>(m + 1)); // 거리
//
//		// 벽 하나를 빈 칸으로
//		graph[wallPos[i].first][wallPos[i].second] = 0;
//
//		// 홍익이 위치부터 BFS
//		checkPos.push(hPos);
//		dis[hPos.first][hPos.second] = 1;
//
//		while (!checkPos.empty()) // 큐가 빌때까지
//		{
//			// 기준위치 꺼냄
//			pair<int, int> standardPos = checkPos.front();
//			checkPos.pop();
//
//			// 상하좌우
//			for (int j = 0; j < 4; j++)
//			{
//				// 체크 할 위치
//				int checkI = standardPos.first + checkDir[j].first;
//				int checkJ = standardPos.second + checkDir[j].second;
//
//				// 경계체크
//				if (checkI < 1 || checkJ < 1 || checkI >= n + 1 || checkJ >= m + 1)
//				{
//					continue;
//				}
//
//				// 방문체크(거리로)
//				if (dis[checkI][checkJ] > 0)
//				{
//					continue;
//				}
//
//				// 벽체크
//				if (graph[checkI][checkJ] == 1)
//				{
//					continue;
//				}
//
//				// 큐에 저장 후 거리 저장
//				checkPos.push({ checkI, checkJ });
//				dis[checkI][checkJ] = dis[standardPos.first][standardPos.second] + 1;
//			}
//		}
//
//		// 탈출 할 수 있는 경우만 최단시간 갱신
//		if (dis[ePos.first][ePos.second] > 0)
//		{
//			minDis = min(minDis, dis[ePos.first][ePos.second]);
//		}
//
//		// 빈 칸으로 된 벽 다시 벽으로
//		graph[wallPos[i].first][wallPos[i].second] = 1;
//	}
//
//	// 최단거리가 갱신되지않았으면 탈출할수없음
//	if (minDis == 2147000000)
//	{
//		cout << -1 << '\n';
//
//		return 0;
//	}
//
//	// 거리 1로 시작했으므로 1 빼줌
//	cout << minDis - 1 << '\n';
//
//	return 0;
//}
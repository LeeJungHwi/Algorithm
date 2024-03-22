#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <tuple>
#include <fstream>
using namespace std;

int dis[1001][1001][11][2];

// 벽 부수고 이동하기 3
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m, k; // N, M, K 1, 4, 1
	cin >> n >> m >> k;

	tuple<int, int, int, int> startPos = make_tuple(1, 1, 0, 0); // 시작 위치 1, 1, 0(벽 안 부순 상태), 0(낮)
	pair<int, int> endPos = { n , m }; // 탈출 위치 n, m

	vector<vector<char> > graph(n + 1, vector<char>(m + 1)); // 그래프
	//vector<vector<vector<vector<int> > > > dis(n + 1, vector<vector<vector<int> > >(m + 1, vector<vector<int> >(k + 1, vector<int>(2)))); // 거리
	queue<tuple<int, int, int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	//	0010

	string inputString; // 입력문자열

	for (int i = 1; i < n + 1; i++)
	{
		cin >> inputString;

		for (int j = 1; j < m + 1; j++)
		{
			graph[i][j] = inputString[j - 1];
		}
	}

	// 시작 위치부터 BFS 돌리기
	// 경계체크, 방문체크(거리로)
	// 벽체크 : 벽을 아직 k번 부순상태가 아니면서 낮인경우만 처음 방문이면 처리
	// 빈칸체크 : 처음 방문이면 처리
	// 밤체크 : 밤인 경우 처음 방문이면 처리
	// BFS가 종료될때까지 도착못하면 -1 출력 BFS 내에서 타출위치에 도착하면 거리 출력

	checkPos.push(startPos);
	dis[get<0>(startPos)][get<1>(startPos)][get<2>(startPos)][get<3>(startPos)] = 1;

	while (!checkPos.empty()) // 큐가 빌때까지
	{
		// 기준위치 꺼냄
		tuple<int, int, int, int> standardPos = checkPos.front();
		checkPos.pop();

		// BFS 내에서 타출위치에 도착하면 거리 출력
		if (get<0>(standardPos) == endPos.first && get<1>(standardPos) == endPos.second)
		{
			cout << dis[endPos.first][endPos.second][get<2>(standardPos)][get<3>(standardPos)] << '\n';

			return 0;
		}

		// 상하좌우
		for (int i = 0; i < 4; i++)
		{
			// 체크 할 위치
			int checkI = get<0>(standardPos) + checkDir[i].first;
			int checkJ = get<1>(standardPos) + checkDir[i].second;
			int checkS = get<2>(standardPos);
			int checkT = get<3>(standardPos);

			// 경계체크
			if (checkI < 1 || checkJ < 1 || checkI >= n + 1 || checkJ >= m + 1)
			{
				continue;
			}

			// 방문체크(거리로)
			if (dis[checkI][checkJ][checkS][checkT] > 0)
			{
				continue;
			}

			// 벽이면서 낮인경우 체크
			// 벽을 아직 k번 부순상태가 아니면서
			// 낮이면 처음방문인지 체크해서 큐에저장 거리증가 낮밤전환
			// 밤일때도 큐에 추가하면 메모리초과나므로 여기서 처리 안 함
			if (graph[checkI][checkJ] == '1')
			{
				if (checkS < k) // 벽을 k번 부순게 아니면
				{
					if (checkT == 0) // 낮이면
					{
						if (dis[checkI][checkJ][checkS + 1][!checkT] == 0) // 처음 방문이면
						{
							checkPos.push({ checkI, checkJ, checkS + 1, !checkT });
							dis[checkI][checkJ][checkS + 1][!checkT] = dis[get<0>(standardPos)][get<1>(standardPos)][checkS][checkT] + 1;
						}
					}
				}

				continue;
			}

			// 빈칸체크
			// 처음 방문이면 큐에저장, 거리증가, 낮밤전환
			if (graph[checkI][checkJ] == '0')
			{
				if (dis[checkI][checkJ][checkS][!checkT] == 0) // 처음 방문이면
				{
					checkPos.push({ checkI, checkJ, checkS, !checkT });
					dis[checkI][checkJ][checkS][!checkT] = dis[get<0>(standardPos)][get<1>(standardPos)][checkS][checkT] + 1;
				}
			}
		}

		// 여기서 밤 체크(메모리초과)
		if (get<3>(standardPos)) // 밤이면
		{
			if (dis[get<0>(standardPos)][get<1>(standardPos)][get<2>(standardPos)][!get<3>(standardPos)] == 0) // 처음 방문이면
			{
				checkPos.push({ get<0>(standardPos), get<1>(standardPos), get<2>(standardPos), !get<3>(standardPos) });
				dis[get<0>(standardPos)][get<1>(standardPos)][get<2>(standardPos)][!get<3>(standardPos)] = dis[get<0>(standardPos)][get<1>(standardPos)][get<2>(standardPos)][get<3>(standardPos)] + 1;
			}
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
//#include <string>
//#include <map>
//#include <tuple>
//#include <fstream>
//using namespace std;
//
//// 벽 부수고 이동하기 3
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	//ifstream cin;
//	//cin.open("input.txt");
//
//	int n, m, k; // N, M, K 1, 4, 1
//	cin >> n >> m >> k;
//
//	tuple<int, int, int, int> startPos = make_tuple(1, 1, 0, 0); // 시작 위치 1, 1, 0(벽 안 부순 상태), 0(낮)
//	pair<int, int> endPos = { n , m }; // 탈출 위치 n, m
//
//	vector<vector<char> > graph(n + 1, vector<char>(m + 1)); // 그래프
//	vector<vector<vector<vector<int> > > > dis(n + 1, vector<vector<vector<int> > >(m + 1, vector<vector<int> >(k + 1, vector<int>(2)))); // 거리
//	queue<tuple<int, int, int, int> > checkPos; // 체크 할 위치
//	vector<pair<int, int> > checkDir; // 상하좌우
//	checkDir.push_back({ -1, 0 });
//	checkDir.push_back({ 1, 0 });
//	checkDir.push_back({ 0, -1 });
//	checkDir.push_back({ 0, 1 });
//
//	//	0010
//
//	string inputString; // 입력문자열
//
//	for (int i = 1; i < n + 1; i++)
//	{
//		cin >> inputString;
//
//		for (int j = 1; j < m + 1; j++)
//		{
//			graph[i][j] = inputString[j - 1];
//		}
//	}
//
//	// 시작 위치부터 BFS 돌리기
//	// 경계체크, 방문체크(거리로)
//	// 벽체크 : 벽을 아직 k번 부순상태가 아니면서 낮이면 처음방문인지 체크해서 큐에저장 거리증가 낮밤전환 밤이면 이동하지않고 낮밤 상태만 변경해서 큐에저장 거리증가 낮밤전환
//	// 빈칸체크 : 처음 방문이면 큐에저장, 거리증가, 낮밤전환
//	// BFS가 종료될때까지 도착못하면 -1 출력 BFS 내에서 타출위치에 도착하면 거리 출력
//
//	checkPos.push(startPos);
//	dis[get<0>(startPos)][get<1>(startPos)][get<2>(startPos)][get<3>(startPos)] = 1;
//
//	while (!checkPos.empty()) // 큐가 빌때까지
//	{
//		// 기준위치 꺼냄
//		tuple<int, int, int, int> standardPos = checkPos.front();
//		checkPos.pop();
//
//		// BFS 내에서 타출위치에 도착하면 거리 출력
//		if (get<0>(standardPos) == endPos.first && get<1>(standardPos) == endPos.second)
//		{
//			cout << dis[endPos.first][endPos.second][get<2>(standardPos)][get<3>(standardPos)] << '\n';
//
//			return 0;
//		}
//
//		// 상하좌우
//		for (int i = 0; i < 4; i++)
//		{
//			// 체크 할 위치
//			int checkI = get<0>(standardPos) + checkDir[i].first;
//			int checkJ = get<1>(standardPos) + checkDir[i].second;
//			int checkS = get<2>(standardPos);
//			int checkT = get<3>(standardPos);
//
//			// 경계체크
//			if (checkI < 1 || checkJ < 1 || checkI >= n + 1 || checkJ >= m + 1)
//			{
//				continue;
//			}
//
//			// 방문체크(거리로)
//			if (dis[checkI][checkJ][checkS][checkT] > 0)
//			{
//				continue;
//			}
//
//			// 벽체크
//			// 벽을 아직 k번 부순상태가 아니면서
//			// 낮이면 처음방문인지 체크해서 큐에저장 거리증가 낮밤전환
//			// 밤이면 이동하지않고 낮밤 상태만 변경해서 큐에저장 거리증가 낮밤전환
//			if (graph[checkI][checkJ] == '1')
//			{
//				if (checkS < k) // 벽을 k번 부순게 아니면
//				{
//					if (checkT == 0) // 낮이면
//					{
//						if (dis[checkI][checkJ][checkS + 1][!checkT] == 0) // 처음 방문이면
//						{
//							checkPos.push({ checkI, checkJ, checkS + 1, !checkT });
//							dis[checkI][checkJ][checkS + 1][!checkT] = dis[get<0>(standardPos)][get<1>(standardPos)][checkS][checkT] + 1;
//						}
//					}
//					else // 밤이면
//					{
//						if (dis[get<0>(standardPos)][get<1>(standardPos)][checkS][!checkT] == 0) // 처음 방문이면
//						{
//							checkPos.push({ get<0>(standardPos), get<1>(standardPos), checkS, !checkT });
//							dis[get<0>(standardPos)][get<1>(standardPos)][checkS][!checkT] = dis[get<0>(standardPos)][get<1>(standardPos)][checkS][checkT] + 1;
//						}
//					}
//				}
//
//				continue;
//			}
//
//			// 빈칸체크
//			// 처음 방문이면 큐에저장, 거리증가, 낮밤전환
//			if (graph[checkI][checkJ] == '0')
//			{
//				if (dis[checkI][checkJ][checkS][!checkT] == 0) // 처음 방문이면
//				{
//					checkPos.push({ checkI, checkJ, checkS, !checkT });
//					dis[checkI][checkJ][checkS][!checkT] = dis[get<0>(standardPos)][get<1>(standardPos)][checkS][checkT] + 1;
//				}
//			}
//		}
//	}
//
//	// BFS가 종료될때까지 도착못하면 -1 출력
//	cout << -1 << '\n';
//
//	return 0;
//}
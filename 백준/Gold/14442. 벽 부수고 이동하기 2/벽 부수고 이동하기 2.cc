#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <tuple>
#include <fstream>
using namespace std;

// 벽 부수고 이동하기 2
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m, k; // N, M, K 6, 4, 2
	cin >> n >> m >> k;

	tuple<int, int, int> startPos = make_tuple(1, 1, 0); // 시작 위치 1, 1, 0(벽 안 부순 상태)
	pair<int, int> endPos = { n , m }; // 탈출 위치 n, m

	vector<vector<char> > graph(n + 1, vector<char>(m + 1)); // 그래프
	vector<vector<vector<int> > > dis(n + 1, vector<vector<int> >(m + 1, vector<int>(k + 1))); // 거리
	queue<tuple<int, int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	//	0100
	//	1110
	//	1000
	//	0000
	//	0111
	//	0000

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
	// 벽체크 : 벽을 k번 부순게 아니면 부순상태로 변환하고 큐에 저장, 거리증가 벽을 이미 k번 부셨으면 continue
	// 빈칸체크 : 큐에 저장, 거리증가
	// BFS가 종료될때까지 도착못하면 -1 출력 BFS 내에서 타출위치에 도착하면 거리 출력

	checkPos.push(startPos);
	dis[get<0>(startPos)][get<1>(startPos)][get<2>(startPos)] = 1;

	while (!checkPos.empty()) // 큐가 빌때까지
	{
		// 기준위치 꺼냄
		tuple<int, int, int> standardPos = checkPos.front();
		checkPos.pop();

		// BFS 내에서 타출위치에 도착하면 거리 출력
		if (get<0>(standardPos) == endPos.first && get<1>(standardPos) == endPos.second)
		{
			cout << dis[endPos.first][endPos.second][get<2>(standardPos)] << '\n';

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
			// 벽을 k번 부순게 아니면서 처음방문이면 부순상태로 변환하고 큐에 저장, 거리증가
			// 벽을 이미 k번 부셨으면 continue
			if (graph[checkI][checkJ] == '1')
			{
				if (checkS < k)
				{
					if (dis[checkI][checkJ][checkS + 1] == 0)
					{
						checkPos.push({ checkI, checkJ, checkS + 1 });
						dis[checkI][checkJ][checkS + 1] = dis[get<0>(standardPos)][get<1>(standardPos)][checkS] + 1;
					}
				}

				continue;
			}

			// 빈칸체크
			// 처음방문이면 큐에저장, 거리증가
			if (dis[checkI][checkJ][checkS] == 0)
			{
				checkPos.push({ checkI, checkJ, checkS });
				dis[checkI][checkJ][checkS] = dis[get<0>(standardPos)][get<1>(standardPos)][checkS] + 1;
			}
		}
	}

	// BFS가 종료될때까지 도착못하면 -1 출력
	cout << -1 << '\n';

	return 0;
}
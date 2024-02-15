#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

// 구슬 탈출
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 5, 5
	cin >> n >> m;

	// 구멍 하나가 뚤린 직사각형 보드에 빨간 구슬과 파란 구슬을 하나씩 넣고 빨간 구슬을 구멍을 통해 빼내는 게임
	// 상하좌우로 기울이면 벽을 만날때까지 빨간 구슬과 파란 구슬이 같이 움직임
	// 빨간 구슬만 구멍으로 빠져야 성공(동시에 빠지거나 나중에라도 파란 구슬이 빠지면 실패)
	// 빨간 구슬과 파란 구슬이 동시에 같은 칸에 있을 수 없으므로 앞에 구슬이 있으면 멈춰야함
	// 10번 이하로 기울여서 빨간 구슬을 구멍으로 빼낼수있으면 기울인 횟수 출력 없으면 -1 출력

	vector<vector<char>> graph(n, vector<char>(m)); // 그래프
	vector<vector<vector<vector<bool>>>> vis(graph.size(), vector<vector<vector<bool>>>(graph[0].size(), vector<vector<bool>>(graph.size(), vector<bool>(graph[0].size())))); // 방문체크
	queue<pair<pair<int, int>, pair<int, int> > > checkPos; // 체크 할 위치 (빨간구슬위치쌍, 파란구슬위치쌍)의 쌍 저장
	vector<pair<int, int>> checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });
	pair<int, int> redPos;   // 빨간구슬위치
	pair<int, int> bluePos;  // 파란구슬위치

	string inputString; // 입력문자열

	//#####
	//#..B#
	//#.#.#
	//#RO.#
	//#####
	// 체크 할 위치 저장
	for (int i = 0; i < n; i++)
	{
		cin >> inputString;

		for (int j = 0; j < m; j++)
		{
			graph[i][j] = inputString[j];

			if (graph[i][j] == 'R')
			{
				redPos = { i, j };
			}
			else if (graph[i][j] == 'B')
			{
				bluePos = { i, j };
			}
		}
	}

	// 두 구슬 위치부터 BFS 돌리기
	checkPos.push({ redPos, bluePos });
	vis[redPos.first][redPos.second][bluePos.first][bluePos.second] = true;

	int cnt = 1; // 구슬이 움직인 횟수

	while (!checkPos.empty() && cnt <= 10) // 큐가 비거나 구슬이 움직인 횟수가 10보다 크면 종료
	{
		// 체크 할 위치 개수
		int checkCnt = checkPos.size();

		while (checkCnt != 0) // 체크 할 위치 개수만큼 돌면서
		{
			// 기준위치 꺼냄
			pair<pair<int, int>, pair<int, int>> standardPos = checkPos.front();
			checkPos.pop();

			for (int i = 0; i < 4; i++)
			{
				// 체크 할 두 구슬 위치
				pair<int, int> checkRedPos = standardPos.first;
				pair<int, int> checkBluePos = standardPos.second;

				// 각 구슬의 움직인 횟수
				int redCnt = 0;
				int blueCnt = 0;

				// 빨간 구슬 기울이기
				while (true)
				{
					// 벽체크
					if (graph[checkRedPos.first + checkDir[i].first][checkRedPos.second + checkDir[i].second] == '#')
					{
						break;
					}

					// 구멍체크
					if (graph[checkRedPos.first][checkRedPos.second] == 'O')
					{
						break;
					}

					// 이동 후 이동횟수 증가
					checkRedPos.first += checkDir[i].first;
					checkRedPos.second += checkDir[i].second;
					redCnt++;
				}

				// 파란 구슬 기울이기
				while (true)
				{
					// 벽체크
					if (graph[checkBluePos.first + checkDir[i].first][checkBluePos.second + checkDir[i].second] == '#')
					{
						break;
					}

					// 구멍체크
					if (graph[checkBluePos.first][checkBluePos.second] == 'O')
					{
						break;
					}

					// 이동 후 이동횟수 증가
					checkBluePos.first += checkDir[i].first;
					checkBluePos.second += checkDir[i].second;
					blueCnt++;
				}

				// 파란 구슬이 구멍에 빠지는 경우 체크
				if (graph[checkBluePos.first][checkBluePos.second] == 'O')
				{
					continue;
				}

				// 빨간 구슬이 구멍에 빠지는 경우 기울인 횟수 출력 후 종료
				if (graph[checkRedPos.first][checkRedPos.second] == 'O')
				{
					cout << cnt << '\n';

					return 0;
				}

				// 빨간 구슬과 파란 구슬이 같은 위치에 있는 경우
				if (checkRedPos == checkBluePos)
				{
					// 이동한 거리가 더 많은 구슬을 한 칸 뒤로 이동시킴
					if (redCnt > blueCnt)
					{
						checkRedPos.first -= checkDir[i].first;
						checkRedPos.second -= checkDir[i].second;
					}
					else
					{
						checkBluePos.first -= checkDir[i].first;
						checkBluePos.second -= checkDir[i].second;
					}
				}

				// 빨간 구슬과 파란 구슬의 위치 방문체크
				if (vis[checkRedPos.first][checkRedPos.second][checkBluePos.first][checkBluePos.second])
				{
					continue;
				}

				// 빨간 구슬과 파란 구슬이 초기상태인지 체크
				if (checkRedPos == redPos && checkBluePos == bluePos)
				{
					continue;
				}

				// 큐에 저장 후 방문체크
				checkPos.push({ checkRedPos, checkBluePos });
				vis[checkRedPos.first][checkRedPos.second][checkBluePos.first][checkBluePos.second] = true;
			}

			// 하나의 체크 할 위치 처리한 상태
			checkCnt--;
		}

		// 한스텝 끝나면 구슬이 움직인 횟수 증가
		cnt++;
	}

	// BFS 과정에서 종료되지 않은경우
	// 10번 이내로 빨간 구슬을 구멍에 빼낼 수 없는 경우이므로 -1 출력
	cout << -1 << '\n';

	return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 톰과 제리
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 10
	cin >> n;

	vector<vector<int> > graph(n + 1, vector<int>(n + 1)); // 그래프
	vector<vector<int> > turnCnt(n + 1, vector<int>(n + 1)); // 방향전환 횟수

	//	0 0 0 0 0 0 0 0 0 0
	//	0 1 1 0 0 0 0 1 1 1
	//	0 1 1 0 1 1 0 0 0 0
	//	0 1 1 0 0 1 0 1 1 0
	//	0 0 0 0 0 1 1 1 0 0
	//	0 1 0 0 0 0 0 0 0 0
	//	0 1 1 1 1 0 0 0 1 1
	//	0 1 0 0 0 0 0 0 0 0
	//	0 0 0 0 0 1 1 1 0 0
	//	0 1 1 1 1 0 0 0 0 0
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			cin >> graph[i][j];
		}
	}

	int x, y; // 톰제리 좌표

	cin >> x >> y;
	pair<int, int> tomPos = { x, y }; // 1 1

	cin >> x >> y;
	pair<int, int> jerryPos = { x, y }; // 10 9

	// BFS
	// 톰 위치에서 제리 위치까지 가는데 방향 전환 최소값 찾기
	// 경계나 벽을 만날때까지 한쪽방향으로 가면서 아직 방향전환횟수가 할당되지 않은곳만 기준위치의 방향전환횟수 + 1

	queue<pair<int, int> > checkPos; // 체크할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	checkPos.push({ tomPos.first, tomPos.second }); // 톰 좌표부터 BFS

	while (!checkPos.empty()) // 큐가 빌때까지
	{
		// 기준위치 꺼냄
		pair<int, int> standardPos = checkPos.front();
		checkPos.pop();

		// 상하좌우 체크
		for (int i = 0; i < 4; i++)
		{
			// 체크할 위치
			int checkI = standardPos.first + checkDir[i].first;
			int checkJ = standardPos.second + checkDir[i].second;

			while (true)
			{
				// 경계체크
				if (checkI < 1 || checkJ < 1 || checkI >= n + 1 || checkJ >= n + 1)
				{
					break;
				}

				// 벽체크
				if (graph[checkI][checkJ] == 1)
				{
					break;
				}

				// 길을 만나면 방향전환횟수가 할당되어있는지 체크하고 큐에 저장 후 기준위치의 방향전환횟수 + 1
				if (turnCnt[checkI][checkJ] == 0)
				{
					checkPos.push({ checkI, checkJ });
					turnCnt[checkI][checkJ] = turnCnt[standardPos.first][standardPos.second] + 1;
				}

				// 한쪽방향으로 쭉 나아감
				checkI += checkDir[i].first;
				checkJ += checkDir[i].second;
			}
		}
	}

	// 제리까지가는 방향전환횟수가 할당되어있지않으면 갈수없음
	if (turnCnt[jerryPos.first][jerryPos.second] == 0)
	{
		cout << "-1";

		return 0;
	}

	// 처음 톰 위치에서 직선으로 이동할때는 방향전환이 아닌데 1 증가하므로 1 빼줌
	cout << turnCnt[jerryPos.first][jerryPos.second] - 1;

	return 0;
}
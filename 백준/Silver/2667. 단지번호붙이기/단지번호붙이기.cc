#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

// 단지번호 붙이기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 7
	cin >> n;

	vector<vector<int> > graph(n, vector<int>(n)); // 그래프
	vector<vector<bool> > vis(n, vector<bool>(n)); // 방문체크
	vector<int> houseCnts; // 각 단지별 집 수 저장

	string inputString; // 입력이 스트링으로 들어옴

	queue<pair<int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	//	0110100
	//	0110101
	//	1110101
	//	0000111
	//	0100000
	//	0111110
	//	0111000
	for (int i = 0; i < n; i++)
	{
		cin >> inputString;

		for (int j = 0; j < n; j++)
		{
			graph[i][j] = inputString[j] - '0';
		}
	}

	// BFS
	// 그래프를 돌면서 1을 만나면 방문체크, 큐에 저장 후 방문체크
	// 큐가 빌때까지 돌면서 경계체크, 방문체크, 0체크, 1을 만나면 큐에 저장 후 방문체크, 집 수 증가
	// 한 스텝이 끝나면 단지 수 증가

	int blockCnt = 0; // 단지 수

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] == 1) // 1을 만나면
			{
				// 방문체크
				if (vis[i][j])
				{
					continue;
				}

				// 큐에 저장 후 방문체크
				checkPos.push({ i, j });
				vis[i][j] = true;

				// 집 수
				int houseCnt = 1;

				while (!checkPos.empty()) // 큐가 빌때까지
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
						if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= n)
						{
							continue;
						}

						// 방문체크
						if (vis[checkI][checkJ])
						{
							continue;
						}

						// 0체크
						if (graph[checkI][checkJ] == 0)
						{
							continue;
						}

						// 1을 만나면 큐에 저장 후 방문체크, 집 수 증가
						checkPos.push({ checkI, checkJ });
						vis[checkI][checkJ] = true;
						houseCnt++;
					}
				}

				houseCnts.push_back(houseCnt); // 각 단지의 집 수가 저장됨
				blockCnt++; // 단지 수 증가
			}
		}
	}

	// 단지 수 출력
	cout << blockCnt << '\n';

	// 각 단지의 집 수 오름차순 출력

	sort(houseCnts.begin(), houseCnts.end());

	for (int i = 0; i < houseCnts.size(); i++)
	{
		cout << houseCnts[i] << '\n';
	}

	return 0;
}
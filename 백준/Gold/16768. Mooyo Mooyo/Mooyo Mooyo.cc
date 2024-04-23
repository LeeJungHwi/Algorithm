#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// Mooyo Mooyo
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 퍼즐게임
	// 같은색이 k개이상 연결되어있으면 한꺼번에 없어짐 
	// 없어지고 위에 다른색이 있으면 아래로 내려옴
	// 마지막 그래프 출력

	int n, k; // N, K 6, 3
	cin >> n >> k;

	vector<vector<char> > graph(n, vector<char>(10)); // 그래프
	vector<vector<char> > vis(n, vector<char>(10)); // 방문체크
	queue<pair<int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	//	0000000000
	//	0000000300
	//	0054000300
	//	1054502230
	//	2211122220
	//	1111111223
	string inputString;

	for (int i = 0; i < n; i++)
	{
		cin >> inputString;

		for (int j = 0; j < 10; j++)
		{
			graph[i][j] = inputString[j];
		}
	}

	// 1.그래프를 정방향으로 탐색하면서 같은색깔 k개이상이 되는 영역을 찾으면 빈칸으로 없앰
	// 2.그래프를 역방향으로 탐색하면서 퍼즐을 만나면 퍼즐이나 경계를 만날때까지 아래로 이동시킴
	// 1, 2를 반복하다가 퍼즐을 없앤적이 없는경우 종료

	while (true)
	{
		bool isRemove = false; // 퍼즐을 없앤적이 있는지 체크

		// 1.그래프를 정방향으로 탐색하면서 같은색깔 k개이상이 되는 영역을 찾으면 빈칸으로 없앰
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (graph[i][j] != '0' && !vis[i][j])
				{
					// 그래프를 돌면서 퍼즐을 만나면서 방문하지 않았으면 BFS 돌리기

					vector<pair<int, int> > removePuzzle; // 없앨 퍼즐 저장
					int sameColorPuzzleCnt = 1; // 같은색깔 퍼즐 개수
					checkPos.push({ i, j });
					vis[i][j] = true;
					removePuzzle.push_back({ i, j });

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
							if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= 10) continue;

							// 방문체크
							if (vis[checkI][checkJ]) continue;

							// 빈칸체크
							if (graph[checkI][checkJ] == '0') continue;

							// 다른색깔 퍼즐 체크
							if (graph[checkI][checkJ] != graph[standardPos.first][standardPos.second]) continue;

							// 같은색깔 퍼즐을 만났으면 큐에저장, 방문체크, 같은색퍼즐카운팅, 없앨 퍼즐에 저장
							checkPos.push({ checkI, checkJ });
							vis[checkI][checkJ] = true;
							sameColorPuzzleCnt++;
							removePuzzle.push_back({ checkI, checkJ });
						}
					}

					// 같은색 퍼즐이 k개이상이면 빈칸으로 바꿔서 없애고 없앴다고 체크
					if (sameColorPuzzleCnt >= k)
					{
						for (int k = 0; k < removePuzzle.size(); k++)
						{
							graph[removePuzzle[k].first][removePuzzle[k].second] = '0';
						}

						isRemove = true;
					}
				}
			}
		}

		// 2.그래프를 역방향으로 탐색하면서 퍼즐을 만나면 퍼즐이나 경계를 만날때까지 아래로 이동시킴
		for (int i = n - 2; i > -1; i--)
		{
			for (int j = 0; j < 10; j++)
			{
				if (graph[i][j] != '0') // 퍼즐을 만나면
				{
					for (int k = i; k < n - 1; k++) // 경계 전까지
					{
						if (graph[k + 1][j] != '0') break; // 퍼즐을 만날때까지

						// 아래로 이동시키고 기존 퍼즐은 빈칸으로
						graph[k + 1][j] = graph[k][j];
						graph[k][j] = '0';
					}
				}
			}
		}

		// 퍼즐이 없어지지않았으면 종료
		if (!isRemove) break;

		// vis 초기화
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				vis[i][j] = false;
			}
		}
	}

	// 마지막 그래프 출력
	for (auto a : graph)
	{
		string outputString;

		for (auto b : a)
		{
			outputString += b;
		}

		cout << outputString << '\n';
	}

	return 0;
}
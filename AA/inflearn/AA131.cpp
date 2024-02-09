#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 물 웅덩이
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int r, c; // R, C 6, 7
	cin >> r >> c;

	vector<vector<char> > graph(r, vector<char>(c)); // 그래프
	vector<vector<bool> > vis(r, vector<bool>(c)); // 방문체크

	queue<pair<int, int> > checkPos; // 체크할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	int areaCnt = 0; // 물웅덩이 영역 개수

	//	.#....#
	//	..#...#
	//	..#..#.
	//	...##..
	//	.#....#
	//	.#..#.#
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> graph[i][j];
		}
	}

	// BFS
	// 웅덩이(#)을 만나면 BFS 돌리기
	// 경계체크, 방문체크, 정상적인곳체크, 웅덩이를 만나면 큐에 저장, 방문체크
	// BFS가 끝나고 웅덩이영역 개수 증가

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (graph[i][j] == '#') // 웅덩이를 만나면
			{
				if (vis[i][j]) // 이미 방문한곳이면 continue
				{
					continue;
				}

				checkPos.push({ i, j }); // BFS를 시작할 웅덩이 좌표 저장
				vis[i][j] = true; // BFS를 시작할 웅덩이 좌표 방문체크

				while (!checkPos.empty()) // 큐가 빌때까지
				{
					// 기준위치 꺼냄
					pair<int, int> standardPos = checkPos.front();
					checkPos.pop();

					// 상하좌우
					for (int k = 0; k < 4; k++)
					{
						// 체크할 위치
						int checkI = standardPos.first + checkDir[k].first;
						int checkJ = standardPos.second + checkDir[k].second;

						// 경계체크
						if (checkI < 0 || checkJ < 0 || checkI >= r || checkJ >= c)
						{
							continue;
						}
						
						// 방문체크
						if (vis[checkI][checkJ])
						{
							continue;
						}

						// 정상적인곳체크
						if (graph[checkI][checkJ] == '.')
						{
							continue;
						}

						// 웅덩이를 만나면 큐에저장, 방문체크
						checkPos.push({ checkI, checkJ });
						vis[checkI][checkJ] = true;
					}
				}

				areaCnt++;
			}
		}
	}

	cout << areaCnt;

	return 0;
}
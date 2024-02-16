#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

// 탈출
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int r, c; // R, C 3, 6
	cin >> r >> c;

	vector<vector<char> > graph(r, vector<char>(c)); // 그래프
	queue<pair<int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	string inputString; // 입력문자열

	pair<int, int> dPos; // 비버굴 위치
	pair<int, int> sPos; // 고슴도치 위치
	vector<vector<int> > wDis(r, vector<int>(c)); // 물 거리
	wDis[dPos.first][dPos.second] = 2147000000; // 비버굴의 물 거리는 max값으로 둬야 고슴도치 BFS 돌릴때 거리 구해짐

	//	D...*.
	//	.X.X..
	//	....S.
	// 비버굴 위치, 고슴도치 위치 저장
	// 물 위치는 먼저 BFS 돌리기 위해 큐에 바로 저장 후 거리 1
	for (int i = 0; i < r; i++)
	{
		cin >> inputString;

		for (int j = 0; j < inputString.size(); j++)
		{
			graph[i][j] = inputString[j];

			if (graph[i][j] == 'D')
			{
				dPos = { i, j };
			}
			else if (graph[i][j] == 'S')
			{
				sPos = { i, j };
			}
			else if (graph[i][j] == '*')
			{
				checkPos.push({ i, j });
				wDis[i][j] = 1;
			}
		}
	}

	// 물 BFS 돌리면서 거리 저장
	// 고슴도치 BFS 돌리면서 거리 저장

	// 물 BFS 돌리면서 거리 저장
	while (!checkPos.empty()) // 큐가 빌때까지
	{
		// 기준위치 꺼냄
		pair<int, int> standardPos = checkPos.front();
		checkPos.pop();

		for (int i = 0; i < 4; i++)
		{
			// 체크 할 위치
			int checkI = standardPos.first + checkDir[i].first;
			int checkJ = standardPos.second + checkDir[i].second;

			// 경계체크
			if (checkI < 0 || checkJ < 0 || checkI >= r || checkJ >= c)
			{
				continue;
			}

			// 돌체크
			if (graph[checkI][checkJ] == 'X')
			{
				continue;
			}

			// 비버굴체크
			if (graph[checkI][checkJ] == 'D')
			{
				continue;
			}

			// 거리가 할당되어있지않다면 큐에 저장 후 거리 저장
			if (wDis[checkI][checkJ] == 0)
			{
				checkPos.push({ checkI, checkJ });
				wDis[checkI][checkJ] = wDis[standardPos.first][standardPos.second] + 1;
			}
			else // 거리가 할당되어있다면 최소인경우만 큐에 저장 후 거리 저장
			{
				if (wDis[checkI][checkJ] > wDis[standardPos.first][standardPos.second] + 1)
				{
					checkPos.push({ checkI, checkJ });
					wDis[checkI][checkJ] = wDis[standardPos.first][standardPos.second] + 1;
				}
			}
		}
	}

	// 고슴도치 BFS 돌리면서 거리 저장
	vector<vector<int> > sDis(r, vector<int>(c)); // 고슴도치 거리
	checkPos.push(sPos);
	sDis[sPos.first][sPos.second] = 1;

	while (!checkPos.empty()) // 큐가 빌때까지
	{
		// 기준위치 꺼냄
		pair<int, int> standardPos = checkPos.front();
		checkPos.pop();

		for (int i = 0; i < 4; i++)
		{
			// 체크 할 위치
			int checkI = standardPos.first + checkDir[i].first;
			int checkJ = standardPos.second + checkDir[i].second;

			// 경계체크
			if (checkI < 0 || checkJ < 0 || checkI >= r || checkJ >= c)
			{
				continue;
			}

			// 방문체크(거리로)
			if (sDis[checkI][checkJ] > 0)
			{
				continue;
			}

			// 돌체크
			if (graph[checkI][checkJ] == 'X')
			{
				continue;
			}

			// 물거리체크 : 고슴도치가 물보다 더 최단시간으로 가면서 물 거리가 할당되어 있는지 체크
			if (sDis[standardPos.first][standardPos.second] + 1 >= wDis[checkI][checkJ] && wDis[checkI][checkJ] != 0)
			{
				continue;
			}

			// 큐에 저장 후 거리 저장
			checkPos.push({ checkI, checkJ });
			sDis[checkI][checkJ] = sDis[standardPos.first][standardPos.second] + 1;
		}
	}

	// 고슴도치 거리의 비버굴위치 거리가 저장되어있지않으면 이동할수없음
	if (sDis[dPos.first][dPos.second] == 0)
	{
		cout << "KAKTUS" << '\n';

		return 0;
	}

	// 1로 시작했으므로 1 빼줌
	cout << sDis[dPos.first][dPos.second] - 1 << '\n';

	return 0;
}
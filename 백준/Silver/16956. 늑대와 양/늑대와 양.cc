#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

// 늑대와 양
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int r, c; // R, C 6, 6
	cin >> r >> c;

	vector<vector<char> > graph(r, vector<char>(c)); // 그래프
	vector<vector<bool> > vis(r, vector<bool>(c)); // 방문체크

	queue<pair<int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	string inputString; // 입력문자열

	vector<pair<int, int> > sheepPos; // 양 위치

	//	..S...
	//	..S.W.
	//	.S....
	//	..W...
	//	...W..
	//	......
	// 큐에 늑대 위치 저장 및 방문체크
	// 양 위치 저장
	// (1, 4) (3, 2) (4, 3)
	for (int i = 0; i < r; i++)
	{
		cin >> inputString;

		for (int j = 0; j < c; j++)
		{
			graph[i][j] = inputString[j];

			if (inputString[j] == 'W')
			{
				checkPos.push({ i, j });
				vis[i][j] = true;
			}
			else if (inputString[j] == 'S')
			{
				sheepPos.push_back({ i, j });
			}
		}
	}

	// 늑대위치부터 DFS 돌리기
	// 경계체크, 방문체크, 양 체크(울타리 설치), 울타리 체크, 빈칸을 만나면 큐에 저장 후 방문체크
	
	while (!checkPos.empty()) // 큐가 빌때까지
	{
		// 기준위치 꺼냄
		pair<int, int> standardPos = checkPos.front();
		checkPos.pop();

		// 상하좌우
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

			// 방문체크
			if (vis[checkI][checkJ])
			{
				continue;
			}

			// 울타리체크
			if (graph[checkI][checkJ] == 'D')
			{
				continue;
			}

			// 양체크(울타리 설치)
			if (graph[checkI][checkJ] == 'S' && graph[standardPos.first][standardPos.second] == '.')
			{
				graph[standardPos.first][standardPos.second] = 'D';
				break;
			}

			// 빈칸을 만나면 큐에 저장 후 방문체크
			checkPos.push({ checkI, checkJ });
			vis[checkI][checkJ] = true;
		}
	}

	// 양 위치에 늑대가 갈수없다면 1 출력
	// 갈수있다면 0 출력

	bool canGo = false;

	for (int i = 0; i < sheepPos.size(); i++)
	{
		if (vis[sheepPos[i].first][sheepPos[i].second])
		{
			canGo = true;
			
			break;
		}
	}

	if (canGo)
	{
		cout << 0 << '\n';
		
		return 0;
	}

	cout << 1 << '\n';

	for (int i = 0; i < r; i++)
	{
		string outputString = ""; // 출력문자열

		for (int j = 0; j < c; j++)
		{
			outputString += graph[i][j];
		}

		cout << outputString << '\n';
	}

	return 0;
}
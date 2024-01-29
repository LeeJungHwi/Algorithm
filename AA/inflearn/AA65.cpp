#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 미로탐색(격자판)
void SearchGraph(int column, int row, int &caseCnt, vector<vector<int> > &graph, vector<vector<bool> > &vis, vector<pair<int, int> > &dir)
{
	if (column == 6 && row == 6) // 종료조건 : 도착지점 (6, 6)
	{
		caseCnt++;
	}
	else
	{
		// 상하좌우 체크 : 0이면서 방문하지않은곳 
		for (int i = 0; i < 4; i++)
		{
			int checkI = column + dir[i].first;
			int checkJ = row + dir[i].second;

			// 경계체크 : 격자를 벗어나면 다음 체크
			if (checkI < 0 || checkJ < 0 || checkI > 6 || checkJ > 6)
			{
				continue;
			}

			if (graph[checkI][checkJ] == 0 && vis[checkI][checkJ] == false) // 0이면서 방문하지않은곳이면
			{
				vis[checkI][checkJ] = true; // 방문체크
				SearchGraph(checkI, checkJ, caseCnt, graph, vis, dir);
				vis[checkI][checkJ] = false; // 뒤로 되돌아갈때 방문체크 해제해줘야함
			}
		}
	}
}

// 미로탐색(격자판)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	vector<vector<int> > graph(7, vector<int>(7)); // 그래프
	vector<vector<bool> > vis(7, vector<bool>(7)); // 방문체크
	int caseCnt = 0; // 도착가능한 경우 수
	vector<pair<int, int> > dir; // 상하좌우
	dir.push_back({ -1, 0 });
	dir.push_back({ 1, 0 });
	dir.push_back({ 0, -1 });
	dir.push_back({ 0, 1 });

	//	0 0 0 0 0 0 0
	//	0 1 1 1 1 1 0
	//	0 0 0 1 0 0 0
	//	1 1 0 1 0 1 1
	//	1 1 0 0 0 0 1
	//	1 1 0 1 1 0 0
	//	1 0 0 0 0 0 0
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cin >> graph[i][j];
		}
	}

	vis[0][0] = true;

	SearchGraph(0, 0, caseCnt, graph, vis, dir);

	cout << caseCnt << '\n';

	return 0;
}
// 핵심
// DFS 격자판 : 상하좌우 체크, 경계 체크, 재귀호출 후 방문체크 해제
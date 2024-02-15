#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
#include <string>
#include <unordered_set>
using namespace std;

vector<vector<int>> graph(5, vector<int>(5)); // 그래프
unordered_set<string> sequence; // 서로 다른 여섯자리 수열 저장
vector<pair<int, int> > checkDir = { {-1, 0},{1, 0},{0, -1},{0, 1} }; // 상하좌우

// DFS
void DFS(int i, int j, int cnt, string path)
{
	if (cnt == 5) // 종료조건 : 움직인 횟수가 5번인 경우
	{
		sequence.insert(path);

		return;
	}
	else
	{
		// 상하좌우 체크
		for (int k = 0; k < 4; ++k)
		{
			// 체크 할 위치
			int checkI = i + checkDir[k].first;
			int checkJ = j + checkDir[k].second;

			// 경계체크
			if (checkI < 0 || checkJ < 0 || checkI >= 5 || checkJ >= 5)
			{
				continue;
			}

			DFS(checkI, checkJ, cnt + 1, path + to_string(graph[checkI][checkJ]));
		}
	}
}

// 숫자판 점프
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	//	1 1 1 1 1
	//	1 1 1 1 1
	//	1 1 1 1 1
	//	1 1 1 2 1
	//	1 1 1 1 1
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> graph[i][j];
		}
	}

	// DFS
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			DFS(i, j, 0, to_string(graph[i][j]));
		}
	}

	// 서로 다른 수열 개수 출력
	cout << sequence.size() << '\n';

	return 0;
}

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 봉우리
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	vector<vector<int> > peekHeights(n, vector<int>(n)); // 봉우리 높이 저장
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });
	vector<vector<bool> > vis(n, vector<bool>(n)); // 봉우리 방문 체크
	int peekCnt = 0; // 봉우리 개수

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> peekHeights[i][j];
		}
	}

	// 2차원 벡터를 돌면서 상하좌우 봉우리 체크
	// 격자를 벗어나면 체크 X
	// 방문체크가 안된 봉우리만 체크
	// 자신의 봉우리보다 작으면 방문체크
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// 방문된 봉우리 체크
			if (vis[i][j])
			{
				continue;
			}

			int curPeek = peekHeights[i][j]; // 체크할 봉우리
			bool isPeek = true; // 봉우리인지 체크

			for (int k = 0; k < 4; k++)
			{
				// 상하좌우 순서로 체크
				int checkI = i + checkDir[k].first;
				int checkJ = j + checkDir[k].second;

				// 경계체크
				if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= n)
				{
					continue;
				}
				
				// 자신의 봉우리보다 작으면 방문체크
				if (peekHeights[checkI][checkJ] < curPeek)
				{
					vis[checkI][checkJ] = true;
				}
				else // 상하좌우 중 자신보다 높은 봉우리가 있으므로 봉우리가 아님
				{
					isPeek = false;
				}
			}
			 
			if (isPeek) // 봉우리일때만 개수 증가
			{
				peekCnt++;
			}
		}
	}

	cout << peekCnt << '\n';

	return 0;
}
// 핵심
// 2차원 벡터 초기화
// bfs 경계체크 범위
// 상하좌우 좌표
// bfs 방문체크
// 봉우리가 되는 조건
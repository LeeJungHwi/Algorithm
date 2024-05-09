#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 자두 나무 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 자두는 1초마다 1번 또는 2번 나무에서 떨어짐(T번)
	// 떨어지는 순간에 위치를 이동해서 받아먹을수있음(W번)
	// 처음에는 1번 나무 아래에 있음
	// 받아먹을수있는 자두 개수의 최댓값 구하기

	int t, w; // T, W 7, 2;
	cin >> t >> w;

	vector<vector<long long>> dp(t + 1, vector<long long>(w + 1)); // dp[i][j] = i시간에 j번 이동기회가 남았을때 최대개수 저장

	int treeNum; // 떨어지는 나무 번호
	long long maxCnt = 0; // 받아먹을수있는 자두 최대개수

	for (int i = 1; i < t + 1; i++)
	{
		cin >> treeNum;

		for (int j = 0; j < w + 1; j++)
		{
			// 일단 움직이지 않는 경우를 현재 dp값에 넣어줌
			// 현재 dp값 == 이전 시간에서 그대로 머무르면서, 떨어지는 나무 번호가 j 위치면 1개 누적
			dp[i][j] = dp[i - 1][j] + (treeNum == j % 2 + 1);

			// 움직일수있는 횟수가 남아있다면
			// 움직인것과 움직이지않은것 중 최대개수를 현재 dp값에 넣어줌
			// 움직이지 않는 경우는 위에서 구한 dp[i][j]
			// 움직인 경우는 이전시간에 j - 1 번의 이동 기회가 남았을 때 최대개수 + 나무 번호에 따라 추가되는 개수
			if (j > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (treeNum == j % 2 + 1));

			// 최대개수 갱신
			maxCnt = max(maxCnt, dp[i][j]);
		}
	}

	cout << maxCnt << '\n';

	return 0;
}
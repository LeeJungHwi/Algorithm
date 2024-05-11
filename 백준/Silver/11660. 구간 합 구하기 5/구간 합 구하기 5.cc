#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 구간 합 구하기 5
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 그래프에서 구간합 구하기

	int n, m; // N, M 4, 3
	cin >> n >> m;

	vector<vector<int> > graph(n + 1, vector<int>(n + 1)); // 그래프
	vector<vector<long long> > dp(n + 1, vector<long long>(n + 1)); // i,j에서 구간합 저장

	//	1 2 3 4
	//	2 3 4 5
	//	3 4 5 6
	//	4 5 6 7
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			cin >> graph[i][j];
		}
	}

	// dp 채우기
	// 1행 : 좌 값 누적
	// 1열 : 상 값 누적
	// 2,2 ~ n,n : 좌 값 + 상 값 - 좌상 값 + 현재 값

	dp[1][1] = graph[1][1];

	for (int i = 2; i < n + 1; i++)
	{
		dp[1][i] = dp[1][i - 1] + graph[1][i];
		dp[i][1] = dp[i - 1][1] + graph[i][1];
	}

	for (int i = 2; i < n + 1; i++)
	{
		for (int j = 2; j < n + 1; j++)
		{
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + graph[i][j];
		}
	}

	//for (auto a : dp)
	//{
	//	for (auto b : a)
	//	{
	//		cout << b << ' ';
	//	}
	//	cout << '\n';
	//}

	pair<int, int> leftTop;
	pair<int, int> rightBot;

	for (int i = 0; i < m; i++)
	{
		//	2 2 3 4
		//	3 4 3 4
		//	1 1 4 4
		cin >> leftTop.first >> leftTop.second >> rightBot.first >> rightBot.second;

		// 우하 dp 값 - (우하 i, 좌상 j - 1) dp 값 - (좌상 i - 1, 우하 j) + (좌상 i - 1, 좌상 j - 1)
		cout << dp[rightBot.first][rightBot.second] - dp[rightBot.first][leftTop.second - 1] - dp[leftTop.first - 1][rightBot.second] + dp[leftTop.first - 1][leftTop.second - 1] << '\n';
	}

	return 0;
}
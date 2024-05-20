#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 이동하기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 3, 4
	cin >> n >> m;

	vector<vector<int> > graph(n + 1, vector<int>(m + 1));
	vector<vector<int> > dp(n + 1, vector<int>(m + 1));

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			cin >> graph[i][j];
		}
	}

	dp[1][1] = graph[1][1];

	// 1행 1열
	for (int i = 2; i < n + 1; i++) dp[i][1] = dp[i - 1][1] + graph[i][1];
	for (int i = 2; i < m + 1; i++) dp[1][i] = dp[1][i - 1] + graph[1][i];

	// 2,2 부터
	for (int i = 2; i < n + 1; i++)
	{
		for (int j = 2; j < m + 1; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + graph[i][j];
		}
	}

	cout << dp[n][m] << '\n';

	return 0;
}
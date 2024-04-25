#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 정수 삼각형
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 합이 최대가 되는 경로에 있는 수의 합 구하기

	int n; // N 5
	cin >> n;

	vector<vector<int> > graph(n + 1, vector<int>(n + 1));

	//	7
	//	3 8
	//	8 1 0
	//	2 7 4 4
	//	4 5 2 6 5
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < i + 1; j++)
		{
			cin >> graph[i][j];
		}
	}

	//for (auto a : graph)
	//{
	//	for (auto b : a)
	//	{
	//		cout << b << ' ';
	//	}
	//	cout << '\n';
	//}

	vector<vector<int> > dp(n + 1, vector<int>(n + 1)); // dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + 자기숫자

	int maxSize = 0; // 합이 최대가 되는 경로에 있는 수의 합

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < i + 1; j++)
		{
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + graph[i][j];
			maxSize = max(maxSize, dp[i][j]);
		}
	}

	cout << maxSize << '\n';

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 삼각 그래프
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int tc = 0;

	while (true)
	{
		int n;
		cin >> n;
		if (n == 0) break;
		tc++;

		vector<vector<long long> > graph(n + 1, vector<long long>(4)); // 그래프
		for (int i = 1; i < n + 1; i++)
		{
			for (int j = 1; j < 4; j++)
			{
				cin >> graph[i][j];
			}
		}
		vector<vector<long long> > dp(n + 1, vector<long long>(4)); // i,j 까지 오는 경로의 최솟값 저장
		dp[1][1] = graph[1][1];
		
		// 1행 : 1열 X, 2열은 2열값 3열은 2열값 + 3열값
		dp[1][1] = 2147000000;
		dp[1][2] = graph[1][2];
		dp[1][3] = graph[1][2] + graph[1][3];

		// 2행 부터
		// 1열 : 상, 우상 둘 중 최솟값 + 현재비용
		// 2열 : 좌상, 상, 우상, 좌 넷 중 최솟값 + 현재비용
		// 3열 : 좌상, 상, 좌 셋 중 최솟값 + 현재비용

		for (int i = 2; i < n + 1; i++)
		{
			for (int j = 1; j < 4; j++)
			{
				if (j == 1) dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + graph[i][j];
				else if (j == 2) dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1], dp[i][j - 1] }) + graph[i][j];
				else dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + graph[i][j];
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

		cout << tc << ". " << dp[n][2] << '\n';
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 파도반 수열
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 1 => 1
	// 2 => 1
	// 3 => 1
	// 4 => 2
	// 5 => 2
	// 6 => 2 + 1 => 3
	// 7 => 3 + 1 => 4
	// 8 => 4 + 1 => 5
	// 9 => 5 + 2 => 7
	//10 => 7 + 2 => 9
	//11 => 9 + 3 => 12
	// ....
	// dp[1] = 1, dp[2] = 1, dp[3] = 1, dp[4] = 2, dp[5] = 2
	// 5 ~ n + 1 : dp[i] = dp[i - 1] + dp[i - 5]

	int tc; // TC 2;
	cin >> tc;

	vector<long long> dp(101);

	dp[1] = 1, dp[2] = 1, dp[3] = 1, dp[4] = 2, dp[5] = 2;

	for (int i = 5; i < 101; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	int n; // N 6, 12

	while (tc--)
	{
		cin >> n;

		cout << dp[n] << '\n';
	}

	return 0;
}
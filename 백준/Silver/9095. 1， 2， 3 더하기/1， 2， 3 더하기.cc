#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 1, 2, 3 더하기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// n을 1, 2, 3의 합으로 나타내는 방법의 수 구하기

	int tc; // TC 3
	cin >> tc;

	int n; // N 4 7 10

	vector<int> dp(11); // 각 숫자를 1, 2, 3의 합으로 나타내는 방법의 수 저장

	// 1 => 1 => 1
	// 2 => 1 1, 2 => 2
	// 3 => 1 1 1, 1 2, 2 1, 3 => 4
	// 4 => 1 1 1 1, 1 1 2, 1 2 1, 2 1 1, 2 2, 1 3, 3 1 => 7
	// dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	dp[4] = 7;

	for (int i = 5; i < 11; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	while (tc--)
	{
		cin >> n;

		cout << dp[n] << '\n';
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 가장 큰 증가하는 부분 수열
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 증가하는 부분 수열 중 합이 가장 큰 것 구하기

	// 1. i - 1 ~ 1(자기자신 이전) 까지 돌면서 마지막 숫자가 자기자신보다 작은 dp값에 자기자신을 더한값 중 최대값 갱신
	// 2. 최대값이 갱신되면 최대부분수열값 갱신

	int n; // N 10
	cin >> n;

	vector<long long> num(n + 1); // 1 100 2 50 60 3 5 6 7 8
	for (int i = 1; i < n + 1; i++) cin >> num[i];
	vector<long long> dp(n + 1);
	dp[1] = num[1];
	long long maxSum = dp[1];

	// 1. i - 1 ~ 1(자기자신 이전) 까지 돌면서 마지막 숫자가 자기자신보다 작은 dp값에 자기자신을 더한값 중 최대값 갱신
	for (int i = 2; i < n + 1; i++)
	{
		// 현재 dp값 초기화 하고 시작해야함
		// 5 1 2 3 7
		// anser : 1 + 2 + 3 + 7 => 13
		// wrong : 5 + 7 => 12 
		dp[i] = num[i];

		for (int j = i - 1; j > 0; j--)
		{
			if (num[j] < num[i] && dp[i] < dp[j] + num[i])
			{
				dp[i] = dp[j] + num[i];
			}
		}

		// 2. 최대값이 갱신되면 최대부분수열값 갱신
		maxSum = max(maxSum, dp[i]);
	}

	cout << maxSum << '\n';

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 동전
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 각 동전을 적당히 사용해서 합이 m원이 되도록하는 경우의 수

	int tc; // TC 3
	cin >> tc;

	while (tc--)
	{
		int n; // N 2
		cin >> n;

		vector<long long> coin(n + 1); // 1 2
		for (int i = 1; i < n + 1; i++) cin >> coin[i];

		int m; // M 1000
		cin >> m;
		vector<long long> dp(m + 1); // m원을 만드는 경우의 수 저장
		dp[0] = 1; // 0원은 동전을 모두 사용하지 않는 경우 한 가지

		// 모든 동전을 돌면서
		for (int i = 1; i < n + 1; i++)
		{
			// 각 동전을 사용할 수 있는
			for (int j = coin[i]; j < m + 1; j++)
			{
				// 각 j 원에 대해
				// coin[i]를 마지막으로 사용해서 j원을 만드는 경우의 수 누적
				// dp[j - coin[i]] : coin[i]를 사용하지 않은 상태
				dp[j] += dp[j - coin[i]];
			}
		}

		// m원을 만들 수 있는 경우의 수
		cout << dp[m] << '\n';
	}

	return 0;
}
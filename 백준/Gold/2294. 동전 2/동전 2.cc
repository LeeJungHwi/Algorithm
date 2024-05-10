#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 동전 2
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 각 동전을 적당히 사용해서 합이 k원이 되도록하는 경우의 수

	int n, k; // N, K 3, 15
	cin >> n >> k;

	vector<long long> coin(n + 1); // 1 5 12
	for (int i = 1; i < n + 1; i++) cin >> coin[i];
	vector<long long> dp(k + 1, 2147000000); // i원을 만드는 사용한 동전의 최소개수 저장
	dp[0] = 0; // 0원을 만드는 동전의 개수 0개

	// 모든 동전을 돌면서
	for (int i = 1; i < n + 1; i++)
	{
		// 각 동전을 사용할 수 있는
		for (int j = coin[i]; j < k + 1; j++)
		{
			// 각 j 원에 대해
			// coin[i]를 마지막으로 사용해서 j원을 만드는 동전의 최소개수 갱신
			// dp[j - coin[i]] : coin[i]를 사용하지 않은 상태
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	// k원을 만들 수 있는 동전의 최소개수
	cout << (dp[k] == 2147000000 ? -1 : dp[k]) << '\n';

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 01타일
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 타일 종류 : 00, 1
	// 만들 수 있는 길이가 n인 2진 수열 개수 % 15746

	int n; // N 4
	cin >> n;

	vector<long long> dp(n + 1); // 길이 n인 2진 수열 개수 저장

	if (n == 1)
	{
		cout << 1 << '\n';
		return 0;
	}

	dp[1] = 1;
	dp[2] = 2;

	// 이전 두 개 dp값 합
	for (int i = 3; i < n + 1; i++)
	{
		dp[i] = dp[i - 1] % 15746 + dp[i - 2] % 15746;
		dp[i] %= 15746;
	}

	cout << dp[n] % 15746 << '\n';

	return 0;
}
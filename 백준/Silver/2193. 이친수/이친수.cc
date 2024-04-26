#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 이친수
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 이진수 중에서 아래 조건을 가지는 수
	// 0으로 시작하지않음
	// 1이 두번연속 나타나지않음
	// n자리 이친수 구하기

	// 1 => 1

	// 2 => 10

	// 3 => 10 0
	// 4 => 10 1

	// 5 => 10 00
	// 6 => 10 01
	// 7 => 10 10

	// 8 => 10 000
	// 9 => 10 001
	// 10=> 10 010
	// 11=> 10 100
	// 12=> 10 101

	// 12=> 10 0000
	// ....
	// dp[i] = dp[i - 1] + dp[i - 2]

	int n; // N 3
	cin >> n;

	vector<long long> dp(n + 1);

	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i < n + 1; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n] << '\n';

	return 0;
}
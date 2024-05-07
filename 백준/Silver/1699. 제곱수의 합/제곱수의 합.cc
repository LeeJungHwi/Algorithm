#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 제곱수의 합
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// n을 n이하 제곱수 들의 합으로 표현할 때 항의 최소개수 구하기

	int n; // N 7
	cin >> n;

	vector<long long> dp(n + 1, 2147000000); // 각 i 번 째 수를 표현하는 항의 최소개수 저장
	dp[0] = 0;
	dp[1] = 1;

	// 2 부터
	// 현재숫자 i를 나타낼 수 있는 제곱수 j 체크
	// 현재 dp 값과 i - j^2 dp값 + 1 중 최솟값으로 갱신
	// dp[i - j * j] : 현재 숫자 i 에서 j 제곱을 뺀 숫자를 만드는 최소항의 개수
	// 여기에 j 제곱항이 추가되므로 + 1

	for (int i = 2; i < n + 1; i++)
	{
		for (int j = 1; j * j < i + 1; j++)
		{
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[n] << '\n';

	return 0;
}
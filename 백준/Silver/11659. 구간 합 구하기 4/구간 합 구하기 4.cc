#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 구간 합 구하기 4
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// i ~ j 까지 수의 합 구하기

	int n, m; // N, M 5, 3
	cin >> n >> m;

	vector<int> num(n + 1); // 5 4 3 2 1
	vector<int> dp(n + 1); // 5 9 12 14 15

	// 누적합
	for (int i = 1; i < n + 1; i++)
	{
		cin >> num[i];
		dp[i] = dp[i - 1] + num[i];
	}

	// j까지합 - i까지합
	int i, j;

	for (int k = 0; k < m; k++)
	{
		cin >> i >> j;

		cout << dp[j] - dp[i - 1] << '\n';
	}

	return 0;
}
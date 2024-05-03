#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 오르막 수
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 오르막 수 : 수의 자리가 비내림차순인 수
	// 길이가 n인 오르막 수의 개수 % 10007 구하기
	
	int n; // N 3
	cin >> n;

	vector<vector<long long> > dp(n + 1, vector<long long>(10)); // 길이가 i 일때 각 숫자 j로 만들 수 있는 오르막의 개수 저장

	// 길이기 1인 경우 각 숫자 j(0~9)로 만들 수 있는 오르막의 개수는 1개
	for (int i = 0; i < 10; i++) dp[1][i] = 1;

	if (n == 1)
	{
		cout << 10 << '\n';
		return 0;
	}

	long long cnt = 0; // 길이가 n인 오르막 수의 개수

	for (int i = 2; i < n + 1; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			// 현재 dp 값
			// 가능한 숫자 => 이전 길이 마지막 숫자(j) 이상인 숫자(k)로 만들 수 있는 오르막의 개수 누적
			for (int k = j; k < 10; k++)
			{
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= 10007;
			}

			// 길이가 n일때 오르막 수 누적
			if (i == n)
			{
				cnt += dp[i][j];
				cnt %= 10007;
			}
		}
	}

	cout << cnt % 10007 << '\n';

	return 0;
}
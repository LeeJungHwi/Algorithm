#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 2xn 타일링
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 2 by n 직사각형을 1 by 2, 2 by 1 타일로 채우는 방법의 수 구하기
	// 방법 수 % 10007 출력

	int n; // N 9
	cin >> n;

	// n 1 => | => 1개
	// n 2 => ||, = => 2개
	// n 3 => n 2 + | 2개, n 1 + = 1개 => 3개
	// n 4 => n 3 + | 3개, n 2 + = 2개 => 5개

	vector<int> dp(n + 1);
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i < n + 1; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	cout << dp[n] << '\n';

	return 0;
}
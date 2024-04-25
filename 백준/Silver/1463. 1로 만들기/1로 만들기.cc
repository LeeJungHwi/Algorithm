#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 1로 만들기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 1.X가 3으로 나누어떨어지면 3으로 나눈다
	// 2.X가 2로 나누어떨어지면 2로 나눈다
	// 3.1을 뺸다

	// 위 3개의 연산을 사용해서 연산횟수의 최솟값 구하기

	int x; // X 10
	cin >> x;

	vector<int> dp(x + 1); // 각 i를 1로 만드는데 필요한 연산횟수 최솟값 저장

	for (int i = 2; i < x + 1; i++)
	{
		// 3.1을 뺸다
		dp[i] = dp[i - 1] + 1;

		// 2.X가 2로 나누어떨어지면 2로 나눈다
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);

		// 1.X가 3으로 나누어떨어지면 3으로 나눈다
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
	}

	cout << dp[x] << '\n';

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 1로 만들기 2
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
	// x를 1로 만드는 과정에서 포함되어있는 수 출력하기

	int x; // X 10
	cin >> x;

	vector<int> dp(x + 1); // 각 i를 1로 만드는데 필요한 연산횟수 최솟값 저장
	vector<int> idx(x + 1); // 연산에 사용된 인덱스 추적

	for (int i = 2; i < x + 1; i++)
	{
		// 3.1을 뺸다
		dp[i] = dp[i - 1] + 1;
		idx[i] = i - 1;

		// 2.X가 2로 나누어떨어지면 2로 나눈다
		if (i % 2 == 0)
		{
			if (dp[i] > dp[i / 2] + 1)
			{
				dp[i] = dp[i / 2] + 1;
				idx[i] = i / 2;
			}
		}

		// 1.X가 3으로 나누어떨어지면 3으로 나눈다
		if (i % 3 == 0)
		{
			if (dp[i] > dp[i / 3] + 1)
			{
				dp[i] = dp[i / 3] + 1;
				idx[i] = i / 3;
			}
		}
	}

	cout << dp[x] << '\n';

	while (true)
	{
		if (x == 0) break;

		cout << x << ' ';

		x = idx[x]; // idx[10] == 9, idx[9] == 3, idx[3] == 1, idx[1] == 0
	}

	return 0;
}
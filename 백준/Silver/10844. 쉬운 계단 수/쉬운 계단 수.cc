#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 쉬운 계단 수
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 계단 수 : 인접한 모든 자리의 차가 1이고 모든 계단 수는 0으로 시작 할 수 없음
	// 길이가 n인 계단 수가 총 몇개인지 구하기
	// 결과 % 1000000000 출력

	int n; // N 2
	cin >> n;

	// dp[i][j] : 길이가 i, 마지막 숫자가 j인 계단 수의 개수
	vector<vector<long long> > dp(n + 1, vector<long long>(10));
	int stairCnt = 0;

	// n == 1 : 1 2 3 4 5 6 7 8 9
	for (int i = 1; i < 10; i++) dp[1][i] = 1;

	// n == 2 ~
	for (int i = 2; i < n + 1; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			// j > 0 인 경우
			// 이전 숫자가 j - 1 일 수 있음
			// 현재 숫자가 3 -> 이전 숫자가 2
			// 길이가 i - 1이고 마지막 숫자가 j - 1인 계단 수의 개수를 현재 dp값에 누적
			// => j - 1에서 j로 한 칸 올라간 경우를 누적한것
			if (j > 0)
			{
				dp[i][j] += dp[i - 1][j - 1];
				dp[i][j] %= 1000000000;
			}

			// j < 0 인 경우
			// 이전 숫자가 j + 1 일 수 있음
			// 현재 숫자가 7 -> 이전 숫자가 8
			// 길이가 i - 1이고 마지막 숫자가 j + 1인 계단 수의 개수를 현재 dp값에 누적
			// => j + 1에서 j로 한 칸 내려간 경우를 누적한것
			if (j < 9)
			{
				dp[i][j] += dp[i - 1][j + 1];
				dp[i][j] %= 1000000000;
			}
		}
	}

	// n == n
	for (int i = 0; i < 10; i++)
	{
		stairCnt += dp[n][i];
		stairCnt %= 1000000000;
	}

	cout << stairCnt % 1000000000 << '\n';

	return 0;
}
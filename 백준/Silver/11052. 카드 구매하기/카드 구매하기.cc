#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 카드 구매하기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 카드팩 종류 => 1 ~ N 개가 포함된 카드팩
	// 카드가 i 개 들어있는 카드팩의 가격이 Pi
	// 돈을 최대한 많이 사용해서 카드 N 개를 구매 해야함

	int n; // N 4
	cin >> n;

	vector<long long> pi(n + 1); // 카드가 i 개 들어있는 카드팩의 가격, 1 5 6 7
	for (int i = 1; i < n + 1; i++) cin >> pi[i];
	vector<long long> dp(n + 1); // 카드 i 개를 구매하는데 필요한 최대비용 저장

	// 각 i개 카드팩에 대해 가능한 모든 j개 카드팩을 보면서
	// 현재 dp 값과 i - j 개의 카드를 구매하는 dp 값 + j 개가 들어있는 카드팩의 가격 둘 중 최댓값으로 갱신
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < i + 1; j++)
		{
			dp[i] = max(dp[i], dp[i - j] + pi[j]);
		}
	}

	cout << dp[n] << '\n';

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)
#define rloop(v, s, e) for(int v = s; v > e; v--)
#define elprint(a) cout << a << '\n'

// 앱
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m;
	cin >> n >> m;

	// memory => 각 앱이 사용 중인 메모리 양
	// cost => 각 앱을 비활성화 했을 때 추가 비용
	vector<int> memory(n + 1), cost(n + 1);
	loop(i, 1, n + 1) cin >> memory[i];
	loop(i, 1, n + 1) cin >> cost[i];

	// dp[i] => i 만큼의 메모리 양 확보를 위해 필요한 최소비용
	vector<int> dp(10001, -1);
	dp[0] = 0;

	// 각 앱을 비활성화 했을 때 dp 최솟값 갱신
	// 각 앱은 하나만 존재하므로 뒤에서부터 갱신
	// 비용이 계산된적이 있으면 => 현재 앱을 비활성화 했을 때 비용과 이전에 계산된 dp 둘 중 최댓값 갱신
	loop(i, 1, n + 1)
	{
		int m = memory[i];
		int c = cost[i];

		rloop(j, 10000, c - 1) if (dp[j - c] != -1) dp[j] = max(dp[j], dp[j - c] + m);
	}

	// m 바이트 확보를 위해 필요한 최소비용
	int minCost = 0;
	loop(j, 0, 10001)
	{
		if (dp[j] >= m)
		{
			minCost = j;
			break;
		}
	}

	elprint(minCost);

	return home;
}
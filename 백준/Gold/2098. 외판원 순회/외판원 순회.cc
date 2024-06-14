#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)
#define elprint(a) cout << a << '\n'
#define mat(t, v, r, c, i) vector<vector<t> > v(r, vector<t>(c, i))

// 외판원 순회
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n;
	cin >> n;

	mat(int, graph, n, n, 0);
	loop(i, 0, n) loop(j, 0, n) cin >> graph[i][j];

	// 1 << n => 0001에 대해 n비트 이동 => 2^n => 정점의 수가 n 개일 때 모든 가능한 상태
	// dp[mask][i] => 마지막 방문 정점이 i일 때 최소비용 저장
	mat(int, dp, 1 << n, n, 2147000000);
	dp[1][0] = 0;

	// 모든 가능한 mask와 i번 정점에 대해
	// dp[mask][i] == 2147000000 => 현재 mask에서 i번 정점이 방문되지 않았는지 체크
	// !(mask & (1 << j) => 정점 j가 아직 방문되지 않았는지 체크
	// graph[i][j] > 0 => i번 정점에서 j번 정점으로 이동할 수 있는지 체크
	// dp[mask | (1 << j)][j] => 새로운 상태에서 마지막으로 방문한 정점이 j일 때 최소비용
	// dp[mask][i] + graph[i][j] = 현재 상태에서 i번 정점에서 j번 정점으로 이동하는 비용 누적
	// 둘 중 최솟값으로 현재 dp값 갱신
	loop(mask, 1, 1 << n) loop(i, 0, n)
	{
		if (dp[mask][i] == 2147000000) continue;
		loop(j, 0, n) if (!(mask & (1 << j)) && graph[i][j] > 0)
			dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], dp[mask][i] + graph[i][j]);
	}

	// 모든 정점에서 출발 정점으로 돌아오는 최소비용
	// 모든 i번 정점에 대해
	// i번 정점에서 출발하여 0번 도시로 돌아오는 경로가 있는지 체크
	// (1 << n) - 1 => 모든 정점을 방문한 상태
	// dp[(1 << n) - 1][i] => 모든 정점을 방문한 상태에서 마지막으로 i번 정점에 있을 때 최소비용
	// graph[i][0] => i번 정점에서 0번 정점으로 돌아오는 비용
	// i번 정점에서 출발하여 모든 정점을 방문하고 마지막으로 i번 정점에 있다가 다시 0번 정점으로 돌아오는 최소비용
	int minCost = 2147000000;
	loop(i, 1, n) if (graph[i][0] > 0) minCost = min(minCost, dp[(1 << n) - 1][i] + graph[i][0]);

	elprint(minCost);

	return home;
}
#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)
#define elprint(a) cout << a << '\n'
#define mat(t, v, r) vector<vector<t> > v(r)

void DFS(int L, vector<vector<int> > &graph, vector<bool> &vis, vector<int> &dp)
{
	vis[L] = true;
	dp[L] = 1;

	loop(i, 0, graph[L].size())
	{
		if (vis[graph[L][i]]) continue;

		DFS(graph[L][i], graph, vis, dp);
		dp[L] += dp[graph[L][i]];
	}
}

// 트리와 쿼리
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n, r, q;
	cin >> n >> r >> q;
	mat(int, graph, n);
	queue<int> checkPos;
	vector<bool> vis(n);
	int v1, v2;
	loop(i, 0, n - 1)
	{
		cin >> v1 >> v2;
		graph[v1 - 1].push_back(v2 - 1);
		graph[v2 - 1].push_back(v1 - 1);
	}

	// r번 정점을 루트로하는 각 서브트리 정점 수
	vector<int> dp(n);
	DFS(r - 1, graph, vis, dp);

	// 각 쿼리 답
	int query;
	while (q--)
	{
		cin >> query;
		elprint(dp[query - 1]);
	}

	return home;
}
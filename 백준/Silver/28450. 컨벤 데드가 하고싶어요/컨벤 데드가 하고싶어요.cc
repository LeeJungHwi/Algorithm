#include <bits/stdc++.h>
using namespace std;

#define home 0
#define ll long long
#define loop(v, s, e) for(int v = s; v < e; v++)
#define elprint(a) cout << a << '\n'
#define cond(c, t, f) ((c) ? (t) : (f))
#define mat(t, v, r, c) vector<vector<t> > v(r, vector<t>(c))

// 컨벤 데드가 하고싶어요
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m;
	cin >> n >> m;
	mat(ll, graph, n + 1, m + 1);
	mat(ll, dp, n + 1, m + 1);
	loop(i, 1, n + 1) loop(j, 1, m + 1) cin >> graph[i][j];
	loop(i, 1, m + 1) dp[1][i] = dp[1][i - 1] + graph[1][i];
	loop(i, 1, n + 1) dp[i][1] = dp[i - 1][1] + graph[i][1];
	loop(i, 2, n + 1) loop(j, 2, m + 1) dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + graph[i][j];
	int h;
	cin >> h;
	elprint(cond(dp[n][m] > h, "NO", "YES"));
	if (dp[n][m] < h + 1) elprint(dp[n][m]);

	return home;
}
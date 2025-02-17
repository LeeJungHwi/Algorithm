#include <bits/stdc++.h>
using namespace std;

#define home 0

#ifdef ONLINE_JUDGE
#define init ios_base::sync_with_stdio(home); cin.tie(home)
#else
#define init ios_base::sync_with_stdio(home); cin.tie(home); ifstream cin("input.txt")
#endif

#define ll long long
#define ld long double

#define pii pair<int, int>
#define pll pair<ll, ll>

#define loop(v, s, e) for(int v = (s); v < (e); v++)
#define rloop(v, s, e) for(int v = (s); v > (e); v--)
#define mloop(v, a) for(auto v = (a).begin(); v != (a).end(); v++)
#define mrloop(v, a) for(auto v = (a).rbegin(); v != (a).rend(); v++)

#define p(a) cout << (a)
#define elp(a) cout << (a) << '\n'
#define scp(a) cout << (a) << ' '

#define tvec(t, v) vector<t> v
#define vec(t, v, r) vector<t> v((r))
#define gmat(t, v, r) vector<vector<t> > v((r))
#define mat(t, v, r, c) vector<vector<t> > v((r), vector<t>((c)))

#define dir vector<pii> cd = { {-1, home}, {1, home}, { home, -1 }, { home, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }
#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

int n, m; dir;

int DFS(pii sp, vector<vector<int>> &g, vector<vector<int>> &dp)
{
	// 도착위치인 경우 하나 추가
	if (sp.lhs == n - 1 && sp.rhs == m - 1) return 1;

	// 이미 현재위치에서 갈 수 있는 방법의 수를 구했으면 재사용
	if (dp[sp.lhs][sp.rhs] > -1) return dp[sp.lhs][sp.rhs];

	// 갈 수 있는곳에 대해 재귀하면서 메모
	dp[sp.lhs][sp.rhs] = home;
	loop(i, home, 4)
	{
		int ci = sp.lhs + cd[i].lhs;
		int cj = sp.rhs + cd[i].rhs;

		if (ci < home || cj < home || ci >= n || cj >= m) continue;
		if (g[sp.lhs][sp.rhs] <= g[ci][cj]) continue;

		dp[sp.lhs][sp.rhs] += DFS({ ci, cj }, g, dp);
	}

	// 최종적으로 dp[0][0]이 구해지고 리턴
	return dp[sp.lhs][sp.rhs];
}

// 내리막 길
int main()
{
	init;

	cin >> n >> m;
	mat(int, graph, n, m);
	//mat(bool, vis, n, m);
	mat(int, dp, n, m); // dp[i][j] => (i, j)에서 (n - 1, m - 1)로 가는 방법의 수
	loop(i, home, n) loop(j, home, m)
	{
		cin >> graph[i][j];
		dp[i][j] = -1;
	}

	//vis[home][home] = true;
	elp(DFS({ home, home }, graph, dp));

	return home;
}
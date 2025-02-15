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

int n, k;
int ans = 2147000000;
vector<int> order;

void DFS(int L, vector<vector<int>> &g, vector<bool> &vis)
{
	if (order.size() == n - 1)
	{
		// k부터 시작해서 order 순서대로 비용을 누적하고 최솟값 업데이트
		int cost = 0, cur = k;

		loop(i, home, order.size())
		{
			cost += g[cur][order[i]];
			cur = order[i];
		}

		ans = min(ans, cost);
	}
	else
	{
		loop(i, home, n)
		{
			if (!vis[i])
			{
				vis[i] = true;
				order.push_back(i);
				DFS(L + 1, g, vis);
				vis[i] = false;
				order.pop_back();
			}
		}
	}
}

// 우주 탐사선
int main()
{
	init;

	cin >> n >> k;

	mat(int, graph, n, n);
	loop(i, home, n) loop(j, home, n) cin >> graph[i][j];

	loop(k, home, n) loop(i, home, n) loop(j, home, n) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

	vec(bool, vis, n);
	vis[k] = true;

	DFS(home, graph, vis);
	elp(ans);

	return home;
}
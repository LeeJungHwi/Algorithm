#include <bits/stdc++.h>
using namespace std;

#define home 0

#define ll long long

#define pii pair<int, int>
#define pll pair<ll, ll>

#define loop(v, s, e) for(int v = (s); v < (e); v++)
#define rloop(v, s, e) for(int v = (s); v > (e); v--)
#define mloop(v, a) for(auto v = (a).begin(); v != (a).end(); v++)
#define mrloop(v, a) for(auto v = (a).rbegin(); v != (a).rend(); v++)
#define aloop(t, v, s, c, e, i) for(t v = (s); v c (e); i)

#define p(a) cout << (a)
#define elp(a) cout << (a) << '\n'
#define scp(a) cout << (a) << ' '

#define vec(t, v, r) vector<t> v((r))
#define mat(t, v, r, c) vector<vector<t> > v((r), vector<t>((c)))
#define gmat(t, v, r) vector<vector<t> > v((r))
#define dir vector<pii> checkDir = { {-1, 0}, {1, 0}, { 0, -1 }, { 0, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }

#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

int cnt;

void DFS(int L, vector<vector<int> > &g, vector<bool> &v, vector<int> &o)
{
	if(v[L]) return;
	v[L] = true;
	o[L] = ++cnt;
	sort(rall(g[L]));
	loop(i, home, g[L].size()) if (!v[g[L][i]]) DFS(g[L][i], g, v, o);
}

// 알고리즘 수업 - 깊이 우선 탐색 2
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	int n, m, k;
	cin >> n >> m >> k;
	gmat(int, graph, n);
	vec(bool, vis, n);
	vec(int, order, n);
	int v1, v2;
	loop(i, home, m)
	{
		cin >> v1 >> v2;
		graph[v1 - 1].push_back(v2 - 1);
		graph[v2 - 1].push_back(v1 - 1);
	}
	DFS(k - 1, graph, vis, order);
	loop(i, home, n) elp(order[i]);

	return home;
}
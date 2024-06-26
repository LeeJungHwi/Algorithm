#include <bits/stdc++.h>
using namespace std;

#define home 0

#define ll long long
#define ld long double

#define pii pair<int, int>
#define pis pair<int, string>
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
#define dir vector<pii> cd = { {-1, 0}, {1, 0}, { 0, -1 }, { 0, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }

#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

bool comp(const pis &p1, const pis &p2) { return p1.rhs < p2.rhs; }

// 랭킹전 대기열
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	int n, m;
	cin >> n >> m;

	gmat(pis, graph, 300);
	int l; string k; cin >> l >> k;
	graph[home].push_back({ l, k });
	int cnt = 1;
	loop(i, home, n - 1)
	{
		cin >> l >> k;
		bool isNew = false;
		loop(j, home, cnt)
		{
			if (graph[j].size() == m) continue;
			if (graph[j][home].lhs - 10 > l || graph[j][home].lhs + 10 < l) continue;
			graph[j].push_back({ l, k }); isNew = true; break;
		}
		if (!isNew) graph[cnt++].push_back({ l, k });
	}
	loop(i, home, cnt)
	{
		cond(graph[i].size() == m, elp("Started!"), elp("Waiting!"));
		sort(all(graph[i]), comp);
		loop(j, home, graph[i].size()) { scp(graph[i][j].lhs); elp(graph[i][j].rhs); }
	}


	return home;
}
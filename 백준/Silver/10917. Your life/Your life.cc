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

// Your life
int main()
{
	init;

	int n, m; cin >> n >> m;
	gmat(int, graph, n);
	vec(int, dis, n);
	int v1, v2;
	loop(i, home, m) { cin >> v1 >> v2; graph[--v1].push_back(--v2); }
	queue<int> cp;
	cp.push(home);
	dis[home] = 1;
	while (!cp.empty())
	{
		int s = cp.front(); cp.pop();
		loop(i, home, graph[s].size())
		{
			if (dis[graph[s][i]] > home) continue;
			cp.push(graph[s][i]);
			dis[graph[s][i]] = dis[s] + 1;
		}
	}
	elp(cond(!dis[--n], -1, --dis[n]));

	return home;
}
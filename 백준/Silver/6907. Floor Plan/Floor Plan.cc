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

// Floor Plan
int main()
{
	init;

	int k, n, m; cin >> k >> n >> m;
	mat(char, graph, n, m);
	mat(bool, vis, n, m);
	loop(i, home, n) loop(j, home, m) cin >> graph[i][j];
	tvec(int, v);
	queue<pii> cp; dir;
	loop(i, home, n) loop(j, home, m)
	{
		if (graph[i][j] == '.' && !vis[i][j])
		{
			cp.push({ i, j });
			vis[i][j] = true;
			int cnt = 1;

			while (!cp.empty())
			{
				pii s = cp.front(); cp.pop();
				loop(l, home, 4)
				{
					int ci = s.lhs + cd[l].lhs;
					int cj = s.rhs + cd[l].rhs;
					if (ci < home || cj < home || ci >= n || cj >= m) continue;
					if (vis[ci][cj]) continue;
					if (graph[ci][cj] == 'I') continue;
					cp.push({ ci, cj });
					vis[ci][cj] = true;
					++cnt;
				}
			}
			v.push_back(cnt);
		}
	}
	sort(rall(v));

	int i = 0;
	int ans = home;
	while (i < v.size() && k >= v[i])
	{
		k -= v[i];
		ans++;
		i++;
	}

	scp(ans);
	ans == 1 ? scp("room,") : scp("rooms,");
	scp(k);
	elp("square metre(s) left over");

	return home;
}
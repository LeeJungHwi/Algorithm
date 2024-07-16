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

// RAINFOREST CANOPY
int main()
{
	init;

	int n, cur = home;
	while (cin >> n)
	{
		mat(char, graph, n, n);
		mat(bool, vis, n, n);
		queue<pii> cp; dir;
		loop(i, home, n) loop(j, home, n) cin >> graph[i][j];
		int ans = home;
		loop(i, home, n) loop(j, home, n) if (graph[i][j] == '1')
		{
			if (vis[i][j]) continue;
			cp.push({ i, j });
			vis[i][j] = true;
			++ans;
			while (!cp.empty())
			{
				pii s = cp.front(); cp.pop();
				loop(k, home, 8)
				{
					int ci = s.lhs + cd[k].lhs;
					int cj = s.rhs + cd[k].rhs;
					if (ci < home || cj < home || ci >= n || cj >= n) continue;
					if (vis[ci][cj]) continue;
					if (graph[ci][cj] == '0') continue;
					cp.push({ ci, cj });
					vis[ci][cj] = true;
				}
			}
		}
		p("Case #"); p(++cur); scp(":"); elp(ans);
	}

	return home;
}
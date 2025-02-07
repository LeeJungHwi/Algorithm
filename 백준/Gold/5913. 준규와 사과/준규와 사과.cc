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

int k, ans; dir;

void DFS(pii sp, int cnt, vector<vector<int>> &g, vector<vector<bool>> &vis)
{
	if (sp.lhs == 4 && sp.rhs == 4)
	{
		if (cnt == 25 - k) ans++;
	}
	else
	{
		loop(i, home, 4)
		{
			int ci = sp.lhs + cd[i].lhs;
			int cj = sp.rhs + cd[i].rhs;

			if (ci < home || cj < home || ci >= 5 || cj >= 5) continue;
			if (g[ci][cj] == 1) continue;
			if (vis[ci][cj]) continue;

			vis[ci][cj] = true;
			DFS({ ci, cj }, cnt + 1, g, vis);
			vis[ci][cj] = false;
		}
	}
}

// 준규와 사과
int main()
{
	init;

	mat(int, graph, 5, 5);
	mat(bool, vis, 5, 5);
	cin >> k;
	int n, m;
	loop(i, home, k)
	{
		cin >> n >> m;
		graph[--n][--m] = 1;
	}

	vis[home][home] = true;
    DFS({home, home}, 1, graph, vis);
    elp(ans);

	return home;
}
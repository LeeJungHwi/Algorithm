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

// 돌다리
int main()
{
	init;

	int a, b, n, m; cin >> a >> b >> n >> m;
	vec(int, dis, 100001);
	queue<int> cp;
	cp.push(n);
	dis[n] = 1;
	while (!cp.empty())
	{
		int s = cp.front();
		cp.pop();
		if (s == m)
		{
			elp(--dis[m]);
			return home;
		}
		tvec(int, d);
		d.push_back(s + 1);
		d.push_back(s - 1);
		d.push_back(s + a);
		d.push_back(s - a);
		d.push_back(s + b);
		d.push_back(s - b);
		d.push_back(s * a);
		d.push_back(s * b);
		loop(i, home, 8)
		{
			int c = d[i];
			if (c < home || c > 100000) continue;
			if (dis[c] > home) continue;
			dis[c] = dis[s] + 1;
			cp.push(c);
		}
	}

	return home;
}
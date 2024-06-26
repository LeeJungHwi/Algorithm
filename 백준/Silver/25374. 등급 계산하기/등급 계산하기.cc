#include <bits/stdc++.h>
using namespace std;

#define home 0

#define ll long long
#define ld long double

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
#define dir vector<pii> cd = { {-1, 0}, {1, 0}, { 0, -1 }, { 0, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }

#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

// 등급 계산하기
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	int n;
	cin >> n;
	vec(int, v, n);
	loop(i, home, n) cin >> v[i];
	sort(rall(v));
	vec(int, s, 9);
	s[home] = ceil(0.04 * n); s[1] = ceil(0.11 * n); s[2] = ceil(0.23 * n);
	s[3] = ceil(0.40 * n); s[4] = ceil(0.60 * n); s[5] = ceil(0.77 * n);
	s[6] = ceil(0.89 * n); s[7] = ceil(0.96 * n); s[8] = n;
	vec(int, c, 9);
	int cur = home;
	loop(i, home, 9)
	{
		int l = s[i];
		while (l < n && v[l] == v[l - 1]) l++;
		c[i] = l - cur;
		cur = l;
	}
	vec(int, ans, 9);
	int g = home;
	loop(i, home, n)
	{
		if (c[g] > home)
		{
			ans[g]++;
			c[g]--;
			continue;
		}
		g++;
		while (g < 9 && !c[g]) g++;
		ans[g]++;
		c[g]--;
	}
	loop(i, home, 9) elp(ans[i]);

	return home;
}

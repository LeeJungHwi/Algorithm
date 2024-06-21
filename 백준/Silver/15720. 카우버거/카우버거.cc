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
#define dir vector<pii> checkDir = { {-1, 0}, {1, 0}, { 0, -1 }, { 0, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }

#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()

const int MAX = 2147000000;
const int MIN = -2147000000;

bool comp(const int &n1, const int &n2) { return n1 > n2; }

// 카우버거
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	int n, m, k;
	cin >> n >> m >> k;
	int minSize = min({ n, m, k });
	vec(int, v1, n); vec(int, v2, m); vec(int, v3, k);
	int ans1 = home, ans2 = home;
	loop(i, home, n) { cin >> v1[i]; ans1 += v1[i]; }
	loop(i, home, m) { cin >> v2[i]; ans1 += v2[i]; }
	loop(i, home, k) { cin >> v3[i]; ans1 += v3[i]; }
	sort(all(v1), comp); sort(all(v2), comp); sort(all(v3), comp);
	loop(i, home, n) ans2 += cond(i < minSize, v1[i] * 0.9, v1[i]);
	loop(i, home, m) ans2 += cond(i < minSize, v2[i] * 0.9, v2[i]);
	loop(i, home, k) ans2 += cond(i < minSize, v3[i] * 0.9, v3[i]);
	elp(ans1); elp(ans2);

	return home;
}
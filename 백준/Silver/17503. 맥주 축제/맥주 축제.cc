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

bool comp(const pll &p1, const pll &p2) { return p1.rhs < p2.rhs; }

// 맥주 축제
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	ll n, m, k;
	cin >> n >> m >> k;
	vec(pll, v, k);
	priority_queue<pll> maxHeap;
	int n1, n2;
	loop(i, home, k) cin >> v[i].lhs >> v[i].rhs;
	sort(all(v), comp);
	ll l = 1, r = v[k - 1].rhs, ans = -1;
	while (l <= r)
	{
		ll s = (l + r) / 2;
		while (!maxHeap.empty()) maxHeap.pop();
		loop(i, home, k) if (v[i].rhs <= s) maxHeap.push(v[i]);
		ll cnt = home;
		if (maxHeap.size() >= n) loop(i, home, n)
		{
			cnt += maxHeap.top().lhs;
			if (cnt >= m) break;
			maxHeap.pop();
		}
		if (cnt >= m) { ans = s--; r = s; }
		else l = ++s;
	}
	elp(ans);

	return home;
}
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

// 겹치는 건 싫어
int main()
{
	init;

	// 같은 요소가 k개를 넘기면 안 됨
	ll n, k; cin >> n >> k;
	vec(ll, v, n);
	loop(i, home, n) cin >> v[i];

	map<ll, ll> m; // 수열에 있는 수 카운팅
	ll ans = home, l = home;

	loop(h, home, n)
	{
		// 현재 요소 카운팅
		m[v[h]]++;

		// 수열 내 현재 요소가 k개를 넘기면 lo 이동
		while (m[v[h]] > k)
		{
			m[v[l]]--;
			l++;
		}

		ans = max(ans, h - l + 1);
	}
	elp(ans);

	return home;
}
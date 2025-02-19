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

// 합이 0인 네 정수
int main()
{
	init;

	// A, B 두 요소 합
	// C, D 두 요소 합
	// s = A, B 두 요소 합
	// l = lb(-s) h = ub(-s)
	// ans에 h - l 누적

	ll n; cin >> n;
	vec(ll, A, n); vec(ll, B, n); vec(ll, C, n); vec(ll, D, n);
	loop(i, home, n) cin >> A[i] >> B[i] >> C[i] >> D[i];

	tvec(ll, pAB); // A, B 두 요소 합
	tvec(ll, pCD); // C, D 두 요소 합
	loop(i, home, n) loop(j, home, n)
	{
		pAB.push_back(A[i] + B[j]);
		pCD.push_back(C[i] + D[j]);
	}
	sort(all(pCD)); // lb, ub

	ll ans = home;
	loop(i, home, pAB.size())
	{
		ll s = pAB[i];
		ll l = lower_bound(all(pCD), -s) - pCD.begin();
		ll h = upper_bound(all(pCD), -s) - pCD.begin();
		ans += h - l;
	}
	elp(ans);

	return home;
}
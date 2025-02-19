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

// 두 배열의 합
int main()
{
	init;

	// A, B 연속 부 배열 누적합
	// s = A 연속 부 배열
	// l = lb(t - s), h = ub(t - s)
	// ans에 h - l 누적 : l(t - s 이상인 첫 요소의 주소값) h(t - s를 초과하는 첫 요소의 주소값)

	int t, n, m; cin >> t >> n;

	vec(ll, A, n);
	loop(i, home, n) cin >> A[i];
	tvec(ll, pA); // A 연속 부 배열 누적합
	loop(i, home, n)
	{
		ll pSum = A[i];
		pA.push_back(pSum);

		loop(j, i + 1, n)
		{
			pSum += A[j];
			pA.push_back(pSum);
		}
	}
	cin >> m;
	vec(ll, B, m);
	loop(i, home, m) cin >> B[i];
	tvec(ll, pB); // B 연속 부 배열 누적합
	loop(i, home, m)
	{
		ll pSum = B[i];
		pB.push_back(pSum);

		loop(j, i + 1, m)
		{
			pSum += B[j];
			pB.push_back(pSum);
		}
	}
	sort(all(pB)); // lb, ub

	ll ans = home;
	loop(i, home, pA.size())
	{
		ll s = pA[i];
		ll l = lower_bound(all(pB), t - s) - pB.begin();
		ll h = upper_bound(all(pB), t - s) - pB.begin();
		ans += h - l;
	}
	elp(ans);

	return home;
}
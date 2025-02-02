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

ll n, k;

bool Check(ll standard, vector<ll> &v)
{
	// 막걸리를 받은 친구의 수
	int cnt = home;

	loop(i, home, n)
	{
		// 현재 주전자에 담긴 막걸리 양
		ll cur = v[i];

		// 받은 친구의 수가 k명 이상이면 가능한 용량
		cnt += cur / standard;
		if (cnt >= k) return true;
	}

	// k명에게 나눠주지 못 하면 불가능한 용량
	return false;
}

// 이상한 술집
int main()
{
	init;

	cin >> n >> k;
	vec(ll, v, n);

	// lo = 1
	// hi = 막걸리 용량의 최대값
	ll l = 1, h = -2147000000;

	loop(i, home, n)
	{
		cin >> v[i];
		h = max(h, v[i]);
	}

	ll ans = 1;
	while (l <= h)
	{
		ll s = (l + h) / 2;

		// 가능한경우 더 최대가 있는지 재탐색
		if (Check(s, v))
		{
			l = s + 1;
			ans = s;
		}
		else h = s - 1;
	}
	elp(ans);

	return home;
}
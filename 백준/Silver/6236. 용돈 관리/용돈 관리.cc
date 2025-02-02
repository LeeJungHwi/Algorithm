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

// 용돈 관리
int main()
{
	init;

	ll n, m; cin >> n >> m;
	vec(ll, use, n);
	ll l = -2147000000, h = n * 10000;
	loop(i, home, n)
	{
		cin >> use[i];
		l = max(l, use[i]);
	}

	// lo = 이용 금액 중 최대값
	// hi = n * 10000
	int ans = -1;
	while (l <= h)
	{
		ll s = (l + h) / 2;

		ll money = s, k = 1;
		loop(i, home, n)
		{
			// 하루를 보낼 수 있으면
			if (money >= use[i])
			{
				money -= use[i];
				continue;
			}

			// 하루를 보낼 수 없으면
			k++;
			money = s - use[i];
		}

		// k == m 일때도 s가 최소라는 보장이 없음
		// 더 작은 k가 가능할 수 있으므로 재탐색
		if (k <= m)
		{
			h = s - 1;
			ans = s;
		}
		else l = s + 1;
	}
	elp(ans);

	return home;
}
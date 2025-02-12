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

// 징검다리 건너기 (large)
int main()
{
	init;

	// 기준 => 쓸 수 있는 최대 힘
	// lo => 1
	// hi => n * 1000000
	// s로 건널 수 있으면 가능한경우
	ll n; cin >> n;
	vec(ll, v, n);
	loop(i, home, n) cin >> v[i];

	ll l = 1, h = n * 1000000, ans = home;

	while (l <= h)
	{
		ll s = (l + h) / 2;

		vec(int, dp, n);
		dp[home] = 1;

		bool is = false;
		loop(i, home, n)
		{
			if (dp[i] == home) continue;

			loop(j, i + 1, n)
			{
				ll power = (j - i) * (1 + abs(v[i] - v[j]));
				
				if (power > s) continue;

				dp[j] = 1;

				if (j == n - 1)
				{
					is = true;
					break;
				}
			}

			if (is) break;
		}

		if (is)
		{
			ans = s;
			h = s - 1;
		}
		else l = s + 1;
	}
	elp(ans);

	return home;
}
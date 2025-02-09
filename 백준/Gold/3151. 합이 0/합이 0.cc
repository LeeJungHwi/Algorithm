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

vector<int> v;

int main()
{
	init;

	ll n; cin >> n;
	vec(ll, v, n);
	loop(i, home, n) cin >> v[i];
	sort(all(v));

	ll ans = home;
	loop(i, home, n - 2)
	{
		ll l = i + 1;
		ll h = n - 1;

		while (l < h)
		{
			ll lVal = v[l];
			ll hVal = v[h];

			ll sum = v[i] + lVal + hVal;

			// 합이 0이 되는경우를 찾으면
			// lo == hi => lo ~ hi사이가 모두 같은 수
			// lo != hi => lo ~ hi사이 lo와 같은 수의 개수 * hi와 같은 수의 개수
			if (sum == home)
			{
				if (lVal == hVal)
				{
					ans += h - l;
					l++;
				}
				else
				{
					ll lCnt = home, rCnt = home;

					// lo와 같은 수의 개수 카운팅
					while (l < h && v[l] == lVal)
					{
						lCnt++;
						l++;
					}

					// hi와 같은 수의 개수 카운팅
					while (h >= l && v[h] == hVal)
					{
						rCnt++;
						h--;
					}

					ans += lCnt * rCnt;
				}
			}
			else if (sum > home) h--;
			else l++;
		}
	}
	elp(ans);

	return home;
}

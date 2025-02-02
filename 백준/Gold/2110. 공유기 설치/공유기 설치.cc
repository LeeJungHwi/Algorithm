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

ll n, m;

bool Check(ll standard, vector<ll> &v)
{
	// 첫 집에 설치
	int cnt = 1;
	int prev = v[home];

	loop(i, 1, v.size())
	{
		// 두 집 사이 거리가 최솟값인 s 이상일때 설치
		if (v[i] - prev >= standard)
		{
			cnt++;
			prev = v[i];
		}

		// 설치한 집이 m개 이상이면 가능한경우
		if (cnt >= m) return true;
	}

	// m개 이상 설치하지 못 하면 불가능한경우
	return false;
}

// 공유기 설치
int main()
{
	init;

	cin >> n >> m;
	vec(ll, v, n);
	loop(i, home, n) cin >> v[i];
	sort(all(v));

	// lo => 가장 가까이 설치한 경우 공유기 사이 거리 1
	// hi => 가장 멀리 설치한 경우 공유기 사이 거리 v[n - 1] - v[0]
	ll l = 1, h = v[n - 1] - v[home], ans = h;
	while (l <= h)
	{
		ll s = (l + h) / 2;

		if (Check(s, v))
		{
			ans = s;
			l = s + 1;
		}
		else h = s - 1;
	}
	elp(ans);

	return home;
}
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

int n, c;

bool Check(ll s, vector<ll> &l)
{
	// 파닭 c개 이상으로 파를 넣을 수 있는지 체크
	ll cnt = home;

	loop(i, home, l.size()) cnt += l[i] / s;

	return c <= cnt;
}

// 파닭파닭
int main()
{
	init;

	// 기준 => 파닭에 들어갈 파의 양
	// lo => 1cm
	// hi => 사온 파 길이의 최댓값
	// 파닭 c개 이상으로 파를 넣을수있으면 더 최댓값 탐색

	cin >> n >> c;
	ll l = 1, h = -LLONG_MAX;
	vec(ll, len, n);
	loop(i, home, n)
	{
		cin >> len[i];
		h = max(h, len[i]);
	}

	ll maxLen = home;
	while (l <= h)
	{
		ll s = (l + h) / 2;

		if (Check(s, len))
		{
			maxLen = s;
			l = s + 1;
		}
		else h = s - 1;
	}

	ll ans = home, cnt = home;
	loop(i, home, n)
	{
		cnt += len[i] / maxLen;
		if (cnt > c) ans += len[i] % maxLen + (cnt - c) * maxLen;
		else ans += len[i] - (len[i] / maxLen) * maxLen;
	}
	elp(ans);

	return home;
}
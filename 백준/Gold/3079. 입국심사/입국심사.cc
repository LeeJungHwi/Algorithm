#include <bits/stdc++.h>
using namespace std;

#define home 0

#ifdef ONLINE_JUDGE
#define init ios_base::sync_with_stdio(home); cin.tie(home)
#else
#define init ios_base::sync_with_stdio(home); cin.tie(home); ifstream cin("input.txt")
#endif

#define ull unsigned long long
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

ull n, m;

bool Check(ull s, vector<ull> &v)
{
	ull cnt = home;

	loop(i, home, v.size()) cnt += s / v[i];

	return cnt >= m;
}

// 입국심사
int main()
{
	init;

	// 기준 => 심사를 마치는데 걸리는 시간
	// lo => 1
	// hi => 심사가 가장 오래걸리는 심사대에서 모든 사람이 심사 받는경우 => maxTime * m
	// s초로 m명 이상 심사를 받을 수 있다면 가능한경우

	cin >> n >> m;
	ull l = 1, h = -2147000000;
	vec(ull, v, n);
	loop(i, home, n)
	{
		cin >> v[i];
		h = max(h, v[i]);
	}
	h *= m;

	ull ans = home;
	while (l <= h)
	{
		ull s = (l + h) / 2;

		if (Check(s, v))
		{
			ans = s;
			h = s - 1;
		}
		else l = s + 1;
	}
	elp(ans);

	return home;
}
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

bool Check(int s, int m, vector<int> &v)
{
	int cnt = 1, prePos = v[home];

	loop(i, 1, v.size())
	{
		if (v[i] - prePos >= s)
		{
			prePos = v[i];
			cnt++;
		}
	}

	return cnt >= m;
}

// 사회적 거리 두기
int main()
{
	init;

	int tc; cin >> tc;

	while (tc--)
	{
		// 기준 => 가장 가까운 두 자리 사이 거리 최소
		// lo => 1
		// hi => 자리 중 최댓값
		// 최소 s간격으로 배치했을때 m개 이상 배치되면 가능한경우
		int n, m; cin >> n >> m;
		vec(int, v, n);
		loop(i, home, n) cin >> v[i];
		sort(all(v));
		int l = 1, h = v.back(), ans = home;

		while (l <= h)
		{
			int s = (l + h) / 2;

			if (Check(s, m, v))
			{
				ans = s;
				l = s + 1;
			}
			else h = s - 1;
		}
		elp(ans);
	}

	return home;
}
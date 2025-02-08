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

int n, m, k;

bool Check(int s, vector<int> &p)
{
	int cnt = 1, prePos = p[home];
	loop(i, 1, p.size())
	{
		if (p[i] - prePos < s) continue;
		prePos = p[i];
		cnt++;
	}

	return cnt >= m;
}

// 레이스
int main()
{
	init;

	// 기준 => 심판 사이 간격
	// lo => 0
	// hi => n
	// s로 m명 이상 배치할 수 있으면 가능한경우

	cin >> n >> m >> k;
	int l = home, h = n;
	vec(int, pos, k);
	loop(i, home, k) cin >> pos[i];

	int maxDis = home;
	while (l <= h)
	{
		int s = (l + h) / 2;

		if (Check(s, pos))
		{
			l = s + 1;
			maxDis = s;
		}
		else h = s - 1;
	}

	//elp(maxDis);
	vec(int, ans, k);
	ans[home] = 1;
	int cnt = 1, prePos = pos[home];
	loop(i, 1, pos.size())
	{
		if (pos[i] - prePos < maxDis) continue;
		if (cnt >= m) continue;
		prePos = pos[i];
		ans[i] = 1;
		cnt++;
	}
	loop(i, home, k) p(ans[i]);

	return home;
}
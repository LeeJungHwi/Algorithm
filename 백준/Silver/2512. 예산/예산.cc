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

int n, m;

bool Check(int s, vector<int> &r)
{
	int sum = home;

	// 예산 요청액이 상한선을 넘기면 상한선 누적, 넘기지 않으면 요청액 누적
	loop(i, home, r.size()) sum += cond(r[i] > s, s, r[i]);

	return sum <= m;
}

// 예산
int main()
{
	init;

	// 상한액 기준
	// lo => 예산을 주지 않는 경우
	// hi => 예산 요청액 중 최댓값

	cin >> n;
	vec(int, req, n);
	int l = home, h = -2147000000;
	loop(i, home, n)
	{
		cin >> req[i];
		h = max(h, req[i]);
	}
	cin >> m;

	int ans = home;
	while (l <= h)
	{
		int s = (l + h) / 2;

		// m이하로 예산을 모두 줄 수 있으면 상한선 늘림
		if (Check(s, req))
		{
			ans = s;
			l = s + 1;
		}
		else h = s - 1;
	}
	elp(ans);

	return home;
}
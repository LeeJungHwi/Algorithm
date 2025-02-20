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

// 회전 초밥
int main()
{
	init;

	// 슬라이딩 윈도 => 윈도우 크기 k
	int n, d, k, c; cin >> n >> d >> k >> c;
	vec(int, rotation, n);
	loop(i, home, n) cin >> rotation[i];

	map<int, int> m; // 초밥 카운팅

	// 윈도우 초기화
	loop(i, home, k) m[rotation[i]]++;

	// 가짓수 초기화
	int cnt = m.size();
	if (m[c] == home)
	{
		cnt++;
		m[c]++;
	}

	int ans = cnt;
	loop(i, home, n)
	{
		// lhs 한칸 이동 => lhs에서 먹은 초밥을 제거했을 때 0이면 제거
		if(--m[rotation[i]] == home) cnt--;

		// rhs 한칸 이동 => rhs에서 먹은 초밥이 새로 먹은 초밥이면 추가
		if(++m[rotation[(i + k) % n]] == 1) cnt++;

		// 가짓수 최댓값 업데이트 => 먹은 초밥 중 쿠폰 초밥이 없으면 1개 추가
		ans = max(ans, cnt + cond(m[c] > home, home, 1));
	}
	elp(ans);

	return home;
}
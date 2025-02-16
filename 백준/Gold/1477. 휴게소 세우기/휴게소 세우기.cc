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

bool Check(int s, vector<int> &v)
{
	int cnt = home;

	loop(i, 1, v.size())
	{
		int dis = v[i] - v[i - 1] - 1;// 현재 구간 거리
		cnt += dis / s; // 최대 s간격을 유지하기위해 필요한 휴게소 개수
	}

	return cnt <= m;
}

// 휴게소 세우기
int main()
{
	init;

	cin >> n >> m >> k;
	vec(int, v, n);
	loop(i, home, n) cin >> v[i];

	// 고속도로 시작과 끝점 추가 => 고속도로 시작 ~ 첫 번째 휴게소 구간, 마지막 휴게소 ~ 고속도로 끝 구간
	v.push_back(home); v.push_back(k);
	sort(all(v));

	// 기준 => 두 휴게소 사이 최대 간격
	// lo => 최소간격 1
	// hi => 최대간격 k - 1
	// 최대간격을 s로 유지하면서 필요한 휴게소의 개수가 m개 이하면 가능한경우

	int lo = 1, hi = k - 1, ans = home;

	while (lo <= hi)
	{
		int s = (lo + hi) / 2;

		if (Check(s, v))
		{
			ans = s;
			hi = s - 1;
		}
		else lo = s + 1;
	}
	elp(ans);

	return home;
}
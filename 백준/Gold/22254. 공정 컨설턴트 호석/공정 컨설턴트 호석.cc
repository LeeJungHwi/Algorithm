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

int n, x;

bool Check(int s, vector<int> &v)
{
	priority_queue<int, vector<int>, greater<int>> pq;

	// 가장 빨리 끝나는 공정 라인에서 선물 제작
	loop(i, home, n)
	{
		if (pq.size() < s) pq.push(v[i]);
		else
		{
			int time = pq.top();
			pq.pop();
			pq.push(time + v[i]);
		}
	}

	// 가장 오래걸리는 공정 라인의 시간 <= x인 경우 가능한 경우
	while (pq.size() > 1) pq.pop();

	return pq.top() <= x;
}

// 공정 컨설턴트 호석
int main()
{
	init;

	// 기준 => 공정 라인의 수
	// lo => 1
	// hi => n
	// 모든 선물을 제작하는데 걸리는 시간이 x이하면 가능한경우

	cin >> n >> x;
	int l = 1, h = n;
	vec(int, v, n);
	loop(i, home, n) cin >> v[i];

	int ans = home;
	while (l <= h)
	{
		int s = (l + h) / 2;

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
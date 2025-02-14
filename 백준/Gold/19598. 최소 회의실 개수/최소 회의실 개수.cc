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

bool comp(const pii & p1, const pii & p2)
{
	// 시작 시간 오름차순
	// 끝나는 시간 오름차순
	if (p1.lhs != p2.lhs) return p1.lhs < p2.lhs;
	return p1.rhs < p2.rhs;
}

// 최소 회의실 개수
int main()
{
	init;

	int n; cin >> n;
	vec(pii, v, n);
	loop(i, home, n) cin >> v[i].lhs >> v[i].rhs;
	sort(all(v), comp);

	priority_queue<int, vector<int>, greater<int>> pq;
	
	loop(i, home, n)
	{
		pii cur = v[i];

		if (!pq.empty() && pq.top() <= cur.lhs) pq.pop();
		pq.push(cur.rhs);
	}
	elp(pq.size());

	return home;
}
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
	if (p1.lhs != p2.lhs) return p1.lhs < p2.lhs;
	return p1.rhs < p2.rhs;
}

// 강의실
int main()
{
	init;

	// 3 2 14
	// 1 3 8
	// 5 6 20
	// 8 6 27
	// 2 7 13
	// 4 12 18
	// 6 15 21
	// 7 20 25

	int n; cin >> n;
	vec(pii, room, n);
	int num, s, e;
	loop(i, home, n)
	{
		cin >> num >> s >> e;
		room[i] = { s, e };
	}
	sort(room.begin(), room.end(), comp);

	priority_queue<int, vector<int>, greater<int>> pq;

	loop(i, home, n)
	{
		// 시작시간 오름차순
		// 끝나는시간 오름차순
		pii cur = room[i];

		// 현재 강의실 중 가장빨리끝나는 강의실의 끝나는시간이
		// 현재 강의 시작시간 이하면 해당 강의실에서 강의할수있으므로 pop하고 현재강의 끝나는시간 저장
		// 아니면 pop하지않고 새로운 강의실 저장
		if (!pq.empty() && pq.top() <= cur.lhs) pq.pop();
		pq.push(cur.rhs);
	}
	elp(pq.size());

	return home;
}
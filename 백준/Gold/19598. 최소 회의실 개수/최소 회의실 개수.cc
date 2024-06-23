#include <bits/stdc++.h>
using namespace std;

#define home 0

#define ll long long

#define pii pair<int, int>
#define pll pair<ll, ll>

#define loop(v, s, e) for(ll v = (s); v < (e); v++)
#define rloop(v, s, e) for(int v = (s); v > (e); v--)
#define mloop(v, a) for(auto v = (a).begin(); v != (a).end(); v++)
#define mrloop(v, a) for(auto v = (a).rbegin(); v != (a).rend(); v++)
#define aloop(t, v, s, c, e, i) for(t v = (s); v c (e); i)

#define p(a) cout << (a)
#define elp(a) cout << (a) << '\n'
#define scp(a) cout << (a) << ' '

#define vec(t, v, r) vector<t> v((r))
#define mat(t, v, r, c) vector<vector<t> > v((r), vector<t>((c)))
#define dir vector<pii> checkDir = { {-1, 0}, {1, 0}, { 0, -1 }, { 0, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }

#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()

const int MAX = 2147000000;
const int MIN = -2147000000;

struct Num
{
	int room;
	ll number;

	Num() {}
	Num(int r, ll n) : room(r), number(n) {}

	bool operator<(const Num &num)const { return number > num.number; }
};

bool comp(const pll &p1, const pll &p2)
{
	if (p1.lhs != p2.lhs) return p1.lhs < p2.lhs;
	return p1.rhs < p2.rhs;
}

// 최소 회의실 개수
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	int n;
	cin >> n;

	vec(pll, v, n);
	loop(i, home, n) cin >> v[i].lhs >> v[i].rhs;
	sort(all(v), comp);
	priority_queue<Num> minHeap;
	int ans = 1;
	minHeap.push(Num(ans, v[home].rhs));
	loop(i, 1, n)
	{
		if (minHeap.top().number <= v[i].lhs)
		{
			int n1 = minHeap.top().room;
			minHeap.pop();
			minHeap.push(Num(n1, v[i].rhs));
			continue;
		}
		minHeap.push(Num(++ans, v[i].rhs));
	}
	elp(ans);

	return home;
}
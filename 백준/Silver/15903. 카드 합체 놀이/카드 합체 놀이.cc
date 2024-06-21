#include <bits/stdc++.h>
using namespace std;

#define home 0

#define ll long long

#define pii pair<int, int>
#define pll pair<ll, ll>

#define loop(v, s, e) for(int v = (s); v < (e); v++)
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
	ll number;

	Num() {}
	Num(ll n) : number(n) {}

	bool operator<(const Num &num)const { return number > num.number; }
};

// 카드 합체 놀이
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	int n, m;
	cin >> n >> m;
	priority_queue<Num> minHeap;
	ll num;
	loop(i, home, n) { cin >> num; minHeap.push(Num(num)); }
	loop(i, home, m)
	{
		ll n1 = minHeap.top().number; minHeap.pop();
		ll n2 = minHeap.top().number; minHeap.pop();
		loop(j, home, 2) minHeap.push(Num(n1 + n2));
	}
	ll ans = home;
	while (!minHeap.empty()) { ans += minHeap.top().number; minHeap.pop(); }
	elp(ans);

	return home;
}
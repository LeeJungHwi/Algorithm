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

// 삼각형 만들기
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	int n;
	cin >> n;
	priority_queue<int> maxHeap;
	int num;
	loop(i, home, n) { cin >> num; maxHeap.push(num); }
	int ans = home;
	while (maxHeap.size() > 2)
	{
		int n1 = maxHeap.top(); maxHeap.pop();
		int n2 = maxHeap.top(); maxHeap.pop();
		int n3 = maxHeap.top(); maxHeap.pop();
		if (n1 < n2 + n3) { ans = n1 + n2 + n3; break; }
		maxHeap.push(n2); maxHeap.push(n3);
	}
	cond(!ans, elp(-1), elp(ans));

	return home;
}
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

// 알고리즘 수업 - 너비 우선 탐색 1
int main()
{
	init;

	int n, m, r; cin >> n >> m >> r;
	vec(int, order, n);
	int cur = 1;
	order[r - 1] = cur++;

	gmat(int, graph, n);
	int u1, u2;
	loop(i, home, m)
	{
		cin >> u1 >> u2;
		
		// 0 -> 3, 1
		// 1 -> 0, 2, 4
		// 2 -> 1, 3
		// 3 -> 0, 2
		// 4 -> 1
		graph[u1 - 1].push_back(u2 - 1);
		graph[u2 - 1].push_back(u1 - 1);
	}
	loop(i, home, n) sort(graph[i].begin(), graph[i].end());

	queue<int> cp;
	cp.push(r - 1);
	while (!cp.empty())
	{
		int s = cp.front();
		cp.pop();

		loop(i, home, graph[s].size())
		{
			if (order[graph[s][i]] > home) continue;
			order[graph[s][i]] = cur++;
			cp.push(graph[s][i]);
		}
	}

	loop(i, home, n) cout << order[i] << '\n';

	return home;
}
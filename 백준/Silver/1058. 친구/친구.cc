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

// 친구
int main()
{
	init;

	// 거리가 2이하로 연결되어있으면 2-친구
	// 각 정점의 2-친구 수의 최댓값

	int n; cin >> n;
	mat(int, graph, n + 1, n + 1);
	loop(i, home, n + 1) loop(j, home, n + 1) graph[i][j] = 1000000000;
	char ic;
	loop(i, 1, n + 1)
	{
		loop(j, 1, n + 1)
		{
			cin >> ic;
			if (ic == 'Y') graph[i][j] = 1;
		}
	}
	loop(i, home, n + 1) graph[i][i] = home;

	loop(k, 1, n + 1)
	{
		loop(i, 1, n + 1)
		{
			loop(j, 1, n + 1)
			{
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	//for (auto a : graph)
	//{
	//	for (auto b : a)
	//	{
	//		scp(b);
	//	}
	//	elp(' ');
	//}

	int ans = -2147000000;
	loop(i, 1, n + 1)
	{
		int cnt = home;
		loop(j, 1, n + 1)
		{
			if (i == j) continue;
			if (graph[i][j] <= 2) cnt++;
		}
		ans = max(ans, cnt);
	}
	elp(ans);

	return home;
}
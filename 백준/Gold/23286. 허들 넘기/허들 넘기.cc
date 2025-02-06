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

// 허들 넘기
int main()
{
	init;

	// 경로상 허들 최대 높이의 최솟값을 갱신
	
	int n, m, t; cin >> n >> m >> t;
	mat(int, graph, n + 1, n + 1);
	loop(i, home, n + 1) loop(j, home, n + 1) graph[i][j] = 1000000000;
	int v1, v2, c;
	loop(i, home, m)
	{
		cin >> v1 >> v2 >> c;
		graph[v1][v2] = c;
	}
	loop(i, home, n + 1) graph[i][i] = home;

	// 기존 i -> j로 가는 가장 높은 허들의 높이와 i -> k -> j로 가는 가장 높은 허들의 높이 중 최솟값으로 갱신
	loop(k, 1, n + 1) loop(i, 1, n + 1) loop(j, 1, n + 1) graph[i][j] = min(graph[i][j], max(graph[i][k], graph[k][j]));

	loop(i, home, t)
	{
		cin >> v1 >> v2;
		elp(cond(graph[v1][v2] == 1000000000, -1, graph[v1][v2]));
	}

	return home;
}
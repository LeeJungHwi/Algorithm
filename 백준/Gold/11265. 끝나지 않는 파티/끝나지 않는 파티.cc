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

// 끝나지 않는 파티
int main()
{
	init;

	// n개 파티장
	// 방향그래프
	// 중간 경유지 => 플로이드??
	// 플로이드 그래프가 주어짐
	// 그뒤로 a -> n로 c 시간안에 도착가능하면 Enjoy other party
	// 불간으하면 Stay here

	int n, m; cin >> n >> m;
	mat(int, graph, n + 1, n + 1);
	loop(i, 1, n + 1) loop(j, 1, n + 1) cin >> graph[i][j];

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

	int v1, v2, c;
	loop(i, home, m)
	{
		cin >> v1 >> v2 >> c;
		elp(cond(graph[v1][v2] <= c, "Enjoy other party", "Stay here"));
	}

	return home;
}
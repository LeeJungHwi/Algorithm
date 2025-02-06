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

// 비밀 모임
int main()
{
	init;

	// 양방향
	// 각 친구들은 N개의 방 중 하나에 위치
	// 출발장소 -> 모임장소까지 가는 최단경로로 이동
	// 모임장소 => 각 친구들이 모임장소까지 가는 최단거리의 총합이 최소가되는 정점
	// 플로이드 진행 후 각 정점을 모임장소로 했을때 친구들의 최단거리의 총합이 최소가 되는 정점
	// 정답 정점이 여러개면 가장 작은 정점 출력

	int tc; cin >> tc;

	while (tc--)
	{
		int n, m; cin >> n >> m;
		mat(int, graph, n + 1, n + 1);
		loop(i, home, n + 1) loop(j, home, n + 1) graph[i][j] = 1000000000;
		int v1, v2, c;
		loop(i, home, m)
		{
			cin >> v1 >> v2 >> c;
			graph[v1][v2] = c;
			graph[v2][v1] = c;
		}
		loop(i, home, n + 1) graph[i][i] = home;

		loop(k, 1, n + 1) loop(i, 1, n + 1) loop(j, 1, n + 1) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
		
		int friendCnt; cin >> friendCnt;
		vec(int, friendPos, friendCnt);
		loop(i, home, friendCnt) cin >> friendPos[i];

		int minDis = 2147000000, ans = home;
		loop(i, 1, n + 1)
		{
			int sum = home;
			loop(j, home, friendPos.size()) sum += graph[friendPos[j]][i];

			if (minDis > sum)
			{
				minDis = sum;
				ans = i;
			}
		}
		elp(ans);
	}

	return home;
}
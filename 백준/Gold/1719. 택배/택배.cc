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

// 택배
int main()
{
	init;

	// 플로이드

	int n, m; cin >> n >> m;
	mat(int, graph, n + 1, n + 1);
	mat(int, pre, n + 1, n + 1); // pre[i][j] => i에서 j까지 최단경로에서 j로 오기 직전 정점 저장
	loop(i, home, n + 1) loop(j, home, n + 1)
	{
		graph[i][j] = 1000000000;
		pre[i][j] = -1;
	}
	int v1, v2, c;
	loop(i, home, m)
	{
		cin >> v1 >> v2 >> c;
		graph[v1][v2] = c;
		graph[v2][v1] = c;
		pre[v1][v2] = v1;
		pre[v2][v1] = v2;
	}
	loop(i, home, n + 1) graph[i][i] = home;

	loop(k, 1, n + 1) loop(i, 1, n + 1) loop(j, 1, n + 1)
	{
		if (graph[i][j] > graph[i][k] + graph[k][j])
		{
			graph[i][j] = graph[i][k] + graph[k][j];
			pre[i][j] = pre[k][j];
		}
	}

	// 모든 정점 쌍 (i, j)에 대해 처음 거쳐야하는 정점
	loop(i, 1, n + 1)
	{
		loop(j, 1, n + 1)
		{
			// 자기 자신으로 가는 경우 -
			if (i == j) scp('-');
			else
			{
				tvec(int, path);

				// 타겟 정점부터 역추적
				// pre[i][cur]을 따라가 path에 저장
				// -1이면 직전 경로가 없으므로 종료
				int cur = j;
				while (cur != -1)
				{
					path.push_back(cur);
					cur = pre[i][cur];
				}
				scp(path[path.size() - 2]);
			}
		}
		elp(' ');
	}

	return home;
}
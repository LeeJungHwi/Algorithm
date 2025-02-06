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

// 궁금한 민호
int main()
{
	init;

	// 플로이드 중 더 최단거리가 있으면 -1
	// i -> j까지 다른 도시를 경유해서 도달 가능하면 불필요한 간선이므로 제거

	int n; cin >> n;
	mat(int, graph, n + 1, n + 1);
	loop(i, 1, n + 1) loop(j, 1, n + 1) cin >> graph[i][j];

	loop(k, 1, n + 1)
	{
		loop(i, 1, n + 1)
		{
			loop(j, 1, n + 1)
			{
				// 같은 정점 체크
				if (i == j) continue;

				// 더 최단거리가 있으면 -1
				if (graph[i][j] > graph[i][k] + graph[k][j])
				{
					elp(-1);
					return home;
				}
			}
		}
	}

	int ans = home;
	mat(bool, ch, n + 1, n + 1);
	loop(i, 1, n + 1)
	{
		loop(j, 1, n + 1)
		{
			bool isRemove = false;
			loop(k, 1, n + 1)
			{
				// i -> j 까지 중간 도시를 경유해서 도달 가능하면 불필요한 간선이므로 제거
				if (k != i && k != j && graph[i][j] == graph[i][k] + graph[k][j])
				{
					isRemove = true;
					break;
				}
			}

			// 제거되지 않은 간선만 비용 누적
			if (!ch[i][j] && !isRemove)
			{
				ans += graph[i][j];
				ch[i][j] = true;
				ch[j][i] = true;
			}
		}
	}
	elp(ans);

	return home;
}
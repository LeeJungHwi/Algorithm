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

// 진우의 달 여행 (Small)
int main()
{
	init;

	int n, m; cin >> n >> m;
	mat(int, graph, 6, 6);
	loop(i, home, n) loop(j, home, m) cin >> graph[i][j];

	// i행 j열 k전방향 일때 최소연료
	vector<vector<vector<int> > > dp(6, vector<vector<int> >(6, vector<int>(3)));
	loop(i, home, n) loop(j, home, m) loop(k, home, 3) dp[i][j][k] = 2147000000;

	// 0행 이동방향 없음
	loop(i, home, m) loop(j, home, 3) dp[home][i][j] = graph[home][i];

	loop(i, 1, n)
	{
		loop(j, home, m)
		{
			// 이전방향
			loop(k, home, 3)
			{
				// 현재방향
				loop(l, home, 3)
				{
					// 같은방향 체크
					if (k == l) continue;

					// 이전열
					int prevJ = j; // 아래
					switch (k)
					{
						case home: prevJ -= 1; break; // 왼쪽
						case 2: prevJ += 1; break; // 오른쪽
						default: break;
					}

					if (prevJ < home || prevJ >= m) continue;
					dp[i][j][l] = min(dp[i][j][l], dp[i - 1][prevJ][k] + graph[i][j]);
				}
			}
		}
	}

	int minFuel = 2147000000;
	loop(i, home, m) loop(j, home, 3) minFuel = min(minFuel, dp[n - 1][i][j]);
	elp(minFuel);

	return home;
}
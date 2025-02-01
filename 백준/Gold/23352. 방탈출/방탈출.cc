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

// 방탈출
int main()
{
	init;

	int n, m; cin >> n >> m;
	mat(int, graph, n, m); dir;
	tvec(pii, sPos);
	loop(i, home, n)
	{
		loop(j, home, m)
		{
			cin >> graph[i][j];
			if (graph[i][j] > home) sPos.push_back({ i, j });
		}
	}

	int maxDis = -2147000000;
	int maxSum = -2147000000;
	loop(i, home, sPos.size())
	{
		mat(int, dis, n, m);
		queue<pii> cp;
		cp.push(sPos[i]);
		dis[sPos[i].lhs][sPos[i].rhs] = 1;

		int tempMaxDis = 1;
		int tempMaxSum = graph[sPos[i].lhs][sPos[i].rhs];
		while (!cp.empty())
		{
			pii s = cp.front(); cp.pop();

			loop(j, home, 4)
			{
				int ci = s.lhs + cd[j].lhs;
				int cj = s.rhs + cd[j].rhs;

				if (ci < home || cj < home || ci >= n || cj >= m) continue;
				if (dis[ci][cj] > home) continue;
				if (graph[ci][cj] == home) continue;
				cp.push({ ci, cj });
				dis[ci][cj] = dis[s.lhs][s.rhs] + 1;

				// 거리가 더 멀면 거리, 합 갱신
				if (tempMaxDis < dis[ci][cj])
				{
					tempMaxDis = dis[ci][cj];
					tempMaxSum = graph[sPos[i].lhs][sPos[i].rhs] + graph[ci][cj];
				}
				// 거리가 같으면 합이 더 큰 경로로 갱신
				else if(tempMaxDis == dis[ci][cj])
				{
					tempMaxSum = max(tempMaxSum, graph[sPos[i].lhs][sPos[i].rhs] + graph[ci][cj]);
				}
			}
		}

		if (maxDis < tempMaxDis)
		{
			maxDis = tempMaxDis;
			maxSum = tempMaxSum;
		}
		else if (maxDis == tempMaxDis)
		{
			maxSum = max(maxSum, tempMaxSum);
		}
	}

	elp(maxSum);

	return home;
}
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

// 일요일 아침의 데이트
int main()
{
	init;

	int n, m; cin >> n >> m;
	mat(char, graph, n, m);
	mat(pii, dis, n, m);

	// 원래는 (거리, 위치)
	// 여기는 ({쓰레기 수, 쓰레기 근처 수}, 위치)
	priority_queue<pair<pii, pii>, vector<pair<pii, pii>>, greater<pair<pii, pii>>> pq; dir;
	pii sPos, ePos;
	tvec(pii, tPos);
	loop(i, home, n)
	{
		loop(j, home, m)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 'S') sPos = { i, j };
			else if (graph[i][j] == 'F') ePos = { i, j };
			else if (graph[i][j] == 'g') tPos.push_back({ i, j });
			dis[i][j] = { 2147000000, 2147000000 };
		}
	}

	// 쓰레기 근처 체크
	mat(bool, nearT, n, m);
	loop(i, home, tPos.size())
	{
		pii s = tPos[i];
		
		loop(j, home, 4)
		{
			int ci = s.lhs + cd[j].lhs;
			int cj = s.rhs + cd[j].rhs;

			if (ci < home || cj < home || ci >= n || cj >= m) continue;
			if (graph[ci][cj] != '.') continue;
			nearT[ci][cj] = true;
		}
	}

	pq.push({ {home, home}, sPos });
	dis[sPos.lhs][sPos.rhs] = { home, home };
	
	while (!pq.empty())
	{
		int si = pq.top().rhs.lhs;
		int sj = pq.top().rhs.rhs;
		pii sc = pq.top().lhs;
		pq.pop();

		if (dis[si][sj] < sc) continue;

		loop(i, home, 4)
		{
			int ci = si + cd[i].lhs;
			int cj = sj + cd[i].rhs;

			if (ci < home || cj < home || ci >= n || cj >= m) continue;

			pii cc = {sc.lhs + cond(graph[ci][cj] == 'g', 1, home), sc.rhs + cond(nearT[ci][cj], 1, home)};

			if (dis[ci][cj] <= cc) continue;

			dis[ci][cj] = cc;
			pq.push({ cc, {ci, cj} });
		}
	}
	scp(dis[ePos.lhs][ePos.rhs].lhs);
	elp(dis[ePos.lhs][ePos.rhs].rhs);

	return home;
}
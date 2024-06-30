#include <bits/stdc++.h>
using namespace std;

#define home 0

#define ll long long
#define ld long double

#define pii pair<int, int>
#define pll pair<ll, ll>

#define loop(v, s, e) for(int v = (s); v < (e); v++)
#define rloop(v, s, e) for(int v = (s); v > (e); v--)
#define mloop(v, a) for(auto v = (a).begin(); v != (a).end(); v++)
#define mrloop(v, a) for(auto v = (a).rbegin(); v != (a).rend(); v++)
#define aloop(t, v, s, c, e, i) for(t v = (s); v c (e); i)

#define p(a) cout << (a)
#define elp(a) cout << (a) << '\n'
#define scp(a) cout << (a) << ' '

#define vec(t, v, r) vector<t> v((r))
#define mat(t, v, r, c) vector<vector<t> > v((r), vector<t>((c)))
#define gmat(t, v, r) vector<vector<t> > v((r))
#define dir vector<pii> cd = { {-1, 0}, {1, 0}, { 0, -1 }, { 0, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }

#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

vector<pii> dirtyPos;
vec(bool, vis, 10);
map<pii, int> dMap;
int moveCnt, cleanCnt;
int ans = MAX;

void DFS(int L)
{
	if (cleanCnt == dirtyPos.size()) { ans = min(ans, moveCnt); return; }

	loop(i, 1, dirtyPos.size() + 1)
	{
		if (vis[i - 1]) continue;
		if (!dMap[{L, i}]) continue;

		vis[i - 1] = true;
		moveCnt += dMap[{L, i}];
		cleanCnt += 1;
		DFS(i);
		cleanCnt -= 1;
		moveCnt -= dMap[{L, i}];
		vis[i - 1] = false;
	}
}

// 로봇 청소기
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	dir;
	while (true)
	{
		int n, m;
		cin >> m >> n;
		if (m == home && n == home) break;
		mat(char, graph, n, m);
		mat(int, dis, n, m);
		queue<pii> cp;
		loop(i, home, n) loop(j, home, m)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 'o') { cp.push({ i, j }); dis[i][j] = 1; }
			else if (graph[i][j] == '*') dirtyPos.push_back({ i, j });
		}

		// 시작 칸 <-> 더러운 칸 메모
		while (!cp.empty())
		{
			pii s = cp.front(); cp.pop();
			loop(i, home, 4)
			{
				int ci = s.lhs + cd[i].lhs;
				int cj = s.rhs + cd[i].rhs;
				if (ci < home || cj < home || ci >= n || cj >= m) continue;
				if (dis[ci][cj] > home) continue;
				if (graph[ci][cj] == 'x') continue;
				cp.push({ ci, cj });
				dis[ci][cj] = dis[s.lhs][s.rhs] + 1;
			}
		}
		bool isClean = true;
		loop(i, home, dirtyPos.size())
		{
			dMap[{home, i + 1}] = dis[dirtyPos[i].lhs][dirtyPos[i].rhs] - 1;
			if (dMap[{home, i + 1}] == -1) isClean = false;
		}

		// 더러운 칸 <-> 더러운 칸 메모
		loop(i, home, dirtyPos.size())
		{
			loop(j, home, n) loop(k, home, m) dis[j][k] = home;
			cp.push(dirtyPos[i]);
			dis[dirtyPos[i].lhs][dirtyPos[i].rhs] = 1;
			while (!cp.empty())
			{
				pii s = cp.front(); cp.pop();
				loop(j, home, 4)
				{
					int ci = s.lhs + cd[j].lhs;
					int cj = s.rhs + cd[j].rhs;
					if (ci < home || cj < home || ci >= n || cj >= m) continue;
					if (dis[ci][cj] > home) continue;
					if (graph[ci][cj] == 'x') continue;
					cp.push({ ci, cj });
					dis[ci][cj] = dis[s.lhs][s.rhs] + 1;
				}
			}
			loop(j, home, dirtyPos.size())
			{
				dMap[{i + 1, j + 1}] = dis[dirtyPos[j].lhs][dirtyPos[j].rhs] - 1;
				if (dMap[{i + 1, j + 1}] == -1) isClean = false;
			}
		}

		// 더러운 칸 없을 때
		if (dirtyPos.empty())
		{
			// 초기화
			loop(i, home, dirtyPos.size()) vis[i] = false;
			dirtyPos.clear();
			dMap.clear();
			moveCnt = cleanCnt = home;
			ans = MAX;

			elp(home);
			continue;
		}

		// 청소 못 하는 더러운 칸이 있을 때
		if (!isClean)
		{
			// 초기화
			loop(i, home, dirtyPos.size()) vis[i] = false;
			dirtyPos.clear();
			dMap.clear();
			moveCnt = cleanCnt = home;
			ans = MAX;

			elp(-1);
			continue;
		}

		// 재사용
		DFS(home);

		elp(cond(ans == MAX, -1, ans));

		// 초기화
		loop(i, home, dirtyPos.size()) vis[i] = false;
		dirtyPos.clear();
		dMap.clear();
		moveCnt = cleanCnt = home;
		ans = MAX;
	}

	return home;
}
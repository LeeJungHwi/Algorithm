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
#define piii pair<int, pii>
#define pll pair<ll, ll>
#define plll pair<ll, pll>

#define loop(v, s, e) for(int v = (s); v < (e); v++)
#define rloop(v, s, e) for(int v = (s); v > (e); v--)
#define mloop(v, a) for(auto v = (a).begin(); v != (a).end(); v++)
#define mrloop(v, a) for(auto v = (a).rbegin(); v != (a).rend(); v++)

#define p(a) cout << (a)
#define elp(a) cout << (a) << '\n'
#define scp(a) cout << (a) << ' '

#define tvec(t, v) vector<t> v
#define vec(t, v, r) vector<t> v((r))
#define ivec(t, v, r, i) vector<t> v((r), i)
#define gmat(t, v, r) vector<vector<t> > v((r))
#define mat(t, v, r, c) vector<vector<t> > v((r), vector<t>((c)))
#define imat(t, v, r, c, i) vector<vector<t> > v((r), vector<t>((c), i))
#define smat(t, v, r, c, s) vector<vector<vector<t> > > v((r), vector<vector<t>>((c), vector<t>((s))))
#define ismat(t, v, r, c, s, i) vector<vector<vector<t> > > v((r), vector<vector<t>>((c), vector<t>((s), i)))

#define dir vector<pii> cd = { {-1, home}, {home, 1}, { home, -1 }, { 1, home }, { -1, home }, { -1, 1 }, { 1, -1 }, { 1, 1 } }
#define kdir vector<pii> kcd = { {-1, -2}, {-2, -1}, { -2, 1 }, { -1, 2 }, { 1, -2 }, { 2, -1 }, { 1, 2 }, { 2, 1 } }
#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

// 로봇
int main()
{
	init;

	// 시작 위치와 방향에서 끝 위치와 방향이 되도록하는 명령 최소 횟수
	// 명령 1 => 1, 2, 3칸 이동
	// 명령 2 => 왼쪽, 오른쪽 회전
	// 방향 => 1(우) 2(좌) 3(하) 4(상)
	
	int n, m; cin >> n >> m;
	mat(int, graph, n, m);
	smat(int, dis, n, m, 5); // vis[i][j][k] => i,j로 k방향에서 왔을 때 명령 최소 횟수
	queue<pair<pii, pii>> cp; dir; // (위치, 방향, 명령 횟수)
	loop(i, home, n) loop(j, home, m) cin >> graph[i][j];

	// 시작 위치 및 방향, 끝 위치 및 방향 입력
	pii sPos, ePos;
	int sDir, eDir;
	cin >> sPos.lhs >> sPos.rhs >> sDir; sPos.lhs--; sPos.rhs--;
	cin >> ePos.lhs >> ePos.rhs >> eDir; ePos.lhs--; ePos.rhs--;

	// 시작 위치 및 방향 부터 BFS
	cp.push({ sPos, {sDir, home} });
	dis[sPos.lhs][sPos.rhs][sDir] = 1;

	while (!cp.empty())
	{
		int si = cp.front().lhs.lhs;
		int sj = cp.front().lhs.rhs;
		int sd = cp.front().rhs.lhs;
		int sc = cp.front().rhs.rhs;
		cp.pop();

		// 끝 위치 및 방향에 도착하면 종료
		if (si == ePos.lhs && sj == ePos.rhs && sd == eDir)
		{
			elp(sc);
			return home;
		}

		// 회전하지 않고 현재 방향 그대로 1, 2, 3칸 진행하는 경우
		loop(i, 1, 4)
		{
			int ci = si + cd[sd].lhs * i;
			int cj = sj + cd[sd].rhs * i;
			int cc = sc + 1;

			if (ci < home || cj < home || ci >= n || cj >= m) break;
			if (graph[ci][cj] == 1) break;
			if (dis[ci][cj][sd] > home) continue;

			cp.push({ {ci, cj}, {sd, cc} });
			dis[ci][cj][sd] = cc;
		}

		// 회전하는 경우
		
		// 1.왼쪽으로 회전
		// 1(우) => 4(상)
		// 2(좌) => 3(하)
		// 3(하) => 1(우)
		// 4(상) => 2(좌)
		int cdir = sd;
		switch (cdir)
		{
			case 1: cdir = 4; break;
			case 2: cdir = 3; break;
			case 3: cdir = 1; break;
			case 4: cdir = 2; break;
		}

		if (dis[si][sj][cdir] == home)
		{
			cp.push({ {si, sj}, {cdir, sc + 1} });
			dis[si][sj][cdir] = sc + 1;
		}

		// 2.오른쪽으로 회전
		// 1(우) => 3(하)
		// 2(좌) => 4(상)
		// 3(하) => 2(좌)
		// 4(상) => 1(우)
		cdir = sd;
		switch (cdir)
		{
			case 1: cdir = 3; break;
			case 2: cdir = 4; break;
			case 3: cdir = 2; break;
			case 4: cdir = 1; break;
		}

		if (dis[si][sj][cdir] == home)
		{
			cp.push({ {si, sj}, {cdir, sc + 1} });
			dis[si][sj][cdir] = sc + 1;
		}
	}

	return home;
}
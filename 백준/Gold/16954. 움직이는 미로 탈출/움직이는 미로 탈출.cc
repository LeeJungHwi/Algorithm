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

#define dir vector<pii> cd = { {-1, home}, {1, home}, { home, -1 }, { home, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }
#define kdir vector<pii> kcd = { {-1, -2}, {-2, -1}, { -2, 1 }, { -1, 2 }, { 1, -2 }, { 2, -1 }, { 1, 2 }, { 2, 1 } }
#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

// 움직이는 미로 탈출
int main()
{
	init;

	// 육제는 8방향 이동이 가능하며 이동을 하지 않을 수 있음
	// 벽이 아래로 한 칸씩 내려오고 경계를 만나면 사라짐
	// 벽이 육제를 만나면 육제는 더 이상 이동할 수 없음
	// 육제가 n - 1,0 -> 0,m - 1에 도착 가능하면 1 아니면 0
	
	// 그래프 역순으로 돌면서 벽을 내리면서 벽인 시간 체크
	// 더 이상 벽이 없으면 종료

	// 육제의 시작위치 n -1,0 부터 BFS 돌려서 0,m - 1에 도착 가능하면 1 아니면 0
	// BFS 내부에서 이동하는 경우와 이동하지 않는 경우로 뻗어나감

	mat(char, graph, 8, 8);
	smat(bool, vis, 8, 8, 8); // vis[i][j][k] => i,j가 k초일 때 벽인지 체크
	queue<piii> cp; dir; // (시간, 위치)
	int startI = -1; // 벽이 처음 나오는 행
	int wallCnt = home; // 남아있는 벽의 개수
	loop(i, home, 8) loop(j, home, 8)
	{
		cin >> graph[i][j];
		if (graph[i][j] == '#')
		{
			if (startI == -1) startI = i; // 벽이 처음 나오는 행 저장
			wallCnt++; // 남아있는 벽의 개수 카운팅
		}
	}

	// 그래프 역순으로 돌면서 벽인 시간 체크 후 벽을 내림
	// 더 이상 벽이 없으면 종료
	int time = home;
	while (true)
	{
		if (startI == -1) break;

		rloop(i, 7, startI - 1) loop(j, home, 8) if (graph[i][j] == '#')
		{
			// 벽인 시간 체크
			vis[i][j][time] = true;

			// 벽을 아래로 내림
			int ci = i + 1;

			// 이전 위치를 빈공간으로
			graph[i][j] = '.';

			// 경계를 만나면 벽 개수 감소
			if (ci >= 8)
			{
				wallCnt--;
				continue;
			}

			// 경계가 아니면 내린곳을 벽으로
			graph[ci][j] = '#';
		}

		// 더 이상 벽이 없으면 종료
		if (wallCnt == home) break;

		// 1초 증가
		time++;
	}

	// 육제의 시작위치 n -1,0 부터 BFS 돌려서 0,m - 1에 도착 가능하면 1 아니면 0
	// BFS 내부에서 이동하는 경우와 이동하지 않는 경우로 뻗어나감
	// 벽이 모두 사라지는 시간인 7초 동안 이동 가능한 위치가 있으면 가능한 경우

	// 시작 위치가 0초일 때 벽인 경우 X
	if (vis[7][home][home]) { elp(home); return home; }

	cp.push({ home, {7, home} });
	while (!cp.empty())
	{
		int si = cp.front().rhs.lhs;
		int sj = cp.front().rhs.rhs;
		int st = cp.front().lhs;
		cp.pop();

		// 벽이 모두 사라지는 시간인 7초 동안 이동 가능한 위치가 있으면 가능한 경우
		if (st == 7) { elp(1); return home; }

		// 이동하지 않는 경우
		if (!vis[si][sj][st + 1]) cp.push({ st + 1, {si, sj} });

		// 이동하는 경우
		loop(i, home, 8)
		{
			int ci = si + cd[i].lhs;
			int cj = sj + cd[i].rhs;
			int ct = st + 1;

			if (ci < home || cj < home || ci >= 8 || cj >= 8) continue;

			// 이동하려는 위치가 1초 전 또는 1초 후에 벽이면 이동 X
			if (vis[ci][cj][st] || vis[ci][cj][ct]) continue;

			cp.push({ ct, {ci, cj} });
		}
	}
	// 7초 동안 이동하지 못 하면 불가능한 경우
	elp(home);

	return home;
}
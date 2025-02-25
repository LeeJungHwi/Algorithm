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

// 보이저 1호
int main()
{
	init;

	// 시작 이동 방향을 상우하좌 순서로 각각 시뮬레이션
	// 블랙홀 또는 경계를 만나면 가장 긴 전파시간과 방향 업데이트
	// 진행 과정에서 방향 상태를 추가한 vis가 true면 Voyager
	// 슬래시(/)
	// 1.현재 이동 방향이 상이면 우로
	// 2.현재 이동 방향이 하면 좌로
	// 3.현재 이동 방향이 좌면 하로
	// 4.현재 이동 방향이 우면 상으로
	// 역슬래시(\\)
	// 1.현재 이동 방향이 상이면 좌로
	// 2.현재 이동 방향이 하면 우로
	// 3.현재 이동 방향이 좌면 상으로
	// 4.현재 이동 방향이 우면 하로

	int n, m; cin >> n >> m;
	mat(char, graph, n, m);
	loop(i, home, n) loop(j, home, m) cin >> graph[i][j];
	smat(bool, vis, n, m, 4); // vis[i][j][k] => k방향으로 i,j를 방문함
	dir;
	pii sPos; cin >> sPos.lhs >> sPos.rhs;
	sPos.lhs--; sPos.rhs--;
		
	// 시작 이동 방향을 상우하좌 순서로 각각 시뮬레이션
	vector<int> sDir = { home, 3, 1, 2 };
	map<int, char> dirMap = { {home, 'U'}, {1, 'D'}, {2, 'L'}, {3, 'R'} }; // (방향 숫자, 방향 문자)
	char ansDir = 'U'; // 가장 긴 전파 시간의 시작 방향
	int ansTime = MIN; // 가장 긴 전파 시간
	loop(i, home, sDir.size())
	{
		int si = sPos.lhs;
		int sj = sPos.rhs;
		int sd = sDir[i];
		vis[si][sj][sd] = true;

		int time = 1; // 전파 시간
		while (true)
		{
			// 현재 방향으로 한칸 진행
			si += cd[sd].lhs;
			sj += cd[sd].rhs;

			// 경계를 만나면 가장 긴 전파 시간 및 방향 업데이트
			if (si < home || sj < home || si >= n || sj >= m)
			{
				if (ansTime < time)
				{
					sd = sDir[i];
					ansDir = dirMap[sDir[i]];
					ansTime = time;
				}
				break;
			}
			
			// 블랙홀을 만나면 가장 긴 전파 시간 및 방향 업데이트트
			if (graph[si][sj] == 'C')
			{
				if (ansTime < time)
				{
					sd = sDir[i];
					ansDir = dirMap[sDir[i]];
					ansTime = time;
				}
				break;
			}

			// 진행 과정에서 방향 상태를 추가한 vis가 true면
			// 시작 이동 방향과 Voyager 출력 후 종료
			if (vis[si][sj][sd])
			{
				elp(dirMap[sDir[i]]);
				elp("Voyager");
				return home;
			}

			// 빈 칸은 방향전환 X
			if (graph[si][sj] == '.')
			{
				time++;
				vis[si][sj][sd];
				continue;
			}

			// 슬래시(/)
			// 1.현재 이동 방향이 상이면 우로
			// 2.현재 이동 방향이 하면 좌로
			// 3.현재 이동 방향이 좌면 하로
			// 4.현재 이동 방향이 우면 상으로
			if (graph[si][sj] == '/')
			{
				time++;
				vis[si][sj][sd] = true;

				switch (sd)
				{
					case home: sd = 3; break;
					case 1: sd = 2; break;
					case 2: sd = 1; break;
					case 3: sd = home; break;
				}

				continue;
			}

			// 역슬래시(\\)
			// 1.현재 이동 방향이 상이면 좌로
			// 2.현재 이동 방향이 하면 우로
			// 3.현재 이동 방향이 좌면 상으로
			// 4.현재 이동 방향이 우면 하로
			if (graph[si][sj] == '\\')
			{
				time++;
				vis[si][sj][sd] = true;

				switch (sd)
				{
					case home: sd = 2; break;
					case 1: sd = 3; break;
					case 2: sd = home; break;
					case 3: sd = 1; break;
				}

				continue;
			}
		}

		// 방문체크 초기화
		loop(j, home, n) loop(k, home, m) loop(l, home, 4) vis[j][k][l] = false;
	}

	// 가장 긴 전파시간과 방향 출력
	elp(ansDir);
	elp(ansTime);

	return home;
}
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

// 탈옥
int main()
{
	init;

	// 문(#) => 비용 1 뒤에 추가
	// 빈공간(.) => 비용 0 앞에 추가
	// 가장자리, 죄수1, 죄수2 가 같은 위치에서 만나야함
	// =>각 sPos에 대해 0-1 BFS 돌려서 특정 위치에 도달하는데 열어야 하는 문의 최단거리 저장
	// =>그래프 돌면서 ans = min(ans, 가장자리 + 죄수1 + 죄수2)로 업데이트
	// 외부 입구에서 각각 문을 열어 죄수를 구하는 반례 => 1-based 그래프로 입력받고 가장자리 시작위치를 0,0으로 
	// ex) 0,1과 5,2문을 각각 열어 두 죄수를 구하면 2
	//  1
	//	6 6
	//	*#****
	//	*.$..*
	//	***#**
	//	***#**
	//	*.$..*
	//	**#***
	//  ans = 2
	
	int tc; cin >> tc;

	deque<pii> cp; dir;
	while (tc--)
	{
		int n, m; cin >> n >> m;
		imat(char, graph, n + 2, m + 2, '.');
		deque<pii> sPos = { {home, home} };
		loop(i, 1, n + 1) loop(j, 1, m + 1)
		{
			cin >> graph[i][j];
			if (graph[i][j] == '$') sPos.push_back({ i, j }); // 두 죄수 위치 저장
		}
		
		// 각 sPos에 대해 0 - 1 BFS 돌려서 특정 위치에 도달하는데 열어야 하는 문의 최단거리 저장
		smat(int, dis, n + 2, m + 2, sPos.size()); // dis[i][j][k] => i,j로 오는데 출발위치가 k일 때 최단거리
		loop(i, home, sPos.size())
		{
			cp.push_front(sPos[i]);
			dis[sPos[i].lhs][sPos[i].rhs][i] = cond(graph[sPos[i].lhs][sPos[i].rhs] == '#', 2, 1);

			while (!cp.empty())
			{
				int si = cp.front().lhs;
				int sj = cp.front().rhs;
				cp.pop_front();

				loop(j, home, 4)
				{
					int ci = si + cd[j].lhs;
					int cj = sj + cd[j].rhs;

					if (ci < home || cj < home || ci >= n + 2 || cj >= m + 2) continue;
					if (dis[ci][cj][i] > home) continue;
					if (graph[ci][cj] == '*') continue;

					cond(graph[ci][cj] == '#', cp.push_back({ ci, cj }), cp.push_front({ ci, cj }));
					dis[ci][cj][i] = cond(graph[ci][cj] == '#', dis[si][sj][i] + 1, dis[si][sj][i]);
				}
			}
		}

		// 그래프 돌면서 ans = min(ans, 가장자리 + 죄수1 + 죄수2)로 업데이트
		int ans = MAX;
		loop(i, home, n + 1) loop(j, home, m + 1)
		{
			// 벽이면 X
			if (graph[i][j] == '*') continue;

			// 현재 위치로 올 수 없는 출발위치가 있으면 X
			bool isMeet = true;
			int sum = home;
			loop(k, home, sPos.size())
			{
				if (dis[i][j][k] == home) { isMeet = false; break; }
				sum += dis[i][j][k] - 1;
			}
			if (!isMeet) continue;

			// 현재 위치가 벽이면 첫 사람이 열고 나머지 두 사람이 열어 2번이 중복됨
			if (graph[i][j] == '#') sum -= 2;

			// 현재 위치로 모두 올 수 있으면 업데이트
			ans = min(ans, sum);
		}

		elp(ans);
	}

	return home;
}
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
	// 가장자리 중 벽(*)이 아닌곳, 죄수1, 죄수2 가 같은 위치에서 만나야함
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

		// 그래프
		//for (auto a : graph)
		//{
		//	for (auto b : a)
		//	{
		//		scp(b);
		//	}
		//	elp(' ');
		//}

		// 가장자리 중 벽(*)이 아닌 위치 저장
		//loop(i, home, n)
		//{
		//	// 첫 열
		//	if (graph[i][home] != '*') sPos.push_front({ i, home });

		//	// 막 열
		//	if (graph[i][m - 1] != '*') sPos.push_front({ i, m - 1 });
		//}
		//loop(i, 1, m - 1)
		//{
		//	// 첫 행
		//	if (graph[home][i] != '*') sPos.push_front({ home, i });

		//	// 막 행
		//	if (graph[n - 1][i] != '*') sPos.push_front({ n - 1, i });
		//}

		// 가장자리 시작위치
		//loop(i, home, sPos.size())
		//{
		//	scp(sPos[i].lhs);
		//	elp(sPos[i].rhs);
		//}
		//elp(' ');
		
		// 각 sPos에 대해 0 - 1 BFS 돌려서 특정 위치에 도달하는데 열어야 하는 문의 최단거리 저장
		ismat(int, dis, n + 2, m + 2, sPos.size(), MAX); // dis[i][j][k] => i,j로 오는데 출발위치가 k일 때 최단거리
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
					if (dis[ci][cj][i] <= cond(graph[ci][cj] == '#', dis[si][sj][i] + 1, dis[si][sj][i])) continue;
					if (graph[ci][cj] == '*') continue;

					cond(graph[ci][cj] == '#', cp.push_back({ ci, cj }), cp.push_front({ ci, cj }));
					dis[ci][cj][i] = cond(graph[ci][cj] == '#', dis[si][sj][i] + 1, dis[si][sj][i]);
				}
			}

			// 죄수2 거리
			//if (i == 2)
			//{
			//	for (auto a : dis)
			//	{
			//		for (auto b : a)
			//		{
			//			for (auto c : b)
			//			{
			//				scp(c);
			//			}
			//			elp(' ');
			//		}
			//	}
			//}
		}

		// 그래프 돌면서 ans = min(ans, min(가장자리들) + 죄수1 + 죄수2)로 업데이트
		//int ans = MAX;
		//loop(i, home, n) loop(j, home, m)
		//{
		//	// 벽이면 X
		//	if (graph[i][j] == '*') continue;

		//	// 가장자리들 중 최단거리
		//	int borderMin = MAX;
		//	loop(k, home, sPos.size() - 2)
		//	{
		//		if (borderMin == home) continue;
		//		borderMin = min(borderMin, dis[i][j][k]);
		//	}

		//	// 모든 가장자리가 현재위치로 올 수 없으면 X
		//	if (borderMin == MAX) continue;

		//	// 죄수1, 죄수2가 현재위치로 올 수 없으면 X
		//	if (dis[i][j][sPos.size() - 2] == home || dis[i][j][sPos.size() - 1] == home) continue;

		//	// 가장자리 거리 + 죄수1 거리 + 죄수2 거리
		//	int sum = borderMin + dis[i][j][sPos.size() - 2] + dis[i][j][sPos.size() - 1] - 3;

		//	// i,j가 문이면 여는 횟수 2번이 중복됨
		//	if (graph[i][j] == '#') sum -= 2;

		//	// 특정 위치의 가장자리 거리, 죄수1 거리, 죄수2 거리
		//	if (ans > sum)
		//	{
		//		ans = sum;
		//		scp(i); scp(j); scp(borderMin); scp(dis[i][j][sPos.size() - 2]); elp(dis[i][j][sPos.size() - 1]);
		//	}

		//	ans = min(ans, sum);
		//}

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
				if (dis[i][j][k] == MAX) { isMeet = false; break; }
				sum += dis[i][j][k] - 1;
			}
			if (!isMeet) continue;

			if (graph[i][j] == '#') sum -= 2;

			// 특정 위치의 가장자리 거리, 죄수1 거리, 죄수2 거리
			//if (ans > sum)
			//{
			//	ans = sum;
			//	scp(i); scp(j); scp(dis[i][j][home]); scp(dis[i][j][1]); elp(dis[i][j][2]);
			//}

			// 현재 위치로 모두 올 수 있으면 업데이트
			ans = min(ans, sum);
		}

		elp(ans);
	}

	return home;
}
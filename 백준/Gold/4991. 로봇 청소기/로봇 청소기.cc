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
#define ssmat(t, v, r, c, s1, s2) vector<vector<vector<vector<t> > > > v((r), vector<vector<vector<t>>>((c), vector<vector<t>>((s1), vector<t>((s2)))))
#define issmat(t, v, r, c, s1, s2, i) vector<vector<vector<vector<t> > > > v((r), vector<vector<vector<t>>>((c), vector<vector<t>>((s1), vector<t>((s2), i))))
#define sssmat(t, v, r, c, s1, s2, s3) vector<vector<vector<vector<vector<t> > > > > v((r), vector<vector<vector<vector<t>>>>((c), vector<vector<vector<t>>>((s1), vector<vector<t>>((s2), vector<t>((s3))))))
#define isssmat(t, v, r, c, s1, s2, s3, i) vector<vector<vector<vector<vector<t> > > > > v((r), vector<vector<vector<vector<t>>>>((c), vector<vector<vector<t>>>((s1), vector<vector<t>>((s2), vector<t>((s3), i)))))

#define dir vector<pii> cd = { {-1, home}, {1, home}, { home, -1 }, { home, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }
#define kdir vector<pii> kcd = { {-1, -2}, {-2, -1}, { -2, 1 }, { -1, 2 }, { 1, -2 }, { 2, -1 }, { 1, 2 }, { 2, 1 } }
#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

// 로봇 청소기
int main()
{
	init;

	// 더러운 칸 조합 상태 => 1 << 더러운 칸 개수

	dir;
	while (true)
	{
		int n, m; cin >> m >> n;
		if (n == home && m == home) break;

		mat(char, graph, n, m);
		queue<piii> cp; // (더러운 칸 조합 상태, 위치)
		pii sPos;
		tvec(pii, dirtyPos);
		loop(i, home, n) loop(j, home, m)
		{
			cin >> graph[i][j];

			// 로봇 청소기 위치와 더러운 칸 위치 저장
			if (graph[i][j] == 'o') sPos = { i, j };
			else if (graph[i][j] == '*') dirtyPos.push_back({ i, j });
		}
		smat(int, dis, n, m, 1 << dirtyPos.size()); // dis[i][j][k] => i,j에서 더러운 칸 조합 상태가 k일 때 최단거리

		cp.push({ home, sPos });
		dis[sPos.lhs][sPos.rhs][home] = 1;

		bool isClean = false;
		while (!cp.empty())
		{
			int si = cp.front().rhs.lhs;
			int sj = cp.front().rhs.rhs;
			int sc = cp.front().lhs;
			cp.pop();

			// 모든 더러운 칸을 청소한 상태일 떄 종료
			if (sc == (1 << dirtyPos.size()) - 1)
			{
				elp(dis[si][sj][sc] - 1);
				isClean = true;
				break;
			}

			loop(i, home, 4)
			{
				int ci = si + cd[i].lhs;
				int cj = sj + cd[i].rhs;
				int cc = sc;

				if (ci < home || cj < home || ci >= n || cj >= m) continue;
				if (graph[ci][cj] == 'x') continue;

				// 더러운 칸
				if (graph[ci][cj] == '*')
				{
					loop(j, home, dirtyPos.size())
					{
						if (ci == dirtyPos[j].lhs && cj == dirtyPos[j].rhs)
						{
							// 현재 더러운 칸을 청소한 조합
							cc |= (1 << j);

							if (dis[ci][cj][cc] > home) continue;

							cp.push({ cc, {ci, cj} });
							dis[ci][cj][cc] = dis[si][sj][sc] + 1;
						}
					}

					continue;
				}

				// 빈공간
				if (dis[ci][cj][sc] > home) continue;

				cp.push({ sc, {ci, cj} });
				dis[ci][cj][sc] = dis[si][sj][sc] + 1;
			}
		}

		if (isClean) continue;
		elp(-1);
	}

	return home;
}
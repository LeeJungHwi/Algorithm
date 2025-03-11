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

// 마법사 상어와 파이어스톰
int main()
{
	init;

	// 한 변 길이 2^n인 그래프를 각 L에 대해 한 변 길이 2^L 정사각형으로 나누고 시계방향 90도 회전
	// 얼음이 0인 모든 위치의 상하좌우 위치에 카운팅 => 2개 이상 카운팅 된 위치는 얼음을 1 녹임
	// 가장 큰 얼음덩어리의 영역 개수 업데이트 => 덩어리가 없으면 0 이므로 maxArea = 0으로 시작함
	// 남아있는 얼음 개수와 가장 큰 얼음 덩어리의 영역 개수 출력

	int n, q; cin >> n >> q;
	n = pow(2, n);
	mat(int, graph, n + 2, n + 2);
	mat(bool, vis, n + 2, n + 2);
	queue<pii> cp; dir;
	loop(i, 1, n + 1) loop(j, 1, n + 1) cin >> graph[i][j];

	while (q--)
	{
		int l; cin >> l;
		l = pow(2, l);

		// 한 변 길이 2^L 정사각형으로 나누고 시계방향 90도 회전
		mat(int, temp, l, l);
		tvec(pii, zeroPos);
		for (int i = 1; i < n + 1; i += l)
		{
			for (int j = 1; j < n + 1; j += l)
			{
				// 회전 결과 temp에 저장
				loop(k, home, l)
				{
					loop(p, home, l)
					{
						temp[p][l - 1 - k] = graph[i + k][j + p];
					}
				}

				// 그래프에 temp 저장
				loop(k, home, l)
				{
					loop(p, home, l)
					{
						graph[i + k][j + p] = temp[k][p];
					}
				}
			}
		}

		// 0인 위치 저장
		loop(i, home, n + 2) loop(j, home, n + 2) if (graph[i][j] == home) zeroPos.push_back({ i, j });

		//for (auto a : graph)
		//{
		//	for (auto b : a)
		//	{
		//		scp(b);
		//	}
		//	elp(' ');
		//}

		// 얼음이 0인 모든 위치의 상하좌우 위치에 카운팅 => 2개 이상 카운팅 된 위치는 얼음을 1 녹임
		map<pii, int> meltPos;
		loop(i, home, zeroPos.size())
		{
			loop(j, home, 4)
			{
				int ci = zeroPos[i].lhs + cd[j].lhs;
				int cj = zeroPos[i].rhs + cd[j].rhs;

				if (ci < 1 || cj < 1 || ci >= n + 1 || cj >= n + 1) continue;
				if (graph[ci][cj] == home) continue;

				meltPos[{ci, cj}]++;
			}
		}
		mloop(it, meltPos) if (it->rhs >= 2) graph[it->lhs.lhs][it->lhs.rhs]--;
	}

	// 가장 큰 얼음덩어리의 영역 개수 업데이트 => 덩어리가 없으면 0 이므로 maxArea = 0으로 시작함
	int iceCnt = home, maxArea = home;
	loop(i, 1, n + 1) loop(j, 1, n + 1) if (!vis[i][j] && graph[i][j] > home)
	{
		cp.push({ i, j });
		vis[i][j] = true;
		int area = 1;
		iceCnt += graph[i][j];

		while (!cp.empty())
		{
			int si = cp.front().lhs;
			int sj = cp.front().rhs;
			cp.pop();

			loop(k, home, 4)
			{
				int ci = si + cd[k].lhs;
				int cj = sj + cd[k].rhs;

				if (ci < 1 || cj < 1 || ci >= n + 1 || cj >= n + 1) continue;
				if (vis[ci][cj]) continue;
				if (graph[ci][cj] == home) continue;

				cp.push({ ci, cj });
				vis[ci][cj] = true;
				area++;
				iceCnt += graph[ci][cj];
			}
		}

		maxArea = max(maxArea, area);
	}
	elp(iceCnt); elp(maxArea);

	return home;
}
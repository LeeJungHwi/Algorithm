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

// 라벨 2~7
vector<int> unf(8);

int Find(int v)
{
	if (unf[v] == v) return v;
	return unf[v] = Find(unf[v]);
}

void Union(int v1, int v2)
{
	v1 = Find(v1);
	v2 = Find(v2);
	if (v1 != v2) unf[v1] = v2;
}

struct Edge
{
	int v1, v2, c;
	Edge() {}
	Edge(int v1, int v2, int c) : v1(v1), v2(v2), c(c) {}
	bool operator<(const Edge& e)const { return c < e.c; }
};

// 다리 만들기 2
int main()
{
	init;

	// 영역 라벨링 후 (라벨, 위치) 맵핑
	// 맵 돌면서 현재 라벨의 각 위치에 대해 같은 방향으로 한칸 씩 진행하면서 현재 라벨보다 큰 라벨을 만나면 간선 추가
	// 크루스칼로 모든 섬을 잇는 최단거리
	int n, m; cin >> n >> m;
	mat(int, graph, n, m);
	queue<pii> cp; dir;
	tvec(pii, sPos);
	loop(i, home, n) loop(j, home, m)
	{
		cin >> graph[i][j];
		if (graph[i][j] == 1) sPos.push_back({ i, j }); // 1 위치 저장
	}

	// 영역 라벨링 후 (라벨, 위치) 맵핑
	int curLabel = 1;
	map<int, vector<pii>> labelMap;
	loop(i, home, sPos.size()) if (graph[sPos[i].lhs][sPos[i].rhs] == 1)
	{
		graph[sPos[i].lhs][sPos[i].rhs] = ++curLabel;
		cp.push(sPos[i]);
		labelMap[curLabel].push_back(sPos[i]);

		while (!cp.empty())
		{
			int si = cp.front().lhs;
			int sj = cp.front().rhs;
			cp.pop();

			loop(i, home, 4)
			{
				int ci = si + cd[i].lhs;
				int cj = sj + cd[i].rhs;

				if (ci < home || cj < home || ci >= n || cj >= m) continue;
				if (graph[ci][cj] > 1) continue; // 이미 라벨링된 영역은 X
				if (graph[ci][cj] == home) continue;

				graph[ci][cj] = curLabel;
				cp.push({ ci, cj });
				labelMap[curLabel].push_back({ ci, cj });
			}
		}
	}

	// 라벨링 그래프
	//for (auto a : graph)
	//{
	//	for (auto b : a)
	//	{
	//		scp(b);
	//	}
	//	elp(' ');
	//}

	// 맵 돌면서 현재 라벨의 각 위치에 대해 같은 방향으로 한칸 씩 진행하면서 현재 라벨보다 큰 라벨을 만나면 간선 추가
	tvec(Edge, mst);
	mloop(it, labelMap)
	{
		// 현재 라벨의 각 위치에 대해
		loop(i, home, it->rhs.size())
		{
			int si = it->rhs[i].lhs;
			int sj = it->rhs[i].rhs;
			int sc = home;

			// 같은 방향으로 한칸 씩 진행하면서 현재 라벨보다 큰 라벨을 만나면 간선 추가
			loop(j, home, 4)
			{
				int ci = si;
				int cj = sj;
				int cc = sc;

				while (true)
				{
					ci += cd[j].lhs;
					cj += cd[j].rhs;

					// 경계 X
					if (ci < home || cj < home || ci >= n || cj >= m) break;

					// 현재 라벨과 같은 라벨은 X
					if (graph[ci][cj] == it->lhs) break;

					// 현재 라벨과 다른 라벨인 경우
					// 현재 라벨보다 큰 라벨은 간선 추가 => 길이가 2 이상인 경우
					// 현재 라벨보다 작은 라벨은 종료 => 3 2 4이 일직선일 때 3에서 진행할 때 2인 영역에도 다리를 놓아 4와 연결되는 문제
					if (graph[ci][cj] != home)
					{
						if (graph[ci][cj] < it->lhs) break;
						if (cc < 2) break;
						mst.push_back(Edge(it->lhs, graph[ci][cj], cc));
						break;
					}

					// 바다면 도로길이 카운팅
					cc++;
				}
			}
		}
	}
	sort(all(mst)); // 간선 오름차순
	loop(i, 2, 8) unf[i] = i; // 유파 초기화

	// 간선
	//loop(i, home, mst.size()) { scp(mst[i].v1); scp(mst[i].v2); elp(mst[i].c); }

	// 크루스칼로 모든 섬을 잇는 최단거리
	int ans = home, cnt = home; // 연결 횟수
	loop(i, home, mst.size())
	{
		if (Find(mst[i].v1) != Find(mst[i].v2))
		{
			Union(mst[i].v1, mst[i].v2);
			ans += mst[i].c;
			cnt++;
		}
	}

	// 모든 섬을 잇지 못하면 -1
	elp(cond(cnt != labelMap.size() - 1, -1, ans));

	return home;
}
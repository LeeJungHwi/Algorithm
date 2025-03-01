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

vector<int> unf(200001), minT(200001); // 비상탈출구 설치 최솟값 관리

int Find(int v)
{
	if (unf[v] == v) return v;
	return unf[v] = Find(unf[v]);
}

void Union(int v1, int v2)
{
	v1 = Find(v1);
	v2 = Find(v2);
	if (v1 != v2)
	{
		unf[v1] = v2;

		// 비상탈출구 설치 최솟값 관리
		minT[v1] = min(minT[v1], minT[v2]);
		minT[v2] = min(minT[v1], minT[v2]);
	}
}

struct Edge
{
	int v1, v2, c;
	Edge() {}
	Edge(int v1, int v2, int c) : v1(v1), v2(v2), c(c) {}
	bool operator<(const Edge& e)const { return c < e.c; }
};

// 방탈출
int main()
{
	init;

	// 모든 정점에 개별 비상탈출구를 설치한 상태로 시작
	// 두 분리 집합이 개별 비상탈출구를 설치하는 비용과 두 분리 집합 연결비용 + 합쳐진 후 비상탈출구 설치 최솟값 중 작은 비용 선택

	int n, m; cin >> n >> m;
	loop(i, home, n) unf[i] = i;
	tvec(Edge, graph);
	int v1, v2, c;
	loop(i, home, m)
	{
		cin >> v1 >> v2 >> c;
		graph.push_back(Edge(--v1, --v2, c));
	}
	sort(all(graph));
	int minCost = home;
	loop(i, home, n)
	{
		cin >> minT[i];

		// 모든 정점에 개별 비상탈출구를 설치한 상태로 시작
		minCost += minT[i];
	}

	// 두 분리 집합이 개별 비상탈출구를 설치하는 비용과 두 분리 집합 연결비용 + 합쳐진 후 비상탈출구 설치 최솟값 중 작은 비용 선택
	loop(i, home, graph.size())
	{
		v1 = Find(graph[i].v1);
		v2 = Find(graph[i].v2);

		if (v1 != v2)
		{
			// 두 분리 집합이 개별 비상탈출구를 설치하는 비용
			int sc = minT[v1] + minT[v2];

			// 두 분리 집합 연결비용 + 합쳐진 후 비상탈출구 설치 최솟값
			int cc = graph[i].c + min(minT[v1], minT[v2]);

			// 더 작은 비용 선택
			if (cc < sc)
			{
				Union(v1, v2);
				minCost += cc - sc;
			}
		}
	}
	elp(minCost);

	return home;
}
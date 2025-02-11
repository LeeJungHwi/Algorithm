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
#define pll pair<ll, ll>

#define loop(v, s, e) for(int v = (s); v < (e); v++)
#define rloop(v, s, e) for(int v = (s); v > (e); v--)
#define mloop(v, a) for(auto v = (a).begin(); v != (a).end(); v++)
#define mrloop(v, a) for(auto v = (a).rbegin(); v != (a).rend(); v++)

#define p(a) cout << (a)
#define elp(a) cout << (a) << '\n'
#define scp(a) cout << (a) << ' '

#define tvec(t, v) vector<t> v
#define vec(t, v, r) vector<t> v((r))
#define gmat(t, v, r) vector<vector<t> > v((r))
#define mat(t, v, r, c) vector<vector<t> > v((r), vector<t>((c)))

#define dir vector<pii> cd = { {-1, home}, {1, home}, { home, -1 }, { home, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }
#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

#include <unordered_map>

vector<int> unf(100001);

int Find(int v)
{
	if (v == unf[v]) return v;
	return unf[v] = Find(unf[v]);
}

void Union(int v1, int v2)
{
	v1 = Find(v1);
	v2 = Find(v2);
	if (v1 != v2) unf[v1] = v2;
}

struct Planet
{
	int x, y, z;
	Planet() {}
	Planet(int x, int y, int z) : x(x), y(y), z(z) {}

	bool operator<(const Planet& p)const { return x < p.x; }
};

struct Edge
{
	Planet p1, p2;
	int c;
	Edge() {}
	Edge(Planet p1, Planet p2, int c) : p1(p1), p2(p2), c(c) {}
	bool operator<(const Edge& e)const { return c < e.c; }
};

bool compX(const Planet& p1, const Planet& p2) { return p1.x < p2.x; }
bool compY(const Planet& p1, const Planet& p2) { return p1.y < p2.y; }
bool compZ(const Planet& p1, const Planet& p2) { return p1.z < p2.z; }

// 행성 터널
int main()
{
	init;

	// 두 행성 사이 비용 => x, y, z의 차이 중 최솟값
	// x 좌표로 행성 정렬 => 인접한 행성간 x좌표 차이가 최솟값일 가능성이 높음

	int n; cin >> n;
	loop(i, home, n) unf[i] = i;
	tvec(Edge, graph);
	vec(Planet, planet, n);
	map<Planet, int> m;
	int x, y, z;
	loop(i, home, n)
	{
		cin >> x >> y >> z;
		Planet p = Planet(x, y, z);
		planet[i] = p;
		m[p] = i;
	}

	// 각 좌표를 기준으로 정렬 후 간선 추가
	sort(planet.begin(), planet.end(), compX);
	loop(i, home, n - 1) graph.push_back(Edge(planet[i], planet[i + 1], abs(planet[i].x - planet[i + 1].x)));

	sort(planet.begin(), planet.end(), compY);
	loop(i, home, n - 1) graph.push_back(Edge(planet[i], planet[i + 1], abs(planet[i].y - planet[i + 1].y)));

	sort(planet.begin(), planet.end(), compZ);
	loop(i, home, n - 1) graph.push_back(Edge(planet[i], planet[i + 1], abs(planet[i].z - planet[i + 1].z)));

	sort(all(graph));

	int ans = home;
	loop(i, home, graph.size())
	{
		int planet1 = Find(m[graph[i].p1]);
		int planet2 = Find(m[graph[i].p2]);

		if (planet1 != planet2)
		{
			Union(planet1, planet2);
			ans += graph[i].c;
		}
	}
	elp(ans);

	return home;
}
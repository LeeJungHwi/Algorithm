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

// 발전소 설치
int main()
{
	init;

	// 두 발전소 사이 거리가 m 이하인 경우 간선 추가
	// 이미 연결된 두 발전소는 가중치 0으로 추가

	int n, w; cin >> n >> w;
	double m; cin >> m;
	vector<vector<pair<int, double>>> graph(n);
	vector<pair<double, double>> v(n);
	loop(i, home, n) cin >> v[i].lhs >> v[i].rhs;
	loop(i, home, n)
	{
		loop(j, i + 1, n)
		{
			//double l = v[i].lhs - v[j].lhs, r = v[i].rhs - v[j].rhs;
			//double c = sqrt(l * l + r * r);
			//sqrt(((v[i].lhs - v[j].lhs) * (v[i].lhs - v[j].lhs)) + (v[i].rhs - v[j].rhs) * (v[i].rhs - v[j].rhs));
			if (sqrt(((v[i].lhs - v[j].lhs) * (v[i].lhs - v[j].lhs)) + (v[i].rhs - v[j].rhs) * (v[i].rhs - v[j].rhs)) > m) continue;

			graph[i].push_back({ j, sqrt(((v[i].lhs - v[j].lhs) * (v[i].lhs - v[j].lhs)) + (v[i].rhs - v[j].rhs) * (v[i].rhs - v[j].rhs)) });
			graph[j].push_back({ i, sqrt(((v[i].lhs - v[j].lhs) * (v[i].lhs - v[j].lhs)) + (v[i].rhs - v[j].rhs) * (v[i].rhs - v[j].rhs)) });
		}
	}
	int v1, v2;
	loop(i, home, w)
	{
		cin >> v1 >> v2;
		graph[--v1].push_back({ --v2, home });
		graph[v2].push_back({ v1, home });
	}

	priority_queue<pair<double, int>, vector<pair<double, int>>, greater< pair<double, int>>> pq;
	vector<double> dis(n, numeric_limits<double>::max());
	pq.push({ home, home });
	dis[home] = home;

	while (!pq.empty())
	{
		int sp = pq.top().rhs;
		double sc = pq.top().lhs;
		pq.pop();

		if (dis[sp] < sc) continue;

		loop(i, home, graph[sp].size())
		{
			int cp = graph[sp][i].lhs;
			double cc = graph[sp][i].rhs;

			if (dis[cp] <= dis[sp] + cc) continue;

			dis[cp] = dis[sp] + cc;
			pq.push({ dis[cp], cp });
		}
	}
	elp(static_cast<int>(dis[n - 1] * 1000));

	return home;
}
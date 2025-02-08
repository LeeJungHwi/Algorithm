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

struct Train
{
	string type, v1, v2;
	double c;
	Train() {}
	Train(string t, string v1, string v2, double c)
	{
		this->type = t;
		this->v1 = v1;
		this->v2 = v2;

		if (type == "Mugunghwa" || type == "ITX-Saemaeul" || type == "ITX-Cheongchun") this->c = home;
		else if (type == "S-Train" || type == "V-Train") this->c = c / 2;
		else this->c = c;
	}
};

// 내일로 여행
int main()
{
	init;

	// 무궁화호, ITX-새마을, ITX-청춘 무료
	// S-Train, V-Train 50% 할인

	// 플로이드 2번?
	// 티켓을 사지 않았을때 그래프에 간선 최소비용 넣고 플로이드
	// 티켓을 샀을때 그래프에 무궁화호, ITX-새마을, ITX-청춘d은 비용 0, S-Train V-Train 이면 c / 2와 기존 비용 중 최솟값 넣고 플로이드

	int n;
	double r;
	cin >> n >> r;
	string is;
	map<string, int> cityMap;
	loop(i, home, n)
	{
		cin >> is;
		cityMap[is] = i + 1;
	}
	mat(double, graph, n + 1, n + 1);
	loop(i, home, n + 1) loop(j, home, n + 1) graph[i][j] = 1000000000;
	
	int m; cin >> m;
	vec(string, travel, m);
	loop(i, home, m) cin >> travel[i];

	int k; cin >> k;
	tvec(Train, edge);
	string type, v1, v2;
	double c;
	loop(i, home, k)
	{
		cin >> type >> v1 >> v2 >> c;
		graph[cityMap[v1]][cityMap[v2]] = min(graph[cityMap[v1]][cityMap[v2]], c);
		graph[cityMap[v2]][cityMap[v1]] = min(graph[cityMap[v2]][cityMap[v1]], c);
		edge.push_back(Train(type, v1, v2, c));
	}
	loop(i, home, n + 1) graph[i][i] = home;

	// 티켓을 사지 않았을때 플로이드
	loop(l, 1, n + 1) loop(i, 1, n + 1) loop(j, 1, n + 1) graph[i][j] = min(graph[i][j], graph[i][l] + graph[l][j]);

	double nTicket = home;
	loop(i, home, m - 1) nTicket += graph[cityMap[travel[i]]][cityMap[travel[i + 1]]];
	//elp(nTicket);

	loop(i, home, n + 1) loop(j, home, n + 1) graph[i][j] = 1000000000;
	loop(i, home, edge.size())
	{
		graph[cityMap[edge[i].v1]][cityMap[edge[i].v2]] = min(graph[cityMap[edge[i].v1]][cityMap[edge[i].v2]], edge[i].c);
		graph[cityMap[edge[i].v2]][cityMap[edge[i].v1]] = min(graph[cityMap[edge[i].v2]][cityMap[edge[i].v1]], edge[i].c);
	}
	loop(i, home, n + 1) graph[i][i] = home;

	// 티켓을 샀을때 플로이드
	loop(l, 1, n + 1) loop(i, 1, n + 1) loop(j, 1, n + 1) graph[i][j] = min(graph[i][j], graph[i][l] + graph[l][j]);
	
	double yTicket = r;
	loop(i, home, m - 1) yTicket += graph[cityMap[travel[i]]][cityMap[travel[i + 1]]];
	//elp(yTicket);

	// 티켓을 샀을때 가격이 같거나 더 크면 굳이 살필요없음
	elp(cond(nTicket > yTicket, "Yes", "No"));

	return home;
}
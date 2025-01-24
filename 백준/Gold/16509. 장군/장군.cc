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

// 장군
int main()
{
	init;

	pii start, end;
	cin >> start.lhs >> start.rhs >> end.lhs >> end.rhs;
	vector<pii> d = { {-2, -2}, {-2, 2}, {2, -2}, {2, 2}, {-2, -2}, {2, -2}, {-2, 2}, {2, 2} }; dir;
	queue<pii> cp;
	mat(int, graph, 10, 9);
	graph[start.lhs][start.rhs] = 1;
	cp.push(start);
	while (!cp.empty())
	{
		pii s = cp.front();
		cp.pop();
		//cout << s.lhs << ' ' << s.rhs << '\n';
		if (s.lhs == end.lhs && s.rhs == end.rhs) { elp(--graph[end.lhs][end.rhs]); return home; }
		loop(i, home, 4)
		{
			int ci = s.lhs + cd[i].lhs;
			int cj = s.rhs + cd[i].rhs;
			if (ci < home || cj < home || ci >= 10 || cj >= 9) continue;
			if (ci == end.lhs && cj == end.rhs) continue;
			// 0 01
			// 1 23
			// 2 45
			// 3 67
			
			// 2 + 2*0
			// 2 + 2*1
			// 2 + 2*2
			// 2 + 2*3
			loop(j, i * 2, 2 + 2 * i)
			{
				int ci2 = ci + d[j].lhs / 2;
				int cj2 = cj + d[j].rhs / 2;
				if (ci2 < home || cj2 < home || ci2 >= 10 || cj2 >= 9) continue;
				if (ci2 == end.lhs && cj2 == end.rhs) continue;
				ci2 = ci2 + d[j].lhs / 2;
				cj2 = cj2 + d[j].rhs / 2;
				if (ci2 < home || cj2 < home || ci2 >= 10 || cj2 >= 9) continue;
				if (graph[ci2][cj2] > home) continue;
				cp.push({ ci2, cj2 });
				graph[ci2][cj2] = graph[s.lhs][s.rhs] + 1;
			}
		}
	}

	elp(-1);
	return home;
}
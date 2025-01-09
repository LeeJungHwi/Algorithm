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

// 판화
int main()
{
	init;

	int n; cin >> n;
	mat(char, graph, n, n);
	loop(i, home, n) loop(j, home, n) graph[i][j] = '.';
	pii cur = { 0, 0 };
	map<char, pii> direc = { {'U', {-1, 0}}, {'D', {1, 0}}, {'L', {0, -1}}, {'R', {0, 1}} };
	string command; cin >> command;
	loop(i, home, command.size())
	{
		int ci = cur.first + direc[command[i]].first;
		int cj = cur.second + direc[command[i]].second;
		if (ci < home || cj < home || ci >= n || cj >= n) continue;
		switch (command[i])
		{
			case 'D':
			case 'U':
				if (graph[cur.first][cur.second] == '.') graph[cur.first][cur.second] = '|';
				else if (graph[cur.first][cur.second] == '-') graph[cur.first][cur.second] = '+';
				if (graph[ci][cj] == '.') graph[ci][cj] = '|';
				else if (graph[ci][cj] == '-') graph[ci][cj] = '+';
				break;
			case 'L':
			case 'R':
				if (graph[cur.first][cur.second] == '.') graph[cur.first][cur.second] = '-';
				else if (graph[cur.first][cur.second] == '|') graph[cur.first][cur.second] = '+';
				if (graph[ci][cj] == '.') graph[ci][cj] = '-';
				else if (graph[ci][cj] == '|') graph[ci][cj] = '+';
				break;
		}
		cur = { ci, cj };
	}

	for (auto a : graph)
	{
		for (auto b : a)
		{
			cout << b;
		}
		cout << '\n';
	}

	return home;
}
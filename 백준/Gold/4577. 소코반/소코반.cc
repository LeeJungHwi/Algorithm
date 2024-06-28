#include <bits/stdc++.h>
using namespace std;

#define home 0

#define ll long long
#define ld long double

#define pii pair<int, int>
#define pll pair<ll, ll>

#define loop(v, s, e) for(int v = (s); v < (e); v++)
#define rloop(v, s, e) for(int v = (s); v > (e); v--)
#define mloop(v, a) for(auto v = (a).begin(); v != (a).end(); v++)
#define mrloop(v, a) for(auto v = (a).rbegin(); v != (a).rend(); v++)
#define aloop(t, v, s, c, e, i) for(t v = (s); v c (e); i)

#define p(a) cout << (a)
#define elp(a) cout << (a) << '\n'
#define scp(a) cout << (a) << ' '

#define vec(t, v, r) vector<t> v((r))
#define mat(t, v, r, c) vector<vector<t> > v((r), vector<t>((c)))
#define gmat(t, v, r) vector<vector<t> > v((r))
#define dir map<char, pii> cd = { {'U', {-1,0}}, {'D', {1,0}}, {'L', {0,-1}}, {'R', {0,1}}}

#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

// 스코반
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	dir;
	int cur = home;
	while (true)
	{
		int n, m;
		cin >> n >> m;
		if (!n && !m) return home;
		mat(char, graph, n, m);
		pii sPos;
		int curBoxCnt = home;
		bool isEnd = false;
		map<pii, int> targetPos;
		loop(i, home, n) loop(j, home, m)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 'w') sPos = { i, j };
			else if(graph[i][j] == 'W')
			{
				sPos = { i, j };
				targetPos[{i, j}]++;
			}
			else if (graph[i][j] == 'b') curBoxCnt++;
			else if (graph[i][j] == 'B') targetPos[{i, j}]++;
			else if (graph[i][j] == '+') { targetPos[{i, j}]++; graph[i][j] = '.'; }
		}
		string is;
		cin >> is;
		loop(i, home, is.size())
		{
			int ci = sPos.lhs + cd[is[i]].lhs;
			int cj = sPos.rhs + cd[is[i]].rhs;

			// 일단 벽 거르고
			if (graph[ci][cj] == '#') continue;

			// 다음 칸이 목표 지점이 아닐 때
			if (!targetPos[{ci, cj}])
			{
				// 다음 칸이 박스일 때
				if (graph[ci][cj] == 'b')
				{
					int cii = ci + cd[is[i]].lhs;
					int cjj = cj + cd[is[i]].rhs;

					// 박스 다음 칸이 벽이거나 박스면 못 밀고
					if (graph[cii][cjj] == '#' || graph[cii][cjj] == 'b' || graph[cii][cjj] == 'B') continue;
					
					// 박스 다음 칸이 목표 지점이 아닐 때
					if (!targetPos[{cii, cjj}])
					{
						graph[cii][cjj] = 'b';
						graph[ci][cj] = 'w';
						graph[sPos.lhs][sPos.rhs] = '.';
					}
					else // 박스 다음 칸이 목표 지점일 때
					{
						graph[cii][cjj] = 'B';
						graph[ci][cj] = 'w';
						graph[sPos.lhs][sPos.rhs] = '.';
						curBoxCnt--;
					}
				}
				else // 다음 칸이 빈 칸일 때
				{
					graph[ci][cj] = 'w';
					graph[sPos.lhs][sPos.rhs] = '.';
				}

				sPos.lhs = ci;
				sPos.rhs = cj;
			}
			else // 다음 칸이 목표 지점일 때
			{
				// 다음 칸이 박스일 때
				if (graph[ci][cj] == 'B')
				{
					int cii = ci + cd[is[i]].lhs;
					int cjj = cj + cd[is[i]].rhs;

					// 박스 다음 칸이 벽이거나 박스면 못 밀고
					if (graph[cii][cjj] == '#' || graph[cii][cjj] == 'b' || graph[cii][cjj] == 'B') continue;
				
					// 박스 다음 칸이 목표 지점이 아닐 때
					if (!targetPos[{cii, cjj}])
					{
						graph[cii][cjj] = 'b';
						graph[ci][cj] = 'W';
						graph[sPos.lhs][sPos.rhs] = '.';
						curBoxCnt++;
					}
					else // 박스 다음 칸이 목표 지점일 때
					{
						graph[cii][cjj] = 'B';
						graph[ci][cj] = 'W';
						graph[sPos.lhs][sPos.rhs] = '.';
					}
				}
				else // 다음 칸이 빈 칸일 때
				{
					graph[ci][cj] = 'W';
					graph[sPos.lhs][sPos.rhs] = '.';
				}

				sPos.lhs = ci;
				sPos.rhs = cj;
			}

			// 게임 끝
			if (!curBoxCnt)
			{
				scp("Game"); p(++cur); scp(":"); elp("complete");

				loop(j, home, n)
				{
					loop(k, home, m)
					{
						if (targetPos[{j, k}] && graph[j][k] == '.') p('+');
						else p(graph[j][k]);
					}
					elp("");
				}

				isEnd = true;
				break;
			}
		}

		// 게임 끝 X
		if (!isEnd)
		{
			scp("Game"); p(++cur); scp(":"); elp("incomplete");

			loop(j, home, n)
			{
				loop(k, home, m)
				{
					if(targetPos[{j, k}] && graph[j][k] == '.') p('+');
					else p(graph[j][k]);
				}
				elp("");
			}
		}
	}

	return home;
}
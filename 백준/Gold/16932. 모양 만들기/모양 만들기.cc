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

// 모양 만들기
int main()
{
	init;

	int n, m; cin >> n >> m;
	mat(int, graph, n, m);
	tvec(pii, one);
	tvec(pii, zero);
	loop(i, home, n)
	{
		loop(j, home, m)
		{
			cin >> graph[i][j];

			// 0 1 좌표 저장
			if (graph[i][j] == home) zero.push_back({ i, j });
			else if (graph[i][j] == 1) one.push_back({ i, j });
		}
	}

	// 라벨링하고 라벨크기 저장
	int cur = 2;
	queue<pii> cp; dir;
	map<int, int> labelSize;
	loop(i, home, one.size())
	{
		// 이미 라벨링한곳
		if (graph[one[i].lhs][one[i].rhs] > 1) continue;

		cp.push(one[i]);
		int size = 1;
		while (!cp.empty())
		{
			pii s = cp.front();
			cp.pop();
			graph[s.lhs][s.rhs] = cur;

			loop(j, home, 4)
			{
				int ci = s.lhs + cd[j].lhs;
				int cj = s.rhs + cd[j].rhs;
				if (ci < home || cj < home || ci >= n || cj >= m) continue;
				if (graph[ci][cj] == home) continue;
				if (graph[ci][cj] > 1) continue;
				graph[ci][cj] = cur;
				cp.push({ ci, cj });
				size++;
			}
		}
		labelSize[cur++] = size;
	}

	//for (auto a : graph)
	//{
	//	for (auto b : a)
	//	{
	//		cout << b;
	//	}
	//	cout << '\n';
	//}
	//mloop(it, labelSize) cout << it->lhs << ' ' << it->rhs << '\n';

	// 0인곳에서 상하좌우에 있는 라벨 크기의 합의 최대
	int maxSize = -2147000000;
	loop(i, home, zero.size())
	{
		pii s = zero[i];

		int size = 1;

		// 중복라벨 체크
		set<int> labelSet;
		loop(j, home, 4)
		{
			int ci = s.lhs + cd[j].lhs;
			int cj = s.rhs + cd[j].rhs;
			if (ci < home || cj < home || ci >= n || cj >= m) continue;
			if (graph[ci][cj] == home) continue;
			labelSet.insert(graph[ci][cj]);
		}

		for (auto it = labelSet.begin(); it != labelSet.end(); it++) size += labelSize[*it];
		maxSize = max(maxSize, size);
	}

	elp(maxSize);

	return home;
}
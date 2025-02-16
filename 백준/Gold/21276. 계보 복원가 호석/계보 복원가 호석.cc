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

// 계보 복원가 호석
int main()
{
	init;

	// 맵으로 이름을 정수로 파싱
	// 처음 inDegree가 없는 정점들이 시조
	// 위상정렬 수행
	// 그래프 돌면서 자신하고 연결된 정점이 1차이나면 자식 정점

	int n; cin >> n;
	map<string, int> nameMap;
	map<int, string> numMap;
	string is1, is2;
	loop(i, home, n)
	{
		cin >> is1;
		nameMap[is1] = i + 1;
		numMap[i + 1] = is1;
	}
	gmat(int, graph, n + 1);
	vec(int, directPre, n + 1);
	int m; cin >> m;
	loop(i, home, m)
	{
		cin >> is1 >> is2;
		graph[nameMap[is2]].push_back(nameMap[is1]);
		directPre[nameMap[is1]]++;
	}

	queue<int> noPre;
	int k = home;
	tvec(string, root);
	loop(i, 1, n + 1)
	{
		if (directPre[i] == home)
		{
			k++;
			root.push_back(numMap[i]);
			noPre.push(i);
		}
	}

	// 시조 출력
	elp(k); sort(all(root));
	loop(i, home, k) scp(root[i]);
	cout << '\n';

	// 위상정렬
	vec(int, ans, n + 1);
	while (!noPre.empty())
	{
		int s = noPre.front();
		noPre.pop();

		loop(i, home, graph[s].size())
		{
			int c = graph[s][i];

			ans[c] = max(ans[c], ans[s] + 1);

			if (--directPre[c] == home) noPre.push(c);
		}
	}

	//	2
	//	minji sangdo
	//	1
	//	0
	//	1
	//	2
	//	0
	//	1
	//	2
	//loop(i, 1, n + 1) elp(ans[i]);

	// 사전순이니까 nameMap 순서대로 돌면서
	// 자신과 연결된 정점 중 자신보다 +1 순서를 갖는 정점
	mloop(it, nameMap)
	{
		tvec(string, child);
		loop(i, home, graph[it->rhs].size())
		{
			if (ans[graph[it->rhs][i]] == ans[it->rhs] + 1)
			{
				child.push_back(numMap[graph[it->rhs][i]]);
			}
		}

		scp(it->lhs); scp(child.size()); sort(all(child));
		loop(i, home, child.size()) scp(child[i]);
		cout << '\n';
	}

	return home;
}
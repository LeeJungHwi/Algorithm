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

// 지구 온난화
int main()
{
	init;

	// 0 => 바다, 1 => 땅
	int n, m; cin >> n >> m;
	mat(int, graph, n + 2, m + 2);
	tvec(pii, ground);
	char c; dir;
	loop(i, 1, n + 1) loop(j, 1, m + 1)
	{
		cin >> c;
		if (c == 'X')
		{
			graph[i][j] = 1;
			ground.push_back({ i, j });
		}
	}

	//for (auto a : graph)
	//{
	//	for (auto b : a)
	//	{
	//		cout << b;
	//	}
	//	cout << '\n';
	//}
	//cout << '\n';
	
	// 바다에 잠기는 땅 구하기
	tvec(pii, sea);
	loop(i, home, ground.size())
	{
		int cnt = home;
		loop(j, home, 4)
		{
			int ci = ground[i].lhs + cd[j].lhs;
			int cj = ground[i].rhs + cd[j].rhs;

			if (!graph[ci][cj]) cnt++;
			if (cnt >= 3)
			{
				sea.push_back(ground[i]);
				break;
			}
		}
	}

	// 기존땅이 모두 없어지는 경우 X 출력
	if (ground.size() == sea.size())
	{
		cout << 'X' << '\n';
		return home;
	}

	// 바다로되는 기존땅 처리
	loop(i, home, sea.size()) graph[sea[i].lhs][sea[i].rhs] = home;

	//for (auto a : graph)
	//{
	//	for (auto b : a)
	//	{
	//		cout << b;
	//	}
	//	cout << '\n';
	//}

	// 가장 작은 직사각형
	//000000000000
	//000000000000
	//000111011100
	//011100000000
	//000000000000

	//000000000000
	//000000000000
	//000110001000
	//001100000000
	//000000000000

	int minJ = home, maxJ = home, minI = home, maxI = home;

	loop(j, 1, m + 1)
	{
		bool isGround = false;
		loop(i, 1, n + 1)
		{
			if (graph[i][j] == 1)
			{
				isGround = true;
				minJ = j;
				break;
			}
		}
		if (isGround) break;
	}

	rloop(j, m, home)
	{
		bool isGround = false;
		loop(i, 1, n + 1)
		{
			if (graph[i][j] == 1)
			{
				isGround = true;
				maxJ = j;
				break;
			}
		}
		if (isGround) break;
	}

	loop(i, 1, n + 1)
	{
		bool isGround = false;
		loop(j, 1, m + 1)
		{
			if (graph[i][j] == 1)
			{
				isGround = true;
				minI = i;
				break;
			}
		}
		if (isGround) break;
	}

	rloop(i, n, home)
	{
		bool isGround = false;
		loop(j, 1, m + 1)
		{
			if (graph[i][j] == 1)
			{
				isGround = true;
				maxI = i;
				break;
			}
		}
		if (isGround) break;
	}

	// 2238
	//cout << minI << ' ' << minJ << ' ' << maxI << ' ' << maxJ << '\n';

	// 50년 후 지도
	mat(char, ans, maxI - minI + 1, maxJ - minJ + 1);
	loop(i, minI, maxI + 1)
	{
		loop(j, minJ, maxJ + 1)
		{
			ans[i - minI][j - minJ] = graph[i][j] == home ? '.' : 'X';
		}
	}

	for (auto a : ans)
	{
		for (auto b : a)
		{
			cout << b;
		}
		cout << '\n';
	}


	return home;
}
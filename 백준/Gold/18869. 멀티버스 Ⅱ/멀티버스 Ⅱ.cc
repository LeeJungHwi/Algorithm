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

// 멀티버스 Ⅱ
int main()
{
	init;

	int m, n; cin >> m >> n;
	mat(int, space, m, n);
	loop(i, home, m) loop(j, home, n) cin >> space[i][j];
	
	// 각 우주 내 행성의 순위를 매기고 저장
	map<vector<int>, int> rankSpace;

	int ans = home;
	loop(i, home, m)
	{
		// 현재 우주 내 행성 정렬
		vector<int> sortedSpace = space[i];
		sort(all(sortedSpace));

		// 각 행성의 순위 매김
		unordered_map<int, int> rank;
		loop(j, home, n) rank[sortedSpace[j]] = j;

		// 우주 내 행성의 순위를 벡터로 변환
		vec(int, rankedSpace, n);
		loop(j, home, n) rankedSpace[j] = rank[space[i][j]];

		// 맵에 저장
		rankSpace[rankedSpace]++;
	}

	// 1개 0 => 0
	// 2개 1 => 1
	// 3개 1 + 2 => 3
	// 4개 1 + 2 + 3 => 6
	// 5개 1 + 2 + 3 + 4 => 10
	mloop(it, rankSpace)
	{
		if (it->rhs == 1 || it->rhs == 2) ans += it->rhs - 1;
		else
		{
			// 1 ~ it->rhs - 1 까지 합
			ans += it->rhs * (it->rhs - 1) / 2;
		}
	}
	elp(ans);

	return home;
}
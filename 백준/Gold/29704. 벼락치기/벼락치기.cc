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

// 벼락치기
int main()
{
	init;

	// 아이템 개수 제한 => 역순 냅색

	int n, t, sum = home; cin >> n >> t;
	vec(pii, problem, n);
	loop(i, home, n)
	{
		cin >> problem[i].lhs >> problem[i].rhs;
		sum += problem[i].rhs;
	}

	vec(int, dp, t + 1); // dp[i] => 남은 제출 기한이 i일때 벌금의 최댓값

	// 각 문제에 대해
	loop(i, home, n)
	{
		// 각 문제를 풀 수 있는 날에 대해
		rloop(j, t, problem[i].lhs - 1)
		{
			// dp[j - problem[i].lhs] => 현재 문제를 풀었을때 벌금의 최댓값
			// 기존 dp값과 현재 문제를 풀었을때 벌금의 최댓값 + 현재 문제를 풀지 않았을때 벌금 중 최댓값으로 업데이트
			dp[j] = max(dp[j], dp[j - problem[i].lhs] + problem[i].rhs);
		}
	}
	elp(sum - dp[t]);

	return home;
}
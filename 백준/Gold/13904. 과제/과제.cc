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

// 과제
int main()
{
	init;

	int n; cin >> n;
	int d, s, maxD = -1;
	vec(pii, v, n);
	priority_queue<int> pq;
	int pushCnt = home, ans = home;
	loop(i, home, n)
	{
		cin >> v[i].lhs >> v[i].rhs;
		maxD = max(maxD, v[i].lhs);
	}
	sort(rall(v));

	// 마지막 날짜에 할 수 있는 과제부터
	rloop(i, maxD, home)
	{
		// pushCnt 이전 과제들 => 이미 큐에 추가된 과제
		loop(j, pushCnt, n)
		{
			// 현재 날짜보다 작으면 과제 X
			if (v[j].lhs < i) break;

			// 현재 날짜에 과제가 가능하면 pq에 추가
			pq.push(v[j].rhs);
			pushCnt++;
		}

		// 현재 날짜에 할 수 있는 과제 중 최대 점수인 과제 수행
		if (!pq.empty())
		{
			ans += pq.top();
			pq.pop();
		}
	}
	elp(ans);

	return home;
}
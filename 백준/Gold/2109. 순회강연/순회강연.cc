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

struct Lec
{
	int pay, day;

	Lec() {}
	Lec(int p, int d) : pay(p), day(d) {}

	// 남은 일 수 내림차순
	bool operator<(const Lec& l)
	{
		return day > l.day;
	}
};

// 순회강연
int main()
{
	init;

	int n; cin >> n;
	int p, d, maxD = -2147000000;
	tvec(Lec, v);
	priority_queue<int> pq;
	int pushCnt = home, ans = home;

	loop(i, home, n)
	{
		cin >> p >> d;
		v.push_back(Lec(p, d));
		maxD = max(maxD, d);
	}

	// 20 5
	// 10 50
	// 3 10
	// 2 100
	// 2 8
	// 1 20
	// 1 2
	sort(all(v));

	// 마지막 날짜에 할 수 있는 강연부터
	rloop(i, maxD, home)
	{
		// pushCnt 이전 강연들 => 이미 pq에 추가된 강연
		loop(j, pushCnt, n)
		{
			// 현재 날짜보다 작으면 강연 X
			if (v[j].day < i) break;

			// 현재 날짜에 강연이 가능하면 pq에 추가
			pq.push(v[j].pay);
			pushCnt++;
		}

		// 현재 날짜에 강연할 수 있는 강연 중 최대수입 누적
		// pq {5} => ans = 5
		// pq {50} => ans = 55
		// pq {10} => ans = 65
		// pq {100, 8} => ans = 165
		// pq {20, 8, 2} => ans = 185 => pq {8, 2}
		if (!pq.empty())
		{
			ans += pq.top();
			pq.pop();
		}
	}
	elp(ans);

	return home;
}
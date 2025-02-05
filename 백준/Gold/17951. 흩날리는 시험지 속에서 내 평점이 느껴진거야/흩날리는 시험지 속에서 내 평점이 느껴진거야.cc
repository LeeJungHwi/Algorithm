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

int n, k;

bool Check(int s, vector<int> &v)
{
	int ansCnt = home, groupCnt = home;

	loop(i, home, n)
	{
		ansCnt += v[i];

		if (s <= ansCnt)
		{
			ansCnt = home;
			groupCnt++;
		}
	}
	
	// 그룹을 k개 이상으로 나눌수있으면 가능한 경우
	return k <= groupCnt;
}

// 흩날리는 시험지 속에서 내 평점이 느껴진거야
int main()
{
	init;

	// lo => 맞은 시험 개수 최솟값
	// hi => 맞은 시험 개수 총합

	cin >> n >> k;
	int l = 2147000000, h = home;
	vec(int, v, n);
	loop(i, home, n)
	{
		cin >> v[i];
		l = min(l, v[i]);
		h += v[i];
	}

	int ans = home;
	while (l <= h)
	{
		// 하나의 그룹이 맞을 수 있는 문제 개수의 최솟값
		int s = (l + h) / 2;

		// 그룹을 k개 이상으로 나눌 수 있으면 하나의 그룹이 더 최대개수로 맞을 수 있는지 재탐색
		if (Check(s, v))
		{
			ans = s;
			l = s + 1;
		} // 그룹을 k개 이상으로 나눌 수 없다면 하나의 그룹이 맞을 수 있는 문제의 개수를 줄여 그룹 수를 늘림
		else h = s - 1;
	}
	elp(ans);

	return home;
}
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

int n, k, m;

bool Check(int s, vector<int> &l)
{
	int cnt = home;
	
	loop(i, home, l.size()) cnt += l[i] / s;

	return cnt >= m;
}

// 그르다 김가놈
int main()
{
	init;

	// 기준 => 자르고 싶은 P cm
	// 손질된 김밥 => 양쪽 꼬다리 k cm씩 자를 수 있으면 양쪽을 자르고, 한쪽만 가능하면 한쪽만 k cm를 자름
	// lo => 1
	// hi => 손질된 김밥의 길이 중 최댓값
	// p를 s로 설정했을때 김밥조각이 m개 이상이면 가능한경우

	cin >> n >> k >> m;
	tvec(int, length);
	int l = 1, h = -2147000000;
	int num;
	loop(i, home, n)
	{
		cin >> num;
		if (num <= k) continue;
		length.push_back(cond(num < 2 * k, num = num - k, num = num - 2 * k));
		h = max(h, num);
	}

	int ans = home;
	while (l <= h)
	{
		int s = (l + h) / 2;

		if (Check(s, length))
		{
			l = s + 1;
			ans = s;
		}
		else h = s - 1;
	}
	elp(cond(ans == home, -1, ans));

	return home;
}
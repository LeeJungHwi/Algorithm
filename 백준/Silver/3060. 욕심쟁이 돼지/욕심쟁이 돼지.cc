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

// 욕심쟁이 돼지
int main()
{
	init;

	int tc; cin >> tc;

	// 양옆, 마주보는
	map<int, vector<int> > ch = { {1, {2, 4, 6}}, {2, {1, 3, 5}}, {3, {2, 4, 6}}, {4, {3, 5, 1}}, {5, {4, 6, 2}}, {6, {1, 3, 5}} };
	while (tc--)
	{
		int n; cin >> n;

		// 전 날 먹은
		map<int, int> eat;
		int totalEat = home, ans = 1;
		loop(i, 1, 7)
		{
			cin >> eat[i];
			totalEat += eat[i];
		}

		// 첫 날 체크
		if (totalEat > n)
		{
			cout << ans << '\n';
			continue;
		}

		// 못 먹는 날
		while (true)
		{
			// 다음날
			ans++;

			// 오늘 먹는 사료 합
			totalEat = home;

			// 오늘 각 돼지가 먹는 사료
			vec(int, temp, 7);

			// 각 돼지가 먹는 사료 처리
			mloop(it, ch)
			{
				int curPigEat = eat[it->first];
				loop(i, home, it->second.size()) curPigEat += eat[it->second[i]];
				temp[it->first] = curPigEat;
				totalEat += curPigEat;
			}

			// 못 먹는 날 체크
			if (totalEat > n)
			{
				cout << ans << '\n';
				break;
			}

			// 각 돼지가 오늘 먹은 사료 업데이트
			loop(i, 1, 7) eat[i] = temp[i];
		}
	}

	return home;
}
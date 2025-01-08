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

// 등수 구하기
int main()
{
	init;

	int n, taesu, p;
	cin >> n >> taesu >> p;

	// 기존 등수가 없는경우
	if (n == 0)
	{
		cout << 1 << '\n';
		return home;
	}

	// 등수 저장
	// 10 9 8 7 6 5 4 3 3 0
	// 1 2 3 4 5 6 7 8 8 10
	vec(int, score, n);
	vec(int, rank, n + 1);
	loop(i, home, n) cin >> score[i];
	score.push_back(taesu);
	sort(score.rbegin(), score.rend());
	int curScore = -2147000000, curRank = 1, carry = 0, result = 0;
	loop(i, home, n + 1)
	{
		if (score[i] > curScore)
		{
			curScore = score[i];
			rank[i] = curRank;
		}
		else if (score[i] == curScore)
		{
			rank[i] = curRank;
			carry++;
		}
		else
		{
			curScore = score[i];
			rank[i] = ++curRank += carry;
			carry = 0;
		}

		if (score[i] == taesu)
		{
			//cout << i << ' ';
			result = rank[i];
			if (i >= p)
			{
				cout << -1 << '\n';
				return home;
			}
		}
	}

	//loop(i, home, n + 1) cout << score[i] << ' ' << rank[i] << '\n';
	cout << result << '\n';

	return home;
}
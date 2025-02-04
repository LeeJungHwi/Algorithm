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

vector<int> unf(30001);

int Find(int v)
{
	if (unf[v] == v) return v;
	return unf[v] = Find(unf[v]);
}

void Union(int v1, int v2)
{
	v1 = Find(v1);
	v2 = Find(v2);
	if (v1 != v2) unf[v1] = v2;
}

// 할로윈의 양아치
int main()
{
	init;

	// 1 3 => 9 + 4 => 13
	// 2 5 6 10 => 15 + 1 + 5 + 5 => 26
	// 4 9 => 4 + 20 => 24
	// 7 8 => 19 + 14 => 33

	int n, m, k; cin >> n >> m >> k;
	vec(int, v, n);
	loop(i, home, n) { cin >> v[i]; unf[i] = i; }
	int v1, v2;
	loop(i, home, m)
	{
		cin >> v1 >> v2;
		Union(--v1, --v2);
	}

	unordered_map<int, pii> root;
	loop(i, home, n)
	{
		//elp(Find(i));
		root[Find(i)].lhs += 1;
		root[Find(i)].rhs += v[i];
	}
	//mloop(it, root) cout << it->rhs.lhs << ' ' << it->rhs.rhs << '\n';

	tvec(pii, s);
	mloop(it, root) s.push_back(it->rhs);

	// dp[i] => i명 학생한테 얻을 수 있는 사탕의 최대 가치
	vec(int, dp, k);
	loop(i, home, s.size())
	{
		// 역순 => 같은 집합을 여러 번 사용 X
		rloop(j, k - 1, s[i].lhs - 1)
		{
			// s[i] => 현재 사용 할 집합
			// dp[j - s[i].lhs] => (j - s[i].lhs)명 학생한테 얻을 수 있는 사탕의 최대 가치
			// s[i].rhs => 현재 사용 할 집합의 가치
			// s[i]를 사용한 가치 => dp[j - s[i].lhs] + s[i].rhs
			// s[i]를 사용한 가치가 기존 dp값보다 크면 업데이트
			dp[j] = max(dp[j], dp[j - s[i].lhs] + s[i].rhs);
		}
	}
	elp(dp[--k]);

	return home;
}
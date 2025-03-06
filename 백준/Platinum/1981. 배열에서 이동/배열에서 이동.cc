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
#define piii pair<int, pii>
#define pll pair<ll, ll>
#define plll pair<ll, pll>

#define loop(v, s, e) for(int v = (s); v < (e); v++)
#define rloop(v, s, e) for(int v = (s); v > (e); v--)
#define mloop(v, a) for(auto v = (a).begin(); v != (a).end(); v++)
#define mrloop(v, a) for(auto v = (a).rbegin(); v != (a).rend(); v++)

#define p(a) cout << (a)
#define elp(a) cout << (a) << '\n'
#define scp(a) cout << (a) << ' '

#define tvec(t, v) vector<t> v
#define vec(t, v, r) vector<t> v((r))
#define ivec(t, v, r, i) vector<t> v((r), i)
#define gmat(t, v, r) vector<vector<t> > v((r))
#define mat(t, v, r, c) vector<vector<t> > v((r), vector<t>((c)))
#define imat(t, v, r, c, i) vector<vector<t> > v((r), vector<t>((c), i))
#define smat(t, v, r, c, s) vector<vector<vector<t> > > v((r), vector<vector<t>>((c), vector<t>((s))))
#define ismat(t, v, r, c, s, i) vector<vector<vector<t> > > v((r), vector<vector<t>>((c), vector<t>((s), i)))
#define ssmat(t, v, r, c, s1, s2) vector<vector<vector<vector<t> > > > v((r), vector<vector<vector<t>>>((c), vector<vector<t>>((s1), vector<t>((s2)))))
#define issmat(t, v, r, c, s1, s2, i) vector<vector<vector<vector<t> > > > v((r), vector<vector<vector<t>>>((c), vector<vector<t>>((s1), vector<t>((s2), i))))
#define sssmat(t, v, r, c, s1, s2, s3) vector<vector<vector<vector<vector<t> > > > > v((r), vector<vector<vector<vector<t>>>>((c), vector<vector<vector<t>>>((s1), vector<vector<t>>((s2), vector<t>((s3))))))
#define isssmat(t, v, r, c, s1, s2, s3, i) vector<vector<vector<vector<vector<t> > > > > v((r), vector<vector<vector<vector<t>>>>((c), vector<vector<vector<t>>>((s1), vector<vector<t>>((s2), vector<t>((s3), i)))))

#define dir vector<pii> cd = { {-1, home}, {1, home}, { home, -1 }, { home, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }
#define kdir vector<pii> kcd = { {-1, -2}, {-2, -1}, { -2, 1 }, { -1, 2 }, { 1, -2 }, { 2, -1 }, { 1, 2 }, { 2, 1 } }
#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

int n;
queue<pii> cp; dir;

bool Check(int mmin, int mmax, vector<vector<int>> &g, vector<vector<bool>> &v)
{
	loop(i, home, n) loop(j, home, n) v[i][j] = false;

	// 최솟값과 최댓값을 유지 하지 못 하면 X
	if (mmin > g[home][home] || mmax < g[home][home]) return false;

	cp.push({ home, home });
	v[home][home] = true;

	while (!cp.empty())
	{
		int si = cp.front().lhs;
		int sj = cp.front().rhs;
		cp.pop();

		loop(i, home, 4)
		{
			int ci = si + cd[i].lhs;
			int cj = sj + cd[i].rhs;

			if (ci < home || cj < home || ci >= n || cj >= n) continue;
			if (v[ci][cj]) continue;
			if (g[ci][cj] < mmin || g[ci][cj] > mmax) continue;

			cp.push({ ci, cj });
			v[ci][cj] = true;
		}
	}

	// n-1,n-1 까지 이동할 수 있으면 가능한경우
	return v[n - 1][n - 1];
}

// 배열에서 이동
int main()
{
	init;

	// lo = 그래프 최솟값 ~ 그래프 최댓값
	// hi = 그래프 최댓값
	// 그래프 최솟값 i와 최댓값 후보 s로 0,0에서 n-1,n-1까지 유지하며 이동할 수 있으면 가능한경우

	cin >> n;
	mat(int, graph, n, n);
	mat(bool, vis, n, n);
	int mmax = MIN, mmin = MAX;
	loop(i, home, n) loop(j, home, n)
	{
		cin >> graph[i][j];
		mmax = max(mmax, graph[i][j]);
		mmin = min(mmin, graph[i][j]);
	}

	int ans = mmax - mmin;
	loop(i, mmin, mmax + 1)
	{
		int l = i, h = mmax, aans = ans;

		while (l <= h)
		{
			int s = (l + h) / 2;

			if (Check(i, s, graph, vis))
			{
				aans = s - i;
				h = s - 1;
			}
			else l = s + 1;
		}

		ans = min(ans, aans);
	}
	elp(ans);

	return home;
}
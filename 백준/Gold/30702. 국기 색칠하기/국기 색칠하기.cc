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

// 국기 색칠하기
int main()
{
	init;
	
	// A의 같은 문자 영역 위치 뽑기
	// 뽑아낸 영역 위치가 B에서도 같은 문자 영역 위치인지 체크
	int n, m; cin >> n >> m;
	mat(char, A, n, m);
	mat(char, B, n, m);
	queue<pii> cp; dir;
	loop(i, home, n) loop(j, home, m) cin >> A[i][j];
	loop(i, home, n) loop(j, home, m) cin >> B[i][j];

	loop(i, home, n) loop(j, home, m) if (isalpha(A[i][j]))
	{
		// A의 같은 문자 영역 위치 뽑기
		tvec(pii, cPos);

		cp.push({ i, j });
		char sc = A[i][j];
		A[i][j] = '.';
		cPos.push_back({ i, j });

		while (!cp.empty())
		{
			int si = cp.front().lhs;
			int sj = cp.front().rhs;
			cp.pop();

			loop(k, home, 4)
			{
				int ci = si + cd[k].lhs;
				int cj = sj + cd[k].rhs;

				if (ci < home || cj < home || ci >= n || cj >= m) continue;
				if (A[ci][cj] != sc) continue;

				cp.push({ ci, cj });
				A[ci][cj] = '.';
				cPos.push_back({ ci, cj });
			}
		}

		// 뽑아낸 영역 위치가 B에서도 같은 문자 영역 위치인지 체크
		sc = B[i][j];
		loop(k, home, cPos.size())
		{
			if (B[cPos[k].lhs][cPos[k].rhs] != sc)
			{
				elp("NO");
				return home;
			}
		}
	}
	elp("YES");

	return home;
}
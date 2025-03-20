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

int n, mmax = MIN, mmin = MAX;

vector<int> order; // 피연산자와 연산자 저장

void DFS(int L, vector<int>& v, vector<int>& op, int& res)
{
	if (L == n)
	{
		// 연산자 우선순위에 맞게 연산하기
		// */ => 바로 연산
		// +- => 저장하고 후처리
		tvec(int, number);
		tvec(char, operation);

		// */ 연산
		number.push_back(order[home]);
		for (int i = 1; i < order.size(); i += 2)
		{
			int num = order[i + 1];
			char oper = order[i];

			// */ => 바로 연산
			if (oper == '*') number.back() *= num;
			else if (oper == '/')
			{
				int temp = number.back();
				number.back() = abs(number.back()) / abs(num);
				if (temp < home) number.back() *= -1;
			}
			// +- => 저장하고 후처리
			else
			{
				number.push_back(num);
				operation.push_back(oper);
			}
		}

		// +- 연산
		res = number[home];
		loop(i, home, operation.size()) res = cond(operation[i] == '+', res + number[i + 1], res - number[i + 1]);

		mmax = max(mmax, res);
		mmin = min(mmin, res);
	}
	else
	{
		// +
		if (op[home] > home)
		{
			order.push_back('+');
			order.push_back(v[L]);
			op[home]--;
			DFS(L + 1, v, op, res);
			op[home]++;
			order.pop_back();
			order.pop_back();
		}

		// -
		if (op[1] > home)
		{
			order.push_back('-');
			order.push_back(v[L]);
			op[1]--;
			DFS(L + 1, v, op, res);
			op[1]++;
			order.pop_back();
			order.pop_back();
		}

		// *
		if (op[2] > home)
		{
			order.push_back('*');
			order.push_back(v[L]);
			op[2]--;
			DFS(L + 1, v, op, res);
			op[2]++;
			order.pop_back();
			order.pop_back();
		}

		// /
		if (op[3] > home)
		{
			order.push_back('/');
			order.push_back(v[L]);
			op[3]--;
			DFS(L + 1, v, op, res);
			op[3]++;
			order.pop_back();
			order.pop_back();
		}
	}
}

// 연산자 끼워넣기 (3)
int main()
{
	init;

	// 각 연산자를 사용하거나 사용하지 않거나로 분기하면서 order 벡터에 피연산자와 연산자 저장
	// 연산자 우선순위에 맞게 연산하고 최댓값 및 최솟값 업데이트
	cin >> n;
	vec(int, v, n);
	loop(i, home, n) cin >> v[i];
	vec(int, op, 4);
	loop(i, home, 4) cin >> op[i];

	int res = home;
	order.push_back(v[home]);
	DFS(1, v, op, res);

	elp(mmax);
	elp(mmin);

	return home;
}
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

// 잃어버린 괄호
int main()
{
	init;

	// 숫자는 파싱해서 num 벡터에 저장
	// 연산자는 op 벡터에 저장
	// - ~ -, 마지막 - 이후 숫자들 묶음
	string is; cin >> is;

	tvec(int, num);
	tvec(char, op);

	string temp = "";
	loop(i, home, is.size())
	{
		if (!isdigit(is[i]))
		{
			num.push_back(stoi(temp));
			temp = "";
			op.push_back(is[i]);
			continue;
		}

		temp += is[i];
	}
	num.push_back(stoi(temp));

	// 55 50 40
	// - +

	int ans = num[home]; 
	bool isMinus = false;
	loop(i, home, op.size())
	{
		if (op[i] == '-') isMinus = true;
		ans = cond(isMinus, ans - num[i + 1], ans + num[i + 1]);
	}
	elp(ans);


	return home;
}
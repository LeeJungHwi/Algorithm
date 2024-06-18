#include <bits/stdc++.h>
using namespace std;

#define home 0
#define psi pair<string, int>
#define loop(v, s, e) for(int v = s; v < e; v++)
#define elprint(a) cout << a << '\n'
#define scprint(a) cout << a << ' '
#define X first
#define Y second
#define all(a) a.begin(), a.end()

bool comp(const psi &p1, const psi &p2) { return p1.X < p2.X; }

// 숫자놀이
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m;
	cin >> m >> n;
	map<char, string> nMap =
	{ {'1', "one"},  {'2', "two"}, {'3', "three"}, {'4', "four"}, {'5', "five"},
	{'6', "six"}, {'7', "seven"}, {'8', "eight"}, {'9', "nine"}, {'0', "zero"} };

	vector<psi> ans;
	loop(i, m, n + 1)
	{
		string toString = to_string(i);
		string temp = "";
		loop(j, 0, toString.size()) temp += nMap[toString[j]];
		ans.push_back({ temp, i });
	}
	sort(all(ans), comp);
	loop(i, 0, n - m + 1)
	{
		if (i > 0 && i % 10 == 0) elprint("");
		scprint(ans[i].Y);
	}

	return home;
}
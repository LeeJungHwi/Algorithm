#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)
#define elprint(a) cout << a << '\n'
#define rvs(a) reverse(a.begin(), a.end())

// 단어 나누기
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	string is;
	cin >> is;
	vector<string> ans;
	loop(i, 1, is.size() - 1) loop(j, i + 1, is.size())
	{
		string f = is.substr(0, i), s = is.substr(i, j - i), t = is.substr(j);
		rvs(f);
		rvs(s);
		rvs(t);
		ans.push_back(f + s + t);
	}
	sort(ans.begin(), ans.end());
	elprint(ans[0]);

	return home;
}
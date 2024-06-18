#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)
#define elprint(a) cout << a << '\n'
#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) a.begin(), a.end()

// 줄 세우기
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n;
	cin >> n;

	vector<string> origin(n);
	string inputString;
	loop(i, 0, n) cin >> origin[i];
	vector<string> temp = origin;
	sort(all(temp));
	bool isInc = true, isDec = true;
	loop(i, 0, n)
	{
		if (origin[i] != temp[i]) isInc = false;
		if (origin[i] != temp[n - i - 1]) isDec = false;
	}
	if (!isInc && !isDec) elprint("NEITHER");
	else cond(isInc, elprint("INCREASING"), elprint("DECREASING"));

	return home;
}
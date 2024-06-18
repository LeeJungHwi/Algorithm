#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)
#define elprint(a) cout << a << '\n'

// 임스와 함께하는 미니게임
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n;
	cin >> n;
	char g;
	cin >> g;
	map<char, int> gMap = { {'Y', 1}, {'F', 2}, {'O', 3} };
	map<string, int> pMap;

	string is;
	int cnt = 0;
	int ans = 0;
	loop(i, 0, n)
	{
		cin >> is;
		if (!pMap[is]) cnt++;
		pMap[is]++;
		if (cnt < gMap[g]) continue;
		ans++;
		cnt = 0;
	}
	elprint(ans);

	return home;
}
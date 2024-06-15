#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)
#define elprint(a) cout << a << '\n'

// 지뢰
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n;
	cin >> n;

	vector<int> bomb(n);
	loop(i, 0, n) cin >> bomb[i];
	loop(i, 0, n) if ((i == 0 || bomb[i - 1] < bomb[i] + 1) && (i == n - 1 || bomb[i] + 1 > bomb[i + 1])) elprint(i + 1);

	return 0;
}

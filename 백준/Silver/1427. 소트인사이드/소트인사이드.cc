#include <bits/stdc++.h>
using namespace std;

#define home 0
#define rloop(v, s, e) for(int v = s; v > e; v--)
#define print(a) cout << a;

// 소트인사이드
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	string inputString;
	cin >> inputString;
	sort(inputString.begin(), inputString.end());
	rloop(i, inputString.size() - 1, -1) print(inputString[i]);

	return home;
}
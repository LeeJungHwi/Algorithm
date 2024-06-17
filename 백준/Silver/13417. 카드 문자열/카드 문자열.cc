#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v+=2)
#define elprint(a) cout << a << '\n'
#define cond(c, t, f) ((c) ? (t) : (f))

// 카드 문자열
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int tc;
	cin >> tc;

	while (tc--)
	{
		int n;
		cin >> n;
		cin.ignore();
		string inputString;
		getline(cin, inputString);
		string outputString = "";
		outputString += inputString[0];

		loop(i, 2, inputString.size()) outputString = cond(inputString[i] <= outputString.front(), inputString[i] + outputString, outputString + inputString[i]);

		elprint(outputString);
	}

	return home;
}
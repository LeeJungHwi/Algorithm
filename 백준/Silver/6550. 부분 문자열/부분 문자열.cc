#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)
#define elprint(a) cout << a << '\n'
#define cond(c, t, f) ((c) ? (t) : (f))

// 부분 문자열
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	cin.ignore();
	string inputString;
	while (getline(cin, inputString))
	{
		string s = "", t = "", temp = "";
		loop(i, 0, inputString.size())
		{
			if (inputString[i] == ' ')
			{
				s = temp;
				temp.clear();
				continue;
			}

			temp += inputString[i];
		}
		t = temp;

		int cur = 0;
		loop(i, 0, t.size()) if (t[i] == s[cur]) cur++;

		cond(cur == s.size(), elprint("Yes"), elprint("No"));
	}

	return home;
}
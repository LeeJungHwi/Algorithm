#include <bits/stdc++.h>
using namespace std;

#define home 0
#define ll long long
#define pii pair<int, int>
#define loop(v, s, e) for(int v = s; v < e; v++)
#define rloop(v, s, e) for(int v = s; v > e; v--)
#define mloop(t, v, s, e, c, i) for(t v = s; v c e; i)
#define elprint(a) cout << a << '\n'
#define scprint(a) cout << a << ' '
#define cond(c, t, f) ((c) ? (t) : (f))
#define mat(t, v, r, c) vector<vector<t> > v(r, vector<t>(c))
#define X first
#define Y second

// 철벽 보안 알고리즘
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

		map<int, string> fMap;
		map<string, int> sMap;
		map<int, int> tMap;
		map<int, string> oMap;

		string inputString;
		getline(cin, inputString);
		inputString += ' ';
		string temp = "";
		int cur = 0;
		loop(i, 0, inputString.size())
		{
			if (inputString[i] == ' ')
			{
				fMap[++cur] = temp;
				sMap[temp] = cur;
				temp.clear();
				continue;
			}

			temp += inputString[i];
		}

		getline(cin, inputString);
		inputString += ' ';
		cur = 0;
		loop(i, 0, inputString.size())
		{
			if (inputString[i] == ' ')
			{
				tMap[++cur] = sMap[temp];
				temp.clear();
				continue;
			}

			temp += inputString[i];
		}

		getline(cin, inputString);
		inputString += ' ';
		cur = 0;
		loop(i, 0, inputString.size())
		{
			if (inputString[i] == ' ')
			{
				oMap[tMap[++cur]] = temp;
				temp.clear();
				continue;
			}

			temp += inputString[i];
		}

		mloop(auto, it, oMap.begin(), oMap.end(), != , it++) scprint(it->second);
		elprint("");
	}

	return home;
}
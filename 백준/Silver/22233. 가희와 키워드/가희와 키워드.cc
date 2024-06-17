#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)
#define elprint(a) cout << a << '\n'

// 가희와 키워드
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m;
	cin >> n >> m;
	set<string> kSet;
	string inputString;
	loop(i, 0, n)
	{
		cin >> inputString;
		kSet.insert(inputString);
	}
	loop(i, 0, m)
	{
		cin >> inputString;

		inputString += ',';
		string temp = "";

		loop(j, 0, inputString.size())
		{
			if (inputString[j] == ',')
			{
				if (kSet.find(temp) != kSet.end()) kSet.erase(temp);
				temp.clear();
				continue;
			}

			temp += inputString[j];
		}

		elprint(kSet.size());
	}

	return home;
}
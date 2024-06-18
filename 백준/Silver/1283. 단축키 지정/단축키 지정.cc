#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)
#define elprint(a) cout << a << '\n'

// 단축키 지정
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n;
	cin >> n;
	cin.ignore();

	map<char, int> cMap;

	string inputString;
	loop(i, 0, n)
	{
		getline(cin, inputString);
		inputString = ' ' + inputString;
		int idx = -1;

		// 첫 문자 체크
		loop(j, 0, inputString.size())
		{
			if (inputString[j] == ' ' && !cMap[toupper(inputString[j + 1])] && idx == -1)
			{
				cMap[toupper(inputString[j + 1])]++;
				idx = j + 1;
				break;
			}
		}

		// 모든 문자 체크
		if (idx == -1)
		{
			loop(j, 0, inputString.size())
			{
				if (isalpha(inputString[j]) && !cMap[toupper(inputString[j])])
				{
					cMap[toupper(inputString[j])]++;
					idx = j;
					break;
				}
			}
		}

		// 단축키 지정
		string outputString = "";
		loop(j, 1, inputString.size())
		{
			if (j == idx)
			{
				outputString += '[';
				outputString += inputString[j];
				outputString += ']';
				continue;
			}

			outputString += inputString[j];
		}

		elprint(outputString);
	}

	return home;
}
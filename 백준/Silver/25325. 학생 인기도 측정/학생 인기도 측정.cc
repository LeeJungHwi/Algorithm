#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <fstream>
using namespace std;

// 학생 인기도 측정
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n;
	cin >> n;

	map<string, int> studentMap;
	map<int, vector<string> > cntMap;

	string inputString;
	getline(cin, inputString);
	string temp;
	for (int i = 0; i < n + 1; i++)
	{
		getline(cin, inputString);
		inputString += ' ';

		for (int j = 0; j < inputString.size(); j++)
		{
			if (inputString[j] == ' ')
			{
				studentMap[temp]++;
				temp.clear();
				continue;
			}

			temp += inputString[j];
		}
	}

	for (auto it = studentMap.begin(); it != studentMap.end(); it++) cntMap[it->second - 1].push_back(it->first);
	for (auto it = cntMap.rbegin(); it != cntMap.rend(); it++)
	{
		for (int i = 0; i < it->second.size(); i++)
		{
			cout << it->second[i] << ' ' << it->first << '\n';
		}
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 듣보잡
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 3, 4
	cin >> n >> m;

	// 카운팅하고 2인지 체크
	map<string, int> nameMap;
	string name;
	int nameCnt = 0;
	vector<string> names;

	for (int i = 0; i < n + m; i++)
	{
		cin >> name;

		nameMap[name]++;

		if (nameMap[name] == 2)
		{
			nameCnt++;
			names.push_back(name);
		}
	}

	cout << nameCnt << '\n';
	sort(names.begin(), names.end());
	for (int i = 0; i < names.size(); i++) cout << names[i] << '\n';

	return 0;
}
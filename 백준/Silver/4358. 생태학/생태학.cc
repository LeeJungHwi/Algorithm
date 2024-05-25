#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
#include <iomanip>
using namespace std;

// 생태학
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 나무 종류 백분율 소수점 4자리
	map<string, int> treeMap;

	string inputString;
	int treeCnt = 0;
	while (getline(cin, inputString))
	{
		if (inputString.empty()) break;
		treeMap[inputString]++;
		treeCnt++;
	}

	int precision = 4;
	for (auto it = treeMap.begin(); it != treeMap.end(); it++) cout << it->first << ' ' << fixed << setprecision(precision) << ((float)it->second / (float)treeCnt * 100) << '\n';

	return 0;
}
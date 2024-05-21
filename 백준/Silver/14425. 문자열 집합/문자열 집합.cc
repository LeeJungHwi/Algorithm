#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 문자열 집합
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 5, 11
	cin >> n >> m;

	// S 맵핑하고 체크

	string inputString;
	map<string, int> sMap;
	for (int i = 0; i < n; i++)
	{
		cin >> inputString;
		sMap[inputString]++;
	}

	int mCnt = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> inputString;
		if (sMap[inputString] > 0) mCnt++;
	}

	cout << mCnt << '\n';

	return 0;
}
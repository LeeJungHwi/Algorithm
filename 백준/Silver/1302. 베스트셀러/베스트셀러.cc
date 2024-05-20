#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 베스트셀러
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 5
	cin >> n;

	map<string, int> bookMap;
	string bookName;
	int maxCnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> bookName;

		bookMap[bookName]++;
		maxCnt = max(maxCnt, bookMap[bookName]);
	}

	vector<string> bestSeller;
	for (auto it = bookMap.begin(); it != bookMap.end(); it++)
	{
		if (it->second == maxCnt) bestSeller.push_back(it->first);
	}
	sort(bestSeller.begin(), bestSeller.end());
	cout << bestSeller[0] << '\n';

	return 0;
}
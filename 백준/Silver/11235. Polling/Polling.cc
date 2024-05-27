#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <fstream>
using namespace std;

// Polling
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n;
	cin >> n;

	int maxVote = 0;
	map<string, int> voteMap;
	set<string> nameSet;
	string inputString;

	// 카운팅
	for (int i = 0; i < n; i++)
	{
		cin >> inputString;

		voteMap[inputString]++;
		maxVote = max(maxVote, voteMap[inputString]);
	}

	// 알파벳 순서
	for (auto it = voteMap.begin(); it != voteMap.end(); it++) if (it->second == maxVote) nameSet.insert(it->first);
	for (auto it = nameSet.begin(); it != nameSet.end(); it++) cout << *it << '\n';

	return 0;
}
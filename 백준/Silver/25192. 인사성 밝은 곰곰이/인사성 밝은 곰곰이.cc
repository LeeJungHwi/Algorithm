#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 인사성 밝은 곰곰이
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 9
	cin >> n;

	string inputString;
	map<string, int> userMap;
	int emoticonCnt = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> inputString;

		// Enter : 기록 초기화
		if (inputString == "ENTER")
		{
			userMap.clear();
			continue;
		}

		// 일반 채팅
		if (userMap[inputString] > 0) continue;

		// 곰곰티콘
		userMap[inputString]++;
		emoticonCnt++;
	}

	cout << emoticonCnt << '\n';

	return 0;
}
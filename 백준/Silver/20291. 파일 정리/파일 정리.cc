#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 파일 정리
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 8
	cin >> n;

	string inputString;
	map<string, int> extendCnt; // 확장자 수 ㅁㅂ핑
	for (int i = 0; i < n; i++)
	{
		cin >> inputString;

		bool isExtend = false;
		string extend = "";

		for (int j = 0; j < inputString.size(); j++)
		{
			// . 만나기 전 처리
			if (!isExtend && inputString[j] == '.')
			{
				isExtend = true;
				continue;
			}
			if (!isExtend) continue;

			// . 이후
			extend += inputString[j];
		}

		// 맵핑
		extendCnt[extend]++;
	}

	for (auto it = extendCnt.begin(); it != extendCnt.end(); it++) cout << it->first << ' ' << it->second << '\n';

	return 0;
}
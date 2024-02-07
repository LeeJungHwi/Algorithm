#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <string>
#include <fstream>
using namespace std;

// 유니크한 문자열
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 5
	cin >> n;

	char uniqueChar; // 특정문자 b
	cin >> uniqueChar;

	uniqueChar = toupper(uniqueChar); // 특정문자 대문자로 B

	string inputString; // 입력문자열 Queen Apple Best Remember Beer
	vector<bool> vis(100); // 방문체크
	
	for (int i = 0; i < n; i++)
	{
		cin >> inputString;

		// QUEeN APpLE BEST REMemBer BEeR
		for (int j = 0; j < inputString.size(); j++)
		{
			if (vis[toupper(inputString[j])]) // 이미 방문한 문자는 소문자로 남겨둠
			{
				continue;
			}

			inputString[j] = toupper(inputString[j]); // 방문한 문자가 아니면 대문자로
			vis[inputString[j]] = true; // 방문체크
		}

		// BEST REMemBer BEeR

		bool isUniqueString = false; // 유니크 문자열인지 체크

		for (int j = 0; j < inputString.size(); j++)
		{
			if (inputString[j] == uniqueChar) // 하나라도 특정문자랑 같으면 유니크 문자열
			{
				isUniqueString = true;
				break;
			}
		}

		// BEST REMB BER
		if (isUniqueString)
		{
			string uniqueString = ""; // 유니크 문자열

			for (int j = 0; j < inputString.size(); j++) // 대문자만 저장
			{
				if (isupper(inputString[j]))
				{
					uniqueString += inputString[j];
				}
			}

			cout << uniqueString << '\n';
		}

		fill(vis.begin(), vis.end(), false); // 방문체크 초기화
	}

	return 0;
}
// 핵심
// isupper, islower, toupper, tolower
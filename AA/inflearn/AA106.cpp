#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

// 공통문자열
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N, 3
	cin >> n;

	vector<string> words(n); // 단어 저장

	//	long
	//	longtime
	//	longest
	for (int i = 0; i < n; i++)
	{
		cin >> words[i];
	}

	// 입력된 문자열 중 가장 작은 문자열 찾기

	int minSize = 2147000000;

	for (int i = 0; i < n; i++)
	{
		if (words[i].size() < minSize)
		{
			minSize = words[i].size(); // 4
		}
	}

	// 입력된 단어의 앞 인덱스 부터 같은 문자 체크 후 공통 접두사 찾기

	string commonPrefix = ""; // 공통접두사
	bool isFinish = false; // 공통접두사를 찾았는지 체크

	for (int i = 0; i < minSize; i++)
	{
		int ch = words[0][i]; // l -> o -> n -> g

		for (int j = 0; j < n; j++)
		{
			if (ch != words[j][i]) // 문자가 다르다면 이전 문자까지
			{
				commonPrefix = words[0].substr(0, i); // 공통접두사 저장
				isFinish = true; // 공통접두사 찾음
				break;
			}
		}

		if (isFinish) // 공통접두사를 찾았으면 종료
		{
			break;
		}
	}
	
	// 만약 commonPrefix가 비어있다면 가장 작은 문자열 크기만큼 모두 같은것임
	if (commonPrefix.empty())
	{
		commonPrefix = words[0].substr(0, minSize);
	}

	// 공통접두사 출력
	cout << commonPrefix << '\n';

	return 0;
}
// 핵심
// string.substr()
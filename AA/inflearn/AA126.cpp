#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

// 패턴 찾기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	string inputString; // 철수가 쓴 문자열 앞 일부분 3210232102321023
	cin >> inputString;

	string pattern = ""; // 패턴 문자열 32102

	int n; // N 52
	cin >> n;

	// 패턴 찾기
	// 패턴이 입력문자열크기 / 2개인 경우 체크
	// ....
	// 패턴이 2개인 경우 체크
	// 패턴이 1개인 경우 체크
	for (int i = inputString.size() / 2; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (inputString[j] == inputString[j + i]) // 패턴이 같으면 하나씩 추가
			{
				pattern += inputString[j];
				continue;
			}

			// 패턴이 다르면 패턴 초기화 후 종료
			pattern.clear();
			break;
		}

		// 패턴이 비어있지 않으면 패턴을 찾은것이므로 종료
		if (!pattern.empty())
		{
			break;
		}
	}

	// 한 패턴의 숫자 합 * (n / 패턴길이) + 0부터(n % 패턴길이)까지 패턴숫자

	int onePatternSum = 0; // 한 패턴의 숫자 합 8

	for (int i = 0; i < pattern.size(); i++)
	{
		onePatternSum += pattern[i] - '0';
	}

	int result = onePatternSum * (n / pattern.size()); // 패턴을 길이 n만큼 썼을때 숫자 총합 85

	for (int i = 0; i < n % pattern.size(); i++)
	{
		result += pattern[i] - '0';
	}

	cout << result << '\n';

	return 0;
}
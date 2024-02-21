#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

// 문자열 폭발
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	string inputString; // 입력 문자열
	cin >> inputString;

	string bombString; // 폭탄 문자열
	cin >> bombString;

	string result; // 결과 문자열

	// mirkovC4nizCC44
	// mirkovC4 -> 펑
	// mirkov
	// mirkovnizCC4 -> 펑
	// mirkovnizC
	// mirkovnizC4 -> 펑
	// mirkovniz

	// 12ab112ab2ab
	// 12ab -> 펑
	// 
	// 112ab -> 펑
	// 1
	// 12ab -> 펑
	// 
	// FRULA

	for (int i = 0; i < inputString.size(); i++)
	{
		// 현재문자 저장
		result.push_back(inputString[i]);

		// 결과문자열이 폭탄문자열 크기만큼 되고
		// 뒤에서 문자열 크기만큼 추출할때 폭탄문자열이면
		// 폭탄 문자열이므로 폭탄 문자열 크기만큼 제거
		if (result.size() >= bombString.size() && result.substr(result.length() - bombString.size()) == bombString)
		{
			for (int j = 0; j < bombString.size(); j++)
			{
				result.pop_back();
			}
		}
	}

	// 폭발하고 남은 문자열 출력
	if (result.empty())
	{
		cout << "FRULA\n";

		return 0;
	}

	cout << result << '\n';

	return 0;
}

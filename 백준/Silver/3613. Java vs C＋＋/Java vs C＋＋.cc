#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// Java vs C++
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	string naming; // 변수 네이밍 long_and_mnemonic_identifier
	cin >> naming;

	// 1.name이 Java인지 C++인지 판단하기
	// 2.변수명 상호전환하기

	// C++ : 소문자, 맨앞 맨뒤 _ 가 아니어야함, _가 연속으로 두개가 아니어야함
	// Java : 맨앞이 대문자가 아니어야함
	// C++ + Java : 변수명안에 _와 대문자가 같이 쓰일수없음
	// 소문자로만 이루어지면 정상

	bool cppError = false; // C++ 변수명으로 에러가 있는지 체크
	bool javaError = false; // Java 변수명으로 에러가 있는지 체크
	bool bothError = false; // C++ + Java 변수명으로 에러가 있는지 체크
	bool isLower = false; // 소문자로만 이루어져있는지 체크

	// C++ 체크
	if (naming[0] == '_' || naming[naming.size() - 1] == '_') // 맨앞 맨뒤 _가 아니어야함
	{
		cppError = true;
	}
	else
	{
		for (int i = 1; i < naming.size() - 1; i++) // _가 연속으로 두개가 아니어야함
		{
			if (naming[i] == '_')
			{
				if (i < naming.size() - 2 && naming[i + 1] == '_')
				{
					cppError = true;

					break;
				}
			}
		}
	}

	// Java 체크
	if (isupper(naming[0])) // 맨앞이 대문자가 아니어야함
	{
		javaError = true;
	}

	// C++ + Java 체크
	bool isUpper = false; // 대문자가 쓰였는지 체크
	bool isUnderBar = false; // _가 쓰였는지 체크

	for (int i = 0; i < naming.size(); i++)
	{
		if (!isUpper && isupper(naming[i]))
		{
			isUpper = true;
		}

		if (!isUnderBar && naming[i] == '_')
		{
			isUnderBar = true;
		}
	}

	if (isUpper && isUnderBar) // 대문자와 _를 같이쓰면 에러
	{
		bothError = true;
	}

	// 소문자로만 이루어졌는지 체크
	if (!isUpper && !isUnderBar)
	{
		isLower = true;
	}

	// C++에러, Java에러, C++ + Java에러
	if (cppError || javaError || bothError)
	{
		cout << "Error!" << '\n';

		return 0;
	}

	// 모두 소문자면 전환이 필요없음
	if (isLower)
	{
		cout << naming << '\n';

		return 0;
	}

	// 모두 소문자는 아니면
	// C++인지 Java인지 판단한 후
	// 변수명 상호전환이 필요함

	if (isUnderBar) // 언더바있으면 C++임
	{
		for (int i = 0; i < naming.size(); i++)
		{
			if (naming[i] == '_') // 언더바 만나면 언더바 다음문자 대문자로 바꾸고 언더바 제거
			{
				naming[i + 1] = toupper(naming[i + 1]);
				naming.erase(i, 1);
			}
		}

		cout << naming << '\n';

		return 0;
	}

	for (int i = 0; i < naming.size(); i++)
	{
		if (isupper(naming[i])) // 대문자를 만나면 소문자로 바꾸고 이전문자에 언더바 추가
		{
			naming[i] = tolower(naming[i]);
			naming.insert(i, "_");
			i++;
		}
	}

	cout << naming << '\n';

	return 0;
}
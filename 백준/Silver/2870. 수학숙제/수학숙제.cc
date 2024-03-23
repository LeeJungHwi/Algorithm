#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 문자열 숫자 비내림차순 정렬기준
bool comp(const string &s1, const string &s2)
{
	// 길이가 다르면 긴 문자열
	if (s1.length() != s2.length())
	{
		return s1.length() < s2.length();
	}

	// 길이가 같으면 사전순
	return s1 < s2;
}

// 수학숙제
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 2
	cin >> n;

	vector<string> mathTask; // 수학숙제
	string lineContent; // 각 줄의 내용 lo3za4

	// 종이의 줄 수 만큼 반복
	while (n--)
	{
		cin >> lineContent;
		lineContent += 'a'; // 마지막 숫자도 저장하기위해

		// 각 줄의 내용 읽으면서 
		// 숫자만 수학숙제에 넣음

		for (int i = 0; i < lineContent.size(); i++) // 줄 내용 돌면서
		{
			if (isdigit(lineContent[i])) // 숫자를 만나면 숫자 추가하다가
			{
				string numString = ""; // 숫자 문자열

				for (int j = i; j < lineContent.size(); j++)
				{
					if (islower(lineContent[j])) // 소문자를 만나면 
					{
						while (true) // 0이 아닌숫자 앞에 0 삭제 
						{
							if (numString.size() != 1 && numString[0] == '0')
							{
								numString.erase(0, 1);
							}
							else
							{
								break;
							}
						}

						mathTask.push_back(numString); // 숫자를 수학숙제에 추가
						i = j;
						break;
					}

					numString += lineContent[j];
				}
			}
		}
	}

	// 수학숙제 정렬 후 출력
	sort(mathTask.begin(), mathTask.end(), comp);

	for (int i = 0; i < mathTask.size(); i++)
	{
		cout << mathTask[i] << '\n';
	}

	return 0;
}
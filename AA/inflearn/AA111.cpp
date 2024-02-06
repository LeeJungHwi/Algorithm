#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

// 숨겨진 합
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	string s;
	cin >> s;

	vector<string> nums; // 문자열에서 발견된 숫자를 저장
	int sum = 0; // 숨겨진 숫자의 합

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] - '0' > 0 && s[i] - '0' < 10) // 0이 아닌 숫자를 만나면
		{
			string num = "";

			for (int j = i; j < s.size(); j++) // 발견한 숫자부터 문자를 만날때까지 숫자 만들기
			{
				i = j + 1; // j + 1번 문자부터 다시 읽어감

				if (s[j] - '0' < 0 || s[j] - '0' > 9) // 문자를 만나면 종료
				{
					break;
				}

				num.append(1, s[j]); // 숫자 만들기
			}

			// 문자열에서 발견된 숫자 저장
			nums.push_back(num); // 50 33 17
		}
	}

	for (int i = 0; i < nums.size(); i++)
	{
		sum += stoi(nums[i]);
	}

	cout << sum << '\n';

	return 0;
}
// 핵심
// 어디서부터 다시 읽을건지 갱신
// stoi : 문자열을 숫자로 변환
// append(개수, 문자) : 문자를 개수만큼 붙임
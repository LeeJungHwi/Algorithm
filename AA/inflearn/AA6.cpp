#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// 숫자만 추출
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	string input; // 입력 문자열
	cin >> input;

	string num; // 숫자 문자열
	int num_ = 0; // 숫자 문자열을 숫자로

	int pos = 1; // 자릿수

	int cnt = 0; // 약수 개수

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] - '0' >= 0 && input[i] - '0' <= 9) // 숫자문자만 추출
		{
			num.append(1, input[i]);
		}
	}

	int i = 0;
	//0 2 0 8
	while (true)
	{
		if (num[i] - '0' == 0) // 처음 0이 아닌 숫자가 나올때까지 버림
		{
			i++;
			continue;
		}

		for (int j = num.size() - 1; j > i - 1; j--) // 1의 자릿수부터
		{
			if (num[j] - '0' == 0) // 0이나오면 자릿수만 증가
			{
				pos *= 10;
				continue;
			}

			num_ += (num[j] - '0') * pos; // 숫자 * 자릿수
			pos *= 10; // 자릿수 증가
		}

		break;
	}

	for (int j = 1; j < num_ + 1; j++) // 약수 개수
	{
		if (num_ % j == 0)
		{
			cnt++;
		}
	}

	cout << num_ << '\n' << cnt << '\n';
	return 0;
}
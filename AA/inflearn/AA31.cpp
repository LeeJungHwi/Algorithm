#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

// 탄화수소 질량
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	string ch; // 탄화수소식
	cin >> ch;

	string a, b; // a, b 질량 저장
	int sum = 0; // a, b 질량 합

	int hIndex = 0;

	// a 구하기
	for (int i = 1; i < ch.size(); i++) // 1~ch크기 돌면서
	{
		if (ch[i] == 'H') // H를 만나면 H 인덱스 저장 후 종료
		{
			hIndex = i;
			break;
		}

		a.push_back(ch[i]); // 2 4
	}

	// b 구하기
	for (int i = hIndex + 1; i < ch.size(); i++) // hIndex~ch크기 돌면서
	{
		b.push_back(ch[i]); // 4 2
	}

	// a 질량구하기
	// 12 * 24
	if (a.empty())
	{
		sum += 12;
	}
	else
	{
		for (int i = 0; i < a.size(); i++)
		{
			sum += 12 * (a[i] - '0') * pow(10, a.size() - i - 1);
		}
	}

	// b 질량구하기
	// 1 * 42
	if (b.empty())
	{
		sum += 1;
	}
	else
	{
		for (int i = 0; i < b.size(); i++)
		{
			sum += 1 * (b[i] - '0') * pow(10, b.size() - i - 1);
		}
	}

	cout << sum << '\n';

	// //디버깅 용
	//for (int i = 0; i < a.size(); i++)
	//{
	//	cout << a[i] << ' ';
	//}

	//cout << '\n';

	//for (int i = 0; i < b.size(); i++)
	//{
	//	cout << b[i] << ' ';
	//}

	return 0;
}
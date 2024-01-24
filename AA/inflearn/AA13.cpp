#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

vector<int> cnts(10); // 사용된 자릿수 카운트
int maxCnt; // 가장 많이 사용된 자릿수 개수
int maxNum; // 가장 많이 사용된 자릿수

// 사용된 자릿수 카운팅
// 1230565625
// 1230565625 % 10 = 5
// 123056562 % 10 = 2
// 12305656 % 10 = 6
// ....
void CountPosNum(string num)
{
	while (!num.empty())
	{
		cnts[num.back() - '0']++; // 1의 자릿수 카운팅
		num.pop_back(); // 1의 자릿수 숫자 갱신
	}
}

// 가장 많이 사용된 자릿수
// 1~9 까지 순서대로 체크하므로 같을 경우도 그냥 갱신해도 됨
void MaxPosNum()
{
	for (int i = 1; i < 10; i++)
	{
		if (cnts[i] >= maxCnt) // 사용된 횟수가 같거나 많으면 갱신
		{
			maxCnt = cnts[i];
			maxNum = i;
		}
	}

	cout << maxNum << '\n';
}

// 가장 많이 사용된 자릿수
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	string n; // N
	cin >> n;

	CountPosNum(n);
	MaxPosNum();

	return 0;
}

// 핵심
// 숫자가 매우 크다면 string으로 입력을 받음
// string.back() -> 마지막 문자 리턴
// string.pop_back() -> 마지막 문자 삭제
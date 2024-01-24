#include <iostream>
#include <fstream>
using namespace std;

// 1부터 N까지 합 구하기
int Sum(int num)
{
	int result = 0;

	for (int i = 1; i < num + 1 ; i++) // 1부터 N까지 합
	{
		result += i;
	}

	return result;
}

// 선생님 퀴즈
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	int cardNum, resultNum; // 카드숫자, 적은숫자

	for (int i = 0; i < n; i++)
	{
		cin >> cardNum >> resultNum;

		if (Sum(cardNum) == resultNum) // 적은숫자가 정답이면
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}

	return 0;
}
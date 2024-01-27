#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
using namespace std;

// 어글리 숫자
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 10
	cin >> n;

	int uglyNumCnt = 1; // 어글리 숫자 개수
	int curNum = 2; // 어글리 숫자인지 체크할 숫자

	if (n == 1) // 첫번째 어글리 숫자는 1
	{
		cout << 1 << '\n';

		return 0;
	}
	else // 두번째 어글리 숫자부터는
	{
		while (uglyNumCnt < n) // n번째 어글리 숫자가 되면 종료
		{
			int i = curNum;
			
			// 2로 나누었을때 나머지가 0이 아닐때까지 나누기
			while (i % 2 == 0)
			{
				i /= 2;
			}

			// 3으로 나누었을때 나머지가 0이 아닐때까지 나누기
			while (i % 3 == 0)
			{
				i /= 3;
			}

			// 5로 나누었을때 나머지가 0이 아닐때까지 나누기
			while (i % 5 == 0)
			{
				i /= 5;
			}

			// i가 1이면 어글리 숫자
			if (i == 1)
			{
				uglyNumCnt++;
			}

			// 체크할 숫자 증가
			curNum++;
		}
	}

	cout << curNum - 1 << '\n';

	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

// 어글리숫자
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 1500
	cin >> n;

	vector<int> uglyNums(n + 1); // 인덱스 번째 어글리숫자 저장

	// uglyNums 인덱스를 가리키는 포인터
	// p2, p3, p5 모두 1로 초기화
	// p2, p3, p5 각각 2, 3, 5를 곱하고 최소값을 어글리숫자로 저장
	// 최소값을 만든 포인터는 1 증가시켜 다음 인덱스를 가리키게함
	/*
	1 1 1
	2 3 5 -> 최소값 2, p2 1증가
	2 1 1
	4 3 5 -> 최소값 3, p3 1증가
	2 3 1
	4 9 5 -> 최소값 4, p2 1증가
	4 3 1
	8 9 5 -> 최소값 5, p3 1증가
	....
	*/
	int p2 = 1;
	int p3 = 1;
	int p5 = 1;

	// 최소값
	int minNum = 0;

	// 1은 첫번째 어글리숫자
	uglyNums[1] = 1;

	for (int i = 2; i < n + 1; i++) // 두번째 어글리숫자 부터 찾음
	{
		// p2, p3, p5 각각 2, 3, 5를 곱하고 최소값 찾기
		if (uglyNums[p2] * 2 < uglyNums[p3] * 3)
		{
			minNum = uglyNums[p2] * 2;
		}
		else
		{
			minNum = uglyNums[p3] * 3;
		}

		if (uglyNums[p5] * 5 < minNum)
		{
			minNum = uglyNums[p5] * 5;
		}

		// 최소값을 만든 포인터는 1 증가시켜 다음 인덱스를 가리키게함
		if (minNum == uglyNums[p2] * 2)
		{
			p2++;
		}

		if (minNum == uglyNums[p3] * 3)
		{
			p3++;
		}

		if (minNum == uglyNums[p5] * 5)
		{
			p5++;
		}

		// 어글리숫자 저장
		uglyNums[i] = minNum;
	}

	cout << uglyNums[n] << '\n';

	return 0;
}

//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//#include <fstream>
//using namespace std;
//
//// 어글리 숫자
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	//ifstream cin;
//	//cin.open("input.txt");
//
//	int n; // N 10
//	cin >> n;
//
//	int uglyNumCnt = 1; // 어글리 숫자 개수
//	int curNum = 2; // 어글리 숫자인지 체크할 숫자
//
//	if (n == 1) // 첫번째 어글리 숫자는 1
//	{
//		cout << 1 << '\n';
//
//		return 0;
//	}
//	else // 두번째 어글리 숫자부터는
//	{
//		while (uglyNumCnt < n) // n번째 어글리 숫자가 되면 종료
//		{
//			int i = curNum;
//
//			// 2로 나누었을때 나머지가 0이 아닐때까지 나누기
//			while (i % 2 == 0)
//			{
//				i /= 2;
//			}
//
//			// 3으로 나누었을때 나머지가 0이 아닐때까지 나누기
//			while (i % 3 == 0)
//			{
//				i /= 3;
//			}
//
//			// 5로 나누었을때 나머지가 0이 아닐때까지 나누기
//			while (i % 5 == 0)
//			{
//				i /= 5;
//			}
//
//			// i가 1이면 어글리 숫자
//			if (i == 1)
//			{
//				uglyNumCnt++;
//			}
//
//			// 체크할 숫자 증가
//			curNum++;
//		}
//	}
//
//	cout << curNum - 1 << '\n';
//
//	return 0;
//}
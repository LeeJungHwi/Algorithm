#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 수 찾기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 5
	cin >> n;

	vector<int> A(n);

	for (int i = 0; i < n; i++)
	{
		cin >> A[i]; // 4 1 5 2 3
	}

	sort(A.begin(), A.end()); // 1 2 3 4 5

	int m; // M 5
	cin >> m;

	int num; // 숫자

	for (int i = 0; i < m; i++)
	{
		cin >> num;

		// 기준값 : (처음인덱스 + 마지막인덱스) / 2의 하한 값
		// 기준값과 찾고자하는값 비교
		// 같은경우 : 기준값 인덱스가 위치
		// 큰경우 : 처음인덱스를 기준값인덱스 + 1로하고 재탐색
		// 작은경우 : 마지막인덱스를 기준값인덱스 - 1로하고 재탐색
		// 검색이 실패하는경우 : 처음인덱스 > 마지막인덱스 동안 찾지 못한 경우

		int first = 0; // 처음
		int last = n - 1; // 마지막
		bool isFind = false; // 숫자를 찾았는지 체크

		while (first <= last) // 처음과 마지막이 역전되면 종료
		{
			int standard = (first + last) / 2; // 기준값

			if (A[standard] == num) // 같은경우
			{
				isFind = true; // 숫자를 찾음
				
				break;
			}
			else if (A[standard] < num) // 큰경우
			{
				first = standard + 1; // 처음인덱스 갱신
			}
			else if (A[standard > num]) // 작은경우
			{
				last = standard - 1; // 마지막인덱스 갱신
			}
		}

		cout << (isFind ? 1 : 0) << '\n';
	}

	return 0;
}
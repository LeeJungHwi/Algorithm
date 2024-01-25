#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

// 이분검색
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M
	cin >> n >> m;

	int num; // 숫자
	vector<int> nums(n); // 숫자 저장

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		nums[i] = num; // 23 87 65 12 57 32 99 81
	}

	sort(nums.begin(), nums.end()); // 12 23 32 57 65 81 87 99

	// 이분검색
	// 기준값 : (처음인덱스 + 마지막인덱스) / 2의 하한 값
	// 기준값과 찾고자하는값 비교
	// 같은경우 : 기준값 인덱스가 위치
	// 큰경우 : 처음인덱스를 기준값인덱스 + 1로하고 이분검색
	// 작은경우 : 마지막인덱스를 기준값인덱스 - 1로하고 이분검색
	// 검색이 실패하는경우 : 처음인덱스 > 마지막인덱스

	int firstIndex = 0; // 처음인덱스
	int lastIndex = n - 1; // 마지막인덱스
	int keyIndex = 0; // 찾고자 하는 값의 위치

	while (firstIndex <= lastIndex) // 교차되지 않았을때만 반복
	{
		int standardIndex = (firstIndex + lastIndex) / 2; // 기준값 초기화

		if (nums[standardIndex] == m) // 같은경우
		{
			keyIndex = standardIndex;
			break;
		}
		else if (nums[standardIndex] < m) // 큰경우
		{
			firstIndex = standardIndex + 1; // 처음인덱스 갱신
		}
		else if (nums[standardIndex > m]) // 작은경우
		{
			lastIndex = standardIndex - 1; // 마지막인덱스 갱신
		}
	}

	cout << keyIndex + 1 << '\n';

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

int n; // N 3
vector<int> nums(500000); // 자연수 저장 3, 2, 1
long long swapCnt; // 스왑횟수 카운팅

// 병합
void Merge(int first, int standard, int last)
{
	int i = first; // 첫번째 배열 첫 인덱스
	int j = standard + 1; // 두번째 배열 첫 인덱스
	int k = 0; // 임시벡터 인덱스

	vector<int> tempNums(last - first + 1); // 임시벡터

	// 두 배열 크기 비교 후 정렬
	while (i <= standard && j <= last)
	{
		if (nums[i] <= nums[j])
		{
			tempNums[k++] = nums[i++];
		}
		else
		{
			// 왼쪽 배열의 현재요소가 오른쪽 배열의 현재요소보다 더 크다면
			// 기준 - 현재까지선택된 왼쪽 배열 요소 수 + 1개가 오른쪽 배열의 현재요소보다 모두 크므로
			// 기준 - i + 1만큼의 스왑이 일어남
			tempNums[k++] = nums[j++];
			swapCnt += standard - i + 1;
		}
	}

	// 남은 요소 저장
	while (i <= standard)
	{
		tempNums[k++] = nums[i++];
	}
	while (j <= last)
	{
		tempNums[k++] = nums[j++];
	}

	// 임시벡터값 원본으로 복사
	for (int l = first; l < last + 1; l++)
	{
		nums[l] = tempNums[l - first];
	}
}

// 병합정렬
void MergeSort(int first, int last)
{
	if (first < last) // first와 last가 역전하면 종료
	{
		// 기준
		int standard = (first + last) / 2;

		// 분할
		MergeSort(first, standard);
		MergeSort(standard + 1, last);

		// 정복
		Merge(first, standard, last);
	}
}

// 버블소트
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> nums[i]; // 3, 2, 1
	}

	// 병합정렬
	MergeSort(0, n - 1);

	// 스왑횟수 출력
	cout << swapCnt << '\n';

	return 0;
}
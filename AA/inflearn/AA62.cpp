#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 병합
void Merge(vector<int> &nums, int first, int standard, int last)
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
			tempNums[k++] = nums[j++];
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
void MergeSort(vector<int> &nums, int first, int last)
{
	if (first < last) // first와 last가 역전하지 않아야함
	{
		// 분할
		int standard = (first + last) / 2;

		// 정복
		MergeSort(nums, first, standard);
		MergeSort(nums, standard + 1, last);

		// 합병
		Merge(nums, first, standard, last);
	}
}

// 병합정렬
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	vector<int> nums(n); // 자연수 저장

	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	// 병합정렬
	MergeSort(nums, 0, n - 1);

	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << ' ';
	}

	return 0;
}
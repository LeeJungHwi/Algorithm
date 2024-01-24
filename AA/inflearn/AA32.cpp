#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 선택정렬
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	int num; // 숫자

	vector<int> unsortedVec(n); // 졍렬되지 않은 영역
	vector<int> sortedVec(n); // 정렬된 영역

	// 정렬되지 않은 영역 저장
	for (int i = 0; i < unsortedVec.size(); i++)
	{
		cin >> num;
		unsortedVec[i] = num;
	}

	// 선택정렬
	// 요소 6개 기준
	// 6 -> 5 -> 4 -> ... -> 1
	// n - 0 -> n-1 -> ... -> 1
	// 정렬되지 않은 영역에서 최대값 찾기
	// 찾은 최대 값의 인덱스에 정렬되지 않은 영역의 오른쪽 끝 요소를 대입
	// 찾은 최대 값을 정렬된 영역의 오른쪽 끝에 저장

	for (int i = 0; i < n; i++)
	{
		int max = 0; // 최대값
		int maxIndex = 0; // 최대값의 인덱스

		for (int j = 0; j < n - i; j++) // n - 0 -> n-1 -> ... -> 1
		{
			if (unsortedVec[j] > max) // max 갱신
			{
				max = unsortedVec[j];
				maxIndex = j;
			}
		}

		// 최대값 구한 상태
		unsortedVec[maxIndex] = unsortedVec[n - i - 1]; // 찾은 최대 값의 인덱스에 정렬되지 않은 영역의 오른쪽 끝 요소를 대입
		sortedVec[n - i - 1] = max; // 찾은 최대 값을 정렬된 영역의 오른쪽 끝에 저장
	}

	for (int i = 0; i < n; i++)
	{
		cout << sortedVec[i] << ' ';
	}

	return 0;
}
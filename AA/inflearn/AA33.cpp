#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 3등의 성적은?
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

	// 3등 인덱스 구하기
	// 75 80 82 92 96 96 100
	// 정렬된 영역 끝에서 감소하면서 이전값과 다르면 3등인덱스 ++
	// 3등인덱스가 3인곳의 값이 3등의 점수
	int thirdIndex = 0;
	int preScore = -1;
	for (int i = sortedVec.size() - 1; i > -1; i--)
	{
		if (sortedVec[i] != preScore)
		{
			preScore = sortedVec[i];
			thirdIndex++;

			if (thirdIndex == 3)
			{
				break;
			}
		}
	}

	cout << preScore << '\n';

	return 0;
}
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 삽입정렬
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	int num; // 숫자
	vector<int> insertVec(n);

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		insertVec[i] = num;
	}

	// 삽입정렬
	// 1~n-1 까지 돌면서 본인 이전 인덱스 값들과 비교해 삽입 위치 찾기
	// 본인 값 백업
	// 본인 인덱스 - 1 부터 삽입 인덱스 까지 요소를 차례로 오른쪽으로 시프트
	// 본인 삽입위치에 저장
	// 11 7 5 6 10 9
	for (int i = 1; i < n; i++) // 1~n-1
	{
		int insertIndex = i; // 삽입 할 인덱스
		int backUpValue = insertVec[i];// 본인 값 백업

		// 삽입 위치 찾기
		for (int j = i - 1; j > -1; j--)
		{
			if (insertVec[i] < insertVec[j])
			{
				insertIndex = j;
			}
		}

		// 삽입 위치 이후 요소 오른쪽 시프트
		for (int j = i - 1; j > insertIndex - 1; j--)
		{
			insertVec[j + 1] = insertVec[j];
		}

		// 본인 삽입 위치에 저장
		insertVec[insertIndex] = backUpValue;
	}

	for (int i = 0; i < n; i++)
	{
		cout << insertVec[i] << ' ';
	}

	return 0;
}
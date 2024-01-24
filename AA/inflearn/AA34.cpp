#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 버블정렬
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	int num; // 숫자
	vector<int> bubbleVec(n); // 버블 정렬 할 요소 저장

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		bubbleVec[i] = num;
	}

	// 버블정렬
	// 6 기준 비교
	// 5 -> 4 -> 3 -> 2 -> 1
	// 각 스텝에서 다음 요소와 크기 비교후 스왑
	// 한 스텝 후 각 스텝의 오른쪽 끝 영역이 정렬됨

	int tempNum = 0; // 스왑용
	
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (bubbleVec[j] > bubbleVec[j + 1]) // 크기 비교 후 스왑
			{
				tempNum = bubbleVec[j];
				bubbleVec[j] = bubbleVec[j + 1];
				bubbleVec[j + 1] = tempNum;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << bubbleVec[i] << ' ';
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 두 배열 합치기
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M
	int num; // 숫자
	vector<int> firstVec(200); // 첫 배열
	vector<int> secondVec(200); // 두번째 배열

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		firstVec[i] = num; // 1 3 5
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		secondVec[i] = num; // 2 3 6 7 9
	}		

	// 두 배열 합치기
	// 두번째 배열에 첫 배열 요소를 하나씩 삽입위치 찾아서 삽입
	// 삽입위치는 첫배열 요소의 값보다 크거나 같은 값을 두번째 배열에서 찾아 해당 인덱스에 삽입

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m + i; j++)
		{
			if (firstVec[i] <= secondVec[j]) // 첫 배열 요소 값보다 크거나 같은 값을 두번째 배열에서 찾아
			{
				for (int k = m + i - 1; k > j - 1; k--) // 오른쪽 시프트 후
				{
					secondVec[k + 1] = secondVec[k];
				}

				// 첫 배열 요소값 두번째 배열에 삽입
				secondVec[j] = firstVec[i];
				break;
			}
		}
	}

	for (int i = 0; i < n + m; i++)
	{
		cout << secondVec[i] << ' ';
	}

	return 0;
}
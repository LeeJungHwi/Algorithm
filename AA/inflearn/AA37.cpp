#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// LRU
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int s, n; // S, N
	cin >> s >> n;

	int taskNum; // 작업번호

	vector<int> casheMem(s, 0); // 캐시메모리 0 0 0 0 0

	// 가장 최근 작업이 캐시의 맨앞 -> 큐로 구현하려 했으나 -> 요소 접근이 불편함 -> 벡터로 구현
	// 캐시미스 -> 입력으로 들어온 작업이 캐시메모리에 없을때 캐시의 맨앞 -> 캐시메모리가 가득찼을때 가장 오래된 작업 삭제
	// 캐시히트 -> 입력으로 들어온 작업이 캐시메모리에 있을때 캐시와 값이 같은 요소를 삽입정렬로 캐시메모리 맨앞에 삽입

	for (int i = 0; i < n; i++)
	{
		cin >> taskNum;

		bool isHit = false;

		for (int j = 0; j < s; j++)
		{
			if (casheMem[j] == taskNum) // 캐시메모리에 같은 작업이 있는경우 -> 캐시히트
			{
				for (int k = j - 1; k > -1; k--) // 요소 전 부터 0번 까지 오른쪽 시프트
				{
					casheMem[k + 1] = casheMem[k];
				}

				casheMem[0] = taskNum;
				isHit = true;
				break;
			}
		}

		// 캐시메모리에 같은 작업이 없는경우 -> 캐시미스
		if (!isHit)
		{
			for (int j = s - 2; j > -1; j--) // 0~마지막 전 요소를 오른쪽 시프트 후 task 저장
			{
				casheMem[j + 1] = casheMem[j];
			}

			casheMem[0] = taskNum;
		}
	}

	for (int i = 0; i < s; i++)
	{
		cout << casheMem[i] << ' ';
	}

	return 0;
}

// 핵심
// 큐는 인덱스로 접근 불가
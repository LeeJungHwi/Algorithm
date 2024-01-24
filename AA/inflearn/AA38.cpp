#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 인버전 수열
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	vector<int> inversionVec(n); // 인버전 수열 저장
	vector<int> originVec(n); // 원본 수열

	int inversionNum; // 인버전 숫자

	// 인버전 수열 저장 및 원본 수열 초기화
	for (int i = 0; i < n; i++)
	{
		cin >> inversionNum;
		inversionVec[i] = inversionNum; // 53402110 -> 48625137
		originVec[i] = n - i; // 원본수열 값 내림차순 저장 : 87654321
	}

	// 원본 수열
	// 87654321 : 내림차순으로 초기화
	// 87654132 : 1 전 1보다 큰 수 개수가 5개가 되도록하는 위치에 삽입
	// 87625143 : 2 전 2보다 큰 수 개수가 3개가 되도록하는 위치에 삽입, 본인보다 작은수는 오른쪽으로 시프트하지않음
	// 87625134 : ....
	// 48726135 : ....
	// 48725136 : 5 전 5보다 큰 수 개수가 2개가 되도록하는 위치에 삽입, 본인보다 작은수는 오른쪽으로 시프트하지않음
	// 48625137 : 6 전 6보다 큰 수 개수가 1개가 되도록하는 위치에 삽입, 본인보다 작은수는 오른쪽으로 시프트하지않음

	for (int i = 0; i < n - 1; i++) // 가장 높은 수는 인버전 수가 무조건 0이므로 정렬할필요없음
	{
		int largeCnt = 0; // 본인보다 큰 수
		bool isSort = false; // 정렬되었는지 체크

		for (int j = n - 1; j > -1; j--) // 마지막 인덱스부터 돌면서
		{
			if (originVec[j] == i + 1) // i + 1 찾기 : 정렬해야할 수
			{
				// 찾은 인덱스 전부터 돌면서 i + 1보다 큰 수가 몇개인지 세기
				for (int k = j - 1; k > -1; k--)
				{
					if (originVec[k] > i + 1)
					{
						largeCnt++;
					}
				}

				// 만약 i + 1보다 큰 수가 인버전 수열의 i번째 값과 같다면 종료
				// 같지않다면 largeCnt-- 하면서 삽입할 위치 찾기
				if (largeCnt == inversionVec[i])
				{
					isSort = true;
					break;
				}
				else
				{
					for (int k = j - 1; k > -1; k--) // 찾은 인덱스 전부터 돌면서 largeCnt 감소
					{
						if (originVec[k] > i + 1)
						{
							largeCnt--;
						}

						if (largeCnt == inversionVec[i]) // 개수가 같아지면 삽입 위치는 k
						{
							for (int l = n - 2; l > k - 1; l--) // 마지막 전부터 k까지 i + 1보다 큰수를 오른쪽 시프트(시프트 할때 작은수를 덮어씌우면안됨)
							{
								if (originVec[l] > i + 1) // 큰 수만 오른쪽 시프트
								{
									// 오른쪽 시프트 하려는데 i + 1보다 작은 값은 건너뛰면서 시프트 해야함
									for (int m = l + 1; m < n; m++)
									{
										if (originVec[m] < i + 1) // 오른쪽 값이 i + 1보다 작은 값이면 continue
										{
											continue;
										}

										// 여기서 m값이 시프트되어 저장될 인덱스
										originVec[m] = originVec[l];

										break;
									}
								}
							}

							// i + 1를 k에 삽입 후 종료
							originVec[k] = i + 1;
							isSort = true;
							break;
						}
					}
				}
			}

			if (isSort)
			{
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << originVec[i] << ' ';
	}

	return 0;
}

// 핵심
// break 위치
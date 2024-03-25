#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 정렬기준
// 1.크기 내림차순
bool comp(const int &size1, const int &size2)
{
	return size1 > size2;
}

// 먹을 것인가 먹힐 것인가
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// A는 자기보다 작은 B를 먹을 수 있음 
	// 일단 A, B 모두 내림차순 정렬함
	// startIndex를 두고 다음 A는 B의 startIndex부터 체크하면서 카운팅

	int tc; // TC 2
	cin >> tc;

	int n, m; // N, M 5, 3
	int num; // 숫자

	// 테케 수 만큼
	while (tc--)
	{
		cin >> n >> m;

		vector<int> aVec, bVec; // A, B들 저장

		for (int i = 0; i < n; i++)
		{
			cin >> num;

			aVec.push_back(num);
		}

		for (int i = 0; i < m; i++)
		{
			cin >> num;

			bVec.push_back(num);
		}

		// 일단 A, B 모두 내림차순 정렬함
		sort(aVec.begin(), aVec.end(), comp); // 8 7 3 1 1
		sort(bVec.begin(), bVec.end(), comp); // 6 3 1

		// startIndex를 두고 다음 A는 B의 startIndex부터 체크하면서 카운팅

		int startIndex = 0; // 다음 A가 시작할 B 인덱스
		int eatCnt = 0; // 먹은 횟수

		for (int i = 0; i < aVec.size(); i++)
		{
			bool firstEat = false; // A가 처음 먹을때 체크

			for (int j = startIndex; j < bVec.size(); j++)
			{
				if (aVec[i] > bVec[j])
				{
					eatCnt++;

					if (!firstEat) // A가 처음 먹은 B 인덱스로 갱신
					{
						firstEat = true;
						startIndex = j;
					}
				}
			}
		}

		cout << eatCnt << '\n';
	}

	return 0;
}
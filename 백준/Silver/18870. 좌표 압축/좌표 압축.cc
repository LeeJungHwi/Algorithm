#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <fstream>
using namespace std;

// 좌표 압축
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 5
	cin >> n;

	// 압축결과 : Xi > Xj를 만족하는 서로다른좌표 Xj의 개수

	// 좌표 정렬후 이진탐색

	set<int> s; // 중복 제거용
	vector<int> sortedPos; // 중복이 제거된 정렬된 숫자
	vector<int> findPos(n); // 찾을 숫자

	int num; // 숫자

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		
		s.insert(num); // 중복을 제거하기위해 셋에 저장
		findPos[i] = num; // 찾을 숫자 2 4 -10 4 -9
	}

	for (auto it = s.begin(); it != s.end(); it++)
	{
		sortedPos.push_back(*it); // -10 -9 2 4
	}

	for (int i = 0; i < findPos.size(); i++)
	{
		num = findPos[i]; // 찾을 숫자

		int first = 0; // 처음
		int last = sortedPos.size() - 1; // 마지막
		int cnt = 0; // 기준값보다 작은 서로다른 숫자 개수

		while (first <= last) // 역전되면 종료
		{
			int standard = (first + last) / 2; // 기준값

			if (sortedPos[standard] == num) // 같으면
			{
				cnt = standard; // 기준값보다 작은 서로다른 숫자 개수는 standard 개

				break;
			}
			else if (sortedPos[standard] < num) // 크면
			{
				first = standard + 1; // 처음 갱신
			}
			else if (sortedPos[standard] > num) // 작으면
			{
				last = standard - 1; // 마지막 갱신
			}
		}

		cout << (cnt == 0 ? 0 : cnt) << ' ';
	}
	
	return 0;
}

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <string>
//#include <map>
//#include <set>
//#include <fstream>
//using namespace std;
//
//// 좌표 압축
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	ifstream cin;
//	cin.open("input.txt");
//
//	int n; // N 5
//	cin >> n;
//
//	// 압축결과 : Xi > Xj를 만족하는 서로다른좌표 Xj의 개수
//
//	// 좌표 정렬후 이진탐색
//
//	set<int> s; // 중복 제거용
//	vector<int> sortedPos; // 중복이 제거된 정렬된 숫자
//	vector<int> findPos(n); // 찾을 숫자
//
//	int num; // 숫자
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> num;
//
//		s.insert(num); // 중복을 제거하기위해 셋에 저장
//		findPos[i] = num; // 찾을 숫자 2 4 -10 4 -9
//	}
//
//	for (auto it = s.begin(); it != s.end(); it++)
//	{
//		sortedPos.push_back(*it); // -10 -9 2 4
//	}
//
//	map<int, int> reuse; // (숫자, 압축결과) 맵핑
//
//	for (int i = 0; i < findPos.size(); i++)
//	{
//		num = findPos[i]; // 찾을 숫자
//
//		int first = 0; // 처음
//		int last = sortedPos.size() - 1; // 마지막
//		int cnt = 0; // 기준값보다 작은 서로다른 숫자 개수
//
//		while (first <= last) // 역전되면 종료
//		{
//			int standard = (first + last) / 2; // 기준값
//
//			if (sortedPos[standard] == num) // 같으면
//			{
//				// 이미 구한적이 있다면 재사용
//				// 압축결과가 0인것은 -1을 넣어둠
//				if (reuse[num] != 0)
//				{
//					cnt = reuse[num];
//
//					break;
//				}
//
//				// 기준값부터 왼쪽을 보면서
//				for (int j = standard; j > -1; j--)
//				{
//					if (sortedPos[j] < num) // 기준값보다 작은
//					{
//						cnt++; // 서로다른 숫자 카운팅
//					}
//				}
//
//				// 처음 구한거면 메모
//				// 압축결과가 0인것은 -1을 넣어둠
//				if (cnt == 0)
//				{
//					cnt = -1;
//				}
//
//				reuse[num] = cnt;
//
//				break;
//			}
//			else if (sortedPos[standard] < num) // 크면
//			{
//				first = standard + 1; // 처음 갱신
//			}
//			else if (sortedPos[standard] > num) // 작으면
//			{
//				last = standard - 1; // 마지막 갱싱ㄴ
//			}
//		}
//
//		cout << (cnt == -1 ? 0 : cnt) << ' ';
//	}
//
//	return 0;
//}
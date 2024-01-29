#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

// 송아지 찾기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int s, e; // S, E
	cin >> s >> e;

	int jumpCnt = 0; // 점프 수
	int curPos = s; // 현수 위치

	// 처음 위치 저장

	// 현수위치 < 송아지위치
	// (송아지위치 - 현수위치) % 5 < 3 이면 (송아지위치 - 현수위치) / 5 만큼 점프 후 (송아지위치 - 점프된위치) 만큼 점프
	// (송아지위치 - 현수위치) % 5 >= 3 이면 (송아지위치 - 현수위치) / 5 + 1만큼 점프 후 (점프된위치 - 송아지위치) 만큼 점프

	// 현수위치 > 송아지위치
	// 현수위치 - 송아지위치가 총 점프 수
	if (s < e)
	{
		if ((e - s) % 5 < 3)
		{
			jumpCnt = (e - s) / 5;
			curPos += 5 * jumpCnt;
			jumpCnt += e - curPos;
		}
		else
		{
			jumpCnt = (e - s) / 5 + 1;
			curPos += 5 * jumpCnt;
			jumpCnt += curPos - e;
		}

		cout << jumpCnt << '\n';
	}
	else if (s > e)
	{
		cout << s - e << '\n';
	}

	return 0;
}
// 핵심
// BFS로 시간초과나서 문제 규칙 찾아서 풀었음

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <fstream>
//using namespace std;
//
//// 송아지 찾기
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	//ifstream cin;
//	//cin.open("input.txt");
//
//	int s, e; // S, E
//	cin >> s >> e;
//
//	vector<int> pos(10000); // 직선 좌표에 도달하는 점프 수 저장
//	int jumpCnt = 0; // 점프 수
//	queue<int> checkPos; // 체크할 위치
//	vector<int> move; // 이동 : 앞1 뒤1 앞5
//	move.push_back(1);
//	move.push_back(-1);
//	move.push_back(5);
//
//	// 처음 위치 저장
//	checkPos.push(s);
//	pos[checkPos.front()] = 0;
//
//	while (checkPos.back() != e) // 송아지 위치를 만나면 종료
//	{
//		// 현재 위치 꺼내기
//		int curPos = checkPos.front();
//		checkPos.pop();
//		jumpCnt = pos[curPos] + 1; // 꺼낸 위치의 점프 수 + 1
//
//		// 앞1 뒤1 앞5 체크
//		for (int i = 0; i < 3; i++)
//		{
//			int nextPos = curPos + move[i]; // 다음 위치 구하기
//
//			// 경계체크
//			if (nextPos < 1 || nextPos > 10000)
//			{
//				continue;
//			}
//
//			// 점프 수 저장
//			pos[nextPos] = jumpCnt;
//
//			// 큐에 추가
//			checkPos.push(nextPos);
//		}
//	}
//
//	cout << pos[e] << '\n';
//
//	return 0;
//}
//// 핵심
//// BFS는 무조건 최단거리가 저장됨
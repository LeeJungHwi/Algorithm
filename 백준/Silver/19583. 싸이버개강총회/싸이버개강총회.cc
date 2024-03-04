#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <fstream>
using namespace std;

// 싸이버 개강총회
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	string start; // 개강총회 시작시간
	string end; // 개강총회 끝낸시간
	string quit; // 스트리밍 끝낸시간

	// 22:00 23 : 00 23 : 30
	cin >> start >> end >> quit;

	map<string, int> m; // 학회원 체크
	set<string> s; // 중복제거용

	while (true)
	{
		string chat; // 채팅시간
		string id; // 아이디

		cin >> chat >> id;

		// 더이상 입력이 없으면 break
		if (chat.empty())
		{
			break;
		}

		// 채팅시간이 시작시간 이하면 ++
		if (chat <= start)
		{
			m[id]++;
		}
		else if (chat >= end && chat <= quit) // 채팅시간이 시작시간 이상 스트리밍종료시간 이하일때
		{
			if (m[id] > 0) // 시작시간 이하때 챗 친사람이면 중복제거위해 set에 저장 
			{
				s.insert(id);
			}
		}
	}

	// 출석이 확인된 학회원 수 출력
	cout << s.size() << '\n';

	return 0;
}
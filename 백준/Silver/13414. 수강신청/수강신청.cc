#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 수강신청
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 버튼이 활성화된후 빨리누른학생이 먼저 대기목록에 들어감
	// 이미 눌렀는데 다시 누르면 맨뒤로 밀려남
	// 버튼이 비활성화되면 대기목록 가장앞에있는 학생부터 수강신청이 완료되며
	// 수강인원이 꽉차면 나머지 대기목록은 무시하고 수강신청이 종료됨

	int k, l; // K, L 3, 8 
	cin >> k >> l;

	map<int, string> sugangOrder; // (신청순서, 학번)
	map<string, int> sugangNum; // (학번, 신청순서)

	string studentNum; // 학번

	//	20103324
	//	20133221
	//	20133221
	//	20093778
	//	20140101
	//	01234567
	//	20093778
	//	20103325
	for (int i = 1; i < l + 1; i++)
	{
		cin >> studentNum;

		// 이미 있는 학번이면 기존신청 제거 후 삽입
		// 처음 신청한 학번이면 그냥 삽입
		if (sugangNum.find(studentNum) != sugangNum.end())
		{
			sugangOrder.erase(sugangNum[studentNum]);
			sugangOrder[i] = studentNum;
			sugangNum[studentNum] = i;
		}
		else
		{
			sugangOrder[i] = studentNum;
			sugangNum[studentNum] = i;
		}
	}

	// 수강신청 완료한 학생 중 앞에서부터 k명 뽑아내기

	int sugangCnt = 0; // 수강 신청 완료한 학생 수

	for (auto it = sugangOrder.begin(); it != sugangOrder.end(); it++)
	{
		// k명 뽑았으면 break
		if (sugangCnt == k)
		{
			break;
		}

		cout << it->second << '\n';
		sugangCnt++;
	}

	return 0;
}
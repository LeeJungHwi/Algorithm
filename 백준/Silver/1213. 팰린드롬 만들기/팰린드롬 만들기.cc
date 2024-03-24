#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
using namespace std;

// 팰린드롬 만들기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	string inputString; // AABB
	cin >> inputString;

	// 각 문자 개수 카운팅
	vector<int> alphaCnt(26);

	for (int i = 0; i < inputString.size(); i++)
	{
		alphaCnt[inputString[i] - 'A']++;
	}

	string prefix; // 접두사
	string middle; // 홀수개인문자
	string suffix; // 접미사

	// 홀수 개인 문자가 두개이상이면 만들수없음
	// 홀수 개인 문자를 가운데에 두고 접두사 접미사를 구해야함
	for (int i = 0; i < 26; i++)
	{
		if (alphaCnt[i] % 2 == 1) // 문자가 홀수개이면
		{
			if (middle.empty()) // 아직 홀수개인 문자가 없다면
			{
				middle = string(1, 'A' + i); // 가운데에 홀수 개인 문자를 둠
				alphaCnt[i]--;
			}
			else // 이미 홀수개인 문자가 있었다면 홀수개인 문자가 두개이상이므로 만들수없음
			{
				cout << "I'm Sorry Hansoo" << '\n';

				return 0;
			}
		}
	}

	// 접두사와 접미사 구하기

	string tempString; // 추가 할 임시문자열

	for (int i = 0; i < 26; i++)
	{
		if (alphaCnt[i] > 0)
		{
			// 알파벳 개수의 절반은 접두사에, 절반은 접미사에 추가
			int halfCnt = alphaCnt[i] / 2;
			
			tempString.insert(0, halfCnt, 'A' + i);
			prefix += tempString;
			suffix = tempString + suffix;
			tempString = "";
		}
	}

	// 접두사 + 홀수개인문자 + 접미사
	cout << prefix + middle + suffix << '\n';

	return 0;
}

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <string>
//#include <map>
//#include <fstream>
//using namespace std;
//
//string inputString; // AABB
//string combination; // 중복을 제외한 조합
//vector<bool> vis(50); // 방문체크
//map<string, int> combMap; // 팰린드롬 조합 맵핑
//
//// DFS
//void DFS(int L)
//{
//	if (L == inputString.size()) // 종료조건 : 입력문자열 길이만큼 뽑은경우
//	{
//		// 팰린드롬인지 체크
//		int first = 0;
//		int last = combination.length() - 1;
//
//		while (first < last)
//		{
//			if (combination[first] != combination[last])
//			{
//				return; // 팰린드롬이 아니면 리턴
//			}
//
//			first++;
//			last--;
//		}
//
//		// 팰린드롬이면 맵핑
//		combMap[combination]++;
//	}
//	else
//	{
//		for (int i = 0; i < inputString.size(); i++)
//		{
//			// 중복없이 조합 생성
//			if (!vis[i] && (i == 0 || inputString[i] != inputString[i - 1] || vis[i - 1]))
//			{
//				vis[i] = true; // 선택
//				combination.push_back(inputString[i]);
//				DFS(L + 1);
//				combination.pop_back();
//				vis[i] = false; // 미선택
//			}
//		}
//	}
//}
//
//// 팰린드롬 만들기
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	//ifstream cin;
//	//cin.open("input.txt");
//
//	// 1. 입력문자열을 중복을 제외한 조합 생성하기
//	// 2. 각 조합에 대해 팰린드롬인것을 맵핑
//	// 3. 맵에 요소가있으면 첫요소 출력 아니면 I'm Sorry Hansoo 출력
//
//	cin >> inputString;
//
//	// 1. 입력문자열을 중복을 제외한 조합 생성하기
//	// 2. 각 조합에 대해 팰린드롬인것을 맵핑
//	DFS(0);
//
//	// 3. 맵에 요소가있으면 첫요소 출력 아니면 I'm Sorry Hansoo 출력
//	if (!combMap.empty())
//	{
//		auto it = combMap.begin();
//		cout << it->first << '\n';
//
//		return 0;
//	}
//
//	cout << "I'm Sorry Hansoo" << '\n';
//
//	return 0;
//}

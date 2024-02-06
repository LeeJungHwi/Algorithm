#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

// 모든 아나그램
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	string s, t;
	cin >> s >> t;

	vector<int> alphaT(26); // t의 알파벳 개수 저장
	vector<int> alphaS(26); // s의 부분문자열 알파벳 개수 저장

	// t 문자열의 각 알파벳 개수 저장
	for (int i = 0; i < t.size(); i++)
	{
		alphaT[t[i] - '0' - 49]++;
	}

	int anaCnt = 0; // 아나그램 개수

	// 초기 슬라이딩 윈도우 알파벳 개수 저장
	for (int i = 0; i < t.size(); i++)
	{
		alphaS[s[i] - '0' - 49]++;
	}

	// 첫 번째 윈도우의 아나그램 여부 체크
	bool isAnagram = true;

	for (int i = 0; i < 26; i++)
	{
		if (alphaT[i] != alphaS[i])
		{
			isAnagram = false;
			break;
		}
	}

	if (isAnagram)
	{
		anaCnt++;
	}

	// 슬라이딩 윈도우 이동하며 아나그램 개수 세기
	for (int i = t.size(); i < s.size(); i++)
	{
		alphaS[s[i - t.size()] - '0' - 49]--; // 윈도우에서 제외되는 문자의 개수 감소

		alphaS[s[i] - '0' - 49]++; // 새로운 문자의 개수 증가

		// 윈도우의 아나그램 여부 체크
		isAnagram = true;

		for (int j = 0; j < 26; j++)
		{
			if (alphaT[j] != alphaS[j])
			{
				isAnagram = false;
				break;
			}
		}

		if (isAnagram)
		{
			anaCnt++;
		}
	}

	cout << anaCnt << '\n';

	return 0;
}
// 핵심
// 시간초과 -> 슬라이딩 윈도우로 해결

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <string>
//#include <fstream>
//using namespace std;
//
//// 모든 아나그램
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	ifstream cin;
//	cin.open("input.txt");
//
//	string s, t; // S, T eabcbacade, abc
//	cin >> s >> t;
//
//	vector<int> alpha(26); // 알파벳 개수 저장
//
//	for (int i = 0; i < t.size(); i++)
//	{
//		alpha[t[i] - '0' - 49]++; // 1 1 1
//	}
//
//	// 부분문자열이 아나그램인지 체크
//
//	int anaCnt = 0; // 아나그램 개수
//
//	for (int i = 0; i < s.size() - t.size() + 1; i++) // s를 돌면서
//	{
//		if (alpha[s[i] - '0' - 49] > 0) // t가 가지는 알파벳을 만나면
//		{
//			vector<int> check(26);
//			bool isAnagram = true; // 아나그램인지 체크
//
//			for (int j = i; j < i + t.size(); j++) // 부분 문자열 알파벳 개수 저장
//			{
//				check[s[j] - '0' - 49]++;
//			}
//
//			// 하나라도 개수가 다르면 아나그램 아님
//			for (int j = 0; j < t.size(); j++)
//			{
//				if (alpha[t[j] - '0' - 49] != check[t[j] - '0' - 49])
//				{
//					isAnagram = false;
//				}
//			}
//
//			// 부분문자열이 아나그램이면 아나그램 개수 카운팅
//			if (isAnagram)
//			{
//				anaCnt++;
//			}
//		}
//	}
//
//	cout << anaCnt << '\n';
//
//	return 0;
//}
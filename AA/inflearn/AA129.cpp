#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

// 문자열 점수
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n1, n2, n3; // N1, N2, N3 5, -1, -3
	cin >> n1 >> n2 >> n3;

	string first; // 첫번째 문자열 abcb
	cin >> first;

	string second; // 두번째 문자열 acb
	cin >> second;

	// lengths[i][j] : 첫번째 문자열 i번째 길이까지와 두번째 문자열 j번째 길이까지 얻을수있는 최대점수 저장
	vector<vector<int> > lengths(first.size() + 1, vector<int>(second.size() + 1));

	/*
		공백 a c b
	공백 0 -1 -2 -3
	a	-1
	b	-2
	c	-3
	b	-4
	*/
	for (int i = 1; i < first.size() + 1; i++)
	{
		lengths[i][0] = n2 * i;
	}

	for (int i = 1; i < second.size() + 1; i++)
	{
		lengths[0][i] = n2 * i;
	}

	/*
		공백 a c b
	공백 0 -1 -2 -3
	a	-1  5  4  3
	b	-2  4  3  ?(9) : ab, acb에서 마지막 문자가 b로 같을때
	c	-3  3  9  ?max(8, 8, 1, 0) : abc, acb에서 마지막 문자가 서로 다를때
	b	-4  2  8  14
	*/
	// 마지막 두 문자가 서로 같을때 1가지 방법
	// ab, acb 둘다에서 마지막 문자를 제거해서 a, ac로 얻을수있는 최대점수 4 + 같은문자 b 매칭 점수 5 -> 9
	// 마지막 두 문자가 서로 다를때 4가지 방법
	// 1. acb에서 마지막 문자를 제거해서 abc, ac로 얻을수있는 최대점수 9 + 공백하고 b 매칭 점수 -1 -> 8
	// 2. abc에서 마지막 문자를 제거해서 ab, acb로 얻을수있는 최대점수 9 + 공백하고 c 매칭 점수 -1 -> 8
	// 3. acb, abc 둘다에서 마지막 문자를 제거해서 ac, ab로 얻을수있는 최대점수 3 + 공백하고 b 매칭 점수 -1 + 공백하고 c 매칭 점수 -1 -> 1
	// 4. acb, abc 둘다에서 마지막 문자를 제거해서 ac, ab로 얻을수있는 최대점수 3 + b와 c 매칭 점수 -3 -> 0
	// 위 네가지 방법 중 최대값을 lengths[i][j]에 저장
	for (int i = 1; i < first.size() + 1; i++)
	{
		for (int j = 1; j < second.size() + 1; j++)
		{
			if (first[i - 1] == second[j - 1]) // 두 부분문자열의 마지막 문자가 같을때
			{
				lengths[i][j] = lengths[i - 1][j - 1] + n1;
			}
			else // 두 부분문자열의 마지막 문자가 다를때
			{
				int max = 0;

				// 1. 2.
				if (lengths[i - 1][j] + n2 > lengths[i][j - 1] + n2)
				{
					max = lengths[i - 1][j] + n2;
				}
				else
				{
					max = lengths[i][j - 1] + n2;
				}

				// 4.
				if (lengths[i - 1][j - 1] + n3 > max)
				{
					max = lengths[i - 1][j - 1] + n3;
				}

				// 3.
				if (lengths[i - 1][j - 1] + (n2 * 2) > max)
				{
					max = lengths[i - 1][j - 1] + (n2 * 2);
				}

				// 네가지 방법 중 최대값을 lengths[i][j]에 저장
				lengths[i][j] = max;
			}
		}
	}

	cout << lengths[first.size()][second.size()];

	return 0;
}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//#include <fstream>
//using namespace std;
//
//// 문자열 점수
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	ifstream cin;
//	cin.open("input.txt");
//
//	int n1, n2, n3; // N1, N2, N3 5, -1, -3
//	cin >> n1 >> n2 >> n3;
//
//	string first; // 첫번째 문자열 abcb
//	cin >> first;
//
//	string second; // 두번째 문자열 acb
//	cin >> second;
//
//	// 1. first, second의 LCS 길이를 구하고 점수 += LCS길이 * n1
//
//	int score = 0; // 총점
//
//	vector<vector<int> > lengths(first.size() + 1, vector<int>(second.size() + 1)); // lengths[i][j] : 첫번째 문자열 i번째 길이까지와 두번째 문자열 j번째 길이까지 최대공통문자열 저장
//
//	for (int i = 1; i < first.size() + 1; i++)
//	{
//		for (int j = 1; j < second.size() + 1; j++)
//		{
//			if (first[i - 1] == second[j - 1]) // 두 부분문자열의 마지막 문자가 같다면
//			{
//				lengths[i][j] = lengths[i - 1][j - 1] + 1; // 두 부분문자열의 마지막 문자를 뺀 최대길이 + 1
//			}
//			else // 두 부분문자열의 마지막 문자가 다르다면
//			{
//				lengths[i][j] = max(lengths[i - 1][j], lengths[i][j - 1]); // max(첫문자열의 마지막문자 뺀 최대길이, 두번째문자열의 마지막문자 뺀 최대길이)
//			}
//		}
//	}
//
//	score += n1 * lengths[first.size()][second.size()]; // LCS길이 * n1
//
//	// 2. first, second에서 LCS부분을 공백문자로 대체하기
//
//	int firstSize = first.size(); // 첫번째 문자열 크기
//	int secondSize = second.size(); // 두번째 문자열 크기
//
//	string lcsString = ""; // LCS 문자열
//
//	while (firstSize > 0 && secondSize > 0) // LCS 문자열 찾기 acb
//	{
//		if (first[firstSize - 1] == second[secondSize - 1])
//		{
//			lcsString = first[firstSize - 1] + lcsString;
//			firstSize--;
//			secondSize--;
//		}
//		else if (lengths[firstSize - 1][secondSize] > lengths[firstSize][secondSize - 1])
//		{
//			firstSize--;
//		}
//		else
//		{
//			secondSize--;
//		}
//	}
//
//	int startJ = 0; // 시작할 j 인덱스
//
//	for (int i = 0; i < lcsString.size(); i++) // 첫번째 문자열 LCS부분 공백문자로 대체 : 공백b공백공백
//	{
//		for (int j = startJ; j < first.size(); j++)
//		{
//			if (lcsString[i] == first[j])
//			{
//				first[j] = ' ';
//				startJ = j + 1;
//				break;
//			}
//		}
//	}
//
//	startJ = 0; // 시작할 j 인덱스 초기화
//
//	for (int i = 0; i < lcsString.size(); i++) // 두번째 문자열 LCS부분 공백문자로 대체 : 공백공백공백
//	{
//		for (int j = startJ; j < second.size(); j++)
//		{
//			if (lcsString[i] == second[j])
//			{
//				second[j] = ' ';
//				startJ = j + 1;
//				break;
//			}
//		}
//	}
//
//	// 3. first, second의 크기가 같도록 작은 문자열에 공백문자 넣기
//
//	if (first.size() < second.size())
//	{
//		first.append(second.size() - first.size(), ' ');
//	}
//	else if (second.size() < first.size())
//	{
//		second.append(first.size() - second.size(), ' '); // 두번째 문자열 : 공백공백공백공백
//	}
//
//	// 4. first, second를 비교하면서 둘다 공백이면 무시, 하나만 공백이면 +n2점, 서로 다른 문자면 +n3점
//
//	for (int i = 0; i < first.size(); i++)
//	{
//		if (first[i] == ' ' && second[i] == ' ') // 둘다 공백이면 무시
//		{
//			continue;
//		}
//
//		if (first[i] != ' ' && second[i] != ' ') // 서로 다른 문자면 n3점
//		{
//			if (n2 * 2 > n3) // 서로다른 문자일때 first, second에 공백을 하나씩 추가해서 공백이 하나인 점수 n2 * 2가 서로다른 문자 점수 n3보다 크면
//			{
//				score += n2 * 2; // 공백을 하나씩 추가해서 n2 * 2점 획득
//			}
//			else // 그냥 서로다른 문자 점수가 더 낫다면
//			{
//				score += n3; // n3점 획득
//			}
//		}
//		else // 하나만 공백이면 n2점
//		{
//			score += n2;
//		}
//	}
//
//	cout << score << '\n';
//
//	return 0;
//}


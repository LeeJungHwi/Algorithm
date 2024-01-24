#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// 알파벳 개수 카운트
// cout << 'a' - '0' << 'A' - '0' << 'z' - '0' << 'Z' - '0'; 49 17 74 42
// cout << 'a' - 97 << 'z' - 97 << 'A' - 39 << 'Z' - 39;
// a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z -> 26개 0~25
// A ~ Z -> 26개 26~51
vector<int> fcnts(52), scnts(52); // 알파벳 개수 카운트

// 알파벳 개수 카운트
void CountAlpha(string word, vector<int> &cnts)
{
	for (int i = 0; i < word.size(); i++) // 단어 크기만큼 돌면서
	{
		if (word[i] - '0' >= 49 && word[i] - '0' <= 74) // 소문자
		{
			cnts[word[i] - 97]++;
		}
		else // 대문자
		{
			cnts[word[i] - 39]++;
		}
	}
}

// 아나그램 체크
// fcnts와 scnts가 같으면 아나그램
void CheckAnagram()
{
	for (int i = 0; i < 52; i++) // 알파벳 대소문자 개수만큼 돌면서
	{
		if (fcnts[i] != scnts[i]) // 하나라도 알파벳의 개수가 같지않으면 NO
		{
			cout << "NO" << '\n';
			return;
		}
	}
	
	cout << "YES" << '\n'; // 알파벳 개수가 같다면 YES
}

// 아나그램(구글)
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	string fWord, sWord; // 첫번째 단어, 두번째 단어
	cin >> fWord >> sWord;

	CountAlpha(fWord, fcnts); // 첫번째 단어 알파벳 개수 카운팅
	CountAlpha(sWord, scnts); // 두번째 단어 알파벳 개수 카운팅
	CheckAnagram();

	return 0;
}

// 핵심
// 벡터를 인자로 넘길때 벡터가 복사되어 넘겨지므로 참조형태로 넘김
// 알파벳 개수 26개
// 문자를 숫자로 -> 문자 - '0'
// 소문자를 숫자로 -> a 49 z 74
// 대문자를 숫자로 ->  A 17 Z 42
// 소문자를 0부터 세려면 -> a - '0' - 49 -> a - 97
// 대문자를 26부터 세려면 -> A -'0' + 9 -> A - 39
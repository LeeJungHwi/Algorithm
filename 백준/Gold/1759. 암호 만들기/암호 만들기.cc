#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

int l, c; // L, C 4, 6
vector<char> password; // 암호로 사용될 문자
vector<bool> vis(15); // 방문체크
vector<char> aeiou; // 모음

// DFS
void DFS(int L, int cnt)
{
	if (L == c || cnt == l) // 종료조건 : 암호로 사용될 문자 수를 넘긴경우나 l개 문자를 선택한 경우
	{
		if (L == c) // 암호로 사용될 문자 수를 넘긴경우
		{
			if (cnt != l) // l개 문자를 선택하지 않았으면 리턴
			{
				return;
			}
		}

		// 가능성 있는 암호 조건 : 알파벳 순서, 한 개 모음, 두 개 자음
		// 모음 아니면 자음 이므로 모음의 개수가 1 ~ l - 2 개 사이면 가능한 암호

		int aeiouCnt = 0; // 모음 개수

		for (int i = 0; i < c; i++)
		{
			if (vis[i]) // 뽑은 문자 중에서
			{
				for (int j = 0; j < aeiou.size(); j++) // c개 문자 중 모음 개수만큼 돌면서 
				{
					if (password[i] == aeiou[j]) // 모음이 발견되면 개수 카운팅
					{
						aeiouCnt++;
					}
				}
			}
		}

		// 가능성 있는 암호 출력하기
		if (aeiouCnt >= 1 && aeiouCnt <= l - 2)
		{
			for (int i = 0; i < c; i++)
			{
				if (vis[i])
				{
					cout << password[i];
				}
			}

			cout << '\n';
		}
	}
	else
	{
		vis[L] = true; // 문자 선택
		DFS(L + 1, cnt += 1);
		vis[L] = false; // 문자 미 선택
		DFS(L + 1, cnt -= 1);
	}
}

// 암호 만들기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> l >> c;

	char inputChar; // 문자

	// a t c i s w
	for (int i = 0; i < c; i++)
	{
		cin >> inputChar;

		password.push_back(inputChar);

		// 모음은 따로 저장
		if (inputChar == 'a' || inputChar == 'e' || inputChar == 'i' || inputChar == 'o' || inputChar == 'u')
		{
			aeiou.push_back(inputChar);
		}
	}

	// 알파벳 순서대로 암호가 구성되어있으므로 정렬 a c i s t w
	sort(password.begin(), password.end());

	// DFS
	DFS(0, 0);

	return 0;
}
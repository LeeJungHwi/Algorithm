#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 한국이 그리울 땐 서버에 접속하지
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 3
	cin >> n;

	string pattern; // a*d
	cin >> pattern;

	int charCnt = 0; // *이전 문자 개수 + *이후 문자 개수

	string reversePattern; // d*a
	for (int i = pattern.size() - 1; i > - 1; i--)
	{
		reversePattern += pattern[i];

		if (pattern[i] == '*')
		{
			continue;
		}

		charCnt++;
	}

	// 디버깅용
	//cout << charCnt << '\n';

	// *는 한개
	for (int i = 0; i < n; i++)
	{
		string file;
		cin >> file; // abcd

		bool isDA = true; // DA인지 체크

		// 파일이름 정방향 돌면서 패턴 *를 만나기까지 같은지 체크
		for (int j = 0; j < file.size(); j++)
		{
			if (pattern[j] == '*') // *를 만나면 break
			{
				break;
			}

			if (pattern[j] != file[j]) // *를 만나기까지 하나라도 다르면 DA 아님
			{
				isDA = false;

				break;
			}
		}

		if (!isDA) // DA가 아니면 NE 출력 후 continue
		{
			cout << "NE" << '\n';

			continue;
		}

		// 파일이름 역방향 돌면서 패턴 *를 만나기까지 같은지 체크
		reverse(file.begin(), file.end());

		for (int j = 0; j < file.size(); j++)
		{
			if (reversePattern[j] == '*') // *를 만나면 break
			{
				break;
			}

			if (reversePattern[j] != file[j]) // *를 만나기까지 하나라도 다르면 DA 아님
			{
				isDA = false;

				break;
			}
		}

		if (!isDA || file.size() < charCnt) // DA가 아니거나 파일이름이 * 앞뒤 문자 개수보다 작으면 NE 출력 후 continue
		{
			cout << "NE" << '\n';

			continue;
		}

		// DA이면 DA 출력
		cout << "DA" << '\n';
	}

	return 0;
}
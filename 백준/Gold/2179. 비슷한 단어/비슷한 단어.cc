#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 공통 접두사 길이 반환
int CommonPrefixCnt(const string &s1, const string &s2)
{
	int cnt = 0;

	for (int i = 0; i < min(s1.size(), s2.size()); i++)
	{
		if (s1[i] == s2[i]) cnt++;
		else break;
	}

	return cnt;
}

// 단어 정렬
bool comp(const pair<int, string> &p1, const pair<int, string> &p2)
{
	return p1.second < p2.second;
}

// 비슷한 단어
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 9
	cin >> n;

	vector<string> word(n);
	for (int i = 0; i < n; i++) cin >> word[i];

	// (입력순서, 단어) 쌍 정렬
	vector<pair<int, string> > orderWord;
	for (int i = 0; i < n; i++) orderWord.push_back({ i, word[i] });
	sort(orderWord.begin(), orderWord.end(), comp);

	vector<int> length(n); // 각 단어의 최대공통 접두사 길이 저장
	int maxlength = 0; // 최대공통 접두사 길이

	// 인접한 단어 공통 접두사 최대길이 갱신
	for (int i = 0; i < n - 1; i++)
	{
		int commonPrefixCnt = CommonPrefixCnt(orderWord[i].second, orderWord[i + 1].second);
		maxlength = max(maxlength, commonPrefixCnt);
		length[orderWord[i].first] = max(length[orderWord[i].first], commonPrefixCnt);
		length[orderWord[i + 1].first] = max(length[orderWord[i + 1].first], commonPrefixCnt);
	}

	// 최대 접두사 길이를 가지는 단어 쌍 출력

	bool isFirst = false;
	string prefix;

	for (int i = 0; i < n; i++)
	{
		// 아직 처음 단어를 찾지 않았으면
		if (!isFirst)
		{
			// 최대 공통 접두사 길이를 만나면
			if (length[i] == maxlength)
			{
				// 첫 단어 출력
				cout << word[i] << '\n';

				// 접두사 저장
				prefix = word[i].substr(0, maxlength);

				// 첫 단어를 찾음
				isFirst = true;
			}
		}
		else
		{
			// 최대 공통 접두사 길이면서 첫 단어의 접두사와 같으면
			if (length[i] == maxlength && word[i].substr(0, maxlength) == prefix)
			{
				// 두번째 단어 출력
				cout << word[i] << '\n';
				break;
			}
		}
	}

	return 0;
}

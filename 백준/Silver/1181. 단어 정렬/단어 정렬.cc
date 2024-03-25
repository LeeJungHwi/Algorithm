#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <fstream>
using namespace std;

// 정렬기준
// 1.길이가 다르면 길이 오름차순
// 2.길이가 같으면 사전순
// 단, 중복 단어는 제거
bool comp(const string &s1, const string &s2)
{
	if (s1.size() != s2.size())
	{
		return s1.size() < s2.size();
	}

	return s1 < s2;
}

// 단어 정렬
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 일단 단어 입력받을때 set에 저장해서 중복단어 제거함
	// set에 저장된 단어를 벡터로 옮김
	// 정렬 후 출력함

	int n; // N 13
	cin >> n;

	set<string> s; // 중복 제거용
	vector<string> wordVec; // 중복을 제거한 단어들 저장
	string word; // 단어

	// 일단 단어 입력받을때 set에 저장해서 중복단어 제거함
	for (int i = 0; i < n; i++)
	{
		cin >> word;

		s.insert(word);
	}

	// set에 저장된 단어를 벡터로 옮김
	for (auto it = s.begin(); it != s.end(); it++)
	{
		wordVec.push_back(*it);
	}

	// 정렬 후 출력함
	sort(wordVec.begin(), wordVec.end(), comp);

	for (int i = 0; i < wordVec.size(); i++)
	{
		cout << wordVec[i] << '\n';
	}

	return 0;
}
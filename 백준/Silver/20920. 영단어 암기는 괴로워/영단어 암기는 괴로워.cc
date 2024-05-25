#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <fstream>
using namespace std;

struct Word
{
	string word;
	int cnt;

	Word() {}
	Word(string w, int c) : word(w), cnt(c) {}

	// 1. 빈도 내림
	// 2. 길이 내림
	// 3. 사전 오름
	bool operator<(const Word &compWord)const
	{
		if (cnt != compWord.cnt) return cnt > compWord.cnt;
		if (word.size() != compWord.word.size()) return word.size() > compWord.word.size();
		return word < compWord.word;
	}
};

// 영단어 암기는 괴로워
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	map<string, int> wordMap;
	set<Word> wordSet;

	int n, m;
	cin >> n >> m;

	// 단어 빈도 수 맵핑
	string inputString;
	for (int i = 0; i < n; i++)
	{
		cin >> inputString;
		if (inputString.size() < m) continue;
		wordMap[inputString]++;
	}

	// 정렬 기준
	for (auto it = wordMap.begin(); it != wordMap.end(); it++) wordSet.insert(Word(it->first, it->second));
	for (auto it = wordSet.begin(); it != wordSet.end(); it++) cout << it->word << '\n';

	return 0;
}
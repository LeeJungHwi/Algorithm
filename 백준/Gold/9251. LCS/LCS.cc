#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// LCS
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	string first; // 첫 문자열 ACAYKP
	cin >> first;

	string second; // 두번째 문자열 CAPCAK
	cin >> second;

	// lengths[i][j] : 첫번째 문자열 i번째 길이까지와 두번째 문자열 j번째 길이까지 최대공통문자열 저장
	vector<vector<int> > lengths(first.size() + 1, vector<int>(second.size() + 1));

	// DP
	// 두 부분문자열의 마지막 문자가 같을때 : lengths[i][j] = lengths[i - 1][j - 1] + 1
	// 두 부분문자열의 마지막 문자가 다를때 : lengths[i][j] = max(lengths[i - 1][j], lengths[i][j - 1])
	for (int i = 1; i < first.size() + 1; i++)
	{
		for (int j = 1; j < second.size() + 1; j++)
		{
			if (first[i - 1] == second[j - 1]) // 두 부분문자열의 마지막 문자가 같다면
			{
				lengths[i][j] = lengths[i - 1][j - 1] + 1; // 두 부분문자열의 마지막 문자를 뺀 최대길이 + 1
			}
			else // 두 부분문자열의 마지막 문자가 다르다면
			{
				lengths[i][j] = max(lengths[i - 1][j], lengths[i][j - 1]); // max(첫문자열의 마지막문자 뺀 최대길이, 두번째문자열의 마지막문자 뺀 최대길이)
			}
		}
	}

	cout << lengths[first.size()][second.size()] << '\n';

	return 0;
}
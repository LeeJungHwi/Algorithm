#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 정렬기준
// 1.길이가 다르면 길이 오름차순
// 2.길이가 같으면 문자열 내부 숫자 오름차순
// 3.1과 2로 비교가 불가능하면 사전 오름차순
bool comp(const string &s1, const string &s2)
{
	// 1.길이가 다르면 길이 오름차순
	if (s1.size() != s2.size())
	{
		return s1.size() < s2.size();
	}

	// 2.길이가 같으면 문자열 내부 숫자 오름차순
	int sumS1 = 0, sumS2 = 0; // s1, s2 숫자합

	for (int i = 0; i < s1.size(); i++)
	{
		if (isdigit(s1[i]))
		{
			sumS1 += s1[i] - '0';
		}

		if (isdigit(s2[i]))
		{
			sumS2 += s2[i] - '0';
		}
	}

	if (sumS1 != sumS2)
	{
		return sumS1 < sumS2;
	}

	// 3.1과 2로 비교가 불가능하면 사전 오름차순
	return s1 < s2;
}

// 시리얼 번호
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 5
	cin >> n;

	vector<string> serialNumVec; // 시리얼 번호들 저장
	string serialNum; // 시리얼 번호

	for (int i = 0; i < n; i++)
	{
		cin >> serialNum;

		serialNumVec.push_back(serialNum); // ABCD, 145C, A, A910, Z321
	}

	// 정렬 후 출력
	sort(serialNumVec.begin(), serialNumVec.end(), comp);

	for (int i = 0; i < serialNumVec.size(); i++)
	{
		cout << serialNumVec[i] << '\n';
	}

	return 0;
}
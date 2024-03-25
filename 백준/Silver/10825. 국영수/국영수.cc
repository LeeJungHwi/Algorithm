#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 정렬기준
// 1.국어점수가 다르면 국어점수 내림차순
// 2.국어점수가 같으면 영어점수가 다르면 영어점수 오름차순
// 3.영어점수가 같으면 수학점수가 다르면 수학점수 내림차순
// 4.수학점수가 같으면 사전 오름차순
bool comp(const tuple<string, int, int, int> &t1, const tuple<string, int, int, int> &t2)
{
	if (get<1>(t1) != get<1>(t2))
	{
		return get<1>(t1) > get<1>(t2);
	}

	if (get<2>(t1) != get<2>(t2))
	{
		return get<2>(t1) < get<2>(t2);
	}

	if (get<3>(t1) != get<3>(t2))
	{
		return get<3>(t1) > get<3>(t2);
	}

	return get<0>(t1) < get<0>(t2);
}

// 국영수
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 12
	cin >> n;

	vector<tuple<string, int, int, int> > studentVec; // 학생들 저장

	string name; // 이름
	int kor; // 국어
	int eng; // 영어
	int math; // 수학

	// 학생들 저장
	for (int i = 0; i < n; i++)
	{
		cin >> name >> kor >> eng >> math;

		studentVec.push_back({ name, kor, eng, math });
	}

	// 정렬 후 출력
	sort(studentVec.begin(), studentVec.end(), comp);

	for (int i = 0; i < studentVec.size(); i++)
	{
		cout << get<0>(studentVec[i]) << '\n';
	}

	return 0;
}
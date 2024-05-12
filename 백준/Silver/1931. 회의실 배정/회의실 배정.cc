#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 끝나는 시간 기준 오름차순 정렬
// 끝나는 시간이 같으면 시작 시간 기준 오름차순 정렬
bool comp(const pair<int, int> &p1, const pair<int, int> &p2)
{
	if (p1.second != p2.second) return p1.second < p2.second;
	return p1.first < p2.first;
}

// 회의실 배정
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 11
	cin >> n;

	vector<pair<long long, long long> > room(n);

	long long start, end;

	// 끝나는 시간을 기준으로 오름차순 정렬
	// 끝나는 시간이 같으면 시작 시간 기준 오름차순 정렬
	// 현재 끝나는 시간을 처음 회의의 끝나는 시간으로
	// room 돌면서 시작 시간이 현재 끝나는 시간보다 작으면 스킵
	// 아니면 회의 진행하고 현재 끝나는 시간 갱신
	for (int i = 0; i < n; i++) cin >> room[i].first >> room[i].second;
	sort(room.begin(), room.end(), comp);
	//for (auto a : room) cout << a.first << ' ' << a.second << '\n';
	int cnt = 1;
	long long curEndTime = room[0].second;

	for (int i = 1; i < n; i++)
	{
		// 스킵하는 회의
		if (room[i].first < curEndTime) continue;

		// 회의 진행, 끝나는 시간 갱신
		cnt++;
		curEndTime = room[i].second;
	}

	cout << cnt << '\n';

	return 0;
}
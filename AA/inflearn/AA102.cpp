#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 최대점수 구하기(냅색)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 5 20
	cin >> n >> m;

	vector<pair<int, int> > problems(n); // 문제

	int score; // 문제 점수
	int time; // 걸리는 시간

	//	10 5
	//	25 12
	//	15 8
	//	6 3
	//	7 4
	for (int i = 0; i < n; i++)
	{
		cin >> score >> time;

		problems[i] = { score, time };
	}

	vector<int> scores(m + 1); // 제한시간에 따라 최고점수 갱신, 한 문제를 여러번 풀 수 없음

	for (int i = 0; i < n; i++)
	{
		for (int j = m; j > problems[i].second - 1; j--) // 제한시간 m부터 문제시간 까지 돌면서 최고점수 갱신
		{
			if (scores[j] < scores[j - problems[i].second] + problems[i].first)
			{
				scores[j] = scores[j - problems[i].second] + problems[i].first;
			}
		}
	}

	cout << scores[m] << '\n';

	return 0;
}
// 핵심
// 무제한이 아니면 다이나믹 거꾸로
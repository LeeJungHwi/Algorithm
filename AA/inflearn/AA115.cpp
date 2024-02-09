#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

int n, d, k; // N, D, K 8, 4, 3
vector<vector<int> > students(30001); // 학생 소스취향 
vector<int> vis1(16); // 방문체크
int maxStuCnt; // 음식을 먹을 수 있는 최대학생 수

// DFS
void DFS(int L, int cnt)
{
	if (L == d + 1 || cnt == k) // 종료조건 : 마지막 재료까지 가거나 k개의 재료를 뽑았을때
	{
		// 마지막 재료에서 k개의 재료를 뽑지않은 경우는 버림
		if (L == d + 1)
		{
			if (cnt != k)
			{
				return;
			}
		}

		// k개의 재료를 뽑았을때 몇명이 음식을 먹을 수 있는지 각 학생마다 체크

		int studentCnt = 0; // 음식을 먹을 수 있는 학생 수

		for (int i = 1; i < n + 1; i++)
		{
			bool isEat = true; // 먹을수 있는지 체크

			for (int j = 0; j < students[i].size(); j++)
			{
				if (!vis1[students[i][j]]) // 음식에 하나라도 학생이 좋아하는 재료가 빠지면 먹을수없음
				{
					isEat = false;
					break;
				}
			}

			if (isEat) // 해당 학생이 먹을수있는 음식이면 카운팅
			{
				studentCnt++;
			}
		}

		// 최대학생 수 갱신
		if (maxStuCnt < studentCnt)
		{
			maxStuCnt = studentCnt;
		}
	}
	else
	{
		vis1[L] = true; // 소스 선택
		DFS(L + 1, cnt += 1);
		vis1[L] = false; // 소스 미선택
		DFS(L + 1, cnt -= 1);
	}
}

// 최대 선호 음식
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n >> d >> k;

	// 학생 : N 명, 재료 : D 개, 재료선택 : K 개 이하
	// 최대 몇명의 학생이 음식을 먹을 수 있는지?
	// D 개 중 K 개를 뽑아서 몇명이 먹을 수 있는지 체크

	int sourceCnt; // 소스 개수
	int sourceNum; // 소스 번호

	// 1번 학생부터 연결리스트 기반 선호하는 재료 연결
	/*
	input : 1 1
			2 2 3
			1 3
			2 1 2
			0
			2 2 1
			3 2 3 4
			2 3 4

	graph : 1 -> 1
			2 -> 2 -> 3
			3 -> 3
			4 -> 1 -> 2
			5 
			6 -> 2 -> 1
			7 -> 2 -> 3 -> 4
			8 -> 3 -> 4
	*/
	for (int i = 1; i < n + 1; i++)
	{
		cin >> sourceCnt;

		for (int j = 0; j < sourceCnt; j++) // 소스 개수 만큼 소스를 입력받고 연결
		{
			cin >> sourceNum;

			students[i].push_back(sourceNum);
		}
	}

	// DFS
	DFS(1, 0);

	cout << maxStuCnt << '\n';

	return 0;
}
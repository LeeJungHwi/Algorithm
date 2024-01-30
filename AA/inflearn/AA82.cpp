#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 순열구하기
void GetSequence(int num, vector<int> &nums, vector<bool> &vis, vector<int> &savePickNums, int pickCnt, int r, int n, int &seqCnt)
{
	if (pickCnt == r) // 종료 조건 : r개의 숫자를 뽑으면 종료
	{
		for (int i = 0; i < r; i++)
		{
			cout << savePickNums[i] << ' '; // 뽑은 숫자 출력
		}

		cout << '\n';

		seqCnt++; // 수열 개수 증가
	}
	else
	{
		for (int i = 0; i < n; i++) // n만큼 돌면서
		{
			if (!vis[i]) // 방문하지 않은 경우
			{
				savePickNums[pickCnt] = nums[i]; // 뽑은 숫자 저장
				vis[i] = true; // 방문 체크
				GetSequence(nums[i], nums, vis, savePickNums, pickCnt + 1, r, n, seqCnt);
				vis[i] = false; // 방문 해제
			}
		}
	}
}

// 순열구하기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, r; // N, R 4, 3
	cin >> n >> r;

	int num; // 숫자

	vector<int> nums(n);          // 숫자 저장
	vector<int> savePickNums(r);  // 뽑은 숫자 저장
	vector<bool> vis(n);          // 방문 체크
	int pickCnt = 0;              // 숫자를 뽑은 횟수
	int sequenceCnt = 0;          // 순열 개수

	for (int i = 0; i < n; i++)
	{
		cin >> num;

		nums[i] = num; // 1 3 6 7
	}

	GetSequence(nums[0], nums, vis, savePickNums, pickCnt, r, n, sequenceCnt);

	cout << sequenceCnt << '\n';

	return 0;
}
// 핵심
// 뽑은 숫자 저장
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 순열구하기
void GetSequence()
{

}

// 순열구하기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream cin;
	cin.open("input.txt");

	int n, r; // N, R

	int num; // 숫자

	vector<int> nums(n); // 숫자 저장

	int sequenceCnt = 0; // 순열 개수

	for (int i = 0; i < n; i++)
	{
		cin >> num;

		nums[i] = num;
	}



	return 0;
}
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 가위바위보 결과
// A가 이기는경우
// A    B
// 가위 보
// 바위 가위
// 보   바위
void ResultRockPaperScissors(vector<int> &a, vector<int> &b, int count)
{
	for (int i = 0; i < count; i++) // 가위바위보 횟수만큼 돌면서
	{
		if (a[i] == b[i]) // 비기는경우
		{
			cout << "D\n";
			continue;
		}

		switch (a[i]) // 승패가 결정되는경우
		{
			case 1: // A가 가위일때
				if (b[i] == 3)
				{
					cout << "A\n";
					break;
				}
				cout << "B\n";
				break;
			case 2: // A가 바위일때
				if (b[i] == 1)
				{
					cout << "A\n";
					break;
				}
				cout << "B\n";
				break;
			case 3: // A가 보일때
				if (b[i] == 2)
				{
					cout << "A\n";
					break;
				}
				cout << "B\n";
				break;
		}
	}
}

// 가위바위보
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	vector<int> aRockPaperScissors(101); // A 가위바위보 
	vector<int> bRockPaperScissors(101); // B 가위바위보
	int rockPaperScissors; // 가위바위보

	// A, B 가위바위보 저장
	for (int i = 0; i < n; i++)
	{
		cin >> rockPaperScissors;
		aRockPaperScissors[i] = rockPaperScissors;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> rockPaperScissors;
		bRockPaperScissors[i] = rockPaperScissors;
	}

	ResultRockPaperScissors(aRockPaperScissors, bRockPaperScissors, n);

	return 0;
}
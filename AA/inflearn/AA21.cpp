#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 1. 라운드 결과 내는 함수
void RoundResult(vector<int> &a, vector<int> &b, vector<char> &roundRes)
{
	for (int i = 0; i < 10; i++) // 총 10라운드
	{
		if (a[i] > b[i]) // A가 이기는경우
		{
			roundRes[i] = 'A';
		}
		else if (a[i] < b[i]) // B가 이기는경우
		{
			roundRes[i] = 'B';
		}
		else if (a[i] == b[i]) // 비기는경우
		{
			roundRes[i] = 'D';
		}
	}
}

// 2. A, B 점수 합산 내는 함수
void SumPoint(vector<char> &roundRes, int &a, int &b, char &lastWin)
{
	for (int i = 0; i < 10; i++) // 총 10라운드
	{
		if (roundRes[i] == 'A') // A가 이긴라운드
		{
			a += 3;
			lastWin = 'A';
		}
		else if (roundRes[i] == 'B') // B가 이긴라운드
		{
			b += 3;
			lastWin = 'B';
		}
		else if (roundRes[i] == 'D') // 비긴라운드
		{
			a += 1;
			b += 1;
		}
	}
}

// 3. 최종 결과 내는 함수
void FinalResult(int &a, int &b, char &lastWin)
{
	cout << a << ' ' << b << '\n';

	if (a > b) // A 점수가 높은경우
	{
		cout << 'A' << '\n';
	}
	else if (a < b) // B 점수가 높은경우
	{
		cout << 'B' << '\n';
	}
	else if (a == b) // 점수가 같은경우 -> 전부 비겼거나 승패 개수가 같을 경우
	{
		if (lastWin == 'D') // 전부 비긴경우
		{
			cout << 'D' << '\n';
			return;
		}

		cout << lastWin << '\n'; // 승패 개수가 같은경우
	}
}

// 카드게임
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int num; // 숫자

	vector<int> aNum(10, 0), bNum(10, 0); // A, B 숫자 저장
	
	vector<char> roundResult(10, 0); // 게임 결과

	int aSum = 0, bSum = 0; // A, B 점수 합

	char lastWinner = 'D'; // 마지막에 이긴사람

	// A, B 숫자 저장
	for (int i = 0; i < 10; i++)
	{
		cin >> num;
		aNum[i] = num;
	}
	for (int i = 0; i < 10; i++)
	{
		cin >> num;
		bNum[i] = num;
	}

	// 1. 라운드 결과 내는 함수
	// 2. A, B 점수 합산 함수
	// 3. 최종 결과 내는 함수
	RoundResult(aNum, bNum, roundResult);
	SumPoint(roundResult, aSum, bSum, lastWinner);
	FinalResult(aSum, bSum, lastWinner);

	return 0;
}
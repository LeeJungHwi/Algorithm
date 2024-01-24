#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<int> heights(101); // 키 저장
int cntAngry; // 분노유발자 수
bool isAngry; // 분노유발자 체크

// 분노유발자 수 구하기
void CountAngry(vector<int> &heights, int n)
{
	for (int i = 0; i < n - 1; i++) // 마지막 학생을 제외한 학생수만큼 돌면서
	{
		isAngry = true;

		for (int j = i + 1; j < n; j++) // i번째 학생 기준 뒷자리를 전부 가리면 분노유발자
		{
			if (heights[i] <= heights[j]) // 한명이라도 안 가리면 분노유발자 아님, 키가같으면 안 가려짐
			{
				isAngry = false;
				break;
			}
		}

		if (isAngry)
		{
			cntAngry++;
		}
	}
}

// 분노유발자
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	int height;// 키
	cin >> n;

	// 키 저장
	for (int i = 0; i < n; i++)
	{
		cin >> height;
		heights[i] = height;
	}

	// 분노유발자 구하기
	CountAngry(heights, n);

	cout << cntAngry << '\n';

	return 0;
}

// 핵심
// 벡터 크기 할당 시 인덱스로 대입, 미 할당 시 push_back
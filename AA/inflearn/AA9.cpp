#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 모두의 약수
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // 자연수 N
	cin >> n;

	vector<int> cnts(50001); // 약수 개수

	for (int i = 1; i < n + 1; i++) // 1~N 까지
	{
		for (int j = i; j < n + 1; j = j + i) // i의 배수일때 카운트
		{
			cnts[j - 1]++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << cnts[i] << " ";
	}

	return 0;
}

// 핵심
// 각 수의 약수를 구하는것이 아닌 약수가 되는 수의 배수에 카운트
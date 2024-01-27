#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


// 부분집합 출력함수
void PrintSet(int num, int n, vector<bool> &isEle)
{
	if (num == n + 1) // 부분집합 출력
	{
		for (int i = 0; i < n; i++)
		{
			if (isEle[i])
			{
				cout << i + 1 << ' ';
			}
		}

		cout << '\n';
	}
	else
	{
		// 각 요소를 포함하거나 안하거나로 나눔
		isEle[num - 1] = true;
		PrintSet(num + 1, n, isEle);
		isEle[num - 1] = false;
		PrintSet(num + 1, n, isEle);
	}
}

// 부분집합
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	vector<bool> isElement(n); // 부분집합에 요소가 있는지 체크

	PrintSet(1, n, isElement);

	return 0;
}
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 합이 같은 부분집합 구하기
void SameSumSubSet(int eleIndex, vector<int> &elements, vector<bool> &isEle, bool &exist)
{
	if (eleIndex == elements.size()) // 종료조건 : 인덱스 넘어가면 종료
	{
		int existSum = 0; // 존재하는 요소의 합
		int notExistSum = 0; // 존재하지 않는요소의 합

		for (int i = 0; i < elements.size(); i++) // 부분집합 합과 나머지 원소의 합 구하기
		{
			if (isEle[i])
			{
				existSum += elements[i];
			}
			else
			{
				notExistSum += elements[i];
			}
		}

		// 부분집합 합 체크 : 합이 같은집합 체크, 집합 원소가 중복되지 않아야함
		if (existSum == notExistSum)
		{
			exist = true;
			return;
		}
	}
	else
	{
		isEle[eleIndex] = true; // 요소 포함
		SameSumSubSet(eleIndex + 1, elements, isEle, exist);
		isEle[eleIndex] = false; // 요소 미포함
		SameSumSubSet(eleIndex + 1, elements, isEle, exist);
	}
}

// 합이 같은 부분집합
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	vector<int> elements(n); // 집합 원소 저장
	vector<bool> isEle(n); // 요소가 부분집합에 있는지 체크
	bool isExist = false; // 합이 같은 집합이 존재하는지 체크

	for (int i = 0; i < n; i++)
	{
		cin >> elements[i];
	}

	SameSumSubSet(0, elements, isEle, isExist);

	if (isExist)
	{
		cout << "YES" << '\n';
		return 0;
	}

	cout << "NO" << '\n';

	return 0;
}
// 핵심
// 중복되는 원소가 없어야함
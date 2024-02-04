#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int n, m; // N, M
int elements[11]; // 요소 저장
bool isElement[11]; // 요소가 있는지 체크
bool isPlus[11]; // 요소가 플러스인지 체크
int caseCnt; // m이 만들어지는 경우 개수

// 특정 수 만들기
void MakeNum(int eleIndex, int n)
{
	if (eleIndex == n) // 종료 조건
	{
		int result = 0;

		for (int i = 0; i < n; i++)
		{
			if (isElement[i]) // 요소가 있다면
			{
				result = isPlus[i] ? result + elements[i] : result - elements[i]; // 플러스인지 마이너스인지 체크
			}
		}

		if (m == result) // 만들어지는 경우
		{
			caseCnt++;
		}
	}
	else
	{
		isElement[eleIndex] = true; // 요소 있음
		isPlus[eleIndex] = true; // 요소 플러스
		MakeNum(eleIndex + 1, n);
		isPlus[eleIndex] = false; // 요소 마이너스
		MakeNum(eleIndex + 1, n);
		isElement[eleIndex] = false; // 요소 없음
		MakeNum(eleIndex + 1, n);
	}
}

// 특정 수 만들기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> elements[i];
	}

	// 특정 수 만들기
	MakeNum(0, n);

	if (caseCnt == 0)
	{
		cout << -1 << '\n';

		return 0;
	}

	cout << caseCnt << '\n';

	return 0;
}
// 핵심
// 플러스 마이너스 재귀 추가 -> 시간초과 -> DFS 매개변수를 전역변수로 빼고 벡터 대신 배열 써서 해결

//#include <iostream>
//#include <vector>
//#include <fstream>
//using namespace std;
//
//// 특정 수 만들기
//void MakeNum(int eleIndex, vector<int> &elements, vector<bool> &isEle, vector<bool> &isPlus, int m, int &caseCnt)
//{
//	if (eleIndex == elements.size()) // 종료 조건
//	{
//		int result = 0;
//
//		for (int i = 0; i < elements.size(); i++)
//		{
//			if (isEle[i]) // 요소가 있다면
//			{
//				result = isPlus[i] ? result + elements[i] : result - elements[i]; // 플러스인지 마이너스인지 체크
//			}
//		}
//
//		if (m == result) // 만들어지는 경우
//		{
//			caseCnt++;
//		}
//	}
//	else
//	{
//		isEle[eleIndex] = true; // 요소 있음
//		isPlus[eleIndex] = true; // 요소 플러스
//		MakeNum(eleIndex + 1, elements, isEle, isPlus, m, caseCnt);
//		isPlus[eleIndex] = false; // 요소 마이너스
//		MakeNum(eleIndex + 1, elements, isEle, isPlus, m, caseCnt);
//		isEle[eleIndex] = false; // 요소 없음
//		MakeNum(eleIndex + 1, elements, isEle, isPlus, m, caseCnt);
//	}
//}
//
//// 특정 수 만들기
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	//ifstream cin;
//	//cin.open("input.txt");
//
//	int n, m; // N, M
//	cin >> n >> m;
//
//	vector<int> elements(n); // 요소 저장
//	vector<bool> isElement(n); // 요소가 있는지 체크
//	vector<bool> isPlus(n); // 요소가 플러스인지 체크
//	int caseCnt = 0; // m이 만들어지는 경우 개수
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> elements[i];
//	}
//
//	// 특정 수 만들기
//	MakeNum(0, elements, isElement, isPlus, m, caseCnt);
//
//	if (caseCnt == 0)
//	{
//		cout << -1 << '\n';
//
//		return 0;
//	}
//
//	cout << caseCnt << '\n';
//
//	return 0;
//}
//// 핵심
//// 플러스 마이너스 재귀 추가
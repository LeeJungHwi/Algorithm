#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

// 벽돌 구조체
struct Rock
{
	int area; // 밑넓이
	int height; // 높이
	int weight; // 무게

	Rock() : area(0), height(0), weight(0) {} // 생성자

	Rock(int ar, int he, int we) // 생성자
	{
		area = ar;
		height = he;
		weight = we;
	}

	bool operator<(const Rock &rock)const // 밑넓이 오름차순 정렬
	{
		return area < rock.area;
	}
};

// 가장 높은 탑 쌓기(LIS)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 5
	cin >> n;

	vector<Rock> rocks(n + 1); // 벽돌 저장
	vector<int> heights(n + 1); // 각 벽돌이 마지막일때 높이 최대값 저장

	int area; // 밑넓이
	int height; // 높이
	int weight; // 무게

	for (int i = 1; i < n + 1; i++)
	{
		cin >> area >> height >> weight;

		rocks[i] = Rock(area, height, weight); // (25 3 4) (4 4 6) (9 2 3) (16 2 5) (1 5 2)
	}

	sort(rocks.begin(), rocks.end()); // (1 5 2) (4 4 6) (9 2 3) (16 2 5) (25 3 4)

	// (1 5 2)가 가장 아래 벽돌일때 : (1 5 2) -> 높이 5
	// (4 4 6)이 가장 아래 벽돌일때 : 이전 벽돌을 보면서 자신보다 무게가 낮은것 중 최대높이 + 자신높이 저장 -> (4 4 6) (1 5 2) -> 높이 9
	// (9 2 3)이 가장 아래 벽돌일때 : 이전 벽돌을 보면서 자신보다 무게가 낮은것 중 최대높이 + 자신높이 저장 -> (9 2 3) (1 5 2) -> 높이 7
	// (16 2 5)이 가장 아래 벽돌일때 : 이전 벽돌을 보면서 자신보다 무게가 낮은것 중 최대높이 + 자신높이 저장 -> (16 2 5) (9 2 3) (1 5 2) -> 높이 9
	// (25 3 4)이 가장 아래 벽돌일때 : 이전 벽돌을 보면서 자신보다 무게가 낮은것 중 최대높이 + 자신높이 저장 -> (25 3 4) (9 2 3) (1 5 2) -> 높이 10
	heights[1] = rocks[1].height;
	int result = 0; // 최대 벽돌 높이

	for (int i = 2; i < n + 1; i++)
	{
		int maxHeight = 0;

		for (int j = i - 1; j > 0; j--) // 이전 벽돌을 보면서
		{
			// 자신보다 무게가 낮은것 중 최대높이
			if (rocks[i].weight > rocks[j].weight)
			{
				if (maxHeight < heights[j])
				{
					maxHeight = heights[j];
				}
			}
		}

		// 최대높이 + 자신높이 저장
		heights[i] = maxHeight + rocks[i].height;

		// 최대 벽돌 높이 갱신
		if (result < heights[i])
		{
			result = heights[i];
		}
	}

	cout << result << '\n';

	return 0;
}
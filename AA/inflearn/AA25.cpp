#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 석차 구하기
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	int score; // 점수

	vector<int> originScores(100, 0); // 입력된 순서대로 저장 
	vector<int> sortedScores(100, 0); // 내림차순 정렬 저장

	// 처음 점수 삽입
	cin >> score;
	originScores[0] = score;
	sortedScores[0] = score;

	vector<int>::iterator it = sortedScores.begin(); // 이터레이터

	for (int i = 1; i < n; i++)
	{
		// 입력된 순서대로 저장
		cin >> score;
		originScores[i] = score;

		// 삽입 시 점수에 따라 정렬
		// 5
		// 90 85 92 95 90 -> origin
		// sccore 저장 전 인덱스 0 까지 비교해 삽입되어야할 인덱스 구하기
		// j - 1 점수가 입력된 점수보다 같거나 크면 이동 X
		// j - 1번째 점수가 입력된 점수보다 작으면 이동횟수++
		// 85 -> 90 85
		// 92 -> 92 90 85
		// 95 -> 95 92 90 85
		// 90 -> 95 92 90 90 85 -> sorted

		// 삽입되어야할 인덱스 구하기
		int insertIndex = i;
		for (int j = i - 1; j > -1; j--)
		{
			if (sortedScores[j] < score)
			{
				insertIndex = j;
			}
		}

		// 점수 내림차순 삽입하기
		sortedScores.insert(it + insertIndex, 1, score);

		// 이터레이터 초기화
		it = sortedScores.begin();
	}

	// 디버깅 출력용
	//for (int i = 0; i < originScores.size(); i++)
	//{
	//	cout << originScores[i] << ' ';
	//}

	//cout << '\n';

	//for (int i = 0; i < sortedScores.size(); i++)
	//{
	//	cout << sortedScores[i] << ' ';
	//}

	// 석차 구하기
	// 90 85 92 95 90 -> origin
	// 95 92 90 90 85 -> sorted
	// origin 요소랑 같은 점수를 sorted 에서 찾아 인덱스를 출력함
	// 처음 발견된 점수를 찾으므로 같은 점수는 높은 석차로 자동 출력됨
	// 같은 점수로 동일석차가 나와도 인덱스로 처리하므로 자동으로 그 다음 학생은 동일석차 학생 수 만큼 뒷 등수로 밀려남
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (originScores[i] == sortedScores[j]) // 찾으면 인덱스 출력
			{
				cout << j + 1 << ' ';
				break;
			}
		}
	}

	return 0;
}

// 핵심
// 반복자를 이용한 삽입
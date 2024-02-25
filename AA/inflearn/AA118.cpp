#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <fstream>
using namespace std;

// 학생 구조체
struct Student
{
	int num; // 학생 번호
	int atk; // 학생 공격력
	char team; // 학생이 속한 팀

	Student(int n, int a, char t) : num(n), atk(a), team(t) {} // 생성자

	bool operator<(const Student &student) const // 공격력 오름차순 정렬
	{
		return atk < student.atk;
	}
};

// 전투게임
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream cin;
	cin.open("input.txt");

	int n; // N, 7
	cin >> n;

	long long sumAtk = 0; // 얻는점수 누적
	vector<Student> student; // 학생 정보 저장
	map<char, int> team; // 현재까지 잡힌 각 팀의 공격력
	vector<int> score(n); // 학생이 얻는 점수 저장

	//Input
	//a 17
	//b 12
	//a 10
	//c 11
	//b 24
	//a 25
	//b 12

	char t; // 팀
	int a; // 공격력

	for (int i = 0; i < n; i++)
	{
		cin >> t >> a;
		student.push_back(Student(i, a, t));
	}

	//공격력 기준 오름차순 정렬 nlogn
	//num atk team
	// 2  10  a
	// 3  11  c
	// 1  12  b
	// 6  12  b
	// 0  17  a
	// 4  24  b
	// 5  25  a
	sort(student.begin(), student.end());

	int j = 0; // i가 j를 쫓아감

	for (int i = 1; i < n; i++) // 공격력이 가장낮은 학생은 얻는점수가 없으므로 i가 1부터 돌면서
	{
		for ( ; j < n; j++) // j로 쭉 따라가면서
		{
			if (student[i].atk > student[j].atk) // i보다 공격력이 작으면
			{
				sumAtk += student[j].atk; // j가 잡혀서 점수 누적
				team[student[j].team] += student[j].atk; // 현재까지 잡힌 j팀 점수 누적

				continue;
			}

			// i 자기보다 크지 않으면 break
			break;
		}

		// 각 학생이 얻는 점수 = 자기보다 공격력이 낮은애들 잡아서 얻은 점수 - 현재까지 자기가 속한 팀의 학생을 잡아 얻은 점수
		score[student[i].num] = sumAtk - team[student[i].team];
	}

	// 각 학생이 얻는 점수 출력
	for (int i = 0; i < n; i++)
	{
		cout << score[i] << "\n";
	}

	return 0;
}
// 핵심
// map 사용

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <map>
//#include <algorithm>
//#include <fstream>
//using namespace std;
//
//// 전투 게임
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	//ifstream cin;
//	//cin.open("input.txt");
//
//	int n; // N 7
//	cin >> n;
//
//	vector<pair<char, int> > stuTeam(n + 1); // 각 학생이 속한팀과 공격력 저장
//	map<char, vector<int> > atks; // 각 팀에 속해있는 공격력들 저장
//
//	char team; // 팀
//	int atk; // 공격력
//
//	for (int i = 1; i < n + 1; i++)
//	{
//		//a 17
//		//b 12
//		//a 10
//		//c 11
//		//b 24
//		//a 25
//		//b 12
//		cin >> team >> atk;
//
//		// (a,17) (b,12) (a,10) (c,11) (b,24) (a,25) (b,12)
//		stuTeam[i] = { team,atk };
//
//		//a -> 17 10 25
//		//b -> 12 24 12
//		//c -> 11
//		atks[team].push_back(atk);
//	}
//
//	// 팀이 다른경우 공격력 비교 후 점수 누적
//	for (int i = 1; i < n + 1; i++)
//	{
//		int score = 0; // 점수
//
//		// 다른팀만 공격력 비교 후 점수 누적
//		for (auto it = atks.begin(); it != atks.end(); it++)
//		{
//			if (stuTeam[i].first != it->first) // 팀이 다른경우
//			{
//				for (auto a : it->second) // 각 팀에 속해있는 공격력들을 하나씩 꺼내와서
//				{
//					if (stuTeam[i].second > a) // 공격력이 더 높다면
//					{
//						score += a; // 점수 누적
//					}
//				}
//			}
//		}
//
//		cout << score << '\n';
//	}
//
//	return 0;
//}
//// 핵심
//// map 사용
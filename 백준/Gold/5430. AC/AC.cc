#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

// AC
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// R연산 : 리버스
	// D연산 : 첫요소 삭제, 비어있는데 D연산 수행시 에러

	int t; // 테케 수 4
	cin >> t;

	string command; // 명령어 RDD
	int eleCnt; // 배열 요소 수 4
	string ele; // 배열 요소 저장 [1,2,3,4]

	// 테케 수 만큼
	while (t--)
	{
		cin >> command >> eleCnt >> ele;

		// 숫자만 덱에 저장

		ele += ','; // [1,2,3,4],
		deque<string> d;

		for (int i = 0; i < ele.size(); i++)
		{
			string num;

			// , 가 나올때까지 num에 숫자 저장하고
			for (int j = i; j < ele.size(); j++)
			{
				if (ele[j] == ',')
				{
					i = j;
					break;
				}

				if (isdigit(ele[j]))
				{
					num += ele[j];
				}
			}

			// , 가 나와서 break하면 num을 덱에 저장
			if (!num.empty())
			{
				d.push_back(num);
			}
		}

		// 명령어 수행

		bool isError = false; // 에러인지 체크
		bool isFront = true; // 앞에서부터인지 체크

		for (int i = 0; i < command.size(); i++)
		{
			// 리버스면 뒤집은 상태로
			if (command[i] == 'R')
			{
				if (isFront) // 앞에서부터면 뒤에서부터로
				{
					isFront = false;
				}
				else // 뒤에서부터면 앞에서부터로
				{
					isFront = true;
				}
			}
			else // 딜리트면 첫요소 삭제, 배열이 빈경우 error
			{
				if (d.empty())
				{
					cout << "error" << '\n';
					isError = true;

					break;
				}

				// 앞에서부터면 첫요소 삭제
				// 뒤에서부터면 막요소 삭제
				if (isFront)
				{
					d.pop_front();
				}
				else
				{
					d.pop_back();
				}
			}
		}

		// 에러면 다음 테케로
		if (isError)
		{
			continue;
		}

		// 애초에 입력배열이 [] 이거나
		// D연산으로 숫자가 모두 지워졌으면 [] 출력
		if (ele == "[]" || d.empty())
		{
			cout << "[]" << '\n';

			continue;
		}

		// 에러가 아니므로 배열요소 출력
		if (!d.empty())
		{
			if (isFront) // 앞에서부터면
			{
				// [1
				cout << '[' << d.front();
				d.pop_front();

				// ,2,3,5,8
				while (!d.empty())
				{
					cout << ',' << d.front();
					d.pop_front();
				}

				// ]
				cout << ']' << '\n';
			}
			else // 뒤에서부터면
			{
				// [1
				cout << '[' << d.back();
				d.pop_back();

				// ,2,3,5,8
				while (!d.empty())
				{
					cout << ',' << d.back();
					d.pop_back();
				}

				// ]
				cout << ']' << '\n';
			}
		}
	}

	return 0;
}
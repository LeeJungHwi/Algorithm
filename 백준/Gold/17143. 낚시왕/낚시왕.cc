#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 상어 구조체
struct Shark
{
	pair<int, int> pos; // 상어의 i, j 좌표
	int speed; // 상어가 1초동안 이동하는 칸 수
	int direction; // 상어가 이동하는 방향 상 1 하 2 우 3 좌 4
	int size; // 상어의 크기

	// 생성자
	Shark() {}
	Shark(pair<int, int> p, int s, int d, int z) : pos(p), speed(s), direction(d), size(z) {}
};

// 낚시왕
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// r by c 1-based 행렬
	// 각 칸에는 크기와 속도를 가지는 상어 한마리가 들어있을수있음
	// 1초 동안 일어나는일
	/*
	1.낚시왕이 오른쪽으로 한칸 이동함
	2.낚시왕이 있는 열의 상어 중 땅에서 가장 가까운 상어를 잡음, 상어를 잡으면 잡은 상어가 사라짐
	3.상어가 이동함
	상어는 입력으로 주어진 속도로 이동하며 속도의 단위는 칸/초
	상어가 이동하려고 하는 칸이 경계를 넘으면 방향을 반대로 바꿔서 이동함
	상어가 이동을 마친 후 한칸에 상어가 여러마리면 크기가 가장 큰 상어만 살아남음
	*/

	// 낚시왕이 잡은 상어 크기의 합 구하기

	int r, c, m; // R, C, M 4, 6, 8
	cin >> r >> c >> m;

	vector<vector<Shark> > graph(r + 1, vector<Shark>(c + 1)); // 그래프
	vector<pair<int, int> > checkDir(1); // 상하우좌 1 2 3 4
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, 1 });
	checkDir.push_back({ 0, -1 });

	//	4 1 3 3 8
	//	1 3 5 2 9
	//	2 4 8 4 1
	//	4 5 0 1 4
	//	3 3 1 2 7
	//	1 5 8 4 3
	//	3 6 2 1 2
	//	2 2 2 3 5
	int row, col, speed, direction, size;

	for (int i = 0; i < m; i++)
	{
		cin >> row >> col >> speed >> direction >> size;

		graph[row][col] = Shark({ row, col }, speed, direction, size);
	}

	int time = 0; // c초가 지나면 종료
	int huntSize = 0; // 낚시왕이 잡은 상어의 크기

	while (time != c)
	{
		// 1초 동안 일어나는 일
		// 1.낚시왕이 오른쪽으로 한칸 이동함
		time++;

		// 2.낚시왕이 있는 열의 상어 중 땅에서 가장 가까운 상어를 잡음, 상어를 잡으면 잡은 상어가 사라짐
		for (int i = 1; i < r + 1; i++)
		{
			// 가장 먼저 발견되는 상어를 잡음
			// 낚시왕이 잡은 상어의 크기 누적
			// 잡은 상어는 초기화해서 없앰
			if (graph[i][time].size > 0)
			{
				huntSize += graph[i][time].size;

				graph[i][time] = Shark();

				break;
			}
		}

		//	3.상어가 이동함
		//	상어는 입력으로 주어진 속도로 이동하며 속도의 단위는 칸 / 초
		//	상어가 이동하려고 하는 칸이 경계를 넘으면 방향을 반대로 바꿔서 이동함
		//	상어가 이동을 마친 후 한칸에 상어가 여러마리면 크기가 가장 큰 상어만 살아남음

		vector<Shark> sharks; // 1초 동안 이동을 완료한 상어 저장

		for (int i = 1; i < r + 1; i++)
		{
			for (int j = 1; j < c + 1; j++)
			{
				// 상어가 있는 칸을 발견하면
				if (graph[i][j].size > 0)
				{
					// 상어의 정보를 가져온 후
					int sharkI = graph[i][j].pos.first;
					int sharkJ = graph[i][j].pos.second;
					int sharkSpe = graph[i][j].speed;
					int sharkDir = graph[i][j].direction;

					// 상어의 방향에 따라 처리
					// 더이상 경계를 벗어나지 않을때까지 반복
					while (true)
					{
						if (sharkDir == 1)
						{
							// 상어가 위쪽을 보고있음
							// 위쪽으로 속력만큼 이동했을때 경계를 벗어나면
							// 방향반대, 남은이동칸수감소, i좌표 갱신
							if (sharkI + checkDir[sharkDir].first * sharkSpe < 1)
							{
								sharkDir = 2;
								sharkSpe = sharkSpe - (sharkI - 1);
								sharkI = 1;

								continue;
							}
							
							// 경계를 벗어나지않으면 break
							break;
						}
						else if (sharkDir == 2)
						{
							// 상어가 아래쪽을 보고있음
							// 아래쪽으로 속력만큼 이동했을때 경계를 벗어나면
							// 방향반대, 남은이동칸수감소, i좌표 갱신
							if (sharkI + checkDir[sharkDir].first * sharkSpe > r)
							{
								sharkDir = 1;
								sharkSpe = sharkSpe - (r - sharkI);
								sharkI = r;

								continue;
							}

							// 경계를 벗어나지않으면 break
							break;
						}
						else if (sharkDir == 3)
						{
							// 상어가 오른쪽을 보고있음
							// 오른쪽으로 속력만큼 이동했을때 경계를 벗어나면
							// 방향반대, 남은이동칸수감소, j좌표 갱신
							if (sharkJ + checkDir[sharkDir].second * sharkSpe > c)
							{
								sharkDir = 4;
								sharkSpe = sharkSpe - (c - sharkJ);
								sharkJ = c;

								continue;
							}

							// 경계를 벗어나지않으면 break
							break;
						}
						else if (sharkDir == 4)
						{
							// 상어가 왼쪽을 보고있음
							// 오른쪽으로 속력만큼 이동했을때 경계를 벗어나면
							// 방향반대, 남은이동칸수감소, j좌표 갱신
							if (sharkJ + checkDir[sharkDir].second * sharkSpe < 1)
							{
								sharkDir = 3;
								sharkSpe = sharkSpe - (sharkJ - 1);
								sharkJ = 1;

								continue;
							}

							// 경계를 벗어나지않으면 break
							break;
						}
					}

					// 경계를 벗어나지 않는 남은 이동 칸수 처리
					// 남은 이동 칸수만큼 이동시킴
					if (sharkDir == 1)
					{
						// 위쪽으로
						sharkI = sharkI + checkDir[sharkDir].first * sharkSpe;
					}
					else if (sharkDir == 2)
					{
						// 아래쪽으로
						sharkI = sharkI + checkDir[sharkDir].first * sharkSpe;
					}
					else if (sharkDir == 3)
					{
						// 오른쪽으로
						sharkJ = sharkJ + checkDir[sharkDir].second * sharkSpe;
					}
					else if (sharkDir == 4)
					{
						// 왼쪽으로
						sharkJ = sharkJ + checkDir[sharkDir].second * sharkSpe;
					}

					// 이동을 완료한 상어 정보 저장
					sharks.push_back(Shark({ sharkI, sharkJ }, graph[i][j].speed, sharkDir, graph[i][j].size));

					// 기존 상어의 정보 삭제
					graph[i][j] = Shark();
				}
			}
		}

		// 상어의 이동이 모두 끝나면
		// 이동을 완료한 상어 정보를 하나씩 꺼내서
		// 그래프에 저장하는데 한 칸에 상어가 여러마리면
		// 크기가 큰 상어만 저장됨
		for (int i = 0; i < sharks.size(); i++)
		{
			// 이미 그래프에 저장되어있는 상어의 크기보다 큰 경우만 저장하는식으로 구현
			if (graph[sharks[i].pos.first][sharks[i].pos.second].size < sharks[i].size)
			{
				graph[sharks[i].pos.first][sharks[i].pos.second] = Shark(sharks[i]);
			}
		}
	}

	cout << huntSize << '\n';

	return 0;
}
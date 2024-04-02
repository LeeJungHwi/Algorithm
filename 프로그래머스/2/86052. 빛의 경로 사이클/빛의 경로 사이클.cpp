#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> grid)
{
    vector<int> answer;
    
    // S : 직진
    // L : 좌회전
    // R : 우회전
    // 경계를 넘으면 반대 끝행으로 감
    
    // 빛이 이동할수있는 경로 사이클의 수와 각 사이클의 길이 구하기
    
    // grid : 그래프 
    
    // 그래프 돌면서 각 요소에 대해서 상하좌우로 빛을쏴서 싸이클을 형성하면 길이 저장
    
    vector<vector<char> > graph(grid.size(), vector<char>(grid[0].size())); // 그래프
    vector<vector<vector<int> > > dis(grid.size(), vector<vector<int> >(grid[0].size(), vector<int>(4))); // 거리
    vector<pair<int, int> > checkDir; // 상하좌우
    checkDir.push_back({-1, 0});
    checkDir.push_back({1, 0});
    checkDir.push_back({0, -1});
    checkDir.push_back({0, 1});
    
    // 그래프 초기화
    for(int i = 0; i < graph.size(); i++)
    {
        for(int j = 0; j < graph[0].size(); j++)
        {
            graph[i][j] = grid[i][j];
        }
    }
    
    // 그래프 돌면서
    for(int i = 0; i < graph.size(); i++)
    {
        for(int j = 0; j < graph[0].size(); j++)
        {
            // 각 요소에 대해 상하좌우로 빛을쏨
            for(int k = 0; k < 4; k++)
            {
                // 방문체크
                if(dis[i][j][k] > 0)
                {
                    continue;
                }
                
                // 시작위치
                tuple<int, int, int> startPos = {i, j, k};
                int length = 0;

                while(true)
                {
                    // 시작위치로 돌아오면 break
                    if(dis[get<0>(startPos)][get<1>(startPos)][get<2>(startPos)] > 0)
                    {
                        break;
                    }
                    
                    // 길이증가
                    dis[get<0>(startPos)][get<1>(startPos)][get<2>(startPos)] = length + 1;
                    
                    // 체크 할 위치
                    get<0>(startPos) = (get<0>(startPos) + checkDir[get<2>(startPos)].first + graph.size()) % graph.size();
                    get<1>(startPos) = (get<1>(startPos) + checkDir[get<2>(startPos)].second + graph[0].size()) % graph[0].size();

                    // 방향회전 -> L과 R만
                    if(graph[get<0>(startPos)][get<1>(startPos)] == 'L')
                    {
                        if(get<2>(startPos) == 0) // 상이면 좌로
                        {
                            get<2>(startPos) = 2;
                        }
                        else if(get<2>(startPos) == 1) // 하면 우로
                        {
                            get<2>(startPos) = 3;
                        }
                        else if(get<2>(startPos) == 2) // 좌면 하로
                        {
                            get<2>(startPos) = 1;
                        }
                        else if(get<2>(startPos) == 3) // 우면 상으로
                        {
                            get<2>(startPos) = 0;
                        }
                    }
                    else if(graph[get<0>(startPos)][get<1>(startPos)] == 'R')
                    {
                        if(get<2>(startPos) == 0) // 상이면 우로
                        {
                            get<2>(startPos) = 3;
                        }
                        else if(get<2>(startPos) == 1) // 하면 좌로
                        {
                            get<2>(startPos) = 2;
                        }
                        else if(get<2>(startPos) == 2) // 좌면 상으로
                        {
                            get<2>(startPos) = 0;
                        }
                        else if(get<2>(startPos) == 3) // 우면 하로
                        {
                            get<2>(startPos) = 1;
                        } 
                    }
                    
                    // 길이증가
                    length++;
                }
                
                // 사이클 경로 길이 저장
                answer.push_back(length);
            }
        }
    }
    
    // 오름차순 정렬
    sort(answer.begin(), answer.end());
    
    return answer;
}
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> maps)
{
    vector<int> answer;
    
    // maps : 그래프, X(바다) 숫자(머무를 수 있는 일 수)
    // answer : 각 섬에서 머무를 수 있는 일 수를 저장하고 오름차순 정렬, 섬이 없으면 -1 저장
    
    // 그냥 BFS 영역 개수와 크기 문제인데?
    
    vector<vector<int> > graph(maps.size(), vector<int>(maps[0].size())); // 그래프
    vector<vector<bool> > vis(maps.size(), vector<bool>(maps[0].size())); // 방문체크
    queue<pair<int, int> > checkPos; // 체크 할 위치
    vector<pair<int, int> > checkDir; // 상하좌우
    checkDir.push_back({-1, 0});
    checkDir.push_back({1, 0});
    checkDir.push_back({0, -1});
    checkDir.push_back({0, 1});
    
    // 40 5 9 1 40 
    // 40 1 40 5 40 
    // 40 2 3 1 40 
    // 1 40 40 40 1
    for(int i = 0; i < maps.size(); i++)
    {
        for(int j = 0; j < maps[i].size(); j++)
        {
            graph[i][j] = maps[i][j] - '0';
        }
    }
    
    // // 디버깅용
    // for(auto a : graph)
    // {
    //     for(auto b : a)
    //     {
    //         cout << b << ' ';
    //     }
    //     cout << '\n';
    // }
    
    // BFS
    
    for(int i = 0; i < maps.size(); i++) // 그래프 돌면서
    {
        for(int j = 0; j < maps[i].size(); j++)
        {
            if(graph[i][j] != 40 && !vis[i][j]) // X가 아니면서 방문하지않은 숫자를 만나면
            {
                // 해당영역부터 BFS 돌림
                checkPos.push({i, j});
                vis[i][j] = true;
                int areaSize = graph[i][j];
                
                while(!checkPos.empty()) // 큐가 빌때까지
                {
                    // 기준위치 꺼냄
                    pair<int, int> standardPos = checkPos.front();
                    checkPos.pop();
                    
                    // 상하좌우
                    for(int k = 0; k < 4; k++)
                    {
                        // 체크 할 위치
                        int checkI = standardPos.first + checkDir[k].first;
                        int checkJ = standardPos.second + checkDir[k].second;
                        
                        // 경계체크
                        if(checkI < 0 || checkJ < 0 || checkI >= maps.size() || checkJ >= maps[0].size())
                        {
                            continue;
                        }
                        
                        // 방문체크
                        if(vis[checkI][checkJ])
                        {
                            continue;
                        }
                        
                        // 바다체크
                        if(graph[checkI][checkJ] == 40)
                        {
                            continue;
                        }
                        
                        // 큐에저장 방문체크 영역크기증가
                        checkPos.push({checkI, checkJ});
                        vis[checkI][checkJ] = true;
                        areaSize += graph[checkI][checkJ];
                    }
                }
                
                // answer에 영역크기 저장
                answer.push_back(areaSize);
            }
        }
    }
    
    // 저장된 영역크기가 없으면 -1
    if(answer.empty())
    {
        answer.push_back(-1);
        
        return answer;
    }
    
    // 저장된 영역크기가 있으면 오름차순 정렬
    sort(answer.begin(), answer.end());
    
    return answer;
}
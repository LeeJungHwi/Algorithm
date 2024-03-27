#include<vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    // 디버깅용
    // for(auto a : maps)
    // {
    //     for(auto b : a)
    //     {
    //         cout << b << ' ';
    //     }
    //     cout << '\n';
    // }
    
    // maps : 그래프 0(벽) 1(길)
    // (1,1)에서(n,m)까지 최단거리 구하기
    
    vector<vector<int> > dis(maps.size(), vector<int>(maps[0].size())); // 거리
    queue<pair<int, int> > checkPos; // 체크 할 위치
    vector<pair<int, int> > checkDir; // 상하좌우
    checkDir.push_back({-1, 0});
    checkDir.push_back({1, 0});
    checkDir.push_back({0, -1});
    checkDir.push_back({0, 1});
    
    // (0,0)부터 BFS 돌림
    checkPos.push({0,0});
    dis[0][0] = 1;
    
    while(!checkPos.empty()) // 큐가 빌때까지
    {
        // 기준위치 꺼냄
        pair<int, int> standardPos = checkPos.front();
        checkPos.pop();
        
        // 상하좌우
        for(int i = 0; i < 4; i++)
        {
            // 체크 할 위치
            int checkI = standardPos.first + checkDir[i].first;
            int checkJ = standardPos.second + checkDir[i].second;
            
            // 경계체크
            if(checkI < 0 || checkJ < 0 || checkI >= maps.size() || checkJ >= maps[0].size())
            {
                continue;
            }
            
            // 방문체크
            if(dis[checkI][checkJ] > 0)
            {
                continue;
            }            
            
            // 벽체크
            if(maps[checkI][checkJ] == 0)
            {
                continue;
            }
            
            // 큐에저장, 거리저장
            checkPos.push({checkI, checkJ});
            dis[checkI][checkJ] = dis[standardPos.first][standardPos.second] + 1;
        }
    }
    
    // 거리가 저장되어있지않으면 갈수없으므로 -1
    if(dis[maps.size() - 1][maps[0].size() - 1] == 0)
    {
        answer = -1;
        return answer;
    }
    
    // 갈수있으면 거리
    answer = dis[maps.size() - 1][maps[0].size() - 1];
    return answer;
}
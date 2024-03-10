#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes)
{
    vector<int> answer;
    
    // park : 공원을 나타내는 문자열 배열 S(시작점) O(길) X(벽)
    // routes : 로봇이 수행할 명령이 담긴 문자열 배열 N(북) S(남) W(서) E(동)
    // 모든 명령 수행 후 로봇의 위치
    
    vector<pair<int, int> > checkDir; // 상하좌우
    checkDir.push_back({-1, 0});
    checkDir.push_back({1, 0});
    checkDir.push_back({0, -1});
    checkDir.push_back({0, 1});
    
    // park 돌면서 시작지점 구하기
    
    pair<int, int> startPos = {0, 0};
    
    for(int i = 0; i < park.size(); i++)
    {
        for(int j = 0; j < park[0].size(); j++)
        {
            if(park[i][j] == 'S')
            {
                startPos = {i, j};
            }
        }
    }
    
    // 명령어 수 만큼 돌면서
    // 방향에 따라 이동횟수만큼 한칸씩 가보면서
    // 1. 경계체크
    // 2. 벽체크
    // 3. 로봇위치 갱신
    
    for(int i = 0; i < routes.size(); i++)
    {
        int checkI = 0;
        int checkJ = 0;
        bool canGo = true; // 갈수있는지 체크
        
        if(routes[i][0] == 'N') // 상
        {
            // 체크 할 위치
            for(int j = 1; j < routes[i][2] - '0' + 1; j++)
            {
                checkI = startPos.first + checkDir[0].first * j;
                checkJ = startPos.second + checkDir[0].second * j;
                
                // 경계체크
                if(checkI < 0 || checkJ < 0 || checkI >= park.size() || checkJ >= park[0].size())
                {
                    canGo = false;
                    break;
                }
                
                // 벽체크
                if(park[checkI][checkJ] == 'X')
                {
                    canGo = false;
                    break;   
                }
            }
        }
        else if(routes[i][0] == 'S') // 하
        {
            // 체크 할 위치
            for(int j = 1; j < routes[i][2] - '0' + 1; j++)
            {
                checkI = startPos.first + checkDir[1].first * j;
                checkJ = startPos.second + checkDir[1].second * j;
                
                // 경계체크
                if(checkI < 0 || checkJ < 0 || checkI >= park.size() || checkJ >= park[0].size())
                {
                    canGo = false;
                    break;
                }
                
                // 벽체크
                if(park[checkI][checkJ] == 'X')
                {
                    canGo = false;
                    break;   
                }
            }
        }
        else if(routes[i][0] == 'W') // 좌
        {
            // 체크 할 위치
            for(int j = 1; j < routes[i][2] - '0' + 1; j++)
            {
                checkI = startPos.first + checkDir[2].first * j;
                checkJ = startPos.second + checkDir[2].second * j;
                
                // 경계체크
                if(checkI < 0 || checkJ < 0 || checkI >= park.size() || checkJ >= park[0].size())
                {
                    canGo = false;
                    break;
                }
                
                // 벽체크
                if(park[checkI][checkJ] == 'X')
                {
                    canGo = false;
                    break;   
                }
            }
        }
        else if(routes[i][0] == 'E') // 우
        {
            // 체크 할 위치
            for(int j = 1; j < routes[i][2] - '0' + 1; j++)
            {
                checkI = startPos.first + checkDir[3].first * j;
                checkJ = startPos.second + checkDir[3].second * j;
                
                // 경계체크
                if(checkI < 0 || checkJ < 0 || checkI >= park.size() || checkJ >= park[0].size())
                {
                    canGo = false;
                    break;
                }
                
                // 벽체크
                if(park[checkI][checkJ] == 'X')
                {
                    canGo = false;
                    break;   
                }
            }
        }
        
        // 갈수있을때만 로봇위치 갱신
        if(canGo)
        {
            startPos = {checkI, checkJ};
        }
    }
    
    // 명령어 수행이 모두 끝난 후 로봇위치 저장
    answer.push_back(startPos.first);
    answer.push_back(startPos.second);
    
    return answer;
}
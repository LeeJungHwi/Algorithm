#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand)
{
    string answer = "";
    
    // 왼손엄지 : *에서 시작
    // 오른손엄지 : #에서 시작
    // 엄지 사용규칙
    // 1.상하좌우 이동, 이동 한칸은 거리 1
    // 2.1 4 7은 왼손엄지를 사용함
    // 3.3 6 9는 오른손엄지를 사용함
    // 4.2 5 8 0은 더 가까운 엄지를 사용함
    // 만약 거리가 같다면 오른손잡이는 오른손 왼손잡이는 왼손을 사용함
    
    // numbers : 순서대로 누를 번호가 담긴 배열
    // band : 왼손잡이인지 오른손잡이인지 나타내는 문자열
    // answer : 순서대로 누른 번호를 어느손이 눌렀는지 저장 L or R
    
    // numbers 돌면서
    // 1 4 7 이면 answer에 L 저장 후 LeftHand 위치 1 4 7로 이동
    // 3 6 9 이면 answer에 R 저장 후 RightHand 위치 3 6 9로 이동
    // 2 5 8 0 이면 BFS 돌면서 먼저도착한 손 저장 후 손 위치 2 5 8 0로 이동
    
    vector<vector<int> > graph(4, vector<int>(3)); // 그래프
    queue<pair<int, int> > checkPos; // 체크 할 위치
    vector<pair<int, int> > checkDir; // 상하좌우
    checkDir.push_back({-1, 0});
    checkDir.push_back({1, 0});
    checkDir.push_back({0, -1});
    checkDir.push_back({0, 1});
    
    // 1 2 3
    // 4 5 6
    // 7 8 9
    // 10 0 11
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            graph[i][j] = (j + 1) + 3 * i;
        }
    }
    
    graph[3][0] = 10; // *
    graph[3][1] = 0;
    graph[3][2] = 11; // #
    
    // 디버깅용
    // for(auto a : graph)
    // {
    //     for(auto b : a)
    //     {
    //         cout << b << ' ';
    //     }
    //     cout << '\n';
    // }
    
    // numbers 돌면서
    // 1 4 7 이면 answer에 L 저장 후 LeftHand 위치 1 4 7로 이동
    // 3 6 9 이면 answer에 R 저장 후 RightHand 위치 3 6 9로 이동
    // 2 5 8 0 이면 BFS 돌면서 먼저도착한 손 저장 후 손 위치 2 5 8 0로 이동
    
    pair<int, int> leftHand = {3, 0};
    pair<int, int> rightHand = {3, 2};
    
    for(int i = 0; i < numbers.size(); i++)
    {
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            answer += 'L';
            
            for(int j = 0; j < 4; j++)
            {
                for(int k = 0; k < 3; k++)
                {
                    if(graph[j][k] == numbers[i])
                    {
                        leftHand = {j, k};
                    }
                }
            }
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            answer += 'R';
            
            for(int j = 0; j < 4; j++)
            {
                for(int k = 0; k < 3; k++)
                {
                    if(graph[j][k] == numbers[i])
                    {
                        rightHand = {j, k};
                    }
                }
            }     
        }
        else if(numbers[i] == 2 || numbers[i] == 5 || numbers[i] == 8 || numbers[i] == 0)
        {
            // -> 왼손먼저 BFS 돌리고 pressHand를 왼손으로 저장해둠
            // -> 오른손 BFS 돌리면서 오른손이 더 빨리 도착했으면 pressHand 오른손으로 변경함
            
            vector<vector<int> > disL(4, vector<int>(3)); // 왼손 거리
            vector<vector<int> > disR(4, vector<int>(3)); // 오른손 거리
            
            // 왼손먼저 BFS
            char pressHand = 'L';
            checkPos.push(leftHand);
            disL[leftHand.first][leftHand.second] = 1;
            
            while(!checkPos.empty()) // 큐가 빌때까지
            {
                // 기준위치 꺼냄
                pair<int, int> standardPos = checkPos.front();
                checkPos.pop();
                
                // 상하좌우
                for(int j = 0; j < 4; j++)
                {
                    // 체크 할 위치
                    int checkI = standardPos.first + checkDir[j].first;
                    int checkJ = standardPos.second + checkDir[j].second;
                    
                    // 경계체크
                    if(checkI < 0 || checkJ < 0 || checkI >= 4 || checkJ >= 3)
                    {
                        continue;
                    }
                    
                    // 방문체크(거리로)
                    if(disL[checkI][checkJ] > 0)
                    {
                        continue;
                    }
                    
                    // 큐에추가 거리저장
                    checkPos.push({checkI, checkJ});
                    disL[checkI][checkJ] = disL[standardPos.first][standardPos.second] + 1;
                }
            }
            
            // 오른손 BFS 돌리면서
            checkPos.push(rightHand);
            disR[rightHand.first][rightHand.second] = 1;
            
            while(!checkPos.empty()) // 큐가 빌때까지
            {
                // 기준위치 꺼냄
                pair<int, int> standardPos = checkPos.front();
                checkPos.pop();
                
                // 상하좌우
                for(int j = 0; j < 4; j++)
                {
                    // 체크 할 위치
                    int checkI = standardPos.first + checkDir[j].first;
                    int checkJ = standardPos.second + checkDir[j].second;
                    
                    // 경계체크
                    if(checkI < 0 || checkJ < 0 || checkI >= 4 || checkJ >= 3)
                    {
                        continue;
                    }
                    
                    // 방문체크(거리로)
                    if(disR[checkI][checkJ] > 0)
                    {
                        continue;
                    }
                    
                    // 큐에추가 거리저장
                    checkPos.push({checkI, checkJ});
                    disR[checkI][checkJ] = disR[standardPos.first][standardPos.second] + 1;
                }
            }
            
            // 오른손이 더 빨리 도착했으면 pressHand 오른손으로 변경함
            
            pair<int, int> pressPos; // 누른번호 위치
            
            for(int j = 0; j < 4; j++)
            {
                for(int k = 0; k < 3; k++)
                {
                    if(graph[j][k] == numbers[i])
                    {
                        pressPos = {j, k};
                    }
                }
            }    
            
            // 거리가 같으면 hand에 따라서 answer에 저장 후 누른번호 위치로 손 이동
            if(disL[pressPos.first][pressPos.second] == disR[pressPos.first][pressPos.second])
            {
                if(hand == "left")
                {
                    answer += 'L';
                    leftHand = pressPos;
                }
                else if(hand == "right")
                {
                    answer += 'R';
                    rightHand = pressPos;
                }
            }
            else // 거리가 다르면 최단거리 손을 answer에 저장 후 누른번호 위치로 손 이동
            {
                answer += disL[pressPos.first][pressPos.second] < disR[pressPos.first][pressPos.second] ? 'L' : 'R';
                disL[pressPos.first][pressPos.second] < disR[pressPos.first][pressPos.second] ? leftHand = pressPos : rightHand = pressPos;
            }
        }
    }
    
    return answer;
}
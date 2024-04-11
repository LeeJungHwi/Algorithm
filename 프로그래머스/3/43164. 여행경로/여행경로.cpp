#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, map<string, int>> ticketMap; // (출발도시, 도착도시들맵) 맵핑

// DFS
bool DFS(string curCity, int L, int ticketCnt, vector<string> &ans)
{
    if(L == ticketCnt) // 종료조건 : 모든 티켓을 사용한경우
    {
        return true;
    }
    else
    {
        // 3.각 현재도시에 맵핑된 도착도시들 중 사전순으로 가장 앞서는 도시를 갈수있는지 체크
        // 현재도시부터
        for(auto it = ticketMap[curCity].begin(); it != ticketMap[curCity].end();)
        {
            // 선택
            ans.push_back(it->first);
            string backUpNextCity = it->first; // 도착도시 백업
            it->second--;
            
            // 도착도시에서 갈수있는 도착도시가 없으면 다음도시로
            // 갈수있는 도착도시가 있으면 현재도착도시로 감
            it = it->second > 0 ? ++it : ticketMap[curCity].erase(it);
            
            bool check = DFS(backUpNextCity, L + 1, ticketCnt, ans);
            
            // 모든 티켓을 사용한경우 종료
            if(check)
            {
                return true;
            }
            
            // 미선택
            ticketMap[curCity][backUpNextCity]++;
            ans.pop_back();
        }

        return false;
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer;

    // tickets : 항공권 티켓
    // answer : 방문하는 공항경로
    
    // 1.tickets 돌면서 (출발도시, 도착도시들맵) 맵핑
    // 2.현재도시를 ICN 부터 시작
    // 3.각 현재도시에 맵핑된 도착도시들 중 사전순으로 가장 앞서는 도시를 갈수있는지 체크
    
    // 1.tickets 돌면서 (출발도시, 도착도시들맵) 맵핑
    for(int i = 0; i < tickets.size(); i++)
    {
        ticketMap[tickets[i][0]][tickets[i][1]]++;
    }
    
    // 2.현재도시를 ICN 부터 시작
    string startCity = "ICN";
    answer.push_back("ICN");
    
    // DFS
    DFS(startCity, 0, tickets.size(), answer);

    return answer;
}

// #include <string>
// #include <vector>
// #include <map>
// #include <iostream>
// #include <algorithm>

// using namespace std;

// string curCity; // 현재도시
// map<string, map<string, int>> ticketMap; // (출발도시, 도착도시들맵) 맵핑

// // DFS
// void DFS(vector<string> &ans, int ticketCnt)
// {
//     if(ans.size() == ticketCnt + 1) // 종료조건 : 모든 티켓을 사용한경우
//     {
//         return;
//     }
//     else
//     {
//         // 3.각 현재도시에 맵핑된 도착도시들 중 사전순으로 가장 앞서는 도시를 갈수있는지 체크
//         // 현재도시부터
//         for(auto it = ticketMap[curCity].begin(); it != ticketMap[curCity].end(); it++)
//         {
//             // 갈수있는 도시들을 보면서
//             if(it->second > 0)
//             {
//                 // 선택
//                 it->second--;
//                 ans.push_back(it->first);
//                 curCity = it->first;
                
//                 DFS(ans, ticketCnt);
                
//                 // 모든 티켓을 사용한경우 종료
//                 if(ans.size() == ticketCnt + 1)
//                 {
//                     return;
//                 }
                
//                 // 미선택
//                 ans.pop_back();
//                 it->second++;
//             }
//         }
//     }
// }

// vector<string> solution(vector<vector<string>> tickets)
// {
//     vector<string> answer;
    
//     // tickets : 항공권 티켓
//     // answer : 방문하는 공항경로
    
//     // 1.tickets 돌면서 (출발도시, 도착도시들맵) 맵핑
//     // 2.현재도시를 ICN 부터 시작
//     // 3.각 현재도시에 맵핑된 도착도시들 중 사전순으로 가장 앞서는 도시를 갈수있는지 체크
    
//     // 1.tickets 돌면서 (출발도시, 도착도시들맵) 맵핑
//     for(int i = 0; i < tickets.size(); i++)
//     {
//         ticketMap[tickets[i][0]][tickets[i][1]]++;
//     }
    
//     // 2.현재도시를 ICN 부터 시작
//     curCity = "ICN";
//     answer.push_back("ICN");
    
//     // DFS
//     DFS(answer, tickets.size());
    
//     return answer;
// }
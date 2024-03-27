#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer;
    
    // 각 차량의 주차요금
    // 1.기본시간 이하면 기본요금
    // 2.기본시간 초과시 기본요금 + ((주차시간 - 기본시간) / 단위시간) 올림 * 단위요금
    // fees : [0] 기본시간 [1] 기본요금 [2] 단위시간 [3] 단위요금
    // records : 00:00 시간 0000 번호 IN/OUT 입차
    
    // 1-1.records 돌면서 값 == 0이면 (번호,시각) 맵핑, 값 > 0이면 (시각 - 값)을 (번호, 누적주차시간) 맵핑
    // 1-2.맵 돌면서 아직 시각이 있으면 마지막까지 나가지않았으므로 (23:59 - 값)을 (번호, 누적주차시간) 맵핑
    // 2-1.누적주차시간이 기본시간이하면 (차량번호, 기본요금) 맵핑
    // 2-2.누적주차시간이 기본시간초과면 (차량번호, 기본요금 + ((주차시간 - 기본시간) / 단위시간) 올림 * 단위요금) 맵핑
    // 3.맵 돌면서 answer에 추가
    
    // 1-1.records 돌면서 값 == 0이면 시각 맵핑, 값 > 0이면 (시각 - 값)을 (번호, 누적주차시간) 맵핑
    // 1-2.맵 돌면서 아직 시각이 있으면 마지막까지 나가지않았으므로 (23:59 - 값)을 (번호, 누적주차시간) 맵핑
    
    map<string, pair<int, bool> > inOrOut; // (번호, (시각, 1입차0출차) 맵핑
    map<string, int> parkTime; // (번호, 누적주차시간) 맵핑
    
    string carNum = ""; // 번호
    int sigack = 0; // 시각
    
    for(int i = 0; i < records.size(); i++) // records 돌면서 
    {
        carNum = records[i].substr(6, 4); // 번호
        sigack = stoi(records[i].substr(0, 2)) * 60 + stoi(records[i].substr(3, 2)); // 시각
        
        if(records[i].substr(11, 2) == "IN") // IN 이면
        {
            // (번호, (시각, IN)) 맵핑
            inOrOut[carNum].first = sigack;
            inOrOut[carNum].second = 1;
            
            //디버깅용
            //cout << sigack << '\n'; 
        }
        else // OUT 이면
        {
            //디버깅용
            //cout << inOrOutTime[carNum] << ' ' << sigack << '\n';
            
            parkTime[carNum] += sigack - inOrOut[carNum].first; // (시각 - 값)을 (번호, 누적주차시간) 맵핑
            
            // (번호, (0, OUT)) 맵핑
            inOrOut[carNum].first = 0;
            inOrOut[carNum].second = 0;
        }
    }
    
    for(auto it = inOrOut.begin(); it != inOrOut.end(); it++) // 맵 돌면서
    {
        if(it->second.second == 1) // 아직 IN이 있으면
        {
            parkTime[it->first] += 1439 - it->second.first; // 마지막까지 나가지않았으므로 (23:59 - 값)을 (번호, 누적주차시간) 맵핑
        }
    }
    
    // 2-1.누적주차시간이 기본시간이하면 (차량번호, 기본요금) 맵핑
    // 2-2.누적주차시간이 기본시간초과면 (차량번호, 기본요금 + ((주차시간 - 기본시간) / 단위시간) 올림 * 단위요금) 맵핑
    
    map<string, int> fee; // (번호, 요금) 맵핑
    
    for(auto it = parkTime.begin(); it != parkTime.end(); it++)
    {
        if(it->second <= fees[0]) // 누적주차시간이 기본시간이하면 
        {
            fee[it->first] = fees[1]; // (번호, 기본요금) 맵핑
        }
        else // 누적주차시간이 기본시간초과면
        {
            if((it->second - fees[0]) % fees[2] == 0) // 나누어 떨어지면
            {
                fee[it->first] = fees[1] + ((it->second - fees[0]) / fees[2]) * fees[3]; // (차량번호, 기본요금 + ((주차시간 - 기본시간) / 단위시간) * 단위요금) 맵핑
            }
            else // 올림 필요하면
            {
                fee[it->first] = fees[1] + ((it->second - fees[0]) / fees[2] + 1) * fees[3];// (차량번호, 기본요금 + ((주차시간 - 기본시간) / 단위시간) 올림 * 단위요금) 맵핑
            }
        }
    }
    
    // 3.맵 돌면서 answer에 추가
    for(auto it = fee.begin(); it != fee.end(); it++)
    {
        answer.push_back(it->second);
    }
    
    return answer;
}
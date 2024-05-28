#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    
    // record : 각 요소 => 행동, id, 닉네임
    // id, 닉네임 맵핑
    // id, (순서, 행동) 맵핑
    // 순서, (id, 행동)
    // answer에 닉네임 + "님이 " + Enter면 "들어왔습니다." Leave면 "나갔습니다." 저장
    
    map<string, string> inMap;
    map<string, map<int, string> > ioaMap;
    map<int, pair<string, string> > oiaMap;
    
    // 행동, id, 닉네임 구하기
    string act;
    string userId;
    string nickName;
    for(int i = 0; i < record.size(); i++)
    {
        record[i] += ' ';
        string temp = "";
        bool isId = false;
        
        // 행동
        if(record[i][0] != 'C') act = record[i].substr(0, 5);
        else act = record[i].substr(0, 6);
        
        // id, 닉네임
        for(int j = record[i][0] != 'C' ? 6 : 7; j < record[i].size(); j++)
        {
            if(record[i][j] == ' ')
            {
                if(!isId)
                {
                    isId = true;
                    userId = temp;
                    temp.clear();
                    continue;
                }
                else
                {
                    nickName = temp;
                    continue;
                }
            }
            
            temp += record[i][j];
        }
        
        //cout << act << ' ' << userId << ' ' << nickName << '\n';
        
        // id, 닉네임 맵핑
        // id, (순서, 행동) 맵핑
        // 순서, (id, 행동)
        // answer에 닉네임 + "님이 " + Enter면 "들어왔습니다." Leave면 "나갔습니다." 저장
        if(act != "Leave") inMap[userId] = nickName;
        ioaMap[userId][i + 1] = act;
        if(act != "Change") oiaMap[i + 1] = {userId, act};
    }
    
    for(auto it = oiaMap.begin(); it != oiaMap.end(); it++)
    {
        string insertString = inMap[it->second.first];
        insertString += "님이 ";
        insertString += ioaMap[it->second.first][it->first] == "Enter" ? "들어왔습니다." : "나갔습니다.";
        answer.push_back(insertString);
    }
    
    return answer;
}
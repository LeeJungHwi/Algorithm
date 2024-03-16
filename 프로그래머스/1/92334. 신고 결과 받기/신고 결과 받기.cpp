#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer;
    
    // 1.각 유저는 한번에 한명의 유저만 신고가능함
    // 신고횟수 제한없음, 한 유저를 여러번 신고해도 신고횟수는 1회로 처리됨
    // 2.k번이상 신고된 유저는 게시판 이용이 정지되며 해당유저를 신고한 모든 유저에게 정지사실메일이 발송됨
    // 유저가 신고한 모든내용을 취합하고 마지막에 한꺼번에 정지시키고 메일을 발송함
    
    // id_list : 게시판 이용자의 id 배열
    // report : 각 이용자가 신고한 이용자의 id 배열
    // k : 정지 기준이 되는 신고횟수
    // answer : 각 이용자가 메일을 받은 횟수
    
    // 1.
    // report를 돌면서
    // (신고한사람, 신고당한사람들) 맵핑
    // (신고당한사람, 신고한사람들) 맵핑
    
    // 2.
    // id_list를 돌면서 얘가 신고한사람을 쭉 보면서
    // 걔를 신고한사람이 k명 이상이면 카운팅해서 answer에 저장
    
    map<string, set<string> > m1; // (신고한사람, 신고당한사람들) 맵핑
    map<string, set<string> > m2; // (신고당한사람, 신고한사람들) 맵핑
    
    // report 돌면서
    // (신고한사람, 신고당한사람들) 맵핑
    // (신고당한사람, 신고한사람들) 맵핑
    for(int i = 0; i < report.size(); i++)
    {
        string reportingPerson; // 신고한사람
        string reportedPerson; // 신고당한사람
        int flag = 1; // 1 : 신고한사람, 2 : 신고당한사람
        
        // 신고한사람 및 신고당한사람 구하기
        for(int j = 0; j < report[i].size(); j++)
        {
            if(report[i][j] != ' ' && flag == 1)
            {
                reportingPerson += report[i][j];
                
                continue;
            }
            else if(flag == 1)
            {
                j++;
                flag++;
            }
            
            reportedPerson += report[i][j];
        }
    
        // 디버깅용
        // cout << reportingPerson << ' ' << reportedPerson << '\n';;
        
        m1[reportingPerson].insert(reportedPerson); // (신고한사람, 신고당한사람들) 맵핑
        m2[reportedPerson].insert(reportingPerson); // (신고당한사람, 신고한사람들) 맵핑
    }

//     디버깅용
//     for(auto it = m1.begin(); it != m1.end(); it++)
//     {
//         cout << it->first << '\n';

//         for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
//         {
//             cout << *it2 << ' ';
//         }

//         cout << '\n';
//     }
    
//     디버깅용
//     for(auto it = m2.begin(); it != m2.end(); it++)
//     {
//         cout << it->first << ' ' << it->second << '\n';
//     }
    
    // id_list를 돌면서 얘가 신고한사람을 쭉 보면서
    // 걔를 신고한사람이 k명 이상이면 카운팅해서 answer에 저장
    for(int i = 0; i < id_list.size(); i++)
    {
        int mailCnt = 0;
        
        for(auto it = m1[id_list[i]].begin(); it != m1[id_list[i]].end(); it++)
        {
            if(m2[*it].size() >= k)
            {
                mailCnt++;
            }
        }
        
        answer.push_back(mailCnt);
    }
        
    return answer;
}
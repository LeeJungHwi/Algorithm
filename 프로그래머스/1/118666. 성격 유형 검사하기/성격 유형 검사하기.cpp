#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<string> survey, vector<int> choices)
{
    string answer = "";
    
    // survey : 각 질문에 대해 판단하는 지표 배열
    // choices : 각 질문에 대해 선택한 선택지 배열
    
    // survey 돌면서 choice에 따라 (성격유형, 점수) 맵핑
    // RT, CF, JM, AN 지표를 비교해서
    // 두 유형의 점수가 같지않으면 큰수의 성격유형을 answer에 추가
    // 두 유형의 점수가 같으면 앞쪽의 성격유형을 answer에 추가
    
    map<char, int> personality;
    
    for(int i = 0; i < survey.size(); i++)
    {
        // 이건 앞쪽유형이 점수를 먹음
        if(choices[i] < 4)
        {
            personality[survey[i][0]] += 4 - choices[i];
            continue;
        }

        // 이건 뒤쪽유형이 점수를 먹음
        if(choices[i] > 4)
        {
            personality[survey[i][1]] += choices[i] - 4;
        }
    }
    
    answer += personality['R'] < personality['T'] ? 'T' : 'R';
    answer += personality['C'] < personality['F'] ? 'F' : 'C';
    answer += personality['J'] < personality['M'] ? 'M' : 'J';
    answer += personality['A'] < personality['N'] ? 'N' : 'A';
    
    // 디버깅용
    // for(auto it = personality.begin(); it != personality.end(); it++)
    // {
    //     cout << it->first << ' ' << it->second << '\n';
    // }
    // cout << '\n';
    
    return answer;
}
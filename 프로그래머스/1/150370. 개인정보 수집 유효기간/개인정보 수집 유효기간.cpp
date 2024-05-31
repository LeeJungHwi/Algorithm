#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
    vector<int> answer;
    
    // today : 오늘 날짜
    // terms : 약관 종류, 유효 기간
    // privacies : 수집 일자, 약관 종류
    
    // 약관 종류 유효 기간 맵핑
    map<char, int> termsMap;
    for(int i = 0; i < terms.size(); i++) termsMap[terms[i][0]] = stoi(terms[i].substr(2, terms[i].size() - 2)) * 28;
    //for(auto it = termsMap.begin(); it != termsMap.end(); it++) cout << it->second << ' ';
    
    // 파기 해야 할 개인정보
    for(int i = 0; i < privacies.size(); i++)
    {
        int cur = stoi(today.substr(0, 4)) * 12 * 28 + stoi(today.substr(5, 2)) * 28 + stoi(today.substr(8, 2));
        int pri = stoi(privacies[i].substr(0, 4)) * 12 * 28 + stoi(privacies[i].substr(5, 2)) * 28 + stoi(privacies[i].substr(8, 2));
        
        if(cur - pri < termsMap[privacies[i][11]]) continue;
        answer.push_back(i + 1);
    }
    
    return answer;
}
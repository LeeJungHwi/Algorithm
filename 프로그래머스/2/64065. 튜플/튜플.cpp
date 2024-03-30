#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(string s)
{
    vector<int> answer;
    
    // s : 특정 튜플을 표현하는 집합이 담긴 문자열
    // answer : s가 표현하는 튜플 저장
    
    // 1.(숫자, 횟수) 맵핑
    // 2.(횟수, 숫자) 맵핑
    // 3.answer에 저장
    // 4.answer 뒤집기
    
    // 1.(숫자, 횟수) 맵핑
    // s 돌면서 숫자를 만나면 추가하다가
    // 숫자가 있으면서 } 또는 , 를 만나면 (숫자, 횟수) 맵핑
    
    map<int, int> numCnt;
    string num = "";
    
    for(int i = 0; i < s.size(); i++)
    {
        if(!num.empty() && (s[i] == '}' || s[i] == ','))
        {
            numCnt[stoi(num)]++;
            num = "";
            
            continue;
        }
        
        if(isdigit(s[i]))
        {
            num += s[i];
        }
    }
           
    // // 디버깅용
    // for(auto it = numCnt.begin(); it != numCnt.end(); it++)
    // {
    //     cout << it->first << ' ' << it->second << '\n';
    // }
    
    // 2.(횟수, 숫자) 맵핑
    
    map<int, int> cntNum;
    
    for(auto it = numCnt.begin(); it != numCnt.end(); it++)
    {
        cntNum[it->second] = it->first;
    }
    
    // 3.answer에 저장
    for(auto it = cntNum.begin(); it != cntNum.end(); it++)
    {
        answer.push_back(it->second);
    } 

    // 4.answer 뒤집기
    reverse(answer.begin(), answer.end());
    
    return answer;
}
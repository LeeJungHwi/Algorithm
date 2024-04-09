#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int minLen = 2147000000; // 최소길이

// DFS
void DFS(int L, string originString)
{
    if(L == originString.size() + 1) // 종료조건 : 원본문자열 길이를 넘긴경우
    {
        return;
    }
    else
    {
        map<string, int> m; // (압축단위로 자른 각 문자열, 개수) 맵핑
        string preString = ""; // 이전문자열
        int len = 0; // 압축한 길이
        
        // (압축단위로 자른 각 문자열, 개수) 맵핑
        for(int i = 0; i < originString.size(); i++)
        {
            // 압축단위로 자른 문자열
            string tempString = "";
            
            for(int j = i; j < i + L; j++)
            {
                if(j == originString.size())
                {
                    break;
                }
                
                tempString += originString[j];
            }
            
            // 처음문자열은 이전문자열에 저장
            if(i == 0)
            {
                preString = tempString;
            }
            
            // 이전문자열과 같으면 맵 카운팅
            if(preString == tempString)
            {
                m[preString]++;
            }
            else // 문자열이 다르면
            {
                // 이전문자열 길이 증가하고 키 삭제
                if(m[preString] >= 1000)
                {
                    len += preString.size() + 4;
                }
                else if(m[preString] >= 100)
                {
                    len += preString.size() + 3;
                }
                else if(m[preString] >= 10)
                {
                    len += preString.size() + 2;
                }   
                else if(m[preString] >= 2)
                {
                    len += preString.size() + 1;
                }
                else if(m[preString] == 1)
                {
                    len += preString.size();
                }
                
                m.erase(preString);
                
                // 새로운 문자열 맵 카운팅
                m[tempString]++;
            }
            
            // 이전문자열, i 갱신
            preString = tempString;
            i += L - 1;
        }
        
        // 맵 돌면서 길이증가
        
        for(auto it = m.begin(); it != m.end(); it++)
        {
            if(it->second >= 1000)
            {
                len += it->first.size() + 4;
            }
            else if(it->second >= 100)
            {
                len += it->first.size() + 3;
            }
            else if(it->second >= 10)
            {
                len += it->first.size() + 2;
            }
            else if(it->second >= 2)
            {
                len += it->first.size() + 1;
            }
            else if(it->second == 1)
            {
                len += it->first.size();
            }
        }
        
        // 최소길이 갱신
        minLen = min(minLen, len);
        
        // 다음레벨 재귀
        DFS(L + 1, originString);
    }
}

int solution(string s)
{
    int answer = 0;
    
    // s : 압축할 문자열
    // answer : 1개 이상 단위로 문자열을 잘라 압축해 표현한 문자열 중 가장 짧은 문자열의 길이
    
    // DFS 돌면서
    // 가장 짧은 압축한 문자열을 갱신
    DFS(1, s);
    answer = minLen;
    
    return answer;
}
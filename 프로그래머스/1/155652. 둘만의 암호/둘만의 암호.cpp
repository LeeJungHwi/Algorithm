#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(string s, string skip, int index)
{
    string answer = "";
    
    // s의 각 알파벳을 idx 만큼 뒤의 알파벳으로 바꾸기
    // idx 만큼 뒤의 알파벳이 z를 넘어가면 다시 a 로
    // skip 에 있는 알파벳은 스킵하기
    
    // skip 할 문자 맵핑
    map<char, int> skipMap;
    for(int i = 0; i < skip.size(); i++) skipMap[skip[i]]++;
    
    // 변환
    for(int i = 0; i < s.size(); i++)
    {
        int curIdx = 0;
        while(curIdx < index)
        {
            if(++s[i] > 'z') s[i] = 'a';
            if(!skipMap[s[i]]) curIdx++;
        }
    }
    
    return answer = s;
}
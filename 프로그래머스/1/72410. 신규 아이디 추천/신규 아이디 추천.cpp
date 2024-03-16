#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

string solution(string new_id)
{
    string answer = "";
    
    // 아이디 길이 : 3~15
    // 아이디 가능 : 소문자, 숫자, 빼기, 언더바, 마침표
    // 단, 마침표는 처음과 끝에 사용할수없고 연속적으로 사용할수없음
    
    // 네오 추천 알고리즘
    // 1.대문자 -> 소문자
    // 2.소문자, 숫자, 빼기, 언더바, 마침표만 남김
    // 3.마침표가 2번이상 연속되면 하나의 마침표로 바꿈
    // 4.마침표가 처음 또는 끝에 위치하면 제거함
    // 5.빈 문자열이면 a를 추가함
    // 6.길이가 16이상이면 첫 15개만 남기고 제거함
    // 7.길이가 2이하라면 마지막을 길이가 3이될때까지 추가함
    
    // 1.대문자 -> 소문자
    // 2.소문자, 숫자, 빼기, 언더바, 마침표만 남김
    
    string tempString = ""; // 임시문자열
    
    for(int i = 0; i < new_id.size(); i++)
    {
        if(isupper(new_id[i]))
        {
            new_id[i] = tolower(new_id[i]);
        }
        
        if(islower(new_id[i]) || isdigit(new_id[i]) || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
        {
            tempString += new_id[i];
        }
    }
    
    new_id = tempString;
    
    // 디버깅용
    // cout << tempString;
    
    // 3.마침표가 2번이상 연속되면 하나의 마침표로 바꿈
    // 읽어나가다가 마침표를 만나면 이전문자도 마침표였는지 체크
    // 이전문자도 마침표였다면 임시문자열에 추가하지않음
    
    tempString.clear();
    char pre = 'a';
    
    for(int i = 0; i < new_id.size(); i++)
    {
        if(new_id[i] == '.' && pre == '.')
        {
            pre = '.';
            continue;
        }
        
        tempString += new_id[i];
        pre = new_id[i];
    }
    
    new_id = tempString;
    
    // 디버깅용
    // cout << tempString;
    
    // 4.마침표가 처음 또는 끝에 위치하면 제거함
    // 5.빈 문자열이면 a를 추가함
    if(new_id[0] == '.')
    {
        new_id.erase(0, 1);
    }

    if(new_id[new_id.size() - 1] == '.')
    {
        new_id.pop_back();
    }
    
    if(new_id.empty())
    {
        new_id += 'a';
    }
    
    // 6.길이가 16이상이면 첫 15개만 남기고 제거함
    
    if(new_id.size() >= 16)
    {
        new_id = new_id.substr(0, 15);
    }
    
    cout << new_id << '\n';
    
    // 7.길이가 2이하라면 마지막을 길이가 3이될때까지 추가함
    
    while(new_id.size() <= 2)
    {
        new_id += new_id[new_id.size() - 1];
    }
    
    // 4.마침표가 처음 또는 끝에 위치하면 제거함
    // 5.빈 문자열이면 a를 추가함
    if(new_id[0] == '.')
    {
        new_id.erase(0, 1);
    }

    if(new_id[new_id.size() - 1] == '.')
    {
        new_id.pop_back();
    }
    
    if(new_id.empty())
    {
        new_id += 'a';
    }
    
    answer = new_id;
    
    return answer;
}
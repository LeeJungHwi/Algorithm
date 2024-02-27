#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(string myString)
{
    vector<int> answer;
    
    // 각 나눠진 문자열의 길이
    int length = 0;
    
    // 입력문자열을 읽으면서
    for(int i = 0; i < myString.size(); i++)
    {
        // x를 만나면
        if(myString[i] == 'x')
        {
            // 문자열 길이 저장 후 초기화
            answer.push_back(length);
            length = 0;
        }
        else // x가 아니면 길이 증가
        {
            length++;
        }
    }
    
    // 나눠진 마지막 문자열도 문자열길이 저장
    answer.push_back(length);
    
    return answer;
}
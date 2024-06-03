#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s)
{
    int answer = 0;
    
    // 3 : one two six => on tw si
    // 4 : zero four five nine => ze fo fi ni
    // 5 : three seven eight => th se ei
    
    // 각 숫자 글자 수, 숫자 맵핑
    map<string, pair<int, char> > numMap;
    numMap["on"] = {3, '1'};
    numMap["tw"] = {3, '2'};
    numMap["si"] = {3, '6'};
    numMap["ze"] = {4, '0'};
    numMap["fo"] = {4, '4'};
    numMap["fi"] = {4, '5'};
    numMap["ni"] = {4, '9'};
    numMap["th"] = {5, '3'};
    numMap["se"] = {5, '7'};
    numMap["ei"] = {5, '8'};
    
    string temp = "";
    for(int i = 0; i < s.size(); i++)
    {
        // 숫자가 아니면 문자 두 개 뽑아서 인덱스 갱신 및 temp에 저장
        if(isdigit(s[i]))
        {
            temp += s[i];
            continue;
        }
        
        pair<int, char> p = numMap[s.substr(i, 2)];
        i += p.first - 1;
        temp += p.second;
    }
    
    return answer = stoi(temp);
}
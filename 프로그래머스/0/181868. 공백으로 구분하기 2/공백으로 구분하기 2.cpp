#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> solution(string my_string)
{
    vector<string> answer;
    
    stringstream stringStream(my_string); // 문자열 스트림
    string token; // 문자열 토큰
    
    while(stringStream >> token) // 공백을 기준으로 벡터에 저장 
    {
        answer.push_back(token);
    }
    
    return answer;
}
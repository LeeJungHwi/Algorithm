#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2)
{
    int answer = 2;
    for(int i = 0; i < str1.size() - str2.size() + 1; i++)
    {
        if(str1[i] != str2[0]) continue;
        if(str1.substr(i, str2.size()) != str2) continue;
        return 1;
    }
    return answer;
}
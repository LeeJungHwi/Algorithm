#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2)
{
    for(int i = 0; i < str2.size() - str1.size() + 1; i++)
    {
        if(str2.substr(i, str1.size()) == str1) return 1;
    }
    return 0;
}
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string my_string)
{
    string answer = "";
    map<char, int> m;
    for(int i = 0; i < my_string.size(); i++)
    {
        if(m[my_string[i]] > 0) continue;
        answer.push_back(my_string[i]);
        m[my_string[i]]++;
    }
    return answer;
}
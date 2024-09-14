#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int m, int c)
{
    string answer = "";
    for(int i = 0; i < my_string.size(); i += m) { answer.push_back(my_string[i + c - 1]); }
    return answer;
}
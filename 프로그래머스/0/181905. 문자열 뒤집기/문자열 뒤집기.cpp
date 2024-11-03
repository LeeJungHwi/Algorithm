#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, int s, int e)
{
    string answer = "";
    for(int i = 0; i < s; i++) answer.push_back(my_string[i]);
    string t = my_string.substr(s, e - s + 1);
    reverse(t.begin(), t.end());
    answer += t;
    for(int i = e + 1; i < my_string.size(); i++) answer.push_back(my_string[i]);
    return answer;
}
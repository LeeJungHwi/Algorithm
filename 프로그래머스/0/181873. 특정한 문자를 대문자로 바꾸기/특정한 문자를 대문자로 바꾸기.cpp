#include <string>
#include <map>

using namespace std;

string solution(string my_string, string alp)
{
    map<char, int> m;
    for(int i = 0; i < alp.size(); i++) m[alp[i]]++;
    for(int i = 0; i < my_string.size(); i++) if(m[my_string[i]] > 0) my_string[i] = toupper(my_string[i]);
    return my_string;
}
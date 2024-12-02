#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string my_string)
{
    vector<int> answer(52);
    map<char, int> m;
    for(int i = 0; i < my_string.size(); i++) m[my_string[i]]++;
    for(auto it = m.begin(); it != m.end(); it++) answer[isupper(it->first) ? it->first - '0' - 17 : it->first - '0' - 23] = it->second;
    return answer;
}
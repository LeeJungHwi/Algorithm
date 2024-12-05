#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string rsp)
{
    string answer = "";
    map<char, char> m;
    m['2'] = '0';
    m['0'] = '5';
    m['5'] = '2';
    for(int i = 0; i < rsp.size(); i++) answer.push_back(m[rsp[i]]);
    return answer;
}
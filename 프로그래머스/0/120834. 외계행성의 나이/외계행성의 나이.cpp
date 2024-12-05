#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(int age)
{
    string answer = "";
    map<int, char> m;
    int curN = 0;
    char curC = 'a';
    for(int i = 0; i < 24; i++)
    {
        m[curN++] = curC++;
    }
    string temp = to_string(age);
    for(int i = 0; i < temp.size(); i++) answer.push_back(m[temp[i] - '0']);
    return answer;
}
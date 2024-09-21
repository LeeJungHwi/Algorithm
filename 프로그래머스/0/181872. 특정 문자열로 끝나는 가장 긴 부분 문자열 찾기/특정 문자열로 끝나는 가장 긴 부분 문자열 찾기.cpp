#include <string>
#include <vector>

using namespace std;

string solution(string myString, string pat)
{
    string answer = "";
    for(int i = 0; i < myString.size() - pat.size() + 1; i++) if(myString.substr(i, pat.size()) == pat) answer = myString.substr(0, i + pat.size());
    return answer;
}
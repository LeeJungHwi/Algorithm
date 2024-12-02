#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat)
{
    int answer = 0;
    for(int i = 0; i < myString.size(); i++) myString[i] = myString[i] == 'A' ? 'B' : 'A'; 
    for(int i = 0; i < myString.size() - pat.size() + 1; i++) if(myString.substr(i, pat.size()) == pat) return 1;
    return 0;
}
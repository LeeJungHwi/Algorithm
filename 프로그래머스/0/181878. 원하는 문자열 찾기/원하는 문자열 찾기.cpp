#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat)
{
    if(myString.size() < pat.size()) return 0;
    for(int i = 0; i < myString.size(); i++) if(isupper(myString[i])) myString[i] = tolower(myString[i]);
    for(int i = 0; i < pat.size(); i++) if(isupper(pat[i])) pat[i] = tolower(pat[i]);
    if(myString.size() == pat.size()) return myString == pat ? 1 : 0;
    for(int i = 0; i < myString.size() - pat.size(); i++) if(myString.substr(i, pat.size()) == pat) return 1;
    return 0;
}
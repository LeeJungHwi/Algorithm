#include <string>
#include <vector>

using namespace std;

string solution(string s, int n)
{
    for(int i = 0; i < s.size(); i++) if(isalpha(s[i])) for(int j = 0; j < n; j++) s[i] = islower(s[i]) ? (s[i] + 1 > 'z' ? 'a' : s[i] + 1) : (s[i] + 1 > 'Z' ? 'A' : s[i] + 1);
    
    return s;
}
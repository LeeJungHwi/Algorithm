#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s)
{
    if(s.size() == 1) return 1;
    if(s.size() == 2) return s[0] == s[1] ? 1 : 2;
    
    int answer = 0;
    char x = 'A';
    for(int i = 0; i < s.size(); i++)
    {
        x = s[i];
        cout << x << ' ';
        int xCnt = 0, otherCnt = 0;
        for(int j = i; j < s.size(); j++)
        {
            if(x == s[j]) xCnt++;
            else otherCnt++;
            
            if(xCnt == otherCnt)
            {
                answer++;
                i = j;
                x = 'A';
                break;
            }
            
            i = j;
        }
    }
    if(x != 'A') answer++;
    return answer;
}
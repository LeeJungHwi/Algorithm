#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string a, string b)
{
    string answer = "";
    int aSize = a.size(), bSize = b.size();
    if(aSize > bSize) for(int i = 0; i < aSize - bSize; i++) b = '0' + b;
    else if(aSize < bSize) for(int i = 0; i < bSize - aSize; i++) a = '0' + a;
    int carry = 0;
    for(int i = a.size() - 1; i > -1; i--)
    {
        int num = (a[i] - '0') + (b[i] - '0') + carry;
        carry = num / 10;
        num = num % 10;
        answer.push_back(num + '0');
    }
    if(carry > 0) answer.push_back(carry + '0');
    reverse(answer.begin(), answer.end());
    return answer;
}
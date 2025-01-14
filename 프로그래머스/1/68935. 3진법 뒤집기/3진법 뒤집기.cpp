#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n)
{
    int answer = 0;
    stack<int> s;
    
    //     3 * 15 0
    //     3 * 5 0
    //     3 * 1 2

    //     3 * 41 2
    //     3 * 13 2
    //     3 * 4 1
    //     3 * 1 1
    while(n >= 3)
    {
        s.push(n % 3);
        n /= 3;
    }
    s.push(n % 3);
    
    // 1 * 3 + 3 * 2 + 3^2 * 0 + 3^3 * 0 = 7
    int pos = 0;
    while(!s.empty())
    {
        cout << s.top() << ' ';
        answer += s.top() * pow(3, pos);
        s.pop();
        pos++;
    }
    
    return answer;
}
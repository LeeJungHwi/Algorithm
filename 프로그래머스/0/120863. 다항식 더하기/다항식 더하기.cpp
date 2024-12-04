#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string polynomial)
{
    string answer = "";
    polynomial += '+';
    string temp = "";
    int xCoef = 0, cCoef = 0;
    for(int i = 0; i < polynomial.size(); i++)
    {
        if(polynomial[i] == ' ') continue;
        if(polynomial[i] == 'x')
        {
            xCoef += temp.empty() ? 1 : stoi(temp);
            temp = "";
            continue;
        }
        if(polynomial[i] == '+')
        {
            if(temp.empty()) continue;
            cCoef += stoi(temp);
            temp = "";
            continue;
        }
        
        temp += polynomial[i];
    }
    //cout << xCoef << ' ' << cCoef << '\n';
    if(xCoef) answer += xCoef == 1 ? "x" : to_string(xCoef) + 'x';
    if(xCoef && cCoef) answer += " + " + to_string(cCoef);
    if(!xCoef && cCoef) answer += to_string(cCoef);
    return answer;
}
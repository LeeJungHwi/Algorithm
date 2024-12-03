#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string bin1, string bin2)
{
    if(bin1 == "0" && bin2 == "0") return "0";
    int sz1 = bin1.size(), sz2 = bin2.size(); 
    if(sz1 > sz2)
    {
        for(int i = 0; i < sz1 - sz2; i++)
        {
            bin2 = '0' + bin2;
        }
    }
    else if(sz2 > sz1)
    {
        for(int i = 0; i < sz2 - sz1; i++)
        {
            bin1 = '0' + bin1;
        }
    }
    //cout << bin1 << ' ' << bin2 << '\n';
    string answer = "";
    int carry = 0;
    for(int i = bin1.size() - 1; i > -1; i--)
    {
        int sum = (bin1[i] - '0') + (bin2[i] - '0') + carry;
        carry = sum / 2;
        sum = sum % 2;
        //char temp = sum+'0';
        //cout << temp;
        answer.push_back(sum + '0');
    }
    answer.push_back(carry + '0');
    reverse(answer.begin(), answer.end());
    for(int i = 0; i < answer.size(); i++)
    {
        if(answer[i] == '1') break;
        answer.erase(0, 1);
        i--;
    }
    
    return answer;
}
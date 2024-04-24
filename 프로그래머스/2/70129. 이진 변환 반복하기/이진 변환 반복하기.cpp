#include <string>
#include <vector>
#include <iostream>

using namespace std;

int convertCnt = 0; // 이진변환 횟수
int eraseZeroCnt = 0; // 0을 제거한 횟수

// 이진변환
void BinaryConvert(string &x)
{
    if(x == "1") return; // x가 1이되면 종료
    
    // 1.모든 0 제거
    // 2.x의길이 c를 이진수로
    // 3.1,2 반복
    
    // 1.모든 0 제거
    
    for(int i = 0; i < x.size(); i++)
    {
        if(x[i] == '0')
        {
            x.erase(i, 1);
            eraseZeroCnt++;
            i--;
        }
    }
    
    //cout << x << '\n';
    
    // 2.x의길이 c를 이진수로
    string temp;
    int xSize = x.size();
    
    while(true)
    {
        if(xSize == 1)
        {
            temp = "1" + temp;
            break;
        }
        
        temp = to_string(xSize % 2) + temp;
        xSize /= 2;
    }
    
    x = temp;
    convertCnt++;
    
    //cout << temp << '\n';
    
    // 3.1,2 반복
    BinaryConvert(x);
}

vector<int> solution(string s)
{
    vector<int> answer;
    
    BinaryConvert(s);
    
    answer.push_back(convertCnt);
    answer.push_back(eraseZeroCnt);
    
    return answer;
}
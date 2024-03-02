#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<string> solution(vector<string> quiz)
{
    vector<string> answer;
    
    // quiz 돌면서
    // 처음숫자, 두번째숫자, 세번째숫자, 연산자 구함
    // op에 따라 첫번째숫자와 두번째숫자 연산해서 result에 저장
    // result와 세번째수가 같으면 O 다르면 X 저장
    
    // 전체퀴즈 수만큼 돌면서 -10000 + -10000 = -20000
    for(int i = 0; i < quiz.size(); i++)
    {
        int result = 0; // 결과숫자
        string firstNum = ""; // 처음숫자
        string op = ""; // 연산자
        string secondNum = ""; // 두번째숫자
        string thirdNum = ""; // 세번째숫자
        int thirdNumIdx = 0; // 세번쨰숫자 시작 인덱스
        int curFlag = 1; // 현재 어느숫자를 저장하고있는지
        bool isStartNum = false; // -10000 + -10000 = -20000일때 아직 숫자를 만나지않았으면 연산자도 숫자에 저장
        quiz[i].erase(remove(quiz[i].begin(), quiz[i].end(), ' '), quiz[i].end()); // 공백 제거
        
        // 각 퀴즈를 돌면서
        for(int j = 0; j < quiz[i].size(); j++)
        {
            // 아직 숫자를 만나지않았거나 숫자면 현재플래그에 따라 숫자 저장
            if(!isStartNum ||isdigit(quiz[i][j]) != 0)
            {
                isStartNum = true; // 숫자 만난상태
                
                if(curFlag == 1) // 3
                {
                    firstNum += quiz[i][j];
                }
                else if(curFlag == 2) // 4
                {
                    secondNum += quiz[i][j];
                }
            }
            else // 연산자면 연산자 저장
            {
                if(curFlag == 1) // - 나오면 연산자 저장
                {
                    op = quiz[i][j];                    
                }
                else if(curFlag == 2) // = 나오면 세번째숫자 시작인덱스 구하고 break
                {
                    thirdNumIdx = j + 1;
                        
                    break;
                }
                
                // 현재숫자 저장이 끝났으므로 플래그++
                curFlag++;
                
                // 숫자 만난상태 초기화
                isStartNum = false;
            }
        }
        
        // 세번째숫자 구하기
        for(int j = thirdNumIdx; j < quiz[i].size(); j++)
        {
            thirdNum += quiz[i][j]; // -3
        }
        
        // op에 따라 첫번째숫자와 두번째숫자 연산해서 result에 저장
        if(op == "+")
        {
            result = stoi(firstNum) + stoi(secondNum);
        }
        else if(op == "-")
        {
            result = stoi(firstNum) - stoi(secondNum);
        }
        
        // 디버깅용
        cout << firstNum << ' ' << op << ' ' << secondNum << ' ' << thirdNum << ' ' << result << '\n';
        
        // result와 세번째수가 같으면 O 다르면 X 저장
        if(to_string(result) == thirdNum)
        {
            answer.push_back("O");
        }
        else
        {
            answer.push_back("X");
        }
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;
    
    // phone_book : 전화번호부
    // answer : 한 번호가 다른 번호의 접두사인 경우가 있으면 false 모두 아니면 true
    
    // 정렬하고 인접한 전화번호끼리 체크
    
    sort(phone_book.begin(), phone_book.end());
    
    for (int i = 0; i < phone_book.size() - 1; i++)
    {
        // 이전 전화번호가 현재 전화번호의 접두사인지 체크
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
        {
            return answer = false;
        }
    }
    
    return answer;
}

// #include <string>
// #include <vector>
// #include <map>
// #include <algorithm>
// #include <iostream>

// using namespace std;

// // 맵 정렬
// struct mapCompare
// {
//     bool operator()(const int &size1, const int &size2) const
//     {
//         return size1 < size2;
//     }
// };

// // 전화번호부 정렬
// bool compare(const string &s1, const string &s2)
// {
//     return s1.size() < s2.size();
// }

// bool solution(vector<string> phone_book)
// {
//     bool answer = true;
    
//     // phone_book : 전화번호부
//     // answer : 한 번호가 다른 번호의 접두사인 경우가 있으면 false 모두 아니면 true
    
//     // 전화번호부 돌면서 전화번호 맵핑
//     // 맵돌면서 다른 전화번호의 접두사인지 체크
    
//     map<int, vector<string>, mapCompare> phoneNum;
//     sort(phone_book.begin(), phone_book.end(), compare);
    
//     // for(auto a : phone_book)
//     // {
//     //     cout << a << '\n';
//     // }
    
//     // 전화번호부 돌면서 전화번호 맵핑
//     for(int i = 0; i < phone_book.size(); i++)
//     {
//         phoneNum[phone_book[i].size()].push_back(phone_book[i]);
//     }
    
//     // for(auto it = phoneNum.begin(); it != phoneNum.end(); it++)
//     // {
//     //     for(auto a : it->second)
//     //     {
//     //         cout << a << ' ';
//     //     }
//     //     cout << '\n';
//     // }
//     // cout << '\n';
    
//     // 맵돌면서 
    
//     int numSize = phone_book[0].size(); // 2
        
//     for(int i = 0; i < phone_book.size(); i++)
//     {
//         // 사이즈가 바뀌면 맵 첫요소 삭제
//         if(numSize != phone_book[i].size())
//         {
//             numSize = phone_book[i].size();
//             phoneNum.erase(phoneNum.begin());
//         }
        
//         for(auto it = phoneNum.begin(); it != phoneNum.end(); it++)
//         {
//             for(int j = 0; j < it->second.size(); j++)
//             {
//                 bool isPrefix = true;
                
//                 // 같은전화번호가 아닌경우
//                 if(it->second[j] != phone_book[i])
//                 {
//                     for(int k = 0; k < numSize; k++)
//                     {
//                         if(phone_book[i][k] != it->second[j][k])
//                         {
//                             isPrefix = false;
//                             break;
//                         }
//                     }
//                 }
//                 else continue;
                
//                 if(isPrefix) return answer = false;
//             }
//         }
        
        
//     }
    
//     return answer;
// }
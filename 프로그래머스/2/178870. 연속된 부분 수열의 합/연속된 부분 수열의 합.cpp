#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k)
{
    vector<int> answer;
    
    // k를 초과하지 않을때까지
    // sequence 돌면서 부분수열의 합이 k인 부분수열을 구함
    // 구한 부분수열 중 길이가 가장 짧은 길이를 구함
    
    int minLen = 2147000000; // 최소길이
    pair<int, int> range; // 최소길이 부분수열 범위
    
    int first = 0; // 처음
    int subSequenceSum = 0; // 부분수열 합
    
    // 마지막 값을 정해놓고
    for (int last = 0; last < sequence.size(); last++)
    {
        subSequenceSum += sequence[last]; // 현재까지 부분수열 합
        
        // 합이 k를 초과할 때까지 처음 이동
        while (subSequenceSum > k && first <= last)
        {
            subSequenceSum -= sequence[first++];
        }
        
        // 합이 k인 경우
        // 최소길이 부분수열인 경우만 범위에 저장
        if (subSequenceSum == k && minLen > (last - first + 1))
        {
            if(minLen > (last - first + 1))
            {
                minLen = last - first + 1;
                range = {first, last};         
            }
        }
    }
    
    // answer에 range 저장
    answer.push_back(range.first);
    answer.push_back(range.second);
    
    return answer;
}

// #include <string>
// #include <vector>

// using namespace std;

// vector<int> solution(vector<int> sequence, int k)
// {
//     vector<int> answer;
    
//     // k를 초과하지 않을때까지
//     // sequence 돌면서 부분수열의 합이 k인 부분수열을 구함
//     // 구한 부분수열 중 길이가 가장 짧은 길이를 구함
    
//     int minLen = 2147000000; // 최소길이
//     pair<int, int> range; // 최소길이 부분수열 범위
//     int subSequenceSum; // 부분수열 합
//     int len; // 부분수열 길이
    
//     for(int i = 0; i < sequence.size(); i++)
//     {
//         subSequenceSum = 0;
//         len = 0;
        
//         for(int j = i; j < sequence.size(); j++)
//         {
//             subSequenceSum += sequence[j];
//             len++;
            
//             // k를 초과하면 break
//             if(subSequenceSum > k)
//             {
//                 break;
//             }
//             // k와 같으면
//             // minLen인 경우만 부분수열 범위에 저장
//             else if(subSequenceSum == k)
//             {
//                 if(minLen > len)
//                 {
//                     minLen = len;
//                     range = {i, j};
                    
//                     break;
//                 }
//             }
//         }
//     }
    
//     // range를 answer에 저장
//     answer.push_back(range.first);
//     answer.push_back(range.second);
    
//     return answer;
// }
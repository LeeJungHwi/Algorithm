#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n)
{
    int answer = 0;
    vector<int> nums;
    int cnt = n;
    while(cnt--)
    {
        answer++;
        while(true)
        {
            bool isThree = false;
            string temp = to_string(answer);
            for(int i = 0; i < temp.size(); i++)
            {
                if(temp[i] == '3')
                {
                    isThree = true;
                    break;
                }
            }
            
            if(answer % 3 == 0 || isThree) answer++;
            else break;
        }
        nums.push_back(answer);
    }
    for(auto num : nums) cout << num;
    return nums[n - 1];
}
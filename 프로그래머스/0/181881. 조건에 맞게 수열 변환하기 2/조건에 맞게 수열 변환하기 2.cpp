#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr)
{
    int answer = 0;
    while(true)
    {
        answer++;
        int temp1 = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            int temp2 = arr[i];
            if(arr[i] >= 50 && arr[i] % 2 == 0)arr[i] /= 2;
            else if(arr[i] < 50 && arr[i] % 2 == 1) arr[i] = arr[i] * 2 + 1;
            if(temp2 == arr[i]) temp1++;
        }
        if(temp1 == arr.size()) return --answer;
    }
}
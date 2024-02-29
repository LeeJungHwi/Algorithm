#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list)
{
    vector<int> answer;
    
    // arr : 정수배열
    // delete_list : 여기안에있는 요소를 arr에서 삭제
    // 남은 arr 요소들을 기존순서를 유지해서 출력하기 
    
    // 1. 삭제할 요소 체크하기
    vector<bool> deleteList(1001);
    
    for(int i = 0; i < delete_list.size(); i++)
    {
        deleteList[delete_list[i]] = true;
    }
    
    // 2. arr 돌면서 삭제할요소 아닌것만 answer에 저장
    for(int i = 0; i < arr.size(); i++)
    {
        if(!deleteList[arr[i]])
        {
            answer.push_back(arr[i]);
        }
    }
    
    return answer;
}
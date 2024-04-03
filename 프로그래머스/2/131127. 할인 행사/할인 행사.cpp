#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;
    
    // 일정 금액 지불시 10일동안 회원자격이 부여됨
    // 회원을 대상으로 매일 한가지 제품을 할인함
    // 할인제품은 하루에 하나만 구매가능함
    // 자신이 원하는 제품과 수량이 할인하는 날짜와 10일 연속으로 일치할 경우에 맞춰 회원가입하려고함
    // 예시
    // 바나나 3 사과 2 쌀 2 돼지고기 2 냄비 1 을 할때
    // 14일간 회원을 대상으로 할인하는 제품이 날짜순대로
    // 치킨, 사과, 사과, 바나나, 쌀, 사과, 돼지고기, 바나나, 돼지고기, 쌀, 냄비, 바나나, 사과, 바나나인 경우
    // 첫날부터 열흘간 냄비가 할인하지않으므로 첫날에 가입하지않음
    // 둘날부터 열흘간 원하는 바나나 수만큼 할인가로 구매할수없으므로 둘날에 가입하지않음
    // 셋날, 넷날, 다섯날부터 가입하면 각각 열흘은 원하는 제품과 수량이 일치하므로 셋중 하루에 회원가입을함
    
    // want : 원하는 제품
    // number : 원하는 제품 수
    // discount : 할인 제품
    
    // answer : 회원등록시 원하는 제품을 모두 할인받을수있는 회원등록 날짜의 총 일수, 없으면 0
    
    // (원하는 제품, 원하는 제품 수) 맵핑
    // discount i = 0 ~ discount.size() - 9 까지 돌면서 모두 구매가능하면 answer 카운팅
    
    // (원하는 제품, 원하는 제품 수) 맵핑
    map<string, int> product;
    
    for(int i = 0; i < want.size(); i++)
    {
        product[want[i]] = number[i];
    }
    
    // discount i = 0 ~ discount.size() - 9 까지 돌면서 모두 구매가능하면 answer 카운팅
    for(int i = 0; i < discount.size() - 9; i++)
    {
        map<string, int> temp = product; // 임시로 원하는 제품 복사
        bool isDay = true; // 가능한 날인지 체크
        
        // 현재 날부터 10개 할인제품을 보면서
        for(int j = i; j < i + 10; j++)
        {
            // 원하는 제품이면
            if(temp[discount[j]] > 0)
            {
                temp[discount[j]]--;
            }
        }
        
        // 맵 돌면서
        for(auto it = temp.begin(); it != temp.end(); it++)
        {
            // 구매하지 못한 제품이 있으면 불가능한 날
            if(it->second > 0)
            {
                isDay = false;   
                
                break;
            }
        }
        
        // 가능한 날만 카운팅
        if(isDay)
        {
            answer++;
        }
    }
    
    return answer;
}
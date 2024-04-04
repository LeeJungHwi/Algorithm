#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <map>

using namespace std;

// 예약 구조체
struct Book
{
    int enterTime; // 입실시간
    int exitTime; // 퇴실시간
    
    // 생성자
    Book() {}
    Book(int enter, int exit) : enterTime(enter), exitTime(exit) {}
    
    // 정렬기준
    // 입실시간 최소힙
    bool operator<(const Book &book)const
    {
        return enterTime > book.enterTime;
    }
};

int solution(vector<vector<string>> book_time)
{
    int answer = 0;
    
    // 퇴실시간 기준 10분 뒤에 다음손님 사용 가능함 
    // book_time : 예약시각
    // answer : 필요한 최소 객실 수
    
    // book_time 돌면서 우선순위큐에 저장
    priority_queue<Book> books;
    
    for(int i = 0; i < book_time.size(); i++)
    {
        books.push(Book(stoi(book_time[i][0].substr(0,2)) * 60 + stoi(book_time[i][0].substr(3,2)), stoi(book_time[i][1].substr(0,2)) * 60 + stoi(book_time[i][1].substr(3,2))));
    }
    
    // 디버깅용
    // while(!books.empty())
    // {
    //     cout << books.top().enterTime << '\n';
    //     books.pop();
    // }
    
    // 방을 하나 더 써야하는 상황 : 현재 쓰던 방 중 자리가 없을때
    // 큐가 빌때까지 큐에서 하나씩 꺼내면서
    // 현재 쓰던 방이 없거나 현재 쓰던 방을 모두 사용중이면 (새로운방번호, 퇴실시간 + 10) 맵핑하고 방번호 카운팅
    // 현재 쓰던 방 중 자리가 있으면 (빈방번호, 퇴실시간 + 10) 맵핑
    
    int curRoomNum = 1; // 현재 방 번호
    map<int, int> roomExit; // (방번호, 퇴실시간 + 10) 맵핑
    
    while(!books.empty())
    {
        // 현재 쓰던방이 없는지 체크
        if(curRoomNum == 1)
        {
            // (새로운방번호, 퇴실시간 + 10) 맵핑하고 방번호 카운팅
            roomExit[curRoomNum] = books.top().exitTime + 10;
            books.pop();
            curRoomNum++;
            continue;
        }
        
        // 맵 돌면서
        
        bool isEmptyRoom = false; // 빈방이 있는지 체크
        
        for(auto it = roomExit.begin(); it != roomExit.end(); it++)
        {
            // 현재 쓰던 방 중 퇴실시간 <= 큐탑 입실시간 이면
            // 빈방이므로 (빈방번호, 퇴실시간 + 10) 맵핑
            if(it->second <= books.top().enterTime)
            {
                roomExit[it->first] = books.top().exitTime + 10;
                books.pop();
                isEmptyRoom = true;
                break;
            }
        }
        
        // 빈방이 있었으면 continue
        if(isEmptyRoom)
        {
            continue;
        }
        
        // 현재 쓰던 방을 모두 사용중이면
        // (새로운방번호, 퇴실시간 + 10) 맵핑하고 방번호 카운팅
        roomExit[curRoomNum] = books.top().exitTime + 10;
        books.pop();
        curRoomNum++;
    }
    
    answer = roomExit.size();
    
    return answer;
}
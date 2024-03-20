#include <iostream>
#include <string>
using namespace std;

typedef string bigint;

bigint sum(bigint, bigint);
bigint sub(bigint, bigint);

// 문제 조건 : 입력값은 자연수로 들어온다.

int main(){
    // 숫자 입력
    bigint num1, num2;
    cout<<"First number\t>> ";
    cin>>num1;
    cout<<"Second number\t>> ";
    cin>>num2;
    
    // 계산
    bigint bigSum=sum(num1, num2);
    //bigint bigSub=sub(num1, num2);
    
    // 출력
    cout<<"Sum\t\t>> "<<bigSum<<"\n";
    //cout<<"Sub\t\t>> "<<bigSub;

    return 0;
}
#include <string>
#include <iostream>
using namespace std;
typedef string bigint;

bigint reverse(bigint s){
    bigint result="";
    int size=s.size();
    for(int i=size-1;i>=0;i--) {
        result += s[i];
    }
    return result;
}

bigint sum(bigint a, bigint b){
    int aSize = a.size();
    int bSize = b.size();
    int maxLen=max(aSize, bSize);

    // 계산 편의를 위해 reverse
    a = reverse(a);
    b = reverse(b);

    // 한 자리씩 더하기
    bigint result = "";
    int carry = 0;
    for(int i = 0; i < maxLen; i++){
        int n1 = (i < aSize)? a[i]-'0' : 0;
        int n2 = (i < bSize)? b[i]-'0' : 0;
        result += to_string((n1 + n2 + carry) % 10);
        carry = (n1 + n2) / 10;
    }

    // 마지막 carry 처리
    if(carry > 0) result += to_string(carry);
    
    // 다시 뒤집어서 결과 반환 
    // (입력값이 자연수니까 sum은 앞자리 0이나 - 처리할 필요 없음)
    result = reverse(result);
    return result;
}

bigint sub(bigint a, bigint b){

    return "";
}
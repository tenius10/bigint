#include <string>
#include <iostream>
using namespace std;
typedef string bigint;

bigint reverse(bigint s){
    bigint result = "";
    int size = s.size();
    for(int i = size-1; i >= 0; i--) {
        result += s[i];
    }
    return result;
}

int compare(bigint a, bigint b){
    int aSize = a.size();
    int bSize = b.size();
    
    if(aSize > bSize) return 1;
    else if(aSize < bSize) return -1;
    else{
        for(int i = 0; i < aSize; i++){
            if(a[i] > b[i]) return 1;
            else if(a[i] < b[i]) return -1;
        }
        return 0;
    }
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
        carry = (n1 + n2 + carry) / 10;
    }

    // 마지막 carry 처리
    if(carry > 0) result += to_string(carry);
    
    // 다시 뒤집어서 결과 반환 
    // (입력값이 자연수니까 sum은 앞자리 0이나 - 처리할 필요 없음)
    result = reverse(result);
    return result;
}
/**
 * (큰 수)-(작은 수) 형태로 계산하고서, 
 * a가 더 작으면 result 앞에 마이너스 붙이기
*/
bigint sub(bigint a, bigint b){
    // 큰 수, 작은 수 준비
    bigint small, big;
    int comp = compare(a, b);
    if(comp < 0){
        small = a;
        big = b;
    }
    else{
        small = b;
        big = a;
    }

    // 숫자 뒤집기
    big = reverse(big);
    small = reverse(small);

    // 큰 수에서 작은 수 빼기
    int bigSize = big.size();
    int smallSize = small.size();
    int maxLen = bigSize;

    bigint result = "";
    int borrow = 0;
    for(int i = 0; i < maxLen; i++){
        int n1 = (i < bigSize)? big[i]-'0' : 0;
        int n2 = (i < smallSize)? small[i]-'0' : 0;
        int n3 = n1 - n2;

        if(n3 < 0){
            // borrow 가져오기 
            // (큰 수 - 작은 수 형태라서 borrow를 못 하는 경우는 없음)
            n3 += 10;
            int j = i + 1;  //borrow를 하려는 위치
            while(big[j] == '0'){
                big[j++] = '9';
            }
            big[j]--;  //big[j]가 0보다 크니까 1을 빼도 아스키 상에서 숫자가 유효함.
        }

        result += to_string(n3);
    }

    // a가 더 작았으면 앞에 마이너스 붙이기
    if(comp < 0) result += '-';
    
    // 뒤집고 앞에 0 제거
    result = reverse(result);

    int zeroCount = 0;
    int resultSize = result.size();
    for(int i = 0; i < resultSize; i++){
        if(result[i] == '0') zeroCount++;
        else break;
    }
    result.erase(0, zeroCount);

    if(result.size()==0) result = "0";

    return result;
}